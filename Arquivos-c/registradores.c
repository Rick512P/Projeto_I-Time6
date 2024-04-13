#include "../Arquivos-h/registradores.h"



int Registradores (int valor, char posicao[], int opcao){ //recebe do controle qual registrador usar e o valor a ser salvo
    registradores regs;
    if(opcao == 0){
        if(strcmp(posicao, "000") == 0){ //define em qual registrador o valor sera armazenado
            
            regs.reg0 = valor;
            return regs.reg0;
        }

        else if(strcmp(posicao, "001") == 0){
            
            regs.reg1 = valor;
            return regs.reg1;
        }

        else if(strcmp(posicao, "010") == 0){
            
            regs.reg2 = valor;
            return regs.reg2;
        }

        else if(strcmp(posicao, "011") == 0){
            
            regs.reg3 = valor;
            return regs.reg3;
        }

        else if(strcmp(posicao, "100") == 0){
            
            regs.reg4 = valor;
            return regs.reg4;
        }

        else if(strcmp(posicao, "101") == 0){
            
            regs.reg5 = valor;
            return regs.reg5;
        }

        else if(strcmp(posicao, "110") == 0){
            
            regs.reg6 = valor;
            return regs.reg6;
        }

        else if(strcmp(posicao, "111") == 0){
            
            regs.reg7 = valor;
            return regs.reg7;
        }
        else
            printf("ERRO. Nenhum Registrador encontrado.");
    }
    else {
        printf("Registrador 0: %d", regs.reg0);
        printf("Registrador 1: %d", regs.reg1);
        printf("Registrador 2: %d", regs.reg2);
        printf("Registrador 3: %d", regs.reg3);
        printf("Registrador 4: %d", regs.reg4);
        printf("Registrador 5: %d", regs.reg5);
        printf("Registrador 6: %d", regs.reg6);
        printf("Registrador 7: %d", regs.reg7);
    }
        
    } 
