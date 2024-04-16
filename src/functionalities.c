#include "functionalities.h"





void createTable(char* csvFileName, char* binaryFileName){

    FILE* csvPointer = openCsvFile(csvFileName);
    FILE* binaryPointer = openBinaryFile(binaryFileName);

    HEADER* headerBuffer = createHeader();
    REGISTER* registerBuffer;

    char csvHeader[MAX_LENGTH];
    fgets(csvHeader,MAX_LENGTH,csvPointer);
    
    fseek(binaryPointer,24,SEEK_SET);
    registerBuffer = readCsvFileLine(csvPointer);
    while (registerBuffer != NULL){
        printRegister(registerBuffer);
        writeBinaryRegister(binaryPointer,registerBuffer);
        
        setHeaderProxByteOffset(headerBuffer,getHeaderProxByteOffset(headerBuffer) + getRegisterSize(registerBuffer));
        setHeaderNumRegArq(headerBuffer,getHeaderNumRegArq(headerBuffer) + 1);

        freeRegister(registerBuffer);
       
        registerBuffer = readCsvFileLine(csvPointer);
    }
    setHeaderStatus(headerBuffer,VALID_ARQ);
    writeBinaryHeader(binaryPointer,headerBuffer);

    free(headerBuffer);

    fclose(csvPointer);
    fclose(binaryPointer);

    binarioNaTela(binaryFileName);
}




void selectFrom(char* binaryFileName){

    FILE* binaryPointer = openBinaryFileRead(binaryFileName);

    HEADER* headerBuffer = readBinaryHeader(binaryPointer);
    int numRegArq = getHeaderNumRegArq(headerBuffer);
    
    
    REGISTER* registerBuffer = NULL;
    for (int i = 0; i < numRegArq; i++){
        registerBuffer = readBinaryRegister(binaryPointer);
        if (getRegisterStatus(registerBuffer) == VALID_REGISTER){
            printRegister(registerBuffer);
            printf("\n");
        }
        freeRegister(registerBuffer);
    }
    free(headerBuffer);
    fclose(binaryPointer);

    binarioNaTela(binaryFileName);
}





