#include "./inc/csv.h"


FILE* openCsvFile(FILE* csvFileName){

    FILE* filePointer = fopen(csvFileName,"r");
    if (filePointer == NULL){//Tratar melhor os erros
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    return filePointer;
}


bool isEmpty(char* buffer){
    if (strcmp(buffer,"") == 0){
        return true;
    }
    return false;
}


REGISTER* readCsvFileLine(FILE* csvPointer,REGISTER* register_){
    
    char* line = (char*)malloc(MAX_LENGTH);
    if (!fgets(line,MAX_LENGTH,csvPointer))
        return NULL;

    char* buffer;
    buffer = NULL;
    int camp = 1;
    while ((buffer = strsep(&line,"")) != NULL){
        switch (camp)
        {
            case 1:
                setRegisterId(register_,atoi(buffer));
                break;

            case 2:
                if(isEmpty(buffer))
                    setRegisterAge(register_,NULL_INTEGER);
                else
                    setRegisterAge(register_,atoi(buffer));

                break;
            
            case 3:
                if (isEmpty(buffer)){
                    setRegisterSizeName(register_,NULL_INTEGER);
                    setRegisterName(register_,NULL_CHAR);
                }
                else{
                    setRegisterName(register_,buffer);
                    setRegisterSizeName(register_,strlen(getRegisterName));
                }
                break;

            case 4:
                if (isEmpty(buffer)){
                    setRegisterSizeNac(register_,NULL_INTEGER);
                    setRegisterNac(register_,NULL_CHAR);
                }
                else{
                    setRegisterNac(register_,buffer);
                    setRegisterSizeNac(register_,strlen(getRegisterNac));
                }
                break;

            case 5:
                if (isEmpty(buffer)){
                    setRegisterSizeClubName(register_,NULL_INTEGER);
                    setRegisterClubName(register_,NULL_CHAR);
                }
                else{
                    setRegisterClubName(register_,buffer);
                    setRegisterSizeClubName(register_,strlen(getRegisterClubName));
                }
                break;                
            
            default:
                break;
            }
        free(buffer);
    }
    


}