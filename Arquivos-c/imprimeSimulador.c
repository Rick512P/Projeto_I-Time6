#include "../Arquivos-h/imprimeSimulador.h"


void imprimeSimulador(int tamLinhas, type_instruc **instrucoesDecodificadas, instrucao *memoriaInst){
    for(int i=0;i<tamLinhas;i++){
            printf("\n\nInstrucao %d de %d: [%s]", i+1, tamLinhas, memoriaInst[i].instruc);
            if (strcmp((*instrucoesDecodificadas)[i].opcode, "0000") == 0){
                printf("\n======TIPO R=========\n");
                printf("opcode[%s]\t", (*instrucoesDecodificadas)[i].opcode);
                printf("rs[%s]\t\t", (*instrucoesDecodificadas)[i].rs);
                printf("rt[%s]\t\t", (*instrucoesDecodificadas)[i].rt);
                printf("rd[%s]\t\t", (*instrucoesDecodificadas)[i].rd);
                printf("funct[%s]\t\t", (*instrucoesDecodificadas)[i].funct);
                printf("\n======================\n");
            }
            else if ((strcmp((*instrucoesDecodificadas)[i].opcode, "0100") == 0) || (strcmp((*instrucoesDecodificadas)[i].opcode, "1011") == 0) || (strcmp((*instrucoesDecodificadas)[i].opcode, "1111") == 0) || (strcmp((*instrucoesDecodificadas)[i].opcode, "0110") == 0) || strcmp((*instrucoesDecodificadas)[i].opcode, "1000") == 0) {
                printf("\n\n=======TIPO I=========\n");
                printf("opcode[%s]\t", (*instrucoesDecodificadas)[i].opcode);
                printf("rs[%s]\t\t", (*instrucoesDecodificadas)[i].rs);
                printf("rt[%s]\t\t", (*instrucoesDecodificadas)[i].rt);
                printf("imm[%s]\t\t", (*instrucoesDecodificadas)[i].imm);
                
                printf("\n======================\n");
            }

            else if (strcmp((*instrucoesDecodificadas)[i].opcode, "0010") == 0){
                printf("\n========TIPO J========\n");
                printf("opcode[%s]\t", (*instrucoesDecodificadas)[i].opcode);
                printf("addr[%s]\t\t", (*instrucoesDecodificadas)[i].addr);
                printf("\n======================\n");
            }    
    }
}