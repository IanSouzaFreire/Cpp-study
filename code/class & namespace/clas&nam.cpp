#include <iostream>
#include <fstream>
#include <string>

namespace Handlers {
  class File {
  public:
    std::string dirPath;
    std::string fileName;
    long long size;
  };

  long long getFileBitSize(const std::string &filePath) {
    std::ifstream file(filePath, std::ios::binary | std::ios::ate);

    if (!file) {
      return -1;
    }

    long long fileSizeInBytes = file.tellg();
    file.close();

    return fileSizeInBytes * 8;
  }
}

int main() {
  Handlers::File myclass;
  myclass.dirPath = "../../";
  myclass.fileName = "README.md";
  myclass.size = Handlers::getFileBitSize(myclass.dirPath + myclass.fileName);

  std::cout << myclass.dirPath + myclass.fileName << " size in bits: " << myclass.size;
  return 0;
}