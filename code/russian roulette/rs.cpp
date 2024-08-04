#include <iostream>
#include <cstring>
#include <string>
#include <random>

using namespace std;

string rollBarrel(bool atFirst);

int main(int argc, char **argv) {
  unsigned int num = 6;
  bool stp = true;

  if (argc > 1) {
    num = stoi(argv[1]);
  }

  if (argc > 2) {
    stp = (bool)stoi(argv[2]);
  }

  for (unsigned int i = 0; i < num; i++) {
    cout << "player " << (i + 1) << " was " << rollBarrel(stp) << "shot." << '\n';
  }
  
  return 0;
}

string rollBarrel(bool atFirst) {
  static bool *Wshot = new bool;
  static random_device rd;
  static mt19937 gen(rd());
  uniform_int_distribution<> dis(0, 1);

  if (Wshot == nullptr) { *Wshot = 0; }

  if (atFirst == 1 && *Wshot == 1) {
    return "not ";
  }

  int r = dis(gen);

  switch (r) {
    case 1:
      *Wshot = true;
      return "";
    case 0:
      return "not ";
  }
  
  return "";
}