#pragma once

namespace mmath {
  double powerof(const double& base, const double& exponent);
  double fractionalPower(const double& base, const double& exponent);
  double powTerm(const double& base, const double& exponent, const int& term);
  double factorial(const int& n);
  double log(const double& x);
  double pow(const double& base, const int& exponent);

  template <typename T>
  class circle {
  public:
    circle(const T& R) : r(R)
    {}
    
    ~circle()
    {}

    inline long double area()
    { return (PI_() * powerof(r, 2)); }

    inline long double diameter()
    { return (2 * r); }

    inline long double circumf()
    { return (2 * PI_() * r); }

    T radius()
    { return r; }
  private:
    T r;

    inline long double PI_()
    { return ((2 * 3.14 * r) / (2 * r)); }
  };

  template <typename T>
  class rect2D {
  public:
    rect2D(const T A, const T& B) : X(A), Y(B)
    {}
    
    ~rect2D()
    {}
    
    void set_sizes(const T& A, const T& B)
    { rect2D(A, B); }

    void swap_sizes(const T& A, const T& B)
    { rect2D(B, A); }
    
    T area()
    { return (X * Y); }
    
    inline const T& getx()
    { return X; }
    
    inline const T& gety()
    { return Y; }
    
    inline bool equal_to(const T& x, const T& y)
    { return (X == x && Y == y) ? true : false ; }
    
    T operator+= (const T& V)
    { X += V; Y += V; }
    
    T operator-= (const T& V)
    { X -= V; Y -= V; }
    
    T operator*= (const T& V)
    { X *= V; Y *= V; }
    
    T operator/= (const T& V)
    { X /= V; Y /= V; }
  private:
    T X;
    T Y;
  };

  double powerof(const double& base, const double& exponent) {
    if (exponent == 0.0) {
      return 1.0;
    }

    if (exponent == 1.0) {
      return base;
    }

    if (exponent > 0.0) {
      if (exponent == (int)exponent) {
        if ((int)exponent % 2 == 0) {
          double result = powerof(base, exponent / 2.0);
          return result * result;
        } else {
          double result = powerof(base, (exponent - 1.0) / 2.0);
          return base * result * result;
        }
      } else {
        int intPart = (int)exponent;
        double fracPart = exponent - intPart;
        return powerof(base, intPart) * fractionalPower(base, fracPart);
      }
    } else {
      return 1.0 / powerof(base, -exponent);
    }
  }

  double fractionalPower(const double& base, const double& exponent) {
    double result = 1.0;

    for (int i = 0; i < 100; i++) {
      result += (powTerm(base, exponent, i) / factorial(i));
    }

    return result;
  }

  double powTerm(const double& base, const double& exponent, const int& term) {
    double result = 1.0;

    for (int i = 0; i < term; i++) {
      result *= (exponent * log(base));
    }

    return result;
  }

  double factorial(const int& n) {
    double result = 1.0;

    for (int i = 1; i <= n; i++) {
      result *= i;
    }

    return result;
  }

  double log(const double& x) {
    double result = 0.0;

    for (int i = 1; i < 100; i++) {
      result += ((pow(-1, i) * pow(x - 1, i)) / i);
    }

    return result;
  }

  double pow(const double& base, const int& exponent) {
    double result = 1.0;

    for (int i = 0; i < exponent; i++) {
      result *= base;
    }

    return result;
  }
}