#include <stdio.h>
#include <string.h>
#include "../Arquivos-h/ULA.h"

int ULA(char opc[5], char fc[4]){
    if (strcmp(opc, "0000") == 0 ) {
        if (strcmp(fc, "000") == 0 ){
            //printf("add");
        }
        else if (strcmp(fc, "010") == 0 ){
            //printf("sub");
        }
        else if (strcmp(fc, "100") == 0 ){
            //printf("and");
        }
        else if (strcmp(fc, "101") == 0 ){
            //printf("or");
        }
    }
    else if(strcmp(opc,"0100")){
        //printf("addi");
    }
    else if(strcmp(opc,"1011")){
        //printf("lw");
    }
    else if(strcmp(opc,"1111")){
        //printf("sw");
    }
    else if(strcmp(opc,"1000")){
        //printf("beq");
    }
    else if(strcmp(opc,"0010")){
        //printf("j");
    }
    else{
        printf("OPCODE ERROR!");
    }
}