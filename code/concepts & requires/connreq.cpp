#include <concepts>
#include <type_traits>
#include <iostream>

template <class T>
concept Allocated = requires(T t) {
  { t.allocate() } -> std::same_as<void*>;
  { t.deallocate(std::declval<void*>()) } -> std::same_as<void>;
  { t.is_allocated() } -> std::same_as<bool>;
};

template <class T>
concept Numeric = std::is_arithmetic_v<T>;

template <class T>
concept Printable = requires(T t, std::ostream& os) {
  { os << t } -> std::same_as<std::ostream&>;
};

template <Allocated T>
void use_allocated(T& obj) {
  void* ptr = obj.allocate();
  std::cout << "Allocated: " << obj.is_allocated() << std::endl;
  obj.deallocate(ptr);
}

template <Numeric T>
T square(T value) {
  return value * value;
}

template <Printable T>
void print(const T& value) {
  std::cout << value << std::endl;
}

struct MyAllocator {
  void* allocate() { return nullptr; }
  void deallocate(void*) {}
  bool is_allocated() { return false; }
};

int main() {
  MyAllocator allocator;
  use_allocated(allocator);

  std::cout << "Square of 5: " << square(5) << std::endl;
  std::cout << "Square of 3.14: " << square(3.14) << std::endl;

  print("Hello, Concepts!");
  print(42);

  return 0;
}