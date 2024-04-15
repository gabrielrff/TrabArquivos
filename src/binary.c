#include "./inc/binary.h"



FILE* openBinaryFile(char* binaryFileName){

    FILE* filePointer = fopen(binaryFileName,"rb+");
    if (filePointer == NULL){//Tratar melhor os erros
        perror("Erro ao abrir o arquivo");
        return NULL;
    }
    return filePointer;
}



void writeBinaryHeader(FILE* binaryPointer,HEADER* header){

    fseek(binaryPointer,0,SEEK_SET);

    fwrite(getHeaderStatus(header), sizeof(char),1,binaryPointer);
    fwrite(getHeaderTop(header), sizeof(long int),1,binaryPointer);
    fwrite(getHeaderProxByteOffset(header), sizeof(long int),1,binaryPointer);
    fwrite(getHeaderNumRegArq(header), sizeof(int),1,binaryPointer);
    fwrite(getHeaderNumRegRem(header), sizeof(int),1,binaryPointer);
}


void writeBinaryRegister(FILE* binaryFilePointer,REGISTER* register_){

    if(register_ == NULL){
        //Fazer função de erro!!!!!!!!!
    }


    fwrite(getRegisterStatus(register_),sizeof(char),1,binaryFilePointer);
    fwrite(getRegisterSize(register_),sizeof(int),1,binaryFilePointer);
    fwrite(getRegisterProx(register_),sizeof(long int),1,binaryFilePointer);
    fwrite(getRegisterId(register_),sizeof(int),1,binaryFilePointer);
    fwrite(getRegisterAge(register_),sizeof(int),1,binaryFilePointer);
    
    fwrite(getRegisterSizeName(register_),sizeof(int),1,binaryFilePointer);
    fwrite(getRegisterName(register_),sizeof(char),getRegisterSizeName(register_),binaryFilePointer);

    fwrite(getRegisterSizeNac(register_),sizeof(int),1,binaryFilePointer);
    fwrite(getRegisterNac(register_),sizeof(char),getRegisterSizeNac(register_),binaryFilePointer);

    fwrite(getRegisterSizeClubName(register_),sizeof(int),1,binaryFilePointer);
    fwrite(getRegisterClubName(register_),sizeof(char),getRegisterSizeClubName(register_),binaryFilePointer);

}