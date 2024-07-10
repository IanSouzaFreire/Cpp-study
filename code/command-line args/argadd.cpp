#include <iostream>

using std::cout,
      std::endl;

int main(int argc, char *argv[]) {
  cout << "inputs given:";

  long double result = 0; 
  for (int i=1; argv[i]!=NULL; i++) {
    result = result + ((long double) argv[i])
    cout << " " << argv[i];
  }

  cout << ";\nresult: " << result << endl;  
  return 0;
}