#include <vector>
#include <iostream>

template<class T>
class vector : public std::vector<T> {
public:
  long long count(const T& tofind) {
    long long R = 0;
    
    for (const T& curr : *this)
      if (curr == tofind) R += 1;
    
    return R;
  }
};

int main(void) {
  vector<int> vec;
  
  for (int i=0; i<100; i++) {
    if (i%3 == 0) vec.push_back(3);
    else vec.push_back(i);
  }
  
  std::cout << "vec.count(3) = " << vec.count(3) << '\n';

  return 0;
}