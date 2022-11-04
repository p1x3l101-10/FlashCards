#include "loopvars.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void divi(int fnum, int frange, int ffloor) {
  struct loopvars lv;
  for (int i = 0; i < fnum; i++) {
    // Generate random numbers
    srand(time(NULL));
    lv.ans  = rand() % frange + ffloor;
    lv.num2 = rand() % frange + ffloor;
    lv.num1 = lv.ans * lv.num2;

    // Prompt user for answer
    printf("%d / %d = ", lv.num1, lv.num2);
    scanf("%d", &lv.uans);
    printf("\n");

    // Check user answer
    if (lv.uans == lv.ans) {
      printf("Correct!");
    } else {
      printf("Incorrect... The answer was %d", lv.ans);
    };

    // Add a blank line
    printf("\n\n");
  };
};
