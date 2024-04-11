#include "../Arquivos-h/decode.h"
#include "../Arquivos-h/memoria_instruc.h"
#include "../Arquivos-h/parser.h" //inclui arquivos de cabeçalho que estao no mesmo diretorio deste arquivo .c
#include "../Arquivos-h/registradores.h"
#include "../Arquivos-h/ULA.h"

int memInstruc(void){
    int *tamanho_linhasV;
    int contador=0, tamanho_linhas;
    type_instruc *traduzido;

    instrucao *inst;
    tamanho_linhasV = &tamanho_linhas;
    parser(&inst, tamanho_linhasV); //funçao responsavel por abrir o arquvio .mem e coletar a instruçao, armazenando na variavel inst
    
    traduzido = (type_instruc*)malloc(tamanho_linhas * sizeof(type_instruc));

    //PC PASSA O ENDEREÇO, INCREMENTANDO +1
    for(contador=0; contador<(tamanho_linhas); contador++){

        traduzido[contador] = decoder(inst, contador);
        printf("%s\n", traduzido[contador].opcode);
        ULA(traduzido, contador);
        
    }
        
    free(traduzido);
    free(inst);
    
    return 0;
}