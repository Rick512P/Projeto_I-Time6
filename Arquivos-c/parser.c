#include "../Arquivos-h/parser.h"


void parser(instrucao **inst, int *tamanho_linhas){
    char linha[100];
    int contador_de_linhas = 0;
    instrucao p;
    FILE *arq = fopen("../memoria/programaTestaInstrucoes.mem", "r");

    if(arq){

        //primeiro, conto quantas linhas de instruçoes terei no arquivo
        while(fgets(linha, sizeof(linha), arq) != NULL){
            contador_de_linhas++;
        }

        

        *tamanho_linhas = contador_de_linhas;

        //alocaçao de memoria que minha variavel inst terá será = ao tanto de linhas do arquivo lido
        *inst = (instrucao*)malloc(contador_de_linhas * sizeof(instrucao));

        // Reinicia o arquivo para ler desde a 1° linha
        rewind(arq);


        for (int i=0;i<contador_de_linhas;i++){
            if (fgets(linha, sizeof(linha), arq) == NULL)
                break;
            

            linha[strcspn(linha, "\r\n")] = '\0';

            // Copia a linha para a estrutura inst
            strncpy((*inst)[i].instruc, linha, 17);
            (*inst)[i].instruc[sizeof((*inst)[i].instruc) - 1] = '\0'; // certifica-se de que a string termina com null terminator

        }
        
        fclose(arq);
    }
    

    else
        printf("Erro ao abrir arquivo.");
}