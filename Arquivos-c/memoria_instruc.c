#include "../Arquivos-h/memoria_instruc.h"


type_instruc* memInstruc(int contador, int opcao, instrucao **memoriaInst, int *tamLinhas){
    type_instruc *traduzido; //DECOMPOE A INSTRUÇÃO EM OPCODE, RS, RT, RD, FUNCT, IMM OU ADDR
    switch(opcao){
        case 0: //CASO 0: DECOMPOE AS INTRUÇOES
            traduzido = (type_instruc*)malloc((*tamLinhas) * sizeof(type_instruc));
            A = (Assembly*) malloc((*tamLinhas) * sizeof(Assembly));
            if (traduzido == NULL) {
                fprintf(stderr, "Falha ao alocar memória para instruções traduzidas.\n");
                return NULL;
            }
            //PC PASSA O ENDEREÇO, INCREMENTANDO +1
            for(contador=0; contador<(*tamLinhas); contador++){

                traduzido[contador] = decoder(memoriaInst, contador); //DECODER IRA DECOMPOR A INSTRUÇÃO NA POSIÇÃO [CONTADOR] NA
            //MEMÓRIA E ARMAZENARÁ NA VARIAVEL TRADUZIDO
  
            }
            return traduzido; //retorna para o controller
            break;

            case 1: //CASO 1: LIBERA MEMORIA DO PONTEIRO TRADUZIDO
                free(traduzido);
                break;
    }

}

void imprimeMemInstruc(instrucao *memoriaInst, int tamLinhas){
    for (int i=0; i<tamLinhas;i++){
                printf("Instrucao %d: %s\n", i+1, memoriaInst[i].instruc);
            }
}

void imprimeEstatisticas(instrucao *memoriaInst, int tamLinhas){
    if (memoriaInst == NULL) {
                fprintf(stderr, "Falha ao obter instruções.\n");
            }
    int r=0, i=0, j=0;
    for(int y=0;y<tamLinhas;y++){
        if (strncmp(memoriaInst[y].instruc, "0000", 4) == 0){ //compara os 4 primeiros numeros de memoriaInst com "0000"
            r++;
        }
        else if (strncmp(memoriaInst[y].instruc, "0100", 4) == 0 || strncmp(memoriaInst[y].instruc, "1011", 4) == 0 || strncmp(memoriaInst[y].instruc, "1111", 4) == 0 || strncmp(memoriaInst[y].instruc, "0110", 4) == 0)
            i++;
        else if (strncmp(memoriaInst[y].instruc, "0010", 4) == 0 || strncmp(memoriaInst[y].instruc, "1000", 4) == 0)
            j++;
    }
    printf("O numero de instrucoes e de %d\n", tamLinhas);
    printf("Observa-se: \n%d instrucoes do tipo R\n%d instrucoes do tipo I\n%d instrucoes do tipo J\n", r,i,j);
}
    

