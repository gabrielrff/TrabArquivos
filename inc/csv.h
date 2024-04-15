#include "register.h"
#include "header.h"
#define NULL_INTEGER -1
#define NULL_CHAR "$"


#define MAX_LENGTH 1000







FILE* openCsvFile(FILE* csvFileName);


bool isEmpty(char* buffer);


REGISTER* readCsvFileLine(FILE* csvPointer);