#include "../Arquivos-h/imprimeSimulador.h"


void imprimeSimulador(int tamLinhas, type_instruc *tradu, instrucao **inst, int **regs){
    for(int i=0;i<tamLinhas;i++){
            printf("Instrucao %d de %d: %s", i+1, tamLinhas, (*inst)[i].instruc);
            if (strcmp(tradu[i].opcode, "0000") == 0){
                printf("\n======TIPO R=========\n");
                printf("opcode[%s]\t", tradu[i].opcode);
                printf("rs[%s]\t\t", tradu[i].rs);
                printf("rt[%s]\t\t", tradu[i].rt);
                printf("rd[%s]\t\t", tradu[i].rd);
                printf("funct[%s]\t\t", tradu[i].funct);
                printf("\n================\n");
            }
            else if ((strcmp(tradu[i].opcode, "0100") == 0) || (strcmp(tradu[i].opcode, "1011") == 0) || (strcmp(tradu[i].opcode, "1111") == 0) || (strcmp(tradu[i].opcode, "0110") == 0)) {
                printf("\n=======TIPO I=========\n");
                printf("opcode[%s]\t", tradu[i].opcode);
                printf("rt[%s]\t\t", tradu[i].rs);
                printf("rd[%s]\t\t", tradu[i].rt);
                printf("imm[%s]\t\t", tradu[i].imm);
                
                printf("\n================\n");
            }

            else if (strcmp(tradu[i].opcode, "0010") == 0 || strcmp(tradu[i].opcode, "1000") == 0){
                printf("\n========TIPO J========\n");
                printf("opcode[%s]\t", tradu[i].opcode);
                printf("addr[%s]\t\t", tradu[i].addr);
                printf("\n================\n");
            }    
    }
    Registradores(regs, 0, tradu->rt, 1);
}