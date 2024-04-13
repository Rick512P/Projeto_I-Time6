#include "../Arquivos-h/menu.h"
#include "RemoveData.c"

int main(){
    removedata();
    return 0;
}

int menu(){
    int escolha;
    printf("___________________________________________ ==ATENÇÃO== ____________________________________________\n\n");
    printf("| + TODOS OS ARQUIVOS DE INSTRUÇÂO DEVEM ESTAR NA PASTA 'memoria' COM O SEGUINTE NOME E EXTENSÂO + |\n");
    printf("__________________________________________ =INSTRUCT.mem= __________________________________________");
    do{
        printf("\n\n\n\n\n");
        printf("                              _____________________________________\n");
        printf("                              |1 +       Carregar memória         +|\n");
        printf("                              |2 +       Imprimir memória         +|\n");
        printf("                              |3 +    Imprimir registradores      +|\n");
        printf("                              |4 +    Imprimir estatisticas       +|\n");
        printf("                              |5 +  Imprimir todo o simulador     +|\n");
        printf("                              |6 +          Salvar .asm           +|\n");
        printf("                              |7 +          Salvar .mem           +|\n");
        printf("                              |8 +      Executa Programa (run)    +|\n");
        printf("                              |9 +     Executa instrucao (step)   +|\n");
        printf("                              |10 +    Volta uma instrucao (back) +|\n");
        printf("                              |0 +             Sair               +|\n");
        printf("                              ______________________________________\n\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 0:
            printf("Encerrando o programa!");
            break;
        case 1: //Carregar memória
            memInstruc(0, 0);
            break;
        case 2: //Imprimir memória de instruções e memória de dados
            memInstruc(0, 1);
            //memDados(0, 0, 1); --> exemplo de print da mem de dados 
            break;
        case 3: //Imprimir registradores
            Registradores(0, "tanto-faz", 1);
            break;
        case 4: //Imprimir estatísticas como: quantas intruc, classes, etc;
            
            break;
        case 5: //imprimir todo o simulador
            
            break;
        case 6: //salvar arquivo .asm (com as instruções traduzidas para a linguagem intermediária Assembly)

            break;
        case 7: //salvar todos os dados de memória_Dados no arquivo DATA.mem
            
            break;
        case 8: //Chamar função responsável pela execução do programa
            controller(1);
            break;
        case 9: //Chamar função responsável pela execução do programa passo a passo
            controller(2);
            break;
        case 10: //Chamar função responsável por retornar uma instrução (PC--)
            controller(3);
            break;
        case 11:
            increment_PC(0, 0);
            break;
        default:
            break;
        }
    }while(escolha != 0);

    return 0;
}
