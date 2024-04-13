#include "../Arquivos-h/decode.h"
#include "../Arquivos-h/memoria_instruc.h"
#include "../Arquivos-h/parser.h" //inclui arquivos de cabeçalho que estao no mesmo diretorio deste arquivo .c
#include "../Arquivos-h/registradores.h"
#include "../Arquivos-h/ULA.h"

type_instruc memInstruc(int contador, int opcao){
    int *tamanho_linhasP;
    int tamanho_linhas;
    instrucao *inst; //RESPONSAVEL POR COLETAR  A INSTRUÇÃO

    type_instruc *traduzido; //DECOMPOE A INSTRUÇÃO EM OPCODE, RS, RT, RD, FUNCT, IMM OU ADDR

    
    tamanho_linhasV = &tamanho_linhas;
    if (opcao == 0) {
        parser(&inst, tamanho_linhasP); //funçao responsavel por abrir o arquvio .mem e coletar a instruçao, armazenando na variavel inst
    //O INST TERÁ A INSTRUÇÃO E TAMANHO_LINHAS O TANTO DE INSTRUÇÕES QUE PRECISARÁ SEREM EXECUTADAS
    }

    else if (opcao == 1){
        for (int i=0; i<tamanho_linhas;i++){
            printf("%s", inst[i]);
        }
    }

    else {
        traduzido = (type_instruc*)malloc(tamanho_linhas * sizeof(type_instruc));


        //PC PASSA O ENDEREÇO, INCREMENTANDO +1
        for(contador=0; contador<(tamanho_linhas); contador++){

            traduzido[contador] = decoder(inst, contador); //DECODER IRA DECOMPOR A INSTRUÇÃO NA POSIÇÃO [CONTADOR] NA
        //MEMÓRIA E ARMAZENARÁ NA VARIAVEL TRADUZIDO

            printf("%s\n", traduzido[contador].opcode); //DEBUG

            return *traduzido; //retorna para o controller
            
        }
            
        free(traduzido); //LIMPA A MEMORIA
        free(inst);
    

    }
}
    

