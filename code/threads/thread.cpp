#include <iostream>
#include <thread>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
using namespace std::filesystem;

struct SearchTask {
  string filepath;
  string tofind;
  bool stopatfirst;
  int startpos;
  int endpos;
};

void searchInFile(SearchTask task) {
  int foundmatches = 0;
  ifstream file(task.filepath);
  file.seekg(task.startpos);
  string line;
  for (int i = task.startpos; i < task.endpos; ++i) {
    getline(file, line);
    size_t found = line.find(task.tofind);
    if (found!= string::npos) {
      ++foundmatches;
      if (task.stopatfirst) {
        break;
      }
    }
  }
  cout << "Thread found " << foundmatches << " matches in file " << task.filepath << endl;
}

int main(int argc, char *argv[]) {
  if (argc!= 5) {
    cerr << "Usage: " << argv[0] << " <filepath> <tofind> <stopatfirst> <avathr>" << endl;
    return 1;
  }

  string filepath = argv[1];
  string tofind = argv[2];
  bool stp = (strcmp(argv[3], "true") == 0);
  int avathr = stoi(argv[4]);

  if (avathr <= 0) {
    avathr = 1;
  }

  // Get the number of lines in the file
  ifstream file(filepath);
  int numlines = 0;
  string line;
  while (getline(file, line)) {
    ++numlines;
  }

  // Create search tasks and divide the file into chunks for each thread
  vector<SearchTask> tasks;
  int chunksize = numlines / avathr;
  for (int i = 0; i < avathr; ++i) {
    SearchTask task;
    task.filepath = filepath;
    task.tofind = tofind;
    task.stopatfirst = stp;
    task.startpos = i * chunksize;
    task.endpos = (i == avathr - 1)? numlines : (i + 1) * chunksize;
    tasks.push_back(task);
  }

  // Create threads and execute search tasks
  vector<thread> threads;
  for (auto& task : tasks) {
    threads.emplace_back(searchInFile, task);
  }

  // Wait for all threads to finish
  for (auto& thread : threads) {
    thread.join();
  }

  return 0;
}