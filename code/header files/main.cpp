#include <iostream>
#include "type1.h"
#include "type2.h"

int main() {
  deff::Data mydata;
  
  mydata.id = 1;
  mydata.name = "vincie";
  mydata.data[0] = "dfile.dat";
  mydata.data[1] = "b";
  
  Data2 second;
  second.path = "dfile.dat";
  *second.children = NULL;
  second.size = 4;

  return 0;
}