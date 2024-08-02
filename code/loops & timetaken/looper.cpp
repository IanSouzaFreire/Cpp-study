#include <algorithm>
#include <iostream>
#include <iterator>
#include <csetjmp>
#include <chrono>
#include <thread>
#include <vector>

#define sleepTime chrono::milliseconds(5)

using namespace std::chrono;
using namespace std;

const int count_to = 100;

int recurse(int start, int finish);
void clearscrn();

int main() {
  // While loop
  auto start = high_resolution_clock::now();

  int i = 0;
  while (i < count_to) {
    std::cout << "WHILE: " << i << '\n';
    this_thread::sleep_for(sleepTime);
    clearscrn();
    i++;
  }

  auto final = duration_cast<microseconds>(high_resolution_clock::now() - start);
  microseconds whiletime = final;

  // For loop
  start = high_resolution_clock::now();

  for (int j = 0; j < count_to; j++) {
    std::cout << "FOR: " << j << '\n';
    this_thread::sleep_for(sleepTime);
    clearscrn();
  }

  final = duration_cast<microseconds>(high_resolution_clock::now() - start);
  microseconds fortime = final;

  // Jmp statement
  start = high_resolution_clock::now();

  i = 0;
  jmp_buf loopstrt;
  int val = setjmp(loopstrt); // Save the environment
  if (i < count_to) {
    std::cout << "JMP: " << i << '\n';
    this_thread::sleep_for(sleepTime);
    clearscrn();
    i++;
    longjmp(loopstrt, 1); // Restore the environment
  }

  final = duration_cast<microseconds>(high_resolution_clock::now() - start);
  microseconds jmptime = final;

  // Recursion
  start = high_resolution_clock::now();

  i = 0;
  recurse(i, count_to);

  final = duration_cast<microseconds>(high_resolution_clock::now() - start);
  microseconds recursiontime = final;

  // Goto
  start = high_resolution_clock::now();
  i = 0;
gotoloop:
  if (i < count_to) {
    std::cout << "goto: " << i << '\n';
    this_thread::sleep_for(sleepTime);
    clearscrn();
    i++;
    goto gotoloop;
  } else {
    clearscrn();
    goto finalize;
  }

finalize:
  final = duration_cast<microseconds>(high_resolution_clock::now() - start);
  microseconds gototime = final;

  clearscrn();

  std::cout << "Final timestamps(microseconds) \\/" << '\n'
            << "While: "   << whiletime.count()     << '\n'
            << "For: "     << fortime.count()       << '\n'
            << "JMP: "     << jmptime.count()       << '\n'
            << "recurse: " << recursiontime.count() << '\n'
            << "goto: "    << gototime.count()      << '\n'
  ;

  this_thread::sleep_for(chrono::seconds(5));
  return 0;
}

int recurse(int start, const int finish) {
  if (start+1 == finish) {
    return finish;
  } else {
    cout << "recurse: " << start << '\n';
    this_thread::sleep_for(sleepTime);
    clearscrn();
    return recurse(start+1, finish);
  }
}

void clearscrn() {
  #ifdef _WIN32
  system("cls");
  #else // Unix
  system("clear");
  #endif
}