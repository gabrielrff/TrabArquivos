#include "header.h"

struct header_stc{
    char status;
    long int top;
    long int proxByteOffset;
    int numRegArq;
    int numRegRem;
};



HEADER* createHeader(){
    HEADER* header = malloc(sizeof(HEADER));

    header->status = '0';
    header->top = 0;
    header->proxByteOffset = 0;
    header->numRegArq = 0;
    header->numRegRem = 0;

    return header;
}


//Olhar melhor essa função de erro e colcoar no resto depois!!!!!!!!!!!!
void errorHeader(HEADER* header){
    if (header == NULL){
        printf("Header doesn't exists!\n");
    }
    
}


//Funções de set: Setar os parâmetros do header
void setHeaderStatus(HEADER* header,char status){
    header->status = status;
}

void setHeaderTop(HEADER* header,long int top){
    header->top = top;
}

void setHeaderProxByteOffset(HEADER* header, long int proxByteOffset){
    header->proxByteOffset = proxByteOffset;
}

void setHeaderNumRegArq(HEADER* header,int numRegArq){
    header->numRegArq = numRegArq;
}

void setHeaderNumRegRem(HEADER* header,int numRegRem){
    header->numRegRem = numRegRem;
}





//Funções de get: pegar os parâmetros do header
char getHeaderStatus(HEADER* header){
    return header->status;
}

long int getHeaderTop(HEADER* header){
    return header->top;
}

long int getHeaderProxByteOffset(HEADER* header){
    return header->proxByteOffset;
}

int getHeaderNumRegArq(HEADER* header){
    return header->numRegArq;
}

int getHeaderNumRegRem(HEADER* header){
    return header->numRegRem;
}






