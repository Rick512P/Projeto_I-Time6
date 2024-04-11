#include "../Arquivos-h/menu.h"

int main(){
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
        case 0:
            printf("Encerrando o programa!");
            break;
        case 1:
            //chamar função responsável pelo carregamento do arquivo
            break;
        case 2:
            //chamar função responsável por exibir a memória (Confirmar com se é a memória de dados ou de instruções)
            break;
        case 3:
            //chamar função responsável por exibir valores salvos em todos os registradores e, caso não haja valor, exibir como vazio
            break;
        case 4:
            //Imprimir todo o simulador (seja la o que for)
            break;
        case 5:
            //Chamar função responsável por salvar o arquivo .asm (com as instruções traduzidas para a linguagem intermediária Assembly)
            break;
        case 6:
            //Chamar função responsável por salvar todos os dados de memória no arquivo DATA.mem
            break;
        case 7:
            //Chamar função responsável pela execução do programa
            controller(1);
            break;
        case 8:
            //Chamar função responsável pela execução do programa passo a passo
            controller(2);
            break;
        case 9:
            //Chamar função responsável por retornar uma instrução (PC--)
            controller(3);
            break;
        default:
            break;
        }
    }while(escolha != 0);

    return 0;
}
