#include <iostream>
#include <csetjmp>
#include <chrono>

using namespace std::chrono;
using namespace std;

const int count_to = 10000;

void clearscrn();

int main() {
  auto start = high_resolution_clock::now();

  int i=0;
  while (i < count_to) {
    cout << "WHILE: " << i;
    clearscrn();
    i++;
  }

  auto final = duration_cast<microseconds>(high_resolution_clock::now() - start);
  microseconds whiletime = final;

  start = high_resolution_clock::now();

  i=0;
  for (; i < count_to; i++) {
    cout << "FOR: " << i;
    clearscrn();
  }

  final = duration_cast<microseconds>(high_resolution_clock::now() - start);
  microseconds fortime = final;

  start = high_resolution_clock::now();

  i=0;
  jmp_buf loopstrt;
  switch ((bool)(i<count_to)) {
    case 0:
    break;
    case 1:
    cout << "JMP: " << i;
    clearscrn();
    i++
    longjmp(loopstrt, 1);
  }

  final = duration_cast<microseconds>(high_resolution_clock::now() - start);
  microseconds jmptime = final;

  cout << "Final times";
  cout << "While: " << whiletime;
  cout << "For: " << fortime;
  cout << "JMP: " << jmptime;
  return 0;
}

void clearscrn() {
  #ifdef _WIN32
  system("cls");
  #else
  system("clear");
  #endif
}