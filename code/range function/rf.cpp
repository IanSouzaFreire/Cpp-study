#include <iostream>
#include <vector>

#define in :

std::vector<int> range(const int& given);

int main(int, char**) {
	using namespace std;
	
	for (const int& i in range(100)) {
	  cout << i << '\n';
	}
	
	return 0;
}

std::vector<int> range(const int& given) {
  std::vector<int> R;
  
  for (int i = 0; i < given; i++) {
    R.push_back(i);
  }
  
  return R;
}