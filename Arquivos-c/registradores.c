#include "../Arquivos-h/registradores.h"



void Registradores (registradores *regs, int valor, char posicao[], int opcao){ //recebe do controle qual registrador usar e o valor a ser salvo
    
    if (opcao == 0){
        escritaRegistradores(regs, valor, posicao);
    }
    else if (opcao == 1){
        printf("Registrador 0: %d\n", regs.reg0);
        printf("Registrador 1: %d\n", regs.reg1);
        printf("Registrador 2: %d\n", regs.reg2);
        printf("Registrador 3: %d\n", regs.reg3);
        printf("Registrador 4: %d\n", regs.reg4);
        printf("Registrador 5: %d\n", regs.reg5);
        printf("Registrador 6: %d\n", regs.reg6);
        printf("Registrador 7: %d\n", regs.reg7);
    }
}


int escritaRegistradores(registradores *regs, char posicao[], int valor){
        if(strcmp(posicao, "000") == 0){ //define em qual registrador o valor sera armazenado
            
            (*regs).reg0 = valor;
            return valor;
        }

        else if(strcmp(posicao, "001") == 0){
            
            (*regs).reg1 = valor;
            return valor;
        }

        else if(strcmp(posicao, "010") == 0){
            
            (*regs).reg2 = valor;
            return valor;
        }

        else if(strcmp(posicao, "011") == 0){
            
            (*regs).reg3 = valor;
            return valor;
        }

        else if(strcmp(posicao, "100") == 0){
            
            (*regs).reg4 = valor;
            return valor;
        }

        else if(strcmp(posicao, "101") == 0){
            
            (*regs).reg5 = valor;
            return valor;
        }

        else if(strcmp(posicao, "110") == 0){
            
            (*regs).reg6 = valor;
            return valor;
        }

        else if(strcmp(posicao, "111") == 0){
            
            (*regs).reg7 = valor;
            return valor;
        }
        else
            printf("ERRO. Nenhum Registrador encontrado.");
}
