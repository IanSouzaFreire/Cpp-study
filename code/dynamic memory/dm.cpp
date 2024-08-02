#include <iostream>
#include <memory>

template <typename T>
struct Mstruc {
public:
    Mstruc() {}
    ~Mstruc() {}
};

template <class T>
class Mclass {
public:
    Mclass() {}
    ~Mclass() {}
};

int main(void) {
    int* a = new int(8008135);
    // To access pointer use "a";
    // To access value use "*a".

    std::cout <<  "a = " <<  a << '\n'
              << "*a = " << *a << '\n';

    // Works for other types of data too!
    Mclass<int>* b = new Mclass<int>();
    Mstruc<long double>* c = new Mstruc<long double>();

    // Clear the memory used.
    delete a, b, c;
    return 0;
}