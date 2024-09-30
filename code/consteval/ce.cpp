#include <iostream>

consteval int square(int x) {
  return x * x;
}

consteval int factorial(int n) {
  return (n <= 1) ? 1 : n * factorial(n - 1);
}

consteval int fibonacci(int n) {
  return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  constexpr int sq = square(5);
  constexpr int fact = factorial(5);
  constexpr int fib = fibonacci(10);

  std::cout << "Square of 5: " << sq << "\n";
  std::cout << "Factorial of 5: " << fact << "\n";
  std::cout << "Fibonacci of 10: " << fib << "\n";

  return 0;
}