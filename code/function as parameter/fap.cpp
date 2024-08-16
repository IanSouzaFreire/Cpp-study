#include <iostream>

int foo(int (*f)(int), int);
int bar(int);

int main(int, char**) {
  using namespace std;

  cout << "result of foo(bar, 10) = " << foo(bar, 10) << '\n';

  return 0;
}

int foo(int (*f)(int), int t) {
  int r = 1;

  for (int i=0; i < t; i++) {
    r += f(r);
  }

  return r;
}

int bar(int g) {
  static int r = 0;
  
  r += (r + g) * 2;

  return r;
}