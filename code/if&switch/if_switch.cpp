int main(int argc, char *argv[]) {
  int a = (const int&)argv[1];
  int b = (const int&)argv[2];
  int c = 0;

  // Bland
  if (a<b) {
    c = a + b;
  } else {
    c = 0;
  }

  // Fancier
  switch ((bool)(a<b)) {
    case 1:
    c = a + b;
    break;
    case 0:
    c = 0;
    break;
  }

  // What
  a<b ? c=a+b : c=0;

  return 0;
}
