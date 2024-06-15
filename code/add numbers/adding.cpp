#include <iostream>

using std::cin,
      std::cout,
      std::endl;

int main(void) {
  long double number1,
              number2,
              result;

  cout << "enter the fist number: ";
  cin >> number1;

  cout << "enter the second number: ";
  cin >> number2;

  result = number1 + number2;
  cout << "the result is: " << result << endl;
  return 0;
}