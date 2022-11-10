#ifndef ARG_RESOLVER_H
#define ARG_RESOLVER_H

struct inputVariables{
  int  flashcardFloor      = -254;
  int  flashcardCeiling    = -254;
  // I dont know why, but if argResolver does not do anything with this, then it will be zero, so it is now zero.
  int  flashcardNumber     = 0;
  char flashcardOperator   = 'n';
  int  flashcardOperatorVA = 0;
  int  flashcardRange      = 0;
  int  argResolverRetValue = 1;
};

struct inputVariablesSet {
  int  flashcardFloorSet   = 0;
  int  flashcardCeilingSet = 0;
  int  flashcardNumberSet  = 0;
  int  flashcardOperatorVA = 0;
  int  helpSet             = 0;
  int  miscIntSet          = 0;
  int  miscInt             = 0;
  int  tempFloor           = -254;
  int  tempCeiling         = -254;
  int  tempNumber          = 0;
  char tempOperator        = 'n';
};

int argResolver(int argc, char* argv[], int* flashcardFloor, int* flashcardCeiling, int* flashcardNumber, int* flashcardOperatorVA);

#endif //!ARG_RESOLVER_H
