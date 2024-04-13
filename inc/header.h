#include <stdio.h>
#include <stdlib.h>


typedef struct header_stc HEADER;




//Funções de set: Setar os parâmetros do header
void setHeaderStatus(HEADER* header,char status);
void setHeaderTop(HEADER* header,long int top);
void setHeaderProxByteOffset(HEADER* header, long int proxByteOffset);
void setHeaderNumRegArq(HEADER* header,int numRegArq);
void setHeaderNumRegRem(HEADER* header,int numRegRem);


//Funções de get: pegar os parâmetros do header
char getHeaderStatus(HEADER* header);
void getHeaderTop(HEADER* header);
void getHeaderProxByteOffset(HEADER* header);
void getHeaderNumRegArq(HEADER* header);
void getHeaderNumRegRem(HEADER* header);
