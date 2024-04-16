#include "register.h"



struct register_stc{
    char removed;
    int sizeRegister;
    long int prox;

    int id;
    int age;

    int sizeName;
    char* name;

    int sizeNac;
    char* nac;

    int sizeClubName;
    char* clubName;
};


//Trabalhar na função de erro aqui tb!!!!!!!!!!
void error(){

}




REGISTER* createRegister(){
    REGISTER* register_ = malloc(sizeof(REGISTER));

    register_->removed = '0';
    register_->sizeRegister = 0;
    register_->prox = 0;
    register_->id = 0;
    register_->age = 0;
    register_->sizeName = 0;
    register_->name = NULL;
    register_->sizeNac = 0;
    register_->nac = NULL;
    register_->sizeClubName = 0;
    register_->clubName = NULL;

    return register_;
}



void setRegisterStatus(REGISTER* register_,char status){
    register_->removed = status;
}

void setRegisterSize(REGISTER* register_,int size){
    register_->sizeRegister = size;
}

void setRegisterProx(REGISTER* register_,long int prox){
    register_->prox = prox;
}

void setRegisterId(REGISTER* register_,int id){
    register_->id = id;
}

void setRegisterAge(REGISTER* register_,int age){
    register_->age = age;
}

void setRegisterSizeName(REGISTER* register_,int size){
    register_->sizeName = size;
}

void setRegisterName(REGISTER* register_,char* name){
    //register_->name = malloc(sizeof(register_->sizeName + 1));
    register_->name = strdup(name);

    //free(name);
}

void setRegisterSizeNac(REGISTER* register_,int size){
    register_->sizeNac = size;
}

void setRegisterNac(REGISTER* register_,char* nac){
    //register_->nac = malloc(sizeof(register_->sizeNac + 1));
    register_->nac = strdup(nac);

    //free(nac);
}


void setRegisterSizeClubName(REGISTER* register_,int size){
    register_->sizeClubName = size;
}

void setRegisterClubName(REGISTER* register_,char* clubName){
    //register_->clubName = malloc(sizeof(register_->sizeClubName + 1));
    register_->clubName = strdup(clubName);

    //free(clubName);
}









char getRegisterStatus(REGISTER* register_){
    return register_->removed;
}

int getRegisterSize(REGISTER* register_){
    return register_->sizeRegister;
}

long int getRegisterProx(REGISTER* register_){
    return register_->prox;
}

int getRegisterId(REGISTER* register_){
    return register_->id;
}

int getRegisterAge(REGISTER* register_){
    return register_->age;
}

int getRegisterSizeName(REGISTER* register_){
    return register_->sizeName;
}

char* getRegisterName(REGISTER* register_){
    return register_->name;
}

int getRegisterSizeNac(REGISTER* register_){
    return register_->sizeNac;
}

char* getRegisterNac(REGISTER* register_){
    return register_->nac;
}


int getRegisterSizeClubName(REGISTER* register_){
    return register_->sizeClubName;
}

char* getRegisterClubName(REGISTER* register_){
    return register_->clubName;
}





void freeRegister(REGISTER* register_){
    free(register_->name);
    free(register_->nac);
    free(register_->clubName);

    free(register_);
}




void printRegister(REGISTER* register_){

    //printf("%d\n",register_->id);

    printf("Nome do Jogador: ");
    if ((register_->sizeName != 0) && (register_->name[0] != '$'))
        printf("%s\n",register_->name);
    else
        printf("SEM DADO\n");

    printf("Nacionalidade do Jogador: ");    
    if ((register_->sizeNac != 0) && (register_->nac[0] != '$'))
        printf("%s\n",register_->nac);
    else
        printf("SEM DADO\n");        

    printf("Clube do Jogador: ");
    if ((register_->sizeClubName != 0) && (register_->clubName[0] != '$'))
        printf("%s\n",register_->clubName);
    else
        printf("SEM DADO\n");  


}