#include "../Arquivos-h/registradores.h"



int retornoRegs(int **regs, char posicao[]){
    int indice;
        indice = bin_to_decimal(posicao);
        printf("Indice %d\n", indice);
        if(indice >= 8 || indice<0){
            printf("ERRO. Nenhum Registrador encontrado.");
            return -1;
        }
        return (*regs)[indice];
}

int escritaRegistradores(int **regs, int valor, char posicao[]){
       int indice;
        indice = bin_to_decimal(posicao);
        if(indice >= 8){
            printf("ERRO. Nenhum Registrador encontrado.");
            return -1;
        }
            
        (*regs)[indice] = valor;

            
}

void imprimeRegistradores(int *regs){
    printf("\n");
    for(int i = 0; i<8;i++){
            printf("Registrador $%d: %d\t\t", i, regs[i]);
    }
    printf("\n");
}



