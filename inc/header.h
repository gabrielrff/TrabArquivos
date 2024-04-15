#include <stdio.h>
#include <stdlib.h>
#define UNVALID_ARQ 0
#define VALID_ARQ 1

typedef struct header_stc HEADER;




HEADER* createHeader();



//Funções de set: Setar os parâmetros do header
void setHeaderStatus(HEADER* header,char status);
void setHeaderTop(HEADER* header,long int top);
void setHeaderProxByteOffset(HEADER* header, long int proxByteOffset);
void setHeaderNumRegArq(HEADER* header,int numRegArq);
void setHeaderNumRegRem(HEADER* header,int numRegRem);


//Funções de get: pegar os parâmetros do header
char getHeaderStatus(HEADER* header);
long int getHeaderTop(HEADER* header);
long int getHeaderProxByteOffset(HEADER* header);
int getHeaderNumRegArq(HEADER* header);
int getHeaderNumRegRem(HEADER* header);
