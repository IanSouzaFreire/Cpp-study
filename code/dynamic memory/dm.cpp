#include <memory>

template <class T>
class Mclass {
public:
    Mclass() {}
    ~Mclass() {}
};

int main(void) {
    int* a = new int(8008135);
    // To access pointer use "a =";
    // To access value use "*a =".

    // Works for classes too!
    Mclass<int>* b = new Mclass<int>();

    // Clear the memory used.
    delete b;
    delete a;
    return 0;
}