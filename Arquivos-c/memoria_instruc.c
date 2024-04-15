#include "../Arquivos-h/memoria_instruc.h"


type_instruc* memInstruc(int contador, int opcao, instrucao *inst, int *tamLinhas){
    switch(opcao){
        case 0:
        parser(inst, tamLinhas); //funçao responsavel por abrir o arquvio .mem e coletar a instruçao, armazenando na variavel inst
    //O INST TERÁ A INSTRUÇÃO E TAMANHO_LINHAS O TANTO DE INSTRUÇÕES QUE PRECISARÁ SEREM EXECUTADAS
        break;

        case 1:
            for (int i=0; i<(*tamLinhas);i++){
                printf("%s", inst[i].instruc);
            }
            break;
        
        case 2:
            if (inst == NULL) {
                fprintf(stderr, "Falha ao obter instruções.\n");
                break;
            }
            int r=0, i=0, j=0;
            for(int y=0;y<(*tamLinhas);y++){
                if (strncmp(inst[y].instruc, "0000", 4))
                    r++;
                else if (strncmp(inst[y].instruc, "0100", 4) || strncmp(inst[y].instruc, "1011", 4) || strncmp(inst[y].instruc, "1111", 4) || strncmp(inst[y].instruc, "0110", 4))
                    i++;
                else if (strncmp(inst[y].instruc, "0010", 4) || strncmp(inst[y].instruc, "1000", 4))
                    j++;
            }
            printf("O numero de instrucoes é de %d", (*tamLinhas));
            printf("Observa-se: %d instrucoes do tipo R\n%d instrucoes do tipo I\n%d instrucoes do tipo J", r,i,j);
            break;

        case 3:
            type_instruc *traduzido; //DECOMPOE A INSTRUÇÃO EM OPCODE, RS, RT, RD, FUNCT, IMM OU ADDR
            traduzido = (type_instruc*)malloc((*tamLinhas) * sizeof(type_instruc));

            if (traduzido == NULL) {
                fprintf(stderr, "Falha ao alocar memória para instruções traduzidas.\n");
                return NULL;
            }
            //PC PASSA O ENDEREÇO, INCREMENTANDO +1
            for(contador=0; contador<(*tamLinhas); contador++){

                traduzido[contador] = decoder(inst, contador); //DECODER IRA DECOMPOR A INSTRUÇÃO NA POSIÇÃO [CONTADOR] NA
            //MEMÓRIA E ARMAZENARÁ NA VARIAVEL TRADUZIDO

                printf("%s\n", traduzido[contador].opcode); //DEBUG
            }
            return traduzido; //retorna para o controller
            
            
            break;
    }

}
    

