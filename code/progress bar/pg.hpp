#pragma once

class pBar {
public:
  void update(double newProgress) {
    currentProgress += newProgress;
    amountOfFiller = (int)((currentProgress / neededProgress)*(double)pBarLength);
  }

  void print(std::string id, int lineNumber) {
    std::lock_guard<std::mutex> lock(mutex_);
    currUpdateVal %= pBarUpdater.length();
    std::cout << "\033[" << lineNumber << ";1H" << id << ":" << firstPartOfpBar;
    
    for (int a = 0; a < amountOfFiller; a++) {
      std::cout << pBarFiller;
    }
    
    std::cout << pBarUpdater[currUpdateVal];
    
    for (int b = 0; b < pBarLength - amountOfFiller; b++) {
      std::cout << " ";
    }
    
    std::cout << lastPartOfpBar
              << " (" << (int)(100*(currentProgress/neededProgress)) << "%)"
              << std::flush;
    
    currUpdateVal += 1;
  }
  
  std::string firstPartOfpBar = "[",
              lastPartOfpBar  = "]",
              pBarFiller      = "|",
              pBarUpdater     = "/-\\|";
private:
     int amountOfFiller,
         pBarLength    = 50,
         currUpdateVal = 0;
  
  double currentProgress = 0,
         neededProgress  = 100;
  
  static std::mutex mutex_;
};

std::mutex pBar::mutex_;