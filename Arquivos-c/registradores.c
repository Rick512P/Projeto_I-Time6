#include "../Arquivos-h/registradores.h"



void Registradores (int **regs, int valor, char posicao[], int opcao){ //recebe do controle qual registrador usar e o valor a ser salvo
    
    if (opcao == 0){
        escritaRegistradores(regs, valor, posicao);
    }
    else if (opcao == 1){
        for(int i = 0; i<8;i++){
            printf("Registrador %d: %d\n", i, (*regs)[i]);
        }
        
    }
}


int escritaRegistradores(int **regs, int valor, char posicao[]){
        if(strcmp(posicao, "000") == 0){ //define em qual registrador o valor sera armazenado
            
            (*regs)[0] = valor;
            return valor;
        }

        else if(strcmp(posicao, "001") == 0){
            
            (*regs)[1] = valor;
            return valor;
        }

        else if(strcmp(posicao, "010") == 0){
            
            (*regs)[2] = valor;
            return valor;
        }

        else if(strcmp(posicao, "011") == 0){
            
            (*regs)[3] = valor;
            return valor;
        }

        else if(strcmp(posicao, "100") == 0){
            
            (*regs)[4] = valor;
            return valor;
        }

        else if(strcmp(posicao, "101") == 0){
            
            (*regs)[5] = valor;
            return valor;
        }

        else if(strcmp(posicao, "110") == 0){
            
            (*regs)[6] = valor;
            return valor;
        }

        else if(strcmp(posicao, "111") == 0){
            
            (*regs)[7] = valor;
            return valor;
        }
        else
            printf("ERRO. Nenhum Registrador encontrado.");
}
