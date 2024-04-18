#include "../Arquivos-h/ULA.h"


int ULA(type_instruc *traduzido, int *contador, MemoriaDados **md, int **regs) {
  
    int address, rs, rt, rd;

    if (strcmp(traduzido[*contador].opcode, "0000") == 0 ) {
        char Target[4];
        char Dest[4];
        char Source[4];
        strcpy(Source, traduzido[*contador].rs);
        strcpy(Target, traduzido[*contador].rt);
        strcpy(Dest, traduzido[*contador].rd);

        rs = Registradores(regs, 0, traduzido[*contador].rs, 2);
        rt = Registradores(regs, 0, traduzido[*contador].rt, 2);

        if (strcmp(traduzido[*contador].funct, "000") == 0 ){
            
            //"add -> rs + rt = rd";
            printf("rs: %d \t rt: %d", rs, rt);
            rd = rs + rt;
            int local_decimal = rd;
            printf("\nrd: %d\n", rd); //VALOR DE RD CORRETO
            printf("Valor de Dest: %s", Dest);
            dec_to_bin(local_decimal, Dest); //converte o resultado em binário
            printf("Valor de Dest depois de dectobin: %s\n", Dest);
            printf("\nrd depois de dectobin: %d\n", rd); //VALOR DE RD É MUDADO ??????????????
            return rd; //RETORNA PARA O CONTROLLER O INTEIRO PARA O MESMO ARMAZENAR NO REGISTRADOR


            escreveDado(md, contador, Dest);
            
        }

        else if (strcmp(traduzido[*contador].funct, "010") == 0 ){
            //"sub -> rs - rt = rd";
            bin_dec(Source, Target, Dest, &rs, &rt, &rd);
            rd = rs - rt;

            dec_to_bin(rd, Dest);

            escreveDado(md, contador, Dest);
            return rd; //RETORNA PARA O CONTROLLER O INTEIRO PARA O MESMO ARMAZENAR NO REGISTRADOR
        }

        else if (strcmp(traduzido[*contador].funct, "100") == 0 ){
            //"and -> rs and rt = rd";
            AND(Source, Target, Dest);

            escreveDado(md, contador, Dest);

            bin_dec(NULL, NULL, Dest, NULL, NULL, &rd);
            return rd;
        }

        else if (strcmp(traduzido[*contador].funct, "101") == 0 ){
            //"or -> rs or rt = rd";
            OR(Source, Target, Dest);

            escreveDado(md, contador, Dest);

            bin_dec(NULL, NULL, Dest, NULL, NULL, &rd);
            return rd;
        }
    }

    else if(strcmp(traduzido[*contador].opcode,"0100") == 0){// addi -> rs + immediate = rt
        char Target[4];
        char Source[4];
        char Immediate[7];
        int immediate;
        strcpy(Target, traduzido[*contador].rt);
        strcpy(Source, traduzido[*contador].rs);
        strcpy(Immediate, traduzido[*contador].imm);
        bin_dec(Source, Target, Immediate, &rs, &rt, &immediate);
        rt = rs + immediate;


        dec_to_bin(rt, Target);
        escreveDado(md, contador, Target);

        return rt; //RETORNA PARA O CONTROLLER O INTEIRO PARA O MESMO ARMAZENAR NO REGISTRADOR
    }

    else if(strcmp(traduzido[*contador].opcode,"1011") == 0){// lw --> LW TEM QUE RETORNAR RT
        //$rt = M[$rs + imm]
        char Target[4];
        char Source[4];
        char Immediate[7];
        int immediate;
        strcpy(Target, traduzido[*contador].rt);
        strcpy(Source, traduzido[*contador].rs);
        strcpy(Immediate, traduzido[*contador].imm);
        address = lw_sw_offset(Source, Target, Immediate, traduzido[*contador].imm);
        dec_to_bin(address, Immediate);
        escreveDado(md, contador, Immediate);
    }
    else if(strcmp(traduzido[*contador].opcode,"1111") == 0){// sw
        //M[$rs + imm] = $rt
        char Target[4];
        char Source[4];
        char Immediate[7];
        int immediate;
        strcpy(Target, traduzido[*contador].rt);
        strcpy(Source, traduzido[*contador].rs);
        strcpy(Immediate, traduzido[*contador].imm);
        address = lw_sw_offset(Source, Target, Immediate, traduzido[*contador].imm);
        dec_to_bin(address, Immediate);
        escreveDado(md, contador, Immediate);
    }

    else if(strcmp(traduzido[*contador].opcode,"0010") == 0){ // j -> jump to specified address
        char Target[4];
        char Source[4];
        char ADDR[8];
        strcpy(ADDR, traduzido[*contador].addr);
        bin_dec(Source, Target, ADDR, &address, &rt, &rs);
        dec_to_bin(address, ADDR);
        escreveDado(md, contador, ADDR);
        return address;
    }

    else{
        printf("OPCODE ERROR!");
    }
}


// Implementação do deslocamento de memória para instruções lw e sw
int lw_sw_offset(char Source[], char Target[], char Dest[], char *imm) {
    int base_address, immDec;
    bin_dec(Source, imm, NULL, &base_address, &immDec, NULL);
    int effective_address = base_address + immDec; ///MUDAR ISSO AQUI
    printf("Accessing memory at address: %d\n", effective_address);
    return effective_address;
}


// Função que converte uma string binária para um valor decimal inteiro.
int bin_to_dec(const char *bin) {
    int dec = 0;
    int base = 1;
    int len = strlen(bin);

    for (int i = len - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            dec += base;
        }
        base *= 2;
    }

    return dec;
}

// Função para converter três strings binárias para valores decimais.
void bin_dec(const char Source[], const char Target[], const char Dest[], int *rs, int *rt, int *rd) {
    if (rs) *rs = bin_to_dec(Source); // Converte Source para decimal e armazena em rs.
    if (rt) *rt = bin_to_dec(Target); // Converte Target para decimal e armazena em rt.
    if (rd) *rd = bin_to_dec(Dest);   // Converte Dest para decimal e armazena em rd.
}

void dec_to_bin(int decimal, char *binary) {
    int i;

    // Inicializa a string binária
    for (i = 0; i < 17; i++) {
        binary[i] = '0';
    }
    binary[17] = '\0';  // Garante que o último caractere é o terminador nulo

    // Converte decimal para binário
    for (i = 17 - 1; i >= 0 && decimal > 0; i--) {
        binary[i] = (decimal % 2) ? '1' : '0';
        decimal /= 2;
    }
} 

/*void dec_to_bin(int decimal, char *binary) {
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
}*/

void AND(char Source[], char Target[], char *Dest){
    int i, LS = strlen(Source);
    for (i = 0; i < LS; i++){
        if (Source[i] == '0' || Target[i] == '0'){
            Dest[i] = '0';
        } else {
            Dest[i] = '1';
        }
    }
}

void OR(char Source[], char Target[], char *Dest){
    int i, LS = strlen(Source);
    for (i = 0; i < LS; i++){
        if (Source[i] == '1' || Target[i] == '1'){
            Dest[i] = '1';
        } else {
            Dest[i] = '0';
        }
    }
}
