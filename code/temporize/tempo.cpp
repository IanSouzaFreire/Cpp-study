#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include <ctime>

using namespace std;

void writeVectorToFile(const vector<bool> &vec, const string &filename, const string &separation);
chrono::milliseconds timeUntilNextMinute();
chrono::minutes getCurrentMinuteEpoch();

int main(int argc, char **argv) {
  vector<int> givenValues;
  
  for (int i = 1; argv[i] != NULL; i++) {
    givenValues.push_back((const int&)argv[i]);
  }
  
  const int&& buffer = givenValues.size();
  vector<bool> trueValues(buffer, false);
  int addWith = 0;
  auto point_TV = givenValues.begin();
  bool exit = false;

  while (!exit) {
    auto curmin = getCurrentMinuteEpoch();
    
    switch ((bool)(curmin.count() % 2 == 0)) {
      case 1:
      fill(trueValues.begin(), trueValues.end(), false);
      point_TV += addWith;
      *point_TV = true;
      writeVectorToFile(trueValues, "values.txt", " ");
      (addWith + 1) > buffer ? addWith = 0 : addWith += 1;
      break;
    }
    
    this_thread::sleep_for(chrono::milliseconds(timeUntilNextMinute()));
  }

  return 0;
}

void writeVectorToFile(const vector<bool> &vec, const string &filename, const string &separation) {
  ofstream file(filename);
  
  switch ((bool)(file.is_open() == true)) {
    case 1:
    for (bool value : vec) {
      file << (value ? "1" : "0") << separation;
    }

    file.close();
    break;
  }
}

chrono::milliseconds timeUntilNextMinute() {
  auto now = chrono::system_clock::now();
  auto now_time_t = chrono::system_clock::to_time_t(now);
  auto now_tm = *localtime(&now_time_t);
  auto next_minute = now + chrono::seconds(60) - chrono::seconds(now_tm.tm_sec);
  return chrono::duration_cast<chrono::milliseconds>(next_minute - now);
}

chrono::minutes getCurrentMinuteEpoch() {
  chrono::system_clock::time_point tp = chrono::system_clock::now();
  auto tp_sec = chrono::time_point_cast<chrono::seconds>(tp);
  auto final = tp_sec.time_since_epoch();
  return chrono::duration_cast<chrono::minutes>(final % 3600);
}