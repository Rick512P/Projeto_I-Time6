#include "../Arquivos-h/memoria_instruc.h"


type_instruc memInstruc(int contador, instrucao **memoriaInst, int *tamLinhas){
    type_instruc traduzido; //DECOMPOE A INSTRUÇÃO EM OPCODE, RS, RT, RD, FUNCT, IMM OU ADDR

            //PC PASSA O ENDEREÇO, INCREMENTANDO +1

            traduzido = decoder(memoriaInst, contador); //DECODER IRA DECOMPOR A INSTRUÇÃO NA POSIÇÃO [CONTADOR] NA
            //MEMÓRIA E ARMAZENARÁ NA VARIAVEL TRADUZIDO
  
            return traduzido; //retorna para o controller

}

void imprimeMemInstruc(instrucao *memoriaInst, int tamLinhas){
    for (int i=0; i<tamLinhas+2;i++){
                printf("Instrucao %d: %s\n", i+1, memoriaInst[i].instruc);
            }
}


    

