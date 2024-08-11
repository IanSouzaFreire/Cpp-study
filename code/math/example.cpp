#include <iostream>
#include "geometry.hpp"

int main(int, char**) {
	mmath::rect2D<long double> gold(1, 1.618);

  std::cout
    << "3 ^ 2 = " << mmath::powerof(3, 2) << '\n'
    << "10 ^ 10 = " << mmath::powerof(10, 10) << '\n'
    << "2 ^ 4.3 = " << mmath::powerof(2, 4.3) << '\n'
    << "2 ^ 2 = " << mmath::powerof(2, 2) << '\n';

	return 0;
}