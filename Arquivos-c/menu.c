#include <stdio.h>

#include "../Arquivos-h/menu.h"

int main(){
    int escolha;
    printf("___________________________________________ ==ATENÇÃO== ____________________________________________\n\n");
    printf("| + TODOS OS ARQUIVOS DE INSTRUÇÂO DEVEM ESTAR NA PASTA 'memoria' COM O SEGUINTE NOME E EXTENSÂO + |\n");
    printf("__________________________________________ =INSTRUCT.mem= __________________________________________");
    while(escolha != 0){
        printf("\n\n\n\n\n");
        printf("                              _____________________________________\n");
        printf("                              |1 +       Carregar memória         +|\n");
        printf("                              |2 +       Imprimir memória         +|\n");
        printf("                              |3 +    Imprimir registradores      +|\n");
        printf("                              |4 +  Imprimir todo o simulador     +|\n");
        printf("                              |5 +          Salvar .asm           +|\n");
        printf("                              |6 +          Salvar .mem           +|\n");
        printf("                              |7 +      Executa Programa (run)    +|\n");
        printf("                              |8 +     Executa instrucao (step)   +|\n");
        printf("                              |9 +    Volta uma instrucao (back)  +|\n");
        printf("                              |0 +             Sair               +|\n");
        printf("                              ______________________________________\n\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 01:
            /* code */
            break;
        
        default:
            break;
        }
    }

    return 0;
}
