#include <iostream>
#include <thread>
#include <chrono>
#include "pp.hpp"

void work(int id, int duration) {
  std::this_thread::sleep_for(std::chrono::seconds(duration));
  std::cout << "Task " << id << " completed after " << duration << " seconds." << '\n';
}

int main() {
  using namespace std;
  PromisePool pool;

  cout << "Pushing tasks to the pool... id: 3 is separate" << '\n';
  int id1 = pool.push(work, 1, 2);
  int id2 = pool.push(work, 2, 1);

  int id3 = pool.push([](int a) -> int {
    return 3 * a; // Random number i rolled on a dice.
  }, 2); // Another random number i rolled on a dice.

  this_thread::sleep_for(chrono::seconds(3));

  cout << "id3: " << pool.pop<int>(id3) << '\n'
       << "Pool size: " << pool.size() << '\n'
       << "Is pool empty? " << (pool.isEmpty() ? "Yes" : "No") << '\n'
       << "Waiting for any task to complete..." << '\n';

  int readyId = pool.waitAny();

  cout << "Task " << readyId << " is ready." << '\n'
       << "Waiting for any task to complete within 2 seconds..." << '\n';
  
  readyId = pool.waitAnyFor(chrono::seconds(2));

  if (readyId != -1) {
    cout << "Task " << readyId << " completed within the timeout." << '\n';
  } else {
    cout << "No task completed within the timeout." << '\n';
  }

  cout << "Checking ready tasks..." << '\n';
  auto readyIds = pool.getReadyIds();

  for (int id : readyIds) {
    cout << "Task " << id << " is ready." << '\n';
  }

  cout << "Cancelling task 3..." << '\n';

  pool.cancel(id3);

  cout << "Waiting for all tasks..." << '\n';

  pool.waitAll();

  cout << "All tasks completed or cancelled." << '\n'
       << "Clearing the pool..." << '\n';

  pool.clear();

  cout << "Is pool empty now? " << (pool.isEmpty() ? "Yes" : "No") << '\n';

  return 0;
}
