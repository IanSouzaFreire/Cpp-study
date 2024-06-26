#include <iostream>

using std::cout;

namespace dect {
  bool isrvalue(int &value) {
    return false;
  }
  
  bool isrvalue(int &&value) {
    return true;
  }
}

namespace receive {
  int onlyR(int &reference) {
    return reference;
  }
  
  int onlyL(int &&reference) {
    return reference;
  }
  
  int bothTypes(const int &value) {
    return value;
  }
}

int &changeValue() {
  static int storage = 7;
  return storage;
}

int main() {
	int var = 10;
	
	cout << "is \'var\' a rvalue? : "
	<< dect::isrvalue(var) << '\n';
	
	cout << "is \'10\' a rvalue? : "
	<< dect::isrvalue(10) << '\n';
	
	cout << "\ntesting functions...";
  receive::onlyR(var);
  receive::onlyL(10);
  receive::bothTypes(var);
  receive::bothTypes(10);
  cout << " done!\n" << '\n';
	
	cout << "changeValue() = " << changeValue() << '\n';
	changeValue() = 13;
	cout << "chaged changeValue() = " << changeValue() << '\n';
	return 0;
}