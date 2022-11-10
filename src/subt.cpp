#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "../inc/loopVariables.h"

void subt(int flashcardRange, int flashcardFloor, int flashcardNumber) {
  // Import the variables we will be using
  struct loopVariables lv;

  // Generate a seed
  srand(time(NULL));

  //Start a loop that will last for however long flashcardNumber dictates
  for (int i = 0; i < flashcardNumber; i++) {
    // Generate random numbers
    lv.num1 = rand() % flashcardRange + flashcardFloor;
    lv.num2 = rand() % flashcardRange + flashcardFloor;
    lv.ans = lv.num1 - lv.num2;
    
    // Copy the numbers into strings
    std::stringstream strNum1;
    std::stringstream strNum2;
    std::stringstream strAns;
    strNum1 << lv.num1;
    strNum2 << lv.num2;
    strAns << lv.ans;
    
    // Prompt user for answer
    std::cout << strNum1.str() + " - " + strNum2.str() + " = ";
    std::cin >> lv.uans;
    std::cout << "\n";

    // Check user answer
    if (lv.ans == lv.uans) {
      std::cout << "Correct!";
    }else {
      std::cout << "Incorrect, the answer was " + strAns.str();
    }

    // Add a blank line
    std::cout << "\n\n";
  }
}
