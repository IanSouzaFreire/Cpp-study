#include <random>
#include <functional>

using namespace std;

int main() {
  const int &BUFFER = 64;
  bool list[BUFFER] = {};
  
  auto generate_bool = bind(uniform_int_distribution<>(0, 1), default_random_engine());

  for (int i=0; i<BUFFER; i++) {
    list[i] = generate_bool();
  }
  
  return 0;
}