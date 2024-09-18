#include <iostream>

// Simple constexpr function with no use other than to annoy
constexpr int func(int x) {
  if (x >= 10) {
    return x;
  }

  int R = 0;

  for (int i = 0; i < x * x; i++) {
    R += func(x - 5) + func(i);
  }

  return R;
}

int main(void) {
  // This one is calculated during the compilation
  // And so it won't execute the func, just return the value
  int a = func(35); // results in 0x23

  // Since this value is given at runtime, it runs through the function
  int b = func(std::cin.get());

  return 0;
}