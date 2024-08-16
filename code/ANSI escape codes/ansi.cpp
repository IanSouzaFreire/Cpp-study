#include <iostream>
#include <string>
#include <vector>

namespace text {

namespace style {
std::string defaul    = "0";
std::string bold      = "1";
std::string dim       = "2";
std::string italic    = "3";
std::string underline = "4";
std::string Sblink    = "5";
std::string Rblink    = "6";
}

namespace color {
std::string defaul  = "39";
std::string black   = "30";
std::string red     = "31";
std::string green   = "32";
std::string yellow  = "33";
std::string blue    = "34";
std::string magenta = "35";
std::string cyan    = "36";
std::string white   = "37";
std::string bright_black   = "90";
std::string bright_red     = "91";
std::string bright_green   = "92";
std::string bright_yellow  = "93";
std::string bright_blue    = "94";
std::string bright_magenta = "95";
std::string bright_cyan    = "96";
std::string bright_white   = "97";
}

std::string set_txt(const std::string& fg="39", const std::string& bg="39", const std::vector<std::string>& styles={"0"}) {
  std::string R = "\x1b[";
  
  if (&styles != nullptr) {
    for (const auto& style : styles) {
      R += style + ";";
    }
  }

  R += std::to_string(stoi(bg) + 10) + ";" + fg + "m";

  return R;
}

}

int main(int, char**) {
  namespace col = text::color;

  std::cout
  << text::set_txt(col::bright_green)  << "b"
  << text::set_txt(col::bright_yellow) << "r"
  << text::set_txt(col::yellow)        << "a"
  << text::set_txt(col::blue)          << "s"
  << text::set_txt(col::yellow)        << "i"
  << text::set_txt(col::bright_yellow) << "l"
  << text::set_txt(col::bright_green)  << "!"
  << '\n'; // "brasil!\n"

  return 0;
}