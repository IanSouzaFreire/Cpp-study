#include <iostream>

template < typename T = int > bool isEven( T a ) { return (a % 2 == 0) ? true : false ; }
//         ~~~^~~~~
// My favorite C++ feature!

#define printbool( Type, arg ) ( isEven< Type >( arg ) ? "but of course!" : "not a damn chance" )

int main( void ) {
    std::cout << "is 2 even? " << printbool(int, 2) << '\n';
    std::cout << "is 9 even? " << printbool(int, 9) << '\n';
    return 0;
}