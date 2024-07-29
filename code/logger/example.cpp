#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>

int main() {
  Log(LogLevel::Debug) << "started.";
  Log(LogLevel::Info) << "running.";
  Log(LogLevel::Warn) << "I'm having a headache.";
  Log(LogLevel::Unknown) << "IDK.";
  Log(LogLevel::Error) << "my IDE is malconfigured.";
  return EXIT_SUCCSESS;
}