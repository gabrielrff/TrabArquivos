#include "register.h"
#include "header.h"

#define VALID_REGISTER '0'
#define UNVALIDE_REGISTER '1'





FILE* openBinaryFile(char* binaryFileName);
FILE* openBinaryFileRead(char* binaryFileName);


void writeBinaryHeader(FILE* binaryPointer,HEADER* header);


void writeBinaryRegister(FILE* binaryFilePointer,REGISTER* register_);



HEADER* readBinaryHeader(FILE* binaryPointer);

REGISTER* readBinaryRegister(FILE* binaryPointer);
