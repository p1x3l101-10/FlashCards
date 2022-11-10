#include <string.h>
#include <cstdlib>
#include <iostream>
#include "../inc/argResolver.h"

/* Note:
 * Operator Variable Assingment Key
 * 1 = Addition
 * 2 = Subtraction
 * 3 = Multiplication
 * 4 = Division
 */

/* Note:
 * VA stands for Variable Ailias
 */

void help() {
  std::cout << "Flashcards: By Scott\n\nSyntax: Flashcards <-n [value]><-c [value]><-f [value]><-a/s/m/d>\n\nArguments that need values:\n    -n [Integer]: Specify the number of flashcards\n    -c [Integer]: Specify the highest value for flashcards\n    -f [Integer]: Specify the lowest value for flashcards\n\nOperator arguments:\n    -a: Set the flashcard type to Addition\n    -s: Set the flashcard type to Subtraction\n    -m: Set the flashcard type to Multiplication\n    -d: Set the flashcard type to Division\n";
};


int argResolver(int argc, char* argv[], int* flashcardFloor, int* flashcardCeiling, int* flashcardNumber, int* flashcardOperatorVA) {
  // Import the struct with all the variables
  struct inputVariablesSet inVarSet;

  // Start a loop to find all the variables
  for (int i = 0; i < argc; i++){
    // Find out what argv is pointing to on this iteration of the loop
    if       (strcmp(argv[i], "-f") == 0) {
      inVarSet.flashcardFloorSet   = 1;
      inVarSet.flashcardCeilingSet = 0;
      inVarSet.flashcardNumberSet  = 0;
    }else if (strcmp(argv[i], "-c") == 0) {
      inVarSet.flashcardFloorSet   = 0;
      inVarSet.flashcardCeilingSet = 1;
      inVarSet.flashcardNumberSet  = 0;
    }else if (strcmp(argv[i], "-n") == 0) {
      inVarSet.flashcardFloorSet   = 0;
      inVarSet.flashcardCeilingSet = 0;
      inVarSet.flashcardNumberSet  = 1;
    }else if (strcmp(argv[i], "-h") == 0) {
      inVarSet.helpSet             = 1;
    }else if (strcmp(argv[i], "-a") == 0) {
      inVarSet.flashcardOperatorVA = 1;
    }else if (strcmp(argv[i], "-s") == 0) {
      inVarSet.flashcardOperatorVA = 2;
    }else if (strcmp(argv[i], "-m") == 0) {
      inVarSet.flashcardOperatorVA = 3;
    }else if (strcmp(argv[i], "-d") == 0) {
      inVarSet.flashcardOperatorVA = 4;
    }else if (strcmp(argv[i], "\0") == 0) {
      break;
    }else                                 {
      inVarSet.miscInt             = atoi(argv[i]);
      inVarSet.miscIntSet          = 1;
    }
    // Make value data persistant
    // Values with integers
    if (inVarSet.miscIntSet == 1) {
      // Remove the misc integer flag
      inVarSet.miscIntSet = 0;
      // Begin decoding
      if         (inVarSet.flashcardFloorSet == 1) {
        inVarSet.flashcardFloorSet   = 0;
        inVarSet.tempFloor = inVarSet.miscInt;
      }else if (inVarSet.flashcardCeilingSet == 1) {
        inVarSet.flashcardCeilingSet = 0;
        inVarSet.tempCeiling = inVarSet.miscInt;
      }else if  (inVarSet.flashcardNumberSet == 1) {
        inVarSet.flashcardNumberSet  = 0;
        inVarSet.tempNumber = inVarSet.miscInt;
      }
    }
    // Values with characters
    /* Obsoleted code, using Flashcard Operator VA directly
    if       (inVarSet.flashcardOperatorVA == 1) {
      inVarSet.tempOperator = 'a';
    }else if (inVarSet.flashcardOperatorVA == 2) {
      inVarSet.tempOperator = 's';
    }else if (inVarSet.flashcardOperatorVA == 3) {
      inVarSet.tempOperator = 'm';
    }else if (inVarSet.flashcardOperatorVA == 4) {
      inVarSet.tempOperator = 'd';
    }*/
    // Call help if the help flag was used
    if (inVarSet.helpSet == 1) {
      help();
      return -1;
    }
  }
  // Start transcribing to output
  *flashcardFloor      = inVarSet.tempFloor;
  *flashcardCeiling    = inVarSet.tempCeiling;
  *flashcardNumber     = inVarSet.tempNumber;
  *flashcardOperatorVA = inVarSet.flashcardOperatorVA;
  return 0;
}
