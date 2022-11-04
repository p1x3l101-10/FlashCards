#include "operators.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int argResolver(int argc, char* argv[],int* fopVA,int* fnum, int* fceil, int* ffloor);

int main(int argc, char* argv[]) {
  // Setup
  int arglim = 8;
  // Make sure that there are not too many arguments
  if(argc > arglim + 1){
    printf("Too many arguments supplied...\n exiting\n");
    return 1;
  }

  // Create the single-write variables
  int fnum=0;
  int fceil=0;
  int ffloor=0;
  char fop=0;
  int fopVA=0;

  // Check for argument presets
  int retv=argResolver(argc, argv, &fopVA, &fnum, &fceil, &ffloor);
  // Exit if the help function was called, or there was an error
  if (retv == 1) {
    printf("There was an error in the argument resolver");
    return 1;
  }
  if (retv == 2) {
    return 0;
  }

  // Get inputs, if they are not already set
  if (fnum == 0) {
    printf("Enter the number of flashcards you want:");
    scanf("%d", &fnum);
  } else {
    printf("Number of flashcards: %i", fnum);
  }
  printf("\n\n");
  if (fceil == 0) {
    printf("Enter the highest number for flashcards:");
    scanf("%d", &fceil);
  } else {
    printf("Highest value for flashcards: %i", fceil);
  }
  printf("\n\n");
  if (ffloor == 0) {
    printf("Enter the lowest number for flashcards:");
    scanf("%d", &ffloor);
  } else {
    printf("Lowest number for flashcards: %i", ffloor);
  }
  printf("\n\n");
  if (fopVA == 0){
    printf("Enter the operator to use for flashcards(a/s/m/d):");
    scanf(" %c", &fop);
  } else {
    // Resolve the operator, and tell the user the type of flashcards being used
    switch (fopVA) {
      case 1:
        fop='a';
        printf("Flashcard type: Addition");
        break;
      case 2:
        fop='s';
        printf("Flashcard type: Subtraction");
        break;
      case 3:
        fop='m';
        printf("Flashcard type: Multiplication");
        break;
      case 4:
        fop='d';
        printf("Flashcard type: Division");
        break;
      default:
        printf("Error with operator resolution");
        return 1;
    }
  }
  printf("\n\n");

  // Make sure that a valid operator was input
  if (fop != 'a' && fop != 's' && fop != 'm' && fop != 'd') {
    printf("Invalid input.\n");
  };

  // Find the flashcard range
  int frange = fceil - ffloor;

  // Execute the function for the requested operator
  if (fop == 'a') {
    add(fnum, frange, ffloor);
  } else if (fop == 's') {
    subt(fnum, frange, ffloor);
  } else if (fop == 'm') {
    multi(fnum, frange, ffloor);
  } else if (fop == 'd') {
    divi(fnum, frange, ffloor);
  } else {
    printf("Enter a valid operator");
    return 1;
  }
  return 0;
}
