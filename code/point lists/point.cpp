#include <iostream>

using std::cout;

template<class T>
void fillpt(T* arr, const T& val) {
  for (int i=0; *(arr+i) != '\0'; i++) {
    *(arr+i) = val;
  }
}

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
  
  // Because of it, it's possible to use pointers instead of arrays 
  int* arr;
  *(arr+buffer) = '\0'; // Declare end of array
// ~~~~~~~~~~~^ this line is equivalent to the '[]' in a list declaration
  
  fillpt<int>(arr, 0);
  fillpt<int>(list, 0);
  // 'ray' and 'arr' are equivalents
  return 0;
}