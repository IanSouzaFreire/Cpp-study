#include <iostream>
#include <string>
#include <vector>

namespace text {

namespace style {
const char* defaul    = "0";
const char* bold      = "1";
const char* dim       = "2";
const char* italic    = "3";
const char* underline = "4";
const char* Sblink    = "5";
const char* Rblink    = "6";
}

std::string RGB(const unsigned int R=255, const unsigned int G=255,
const unsigned int B=255, const unsigned int typ=38, const unsigned int tc=2)
{
  std::string res = "\x1b[";
  res += typ;
  res += ";";
  res += tc;
  res += ";";
  res += R;
  res += ";";
  res += G;
  res += ";";
  res += B;
  return res + "m";
}

}

int main(int, char**) {
  return 0;
}