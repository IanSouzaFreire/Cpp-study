#include <iostream>
#include <string>

template <typename T> T input(const std::string& msg);

template <typename T> void input(const std::string& msg, T& var);

int main(int, char**) {
  using namespace std;

	string name = input<string>("Was' yo name? ");

  cout << "Thy new name shall be " << name + "ator" << "!" << '\n';

  return 0;
}

template <typename T>
T input(const std::string& msg) {
  T temp;
  std::cout << msg;
  std::cin >> temp;
  return temp;
}

template <typename T>
void input(const std::string& msg, T& var) {
  std::cout << msg;
  std::cin >> var;
}