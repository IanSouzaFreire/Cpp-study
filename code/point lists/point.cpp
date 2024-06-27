#include <iostream>

using std::cout;

const int buffer = 32;

int main() {
  int list[buffer];

  // Two forms of acessing lists
  for (int index=0; index<buffer; index++) {
    *(list + index) = index * 4; // Point to the desired space in memory
    cout << "list[" << index << "] = " << list[index] << '\n'; // Using list index
  }

  // When using the first method, this is valid
  *(list + buffer * 2) = 0;
//list[buffer * 2] = 0; But this is not
  
  return 0;
}