#include <future>

long long foo(const unsigned int& val) {
  long long R = 1;
  for (int i = 0; i <= val; i++) {
    R *= 2;
  }

  return R;
}

int main(int, char**) {
  using namespace std;
  future<long long> async_function = async(launch::async, foo, 1000000);

  long long do_something = foo(1000000);

  long long final = async_function.get();

  return 0;
}