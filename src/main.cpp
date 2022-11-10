#include <iostream>
#include <sstream>
#include <string.h>
#include "../inc/argResolver.h"
#include "../inc/operators.h"

int main(int argc, char* argv[]){
  // Make the structure useable
  struct inputVariables inVar;

  // Resolve the arguments
  inVar.argResolverRetValue = argResolver(argc, argv, &inVar.flashcardFloor, &inVar.flashcardCeiling, &inVar.flashcardNumber, &inVar.flashcardOperatorVA);
  // Make sure the argument resolver did nothing funny
  if       (inVar.argResolverRetValue < 0) {
    return 0;
  }else if (inVar.argResolverRetValue > 0) {
    std::cout << "There was an error in the Argument Resolver\n";
    return inVar.argResolverRetValue;
  }

  // Test if the variables have been changed, and if they have not, get inputs for their values
  // Flashcard Number
  if (inVar.flashcardNumber == 0) {
    std::cout << "Enter the number of Flashcards you want: ";
    std::cin >> inVar.flashcardNumber;
  }else {
    std::stringstream strFlashcardNumber;
    strFlashcardNumber << inVar.flashcardNumber;
    std::cout << "Number of Flashcards: " + strFlashcardNumber.str();
  }
  std::cout << "\n\n";
  // Flashcard Ceiling
  if (inVar.flashcardCeiling == -254) {
    std::cout << "Enter the highest value for Flashcards you want: ";
    std::cin >> inVar.flashcardCeiling;
  }else {
    std::stringstream strFlashcardCeiling;
    strFlashcardCeiling << inVar.flashcardCeiling;
    std::cout << "Highest value for Flashcards: " + strFlashcardCeiling.str();
  }
  std::cout << "\n\n";
  // Flashcard Floor
  if (inVar.flashcardFloor == -254) {
    std::cout << "Enter the lowest value for Flashcards you want: ";
    std::cin >> inVar.flashcardFloor;
  }else {
    std::stringstream strFlashcardFloor;
    strFlashcardFloor << inVar.flashcardFloor;
    std::cout << "Lowest value for Flashcards: " + strFlashcardFloor.str();
  }
  // Flashcard Operator
  std::cout << "\n\n";
  if (inVar.flashcardOperatorVA == 0) {
    std::cout << "Enter the operator to use for Flashcards(a/s/m/d): ";
    std::cin >> inVar.flashcardOperator;
  }else {
    switch (inVar.flashcardOperatorVA) {
      case 1:
        inVar.flashcardOperator = 'a';
        std::cout << "Flashcard type: Addition";
        break;
      case 2:
        inVar.flashcardOperator = 's';
        std::cout << "Flashcard type: Subtraction";
        break;
      case 3:
        inVar.flashcardOperator = 'm';
        std::cout << "Flashcard type: Multiplication";
        break;
      case 4:
        inVar.flashcardOperator = 'd';
        std::cout << "Flashcard type: Division";
        break;
      default:
        std::cout << "Error with Operator resolution.";
        return 1;
    }
  }
  std::cout << "\n\n";

  // Generate the flashcard range
  inVar.flashcardRange = inVar.flashcardCeiling - inVar.flashcardFloor + 1;

  // Run the correct operator function based on the value of char operator
  switch (inVar.flashcardOperatorVA) {
    case 1:
      add(inVar.flashcardRange, inVar.flashcardFloor, inVar.flashcardNumber);
      break;
    case 2:
      subt(inVar.flashcardRange, inVar.flashcardFloor, inVar.flashcardNumber);
      break;
    case 3:
      multi(inVar.flashcardRange, inVar.flashcardFloor, inVar.flashcardNumber);
      break;
    case 4:
      divi(inVar.flashcardRange, inVar.flashcardFloor, inVar.flashcardNumber);
      break;
    default:
      if       (inVar.flashcardOperator == 'a') {
        add(inVar.flashcardRange, inVar.flashcardFloor, inVar.flashcardNumber);
      }else if (inVar.flashcardOperator == 's') {
        subt(inVar.flashcardRange, inVar.flashcardFloor, inVar.flashcardNumber);
      }else if (inVar.flashcardOperator == 'm') {
        multi(inVar.flashcardRange, inVar.flashcardFloor, inVar.flashcardNumber);
      }else if (inVar.flashcardOperator == 'd') {
        divi(inVar.flashcardRange, inVar.flashcardFloor, inVar.flashcardNumber);
      }else {
        std::cout << "Error with Flashcard type selection";
        return 1;
      }
  }
}
