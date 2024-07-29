#pragma once

enum class LogLevel {
  Debug,
  Info,
  Warn,
  Unknown,
  Error
};

class Log {
public:
  Log(LogLevel level = LogLevel::Error, std::string filePath = "") : level_(level), filePath_(filePath) {
    if (filePath_ == "") {
      output_ = &std::cout;
    } else {
      file_.open(filePath_);
      output_ = &file_;
    }
    
    switch (level_) {
      case LogLevel::Debug:   levelstr = "[ Debug ]\t";   break;
      case LogLevel::Info:  levelstr = "[ Info ]\t";  break;
      case LogLevel::Warn:  levelstr = "[ Warn ]\t";  break;
      case LogLevel::Unknown: levelstr = "[ Unknown ]\t"; break;
      case LogLevel::Error:   levelstr = "[ Error ]\t";   break;
    }

    std::time_t now = std::time(nullptr);
    std::tm* ltm = std::localtime(&now);
    std::stringstream ss;

    ss << "[ " << ltm->tm_mday << "/" << ltm->tm_mon + 1 << "/" << ltm->tm_year + 1900 << " ] "
       << "[ " << ltm->tm_hour << ":" << ltm->tm_min   << ":" << ltm->tm_sec     << " ] ";
    
    *output_ << ss.str() << levelstr;
  }

  ~Log() {
    *output_ << '\n';
    if (filePath_ != "") {
      file_.close();
    }
  }

  template <typename U>
  Log& operator<<(U value) {
    *output_ << value;
    return *this;
  }

private:
  LogLevel level_;
  std::string levelstr;
  std::string filePath_;
  std::ofstream file_;
  std::ostream* output_;
};