int rect(const register int x, const register int y) {
  return x * y;
}

int main(void) {
  // This one keeps memory like "DWORD PTR [rbp-4]"
  int a = 10;

  // This one associates the variable with the rsi memory register
  register int rsi asm("rsi") = 20;

  // They can be used in conjunction with each other
  int b = rect(a, rsi);

  return 0;
}
