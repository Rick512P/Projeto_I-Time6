#include <stdio.h>
#include <string.h>
#include "../Arquivos-h/ULA.h"

void ULA(type_instruc *traduzido, int contador) {
    char Target[4];
    char Dest[4];
    char Source[4];
    strncpy(Source, traduzido[contador].rs, 4);
    strncpy(Target, traduzido[contador].rt, 4);
    strncpy(Dest, traduzido[contador].rd, 4);

    //debugs de print
    /*printf("\n%s\n", Dest);   //quando nao ha valor de dest em traduzido, ha um caracter estranho
    printf("%s\n", Target);
    printf("%s\n", Source);*/

    if (strcmp(traduzido[contador].opcode, "0000") == 0 ) {
    
        if (strcmp(traduzido[contador].funct, "000") == 0 ){
            //"add -> rs + rt = rd";
            int rs, rt, rd;
            bin_dec(Source, Target, Dest, &rs, &rt, &rd);  
            rd = rs + rt;
            dec_to_bin(rd, Dest); //converte o resultado em  binario
        }

        else if (strcmp(traduzido[contador].funct, "010") == 0 ){
            //"sub -> rs - rt = rd";
            int rs, rt, rd;
            bin_dec(Source, Target, Dest, &rs, &rt, &rd);
            rd = rs - rt;
            dec_to_bin(rd, Dest);
        }

        else if (strcmp(traduzido[contador].funct, "100") == 0 ){
            //"and -> rs and rt = rd";
            AND(Source, Target, Dest);
        }

        else if (strcmp(traduzido[contador].funct, "101") == 0 ){
            //"or -> rs or rt = rd";
            OR(Source, Target, Dest);
        }

    }

    else if(strcmp(traduzido[contador].opcode,"0100") == 0){
        // addi -> rs + immediate = rt
        int rs, rt, immediate;
        bin_dec(Source, Target, Dest, &rs, &immediate, &rt);
        rt = rs + immediate;
        dec_to_bin(rt, Dest);
    }

    else if(strcmp(traduzido[contador].opcode,"1011") == 0){
        //printf("lw");
    }
    else if(strcmp(traduzido[contador].opcode,"1111") == 0){
        //printf("sw");
    }
    else if(strcmp(traduzido[contador].opcode,"1000") == 0){
        //printf("beq");
    }

    else if(strcmp(traduzido[contador].opcode,"0010") == 0){
        // j -> jump to specified address
        int address;
        bin_dec(Source, Target, Dest, &address, NULL, NULL);
        // Implementação da função jump
        printf("Jumping to address: %d\n", address);
    }

    else{
        printf("OPCODE ERROR!");
    }
}

void bin_dec(char Source[], char Target[], char Dest[], int *rs, int *rt, int *rd) {
    int i, LS = strlen(Source), LT = strlen(Target), LD = strlen(Dest);
    *rs = 0;
    *rd = 0;
    *rt = 0;
    
    // Etapa de verificação de números negativos
    int NegativeSource = (Source[0] == '1');
    int NegativeTarget = (Target[0] == '1');
    int NegativeDest = (Dest[0] == '1');
    
    // Etapa de Converção de binário para decimal, considerando números negativos
    for (i = 0; i < LS; i++) {
        if (NegativeSource && i == 0) {
            *rs -= (1 << (LS - i - 1));
        } else if (Source[i] == '1') {
            *rs += (1 << (LS - i - 1));
        }
    }
    
    for (i = 0; i < LT; i++) {
        if (NegativeTarget && i == 0) {
            *rt -= (1 << (LT - i - 1));
        } else if (Target[i] == '1') {
            *rt += (1 << (LT - i - 1));
        }
    }
    
    for (i = 0; i < LD; i++) {
        if (NegativeDest && i == 0) {
            *rd -= (1 << (LD - i - 1));
        } else if (Dest[i] == '1') {
            *rd += (1 << (LD - i - 1));
        }
    }
}

char* dec_to_bin(int decimal, char binary[]) {
    int i;
    
    // Etapa de verificação de números negativos
    int Negative = (decimal < 0);
    
    // Se for negativo, ajusta o valor para o complemento de dois
    if (Negative) {
        decimal = (1 << BITS) + decimal;
    }
    
    // Inicializa a string binária
    for (i = 0; i < BITS; i++) {
        binary[i] = '0';
    }
    binary[BITS] = '\0';
    
    // Converte decimal para binário
    for (i = BITS - 1; i >= 0; i--) {
        binary[i] = (decimal % 2) ? '1' : '0';
        decimal /= 2;
    }
    
    // Se o número original era negativo, complementa os bits
    if (Negative) {
        int carry = 1;
        for (i = BITS - 1; i >= 0; i--) {
            if (binary[i] == '1' && carry == 1) {
                binary[i] = '0';
            } else if (binary[i] == '0' && carry == 1) {
                binary[i] = '1';
                carry = 0;
            }
        }
    }
    return binary;
}

void AND(char Source[], char Target[], char Dest[]){
    int i, LS = strlen(Source);
    for (i = 0; i < LS; i++){
        if (Source[i] == '0' || Target[i] == '0'){
            Dest[i] = '0';
        } else {
            Dest[i] = '1';
        }
    }
}

void OR(char Source[], char Target[], char Dest[]){
    int i, LS = strlen(Source);
    for (i = 0; i < LS; i++){
        if (Source[i] == '1' || Target[i] == '1'){
            Dest[i] = '1';
        } else {
            Dest[i] = '0';
        }
    }
    }
