#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct register_stc REGISTER;


REGISTER* createRegister();


void setRegisterStatus(REGISTER* register_,char status);

void setRegisterSize(REGISTER* register_,int size);

void setRegisterProx(REGISTER* register_,long int prox);

void setRegisterId(REGISTER* register_,int id);

void setRegisterAge(REGISTER* register_,int age);

void setRegisterSizeName(REGISTER* register_,int size);

void setRegisterName(REGISTER* register_,char* name);
void setRegisterSizeNac(REGISTER* register_,int size);
void setRegisterNac(REGISTER* register_,char* nac);

void setRegisterSizeClubName(REGISTER* register_,int size);
void setRegisterClubName(REGISTER* register_,char* clubName);





char getRegisterStatus(REGISTER* register_);

int getRegisterSize(REGISTER* register_);

long int getRegisterProx(REGISTER* register_);

int getRegisterId(REGISTER* register_);

int getRegisterAge(REGISTER* register_);

int getRegisterSizeName(REGISTER* register_);

char* getRegisterName(REGISTER* register_);

int getRegisterSizeNac(REGISTER* register_);

char* getRegisterNac(REGISTER* register_);


int getRegisterSizeClubName(REGISTER* register_);

char* getRegisterClubName(REGISTER* register_);


void freeRegister(REGISTER* register_);


void printRegister(REGISTER* register_);
