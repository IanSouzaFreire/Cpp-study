#include <iostream>

template <typename F>
auto proc(F&& f) {
  return f();
}

int main(int, char**) {

  proc([&] () {
    using namespace std;

    for (int i = 0; i < 100; i++) {
      proc([&] () {
        return 0;
      });
    }

    cout << "I love this!" << '\n';
  });

  return 0;
}