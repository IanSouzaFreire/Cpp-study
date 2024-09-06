#include <iostream>
#include <cstring>
#include <string> // Added for std::string

const struct Contains_ {} Contains;

template <typename T>
struct ContainsProxy {
public:
  ContainsProxy(const T& t) : t_(t) {}
  const T& t_;
  static bool _Contains_(const char* a, const char* b);
};

template <typename T>
ContainsProxy<T> operator<(const T& lhs, const Contains_& rhs) {
  return ContainsProxy<T>(lhs);
}

// Add this new overload
bool operator>(const ContainsProxy<const char*>& lhs, const char* rhs) {
  return ContainsProxy<const char*>::_Contains_(lhs.t_, rhs);
}

// Add this new overload
bool operator>(const ContainsProxy<std::string>& lhs, const char* rhs) {
  return ContainsProxy<std::string>::_Contains_(lhs.t_.c_str(), rhs);
}

// Replace the previous overload with this more generic version
template <size_t N>
bool operator>(const ContainsProxy<char[N]>& lhs, const char* rhs) {
  return ContainsProxy<const char*>::_Contains_(lhs.t_, rhs);
}

template <typename T>
inline bool ContainsProxy<T>::_Contains_(const char* a, const char* b) {
  return strstr(a, b) != nullptr;
}

#define contains <Contains>

int main(const int, const char**) {
  if ("hello" contains "ell") {
    std::cout << "too much work for this..." << '\n';
  }

  return 0;
}