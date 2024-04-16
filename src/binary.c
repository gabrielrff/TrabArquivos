#include "binary.h"



FILE* openBinaryFile(char* binaryFileName){

    FILE* filePointer = fopen(binaryFileName,"wb+");
    if (filePointer == NULL){//Tratar melhor os erros
        perror("Erro ao abrir o arquivo");
        return NULL;
    }
    return filePointer;
}

FILE* openBinaryFileRead(char* binaryFileName){

    FILE* filePointer = fopen(binaryFileName,"rb+");
    if (filePointer == NULL){//Tratar melhor os erros
        perror("Erro ao abrir o arquivo");
        return NULL;
    }
    return filePointer;

}



void writeBinaryHeader(FILE* binaryPointer,HEADER* header){

    fseek(binaryPointer,0,SEEK_SET);

    char charBuffer;
    int  intBuffer;
    long int longBuffer;

    charBuffer = getHeaderStatus(header);
    fwrite(&charBuffer, sizeof(char),1,binaryPointer);

    longBuffer = getHeaderTop(header);
    fwrite(&longBuffer, sizeof(long int),1,binaryPointer);
    longBuffer = getHeaderProxByteOffset(header);
    fwrite(&longBuffer, sizeof(long int),1,binaryPointer);

    intBuffer = getHeaderNumRegArq(header);
    fwrite(&intBuffer, sizeof(int),1,binaryPointer);
    intBuffer = getHeaderNumRegRem(header);
    fwrite(&intBuffer, sizeof(int),1,binaryPointer);
}


void writeBinaryRegister(FILE* binaryFilePointer,REGISTER* register_){

    if(register_ == NULL){
        //Fazer função de erro!!!!!!!!!
    }

    char charBuffer;
    int intBuffer;
    long int longBuffer;

    charBuffer = getRegisterStatus(register_);
    fwrite(&charBuffer,sizeof(char),1,binaryFilePointer);

    intBuffer = getRegisterSize(register_);
    fwrite(&intBuffer,sizeof(int),1,binaryFilePointer);

    longBuffer = getRegisterProx(register_);
    fwrite(&longBuffer,sizeof(long int),1,binaryFilePointer);

    intBuffer = getRegisterId(register_);
    fwrite(&intBuffer,sizeof(int),1,binaryFilePointer);

    intBuffer = getRegisterAge(register_);
    fwrite(&intBuffer,sizeof(int),1,binaryFilePointer);

    intBuffer = getRegisterSizeName(register_);
    fwrite(&intBuffer,sizeof(int),1,binaryFilePointer);

    fwrite(getRegisterName(register_),sizeof(char),getRegisterSizeName(register_),binaryFilePointer);

    intBuffer = getRegisterSizeNac(register_);
    fwrite(&intBuffer,sizeof(int),1,binaryFilePointer);

    fwrite(getRegisterNac(register_),sizeof(char),getRegisterSizeNac(register_),binaryFilePointer);

    intBuffer = getRegisterSizeClubName(register_);
    fwrite(&intBuffer,sizeof(int),1,binaryFilePointer);

    fwrite(getRegisterClubName(register_),sizeof(char),getRegisterSizeClubName(register_),binaryFilePointer);

}




HEADER* readBinaryHeader(FILE* binaryPointer){

    //Implementar função de erro
    if (binaryPointer == NULL){
        /**/
    }
    fseek(binaryPointer,0,SEEK_SET);

    HEADER* header = createHeader();

    char charBuffer;
    int intBuffer;
    long int longBuffer;

    fread(&charBuffer,sizeof(char),1,binaryPointer);
    setHeaderStatus(header,charBuffer);

    fread(&longBuffer,sizeof(long int),1,binaryPointer);
    setHeaderTop(header,longBuffer);
    
    fread(&longBuffer,sizeof(long int),1,binaryPointer);
    setHeaderProxByteOffset(header,longBuffer);
    
    fread(&intBuffer,sizeof(int),1,binaryPointer);
    setHeaderNumRegArq(header,intBuffer);
    
    fread(&intBuffer,sizeof(int),1,binaryPointer);
    setHeaderNumRegRem(header,intBuffer);

    return header;
}



REGISTER* readBinaryRegister(FILE* binaryPointer){

    //Implementar função de erro
    if (binaryPointer == NULL){
        /**/
    }
    REGISTER* registerBuffer = createRegister();

    char charBuffer;
    int intBuffer;
    long int longBuffer;

    fread(&charBuffer,sizeof(char),1,binaryPointer);
    setRegisterStatus(registerBuffer,charBuffer);

    fread(&intBuffer,sizeof(int),1,binaryPointer);
    setRegisterSize(registerBuffer,intBuffer);


    fread(&longBuffer,sizeof(long int),1,binaryPointer);
    setRegisterProx(registerBuffer,longBuffer);

    fread(&intBuffer,sizeof(int),1,binaryPointer);
    setRegisterId(registerBuffer,intBuffer);

    fread(&intBuffer,sizeof(int),1,binaryPointer);
    setRegisterAge(registerBuffer,intBuffer);
//////


    fread(&intBuffer,sizeof(int),1,binaryPointer);
    setRegisterSizeName(registerBuffer,intBuffer);
    if (intBuffer != 0){
        char* nameBuffer = malloc(getRegisterSizeName(registerBuffer) + 1);
        fread(nameBuffer,1,getRegisterSizeName(registerBuffer),binaryPointer);
        setRegisterName(registerBuffer,nameBuffer);
        free(nameBuffer);
    }
 
    fread(&intBuffer,sizeof(int),1,binaryPointer);
    setRegisterSizeNac(registerBuffer,intBuffer);
    if (intBuffer != 0){
        char* nacBuffer = malloc(getRegisterSizeNac(registerBuffer) + 1);
        fread(nacBuffer,1,getRegisterSizeNac(registerBuffer),binaryPointer);
        setRegisterNac(registerBuffer,nacBuffer);
        free(nacBuffer);
    }


    fread(&intBuffer,sizeof(int),1,binaryPointer);
    setRegisterSizeClubName(registerBuffer,intBuffer);
    if (intBuffer != 0){
        char* clubBuffer = malloc(getRegisterSizeClubName(registerBuffer) + 1);
        fread(clubBuffer,1,getRegisterSizeClubName(registerBuffer),binaryPointer);
        setRegisterClubName(registerBuffer,clubBuffer);
        free(clubBuffer);

    }



    return registerBuffer;
}