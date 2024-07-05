void print(const char *msg);

int main() {
  print("Hello world!"); // Like you've never seen before ;)
  return 0;
}

void print(const char *msg) {
  unsigned int len = 0;

  while (msg[len] != '\0') {
    len++;
  }

  #if defined(WIN)
  __asm__ (
    "mov eax, 0x04000004 \n"
    "lea edx, [msg] \n"
    "int 0x2e \n"
    :
    : "g" (len), "g" (msg)
    : "%eax", "%edx"
  );
  #elif defined(UNIX)
  __asm__ (
    "movl $1, %%eax \n"
    "movl $1, %%ebx \n"
    "movl %2, %%ecx \n"
    "movl %1, %%edx \n"
    "int $0x80 \n"
    :
    : "g" (len), "g" (msg)
    : "%eax", "%ebx", "%ecx", "%edx"
  );
  #else
  #error "Unsupported platform"
  #endif
}