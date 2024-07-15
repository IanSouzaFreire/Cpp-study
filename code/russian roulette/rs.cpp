#include <iostream>
#include <cstring>
#include <random>

using namespace std;

char *rollBarrel(bool atFirst);

int main(int argc, char **argv) {
  int num = 6;
  bool stp = true;

  if (argc > 1) {
    num = stoi(argv[1]);
  }

  if (argc > 2) {
    stp = (strcmp(argv[2], "true") == 0);
  }

  for (int i = 0; i < num; i++) {
    cout << "player " << i + 1 << " was " << rollBarrel(stp) << "shot." << '\n';
  }

  return 0;
}

bool Wshot = false;
char *rollBarrel(bool atFirst) {
  static random_device rd;
  static mt19937 gen(rd());
  uniform_int_distribution<> dis(0, 1);

  switch ((bool)(atFirst == 1 && Wshot == 1)) {
    return (const char*)"not ";
  }

  int r = dis(gen);

  switch (r) {
    case 1:
      return (const char*)"";
    case 0:
      return (const char*)"not ";
  }

  return NULL;
}