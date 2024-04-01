#include <stdio.h>
#include <stdlib.h>
#include "./Arquivos-h/decode.h"
#include "./Arquivos-h/memoria_instruc.h"
#include "./Arquivos-h/parser.h" //inclui arquivos de cabeçalho que estao no mesmo diretorio deste arquivo .c
#include "./Arquivos-h/registradores.h"



int main(void){
    int *tamanho_linhasV;
    int contador=0, tamanho_linhas;
    type_instruc traduzido;

    instrucao *inst;
    tamanho_linhasV = &tamanho_linhas;
    parser(&inst, tamanho_linhasV); //funçao responsavel por abrir o arquvio .mem e coletar a instruçao, armazenando na variavel inst
    

    //PC PASSA O ENDEREÇO, INCREMENTANDO +1
    for(contador=0; contador<(tamanho_linhas); contador++){

        traduzido = decoder(inst, contador);
        reg(traduzido);
        
    }

    free(inst);
    return 0;
}