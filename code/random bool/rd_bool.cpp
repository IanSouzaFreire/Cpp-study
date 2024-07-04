#include <random>
#include <functional>

using namespace std;

int main() {
  const int &BUFFER = 64;
  auto generate_bool = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
  bool list[BUFFER] = {};

  for (int i=0; i<BUFFER; i++) {
    list[i] = generate_bool();
  }
  
  return 0;
}