#include "./inc/functionalities.h"



int main(){


    char* input = malloc(MAX_LENGTH);
    fgets(input,MAX_LENGTH,stdin);
   
    char* functionality = strsep(&input," ");

    switch(atoi(functionality)){
        
        case 1:{

            char* csvFileName = strsep(&input," ");
            char* binaryFileName = strsep(&input," ");

            createTable(csvFileName,binaryFileName);

            break;
        }
        case 2:{
            char* binaryFileName = strsep(&input," ");
            
            selectFrom(binaryFileName);
            break;
        }



        default:
            break;
    }
    free(input);




    return 0;
}