#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>

#include "logging.hpp"

int main() {
  Log(LogLevel::Debug) << "started.";
  Log(LogLevel::Info) << "running.";
  Log(LogLevel::Warn) << "I'm having a headache.";
  Log(LogLevel::Unknown) << "IDK.";
  Log(LogLevel::Error) << "my IDE is acting weird.";
  return 0;
}