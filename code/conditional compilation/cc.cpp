// Conditional includes with imaginary headers
#ifdef __linux__
#include <linux/optimizations.h> // Linux-specific optimizations
#elif __sun
#include <sun/optimizations.h> // Solaris-specific optimizations
#elif __FreeBSD__
#include <freebsd/optimizations.h> // FreeBSD-specific optimizations
#elif __NetBSD__
#include <netbsd/optimizations.h> // NetBSD-specific optimizations
#elif __OpenBSD__
#include <openbsd/optimizations.h> // OpenBSD-specific optimizations
#elif __APPLE__
#include <apple/optimizations.h> // Mac OS X-specific optimizations
#elif __hpux
#include <hpux/optimizations.h> // HP-UX-specific optimizations
#elif __osf__
#include <osf/optimizations.h> // Tru64 UNIX-specific optimizations
#elif __sgi
#include <sgi/optimizations.h> // Irix-specific optimizations
#elif _AIX
#include <aix/optimizations.h> // AIX-specific optimizations
#elif _WIN32
#include <windows/optimizations.h> // Windows-specific optimizations
#else
#error Platform not supported
#endif

int foo(int x, unsigned int y) {
  // common implementation for all platforms
  int result = x + y;
#ifdef __linux__
  result *= 2;
#elif __sun
  result += 1;
#elif __FreeBSD__
  result >>= 1;
#elif __NetBSD__
  result <<= 1;
#elif __OpenBSD__
  result ^= 1;
#elif __APPLE__
  result += 2;
#elif __hpux
  result *= 3;
#elif __osf__
  result >>= 2;
#elif __sgi
  result <<= 2;
#elif _AIX
  result += 4;
#elif _WIN32
  result *= 5;
#endif
  return result;
}

int main(int, char**) {
  int* bar = new int(foo(3, 8));
  delete bar;
  return 0;
} 