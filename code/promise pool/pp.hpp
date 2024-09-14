#ifndef PP_HPP
#define PP_HPP

#include <future>
#include <functional>
#include <vector>
#include <memory>
#include <atomic>
#include <stdexcept>
#include <algorithm>
#include <chrono>

class PromisePool {
private:
  std::vector<std::future<void*>> futures;
  std::atomic<int> nextId;

public:
  PromisePool() : nextId(0) {}

  template <class F, class... Args>
  int push(F&& func, Args&&... args) {
    auto boundFunc = [f = std::forward<F>(func), ... args = std::forward<Args>(args)]() -> void* {
      if constexpr (std::is_void_v<std::invoke_result_t<F, Args...>>) {
        f(args...);
        return nullptr;
      } else {
        return new std::invoke_result_t<F, Args...>(f(args...));
      }
    };
    futures.push_back(std::async(std::launch::async, std::move(boundFunc)));
    return nextId++;
  }

  template<class T>
  T pop(int id) {
    if (id < 0 || id >= static_cast<int>(futures.size())) {
      throw std::out_of_range("Invalid future ID");
    }

    auto fut = std::move(futures[id]);
    futures[id] = std::future<void*>(); // Clear the future
    fut.wait(); // Ensure the future is ready

    if constexpr (std::is_void_v<T>) {
      fut.get();
    } else {
      auto ptr = static_cast<T*>(fut.get());

      if (ptr == nullptr) {
        throw std::runtime_error("Unexpected null pointer");
      }

      T result = *ptr;
      delete ptr;
      return result;
    }
  }

  void waitAll() {
    for (auto& fut : futures) {
      if (fut.valid()) {
        fut.wait();
      }
    }
  }

  bool isReady(int id) const {
    if (id < 0 || id >= static_cast<int>(futures.size())) {
      throw std::out_of_range("Invalid future ID");
    }
    return futures[id].valid() && 
           futures[id].wait_for(std::chrono::seconds(0)) == std::future_status::ready;
  }

  size_t size() const {
    return futures.size();
  }

  void clear() {
    futures.clear();
    nextId.store(0);
  }

  bool isEmpty() const {
    return futures.empty();
  }

  int waitAny() {
    auto it = std::find_if(futures.begin(), futures.end(), [](const auto& fut) {
      return fut.valid() && fut.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
    });
    if (it != futures.end()) {
      return std::distance(futures.begin(), it);
    }
    return -1;
  }

  template<class Rep, class Period>
  int waitAnyFor(const std::chrono::duration<Rep, Period>& timeout) {
    auto start = std::chrono::steady_clock::now();
    while (std::chrono::steady_clock::now() - start < timeout) {
      int readyId = waitAny();
      if (readyId != -1) {
        return readyId;
      }
      std::this_thread::yield();
    }
    return -1;
  }

  std::vector<int> getReadyIds() const {
    std::vector<int> readyIds;
    for (size_t i = 0; i < futures.size(); ++i) {
      if (isReady(i)) {
        readyIds.push_back(i);
      }
    }
    return readyIds;
  }

  void cancel(int id) {
    if (id < 0 || id >= static_cast<int>(futures.size())) {
      throw std::out_of_range("Invalid future ID");
    }
    futures[id] = std::future<void*>();
  }

  void cancelAll() {
    for (auto& fut : futures) {
      fut = std::future<void*>();
    }
  }
};

#endif