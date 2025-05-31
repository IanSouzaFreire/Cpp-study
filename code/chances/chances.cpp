#include <iostream>
#include <cstdlib>

const double PI = 3.14159;
const double tolerance = 0.6;
const double btn = 165.609; // magic(better) number for comparison
const int max_loss = 10;

double powerof(const double& v, const int& n) noexcept {
  double res = 1;

  for (int i=0; i < n; i++) {
    res *= v;
  }

  return res;
}

int fact(const int n) {
  int f = 1;

  for (int i=1; i<=n; ++i) {
    f *= i;
  }

  return f;
}

// is better than magic number
// a modulus for a double comparing to the magic number
double ibtm(const double& n) noexcept {
  double r = n;

  while (r > btn) {
    r -= btn;
  }

  return r;
}

double sin(const double& angle) noexcept {
  const double rad = (angle * PI) / 180;

  auto sinOp = [] (const double& a, const int& n) {
    return powerof(a, n) / fact(n);
  };

  return rad - sinOp(rad, 3) + sinOp(rad, 5) - sinOp(rad, 7);
}

// the higher 'c' is, the lesser chance to win
// try "sin(x)^(2^y) on a graphical calculator"
double chances(const double& x, const int& c) noexcept {
  return powerof(sin(x), powerof(2, c));
}

inline bool check_tolerance(const double& val) noexcept {
  return val > tolerance;
}

int main(void) {
  std::cout << "press Ctrl+C to quit!\n\n";

  int loss_streak = 0;

  auto reset_ls = [](int& ls){ ls=0; return "passed!"; };

  while (true) {
    const double gen = ibtm((double)std::rand());
    std::cout << "generated number is: " << gen << '\n';

    const double gr = chances(gen, 4);
    std::cout << "final value is: " << gr << '\n';

    const bool passed = check_tolerance(gr);
    if (!passed) { loss_streak += 1; }

    std::cout << "You have " << (passed || loss_streak >= max_loss ? reset_ls(loss_streak) : "not passed...") << "\n\n";

    std::cin.get(); // Wait
  }

  return 0;
}