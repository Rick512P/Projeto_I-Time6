#include "../Arquivos-h/registradores.h"



int Registradores (int **regs, int valor, char posicao[], int opcao){ //recebe do controle qual registrador usar e o valor a ser salvo
    switch (opcao)
    {
    case 0:
        escritaRegistradores(regs, valor, posicao);
        break;
    
    case 2:
        return retornoRegs(regs, posicao);
        break;
    }
}

int retornoRegs(int **regs, char posicao[]){
        if(strcmp(posicao, "000") == 0){ //define em qual registrador o valor sera armazenado
            
            return (*regs)[0];
            
        }

        else if(strcmp(posicao, "001") == 0){
            
            return (*regs)[1];
            
        }

        else if(strcmp(posicao, "010") == 0){
            
            return (*regs)[2];
            
        }

        else if(strcmp(posicao, "011") == 0){
            
            return (*regs)[3];
            
        }

        else if(strcmp(posicao, "100") == 0){
            
            return (*regs)[4];
            
        }

        else if(strcmp(posicao, "101") == 0){
            
            return (*regs)[5];
           
        }

        else if(strcmp(posicao, "110") == 0){
            
            return (*regs)[6];
            
        }

        else if(strcmp(posicao, "111") == 0){
            
            return (*regs)[7];
            
        }
        else
            printf("ERRO. Nenhum Registrador encontrado.");
}


void escritaRegistradores(int **regs, int valor, char posicao[]){
        if(strcmp(posicao, "000") == 0){ //define em qual registrador o valor sera armazenado
            
            (*regs)[0] = valor;
            
        }

        else if(strcmp(posicao, "001") == 0){
            
            (*regs)[1] = valor;
            
        }

        else if(strcmp(posicao, "010") == 0){
            
            (*regs)[2] = valor;
            
        }

        else if(strcmp(posicao, "011") == 0){
            
            (*regs)[3] = valor;
            
        }

        else if(strcmp(posicao, "100") == 0){
            
            (*regs)[4] = valor;
            
        }

        else if(strcmp(posicao, "101") == 0){
            
            (*regs)[5] = valor;
           
        }

        else if(strcmp(posicao, "110") == 0){
            
            (*regs)[6] = valor;
            
        }

        else if(strcmp(posicao, "111") == 0){
            
            (*regs)[7] = valor;
            
        }
        else
            printf("ERRO. Nenhum Registrador encontrado.");
        printf("\nESCREVEU NOS REGISTRADORES");
}

void imprimeRegistradores(int *regs){
    for(int i = 0; i<8;i++){
            printf("Registrador %d: %d\t\t", i, regs[i]);
    }
}
