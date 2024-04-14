#include "../Arquivos-h/decode.h"

type_instruc decoder(instrucao *inst, int i){
    type_instruc traducao;

    inst[i].instruc[16] = '\0';
    printf("\nInstrucao completa: %s\n", inst[i].instruc); //EXCLUIR PRINTF DEPOIS
    
    strncpy(traducao.opcode, inst[i].instruc, 5); //copia para .opcode os 5 primeiros caracteres de inst[i].instruc
    traducao.opcode[4] = '\0';
    
    if (strcmp(traducao.opcode, "0000") == 0){ //SE VERDADEIRO, SABEMOS QUE É DO TIPO R, PORTANTO ADICIONAREMOS O FUNCT
        strncpy(traducao.funct, inst[i].instruc + 13, 4); // Escreve o funct
        traducao.funct[3] = '\0';
        strncpy(traducao.rs, inst[i].instruc + 4, 4); //strncpy copiara 3 caracteres a partir dos 4 caracteres inciais.
        traducao.rs[3] = '\0';
        strncpy(traducao.rt, inst[i].instruc + 7, 4);
        traducao.rt[3] = '\0';
        strncpy(traducao.rd, inst[i].instruc + 10, 4);
        traducao.rd[3] = '\0';
        
        return traducao;
    }


    else if ((strcmp(traducao.opcode, "0100") == 0) || (strcmp(traducao.opcode, "1011") == 0) || (strcmp(traducao.opcode, "1111") == 0) || (strcmp(traducao.opcode, "0110") == 0)) { //TIPO I
        strncpy(traducao.imm, inst[i].instruc + 10, 7); // Escreve o IMMEDIATE de 6 bits
        traducao.imm[6] = '\0';
        strncpy(traducao.rt, inst[i].instruc + 7, 4);
        traducao.rt[3] = '\0';
        strncpy(traducao.rs, inst[i].instruc + 5, 4);
        traducao.rs[3] = '\0';
        
        return traducao;
    }


    else if (strcmp(traducao.opcode, "0010") == 0 || strcmp(traducao.opcode, "1000") == 0){//SE NAO, SABEREMOS QUE SERÁ TIPO J, PORTANDO ADICIONAREMOS APENAS O ADDR
        strncpy(traducao.addr, inst[i].instruc + 9, 8); // Escreve o funct
        traducao.addr[7] = '\0';
        
        return traducao;
    }
    
    
}