#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>

int main() {
    Log(LogLevel::Info) << "some information";
    Log(LogLevel::Debug) << "some information";
    Log(LogLevel::Warn) << "some information";
    Log(LogLevel::Error) << "some information";
    Log(LogLevel::Info) << "some information";
    return EXIT_SUCCSESS;
}