/*********VALUES**********
* -n <flashcard number>  *
* -c <flashcard ceiling> *
* -f <flashcard floor>   *
*                        *
********OPERATORS*********
* -a <addition>          *
* -s <subtraction>       *
* -m <multiplication>    *
* -d <division>          *
*                        *
*************************/

/**OPERATOR VALUE ALIASES***
* Addition = 1             *
* Subtraction = 2          *
* Multiplication = 3       *
* Division = 4             *
***************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void helpFunct(){
  printf("Flashcards: By Scott\n\nSyntax: Flashcards <-n [value]><-c [value]><-f [value]><-a/s/m/d>\n\nArguments that need values:\n    -n [Integer]: Specify the number of flashcards\n    -c [Integer]: Specify the highest value for flashcards\n    -f [Integer]: Specify the lowest value for flashcards\n\nOperator arguments:\n    -a: Set the flashcard type to Addition\n    -s: Set the flashcard type to Subtraction\n    -m: Set the flashcard type to Multiplication\n    -d: Set the flashcard type to Division\n");
};

int argResolver(int argc, char* argv[], int* fopVA, int* fnum, int* fceil, int* ffloor){
  // Identify the arguments
  // Set up the variables
  int fnumSet=0;
  int fceilSet=0;
  int ffloorSet=0;
  int miscIntSet=0;
  int miscInt=0;
  int helpSet=0;
  for (int i = 0; i < argc; i++){
    // Get raw data
    if       (strcmp(argv[i], "-n") == 0) {
      fnumSet=1;
      fceilSet=0;
      ffloorSet=0;
    }else if (strcmp(argv[i], "-c") == 0) {
      fnumSet=0;
      fceilSet=1;
      ffloorSet=0;
    }else if (strcmp(argv[i], "-f") == 0) {
      fnumSet=0;
      fceilSet=0;
      ffloorSet=1;
    }else if (strcmp(argv[i], "-h") == 0) {
      helpSet=1;
    }else if (strcmp(argv[i], "-a") == 0) {
      *fopVA=1;
    }else if (strcmp(argv[i], "-s") == 0) {
      *fopVA=2;
    }else if (strcmp(argv[i], "-m") == 0) {
      *fopVA=3;
    }else if (strcmp(argv[i], "-d") == 0) {
      *fopVA=4;
    }else if (strcmp(argv[i], "\0") == 0) {
      break;
    }else                                 {
      miscInt=atoi(argv[i]);
      miscIntSet=1;
    }
    // Make value data persistant
    
    if (miscIntSet == 1) {
      miscIntSet=0;
      // Figure out what needs to be set and set it
      if (fnumSet == 1) {
        fnumSet=0;
        *fnum=miscInt;
      } else if (fceilSet == 1) {
        fceilSet=0;
        *fceil=miscInt;
      } else if (ffloorSet == 1) {
        ffloorSet=0;
        *ffloor=miscInt;
      }
    }

    // End if the help function was called 
    if (helpSet != 0) {
      helpFunct();
      return 2;
    }
  }
  // Done
  return 0;
}
