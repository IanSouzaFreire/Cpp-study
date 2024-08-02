#include <iostream>
#include <string>
#include <map>
#include <random>

enum class Choice { Rock, Paper, Scissors };

Choice getUserChoice();
Choice getComputerChoice(const std::map<Choice, int>& userChoices);
void updateUserChoices(std::map<Choice, int>& userChoices, Choice userChoice);
void determineWinner(Choice userChoice, Choice computerChoice);

int main() {
  std::map<Choice, int> userChoices;

  while (true) {
    Choice userChoice = getUserChoice();
    Choice computerChoice = getComputerChoice(userChoices);

    updateUserChoices(userChoices, userChoice);

    std::cout << "Computer chose: ";
    switch (computerChoice) {
      case Choice::Rock:
        std::cout << "rock" << std::endl;
        break;
      case Choice::Paper:
        std::cout << "paper" << std::endl;
        break;
      case Choice::Scissors:
        std::cout << "scissors" << std::endl;
        break;
    }

    determineWinner(userChoice, computerChoice);
  }

  return 0;
}

Choice getUserChoice() {
  std::string input;
  std::cout << '\n' << "Enter your choice (rock, paper, scissors)" << '\n'
  << "type 'exit' to quit" << '\n' << "Choose: ";
  std::cin >> input;

  if (input == "exit") {
    std::exit(0);
  }

  if (input == "rock") return Choice::Rock;
  if (input == "paper") return Choice::Paper;
  if (input == "scissors") return Choice::Scissors;

  std::cerr << "Invalid input. Please try again." << '\n' << std::endl;
  return getUserChoice();
}

Choice getComputerChoice(const std::map<Choice, int>& userChoices) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(0, 2);

  // Analyze user's past choices and make a decision
  if (!userChoices.empty()) {
    int maxCount = 0;
    Choice mostFrequentChoice;

    for (const auto& pair : userChoices) {
      if (pair.second > maxCount) {
        maxCount = pair.second;
        mostFrequentChoice = pair.first;
      }
    }

    switch (mostFrequentChoice) {
      case Choice::Rock:
        return Choice::Paper;
      case Choice::Paper:
        return Choice::Scissors;
      case Choice::Scissors:
        return Choice::Rock;
    }
  }

  return static_cast<Choice>(dis(gen));
}

void updateUserChoices(std::map<Choice, int>& userChoices, Choice userChoice) {
  ++userChoices[userChoice];
}

void determineWinner(Choice userChoice, Choice computerChoice) {
  if (userChoice == computerChoice) {
    std::cout << "It's a tie!" << '\n' << std::endl;
  } else {
    switch (userChoice) {
      case Choice::Rock:
        if (computerChoice == Choice::Scissors) {
          std::cout << "You win! Rock crushes scissors." << std::endl;
        } else {
          std::cout << "Computer wins! Paper covers rock." << std::endl;
        }
        break;
      case Choice::Paper:
        if (computerChoice == Choice::Rock) {
          std::cout << "You win! Paper covers rock." << std::endl;
        } else {
          std::cout << "Computer wins! Scissors cuts paper." << std::endl;
        }
        break;
      case Choice::Scissors:
        if (computerChoice == Choice::Paper) {
          std::cout << "You win! Scissors cuts paper." << std::endl;
        } else {
          std::cout << "Computer wins! Rock crushes scissors." << std::endl;
        }
        break;
    }
  }
}