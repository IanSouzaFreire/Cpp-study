#include <iostream>

extern "C" int randomInt();

int main(int, char**) {
	using namespace std;
	
	for (int i=0; i<1000; i++) {
	  cout << randomInt() % 100 << '\n';
  }

	return 0;
}

extern "C" {
#include <stdlib.h>

int randomInt() {
  srand(rand());
  return rand() % rand();
}

}