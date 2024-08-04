#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <vector>
#include <mutex>

#include "pg.hpp"

void barThread(std::string id, int lineNumber);

int main(int, char** argv) {
  std::vector<std::thread> threads;
  
  // Clear the screen and move the cursor to the top-left corner
  std::cout << "\033[2J\033[1;1H";
  
  for (int i = 1; i <= std::stoi(argv[1]); i++) {
    std::thread Thr(&barThread, std::to_string(i) + " ", i);
    threads.push_back(std::move(Thr));
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));
  }
  
  for (std::thread& thr : threads)
  {
    thr.join();
  }
  
  return 0;
}

void barThread(std::string id, int lineNumber) {
  pBar* bar = new pBar;
  
  for (int i = 0; i < 400; i++) {
    (*bar).update(0.25);
    (*bar).print(id, lineNumber);
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
  
  delete bar;
}