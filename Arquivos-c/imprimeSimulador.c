#include "../Arquivos-h/imprimeSimulador.h"


void imprimeSimulador(int tamLinhas, type_instruc tradu, instrucao inst){
    for(i=0;i<tamLinhas;i++){
            printf("Instrucao %d de %d: %s", i, tamLinhas, inst[i]);
            if (strcmp(tradu[i].opcode, "0000") == 0){
                printf("\n======TIPO R=========\n");
                printf("opcode: %s\n", tradu[i].opcode);
                printf("rs: %s\n", tradu[i].rs);
                printf("rt: %s\n", tradu[i].rt);
                printf("rd: %s\n", tradu[i].rd);
                printf("funct: %s\n", tradu[i].funct);

                //AGORA OS REGISTRADORES
                Registradores(0,tradu[i].rd,1);
                printf("================\n");
            }
            else if ((strcmp(tradu[i].opcode, "0100") == 0) || (strcmp(traducao.opcode, "1011") == 0) || (strcmp(traducao.opcode, "1111") == 0) || (strcmp(traducao.opcode, "0110") == 0)) {
                printf("\n=======TIPO I=========\n");
                printf("opcode: %s\n", tradu[i].opcode);
                printf("rt: %s\n", tradu[i].rs);
                printf("rd: %s\n", tradu[i].rt);
                printf("imm: %s\n", tradu[i].imm);
                Registradores(0,tradu[i].rt,1);
                printf("================\n");
            }

            else if (strcmp(traducao.opcode, "0010") == 0 || strcmp(traducao.opcode, "1000") == 0){
                printf("\n========TIPO J========\n");
                printf("opcode: %s\n", tradu[i].opcode);
                printf("addr: %s\n", tradu[i].addr);
                printf("\n================\n");
            }    
    }
}