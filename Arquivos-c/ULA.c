#include "../Arquivos-h/ULA.h"


int ULA(type_instruc **instrucoesDecodificadas, int *contador, MemoriaDados **md, int **regs) {
  
    int address, rs, rt, rd;

    if (strcmp((*instrucoesDecodificadas)[*contador].opcode, "0000") == 0 ) {
        char Target[4];
        char *Dest=malloc(4);
        char Source[4];
        strcpy(Source, (*instrucoesDecodificadas)[*contador].rs);
        strcpy(Target, (*instrucoesDecodificadas)[*contador].rt);
        strcpy(Dest, (*instrucoesDecodificadas)[*contador].rd);

        rs = retornoRegs(regs, (*instrucoesDecodificadas)[*contador].rs);
        rt = retornoRegs(regs, (*instrucoesDecodificadas)[*contador].rt);

        if (strcmp((*instrucoesDecodificadas)[*contador].funct, "000") == 0 ){
            rd = rs + rt;
            int local_decimal = rd;

            dec_to_bin(local_decimal, &Dest); //converte o resultado em binário
            free(Dest);
            return rd; //RETORNA PARA O CONTROLLER O INTEIRO PARA O MESMO ARMAZENAR NO REGISTRADOR


            
            
        }

        else if (strcmp((*instrucoesDecodificadas)[*contador].funct, "010") == 0 ){
            //"sub -> rs - rt = rd";
            bin_dec(Source, Target, Dest, &rs, &rt, &rd);
            rd = rs - rt;

            dec_to_bin(rd, &Dest);

            free(Dest);
            return rd; //RETORNA PARA O CONTROLLER O INTEIRO PARA O MESMO ARMAZENAR NO REGISTRADOR
        }

        else if (strcmp((*instrucoesDecodificadas)[*contador].funct, "100") == 0 ){
            //"and -> rs and rt = rd";
            AND(Source, Target, Dest);


            bin_dec(NULL, NULL, Dest, NULL, NULL, &rd);
            free(Dest);
            return rd;
        }

        else if (strcmp((*instrucoesDecodificadas)[*contador].funct, "101") == 0 ){
            //"or -> rs or rt = rd";
            OR(Source, Target, Dest);


            bin_dec(NULL, NULL, Dest, NULL, NULL, &rd);
            free(Dest);
            return rd;
        }
    }

    else if(strcmp((*instrucoesDecodificadas)[*contador].opcode,"0100") == 0){// addi -> rs + immediate = rt
        char *Target=malloc(4);
        char Source[4];
        char Immediate[7];
        int immediate;
        strcpy(Target, (*instrucoesDecodificadas)[*contador].rt);
        strcpy(Source, (*instrucoesDecodificadas)[*contador].rs);
        strcpy(Immediate, (*instrucoesDecodificadas)[*contador].imm);
        bin_dec(Source, Target, Immediate, &rs, &rt, &immediate);
        rt = rs + immediate;


        dec_to_bin(rt, &Target);
        free(Target);
        return rt; //RETORNA PARA O CONTROLLER O INTEIRO PARA O MESMO ARMAZENAR NO REGISTRADOR
    }

    else if(strcmp((*instrucoesDecodificadas)[*contador].opcode,"1011") == 0){// lw GRAVA CONTEUDO DA MEMORIA NOS REGISTRADORES
        //$rt = M[$rs + imm]
        char Target[4];
        char Source[4];
        char *Immediate = malloc(7);
        int immediate, dados;
        strcpy(Target, (*instrucoesDecodificadas)[*contador].rt);
        strcpy(Source, (*instrucoesDecodificadas)[*contador].rs);
        strcpy(Immediate, (*instrucoesDecodificadas)[*contador].imm);
        bin_dec(Source, Target, Immediate, &rs, &rt, &immediate);
        //Agora sei qual a posicao Immediate em decimal:
        bin_dec(Source, Target, (*md)[immediate].dados, &rs, &rt, &dados);
        //Agora sei qual o valor contido na posição 4 da memoria em decimal:
        free(Immediate);
        return dados;
    }
    else if(strcmp((*instrucoesDecodificadas)[*contador].opcode,"1111") == 0){// sw GRAVA CONTEUDO NA MEMORIA DE DADOS
        //M[$rs + imm] = $rt
        char Target[4];
        char Source[4];
        char Immediate[7];
        int immediate, conteudo;
        char *conteudo_bin = malloc(7);
        strcpy(Target, (*instrucoesDecodificadas)[*contador].rt);
        strcpy(Source, (*instrucoesDecodificadas)[*contador].rs);
        strcpy(Immediate, (*instrucoesDecodificadas)[*contador].imm);
        conteudo = retornoRegs(regs, (*instrucoesDecodificadas)[*contador].rt);
        dec_to_bin(conteudo, &conteudo_bin);
        bin_dec(Source, Target, Immediate, &rs, &rt, &immediate);
        escreveDado(md, &immediate, conteudo_bin);
        free(conteudo_bin);
    }

    else if(strcmp((*instrucoesDecodificadas)[*contador].opcode,"0010") == 0){ // j -> jump to specified address
        char Target[4];
        char Source[4];
        char *ADDR = malloc(8);
        strcpy(ADDR, (*instrucoesDecodificadas)[*contador].addr);
        bin_dec(Source, Target, ADDR, &address, &rt, &rs);
        dec_to_bin(address, &ADDR);
        free(ADDR);
        return address;
    }

    else if(strcmp((*instrucoesDecodificadas)[*contador].opcode,"1000") == 0){
        char Target[4];
        strcpy(Target, (*instrucoesDecodificadas)[*contador].rt);
        char Source[4];
        strcpy(Source, (*instrucoesDecodificadas)[*contador].rs);
        char Immediate[7];
        strcpy(Immediate, (*instrucoesDecodificadas)[*contador].imm);
        int immediate;
        int reg1 = retornoRegs(regs, (*instrucoesDecodificadas)[*contador].rs);
        int reg2 = retornoRegs(regs, (*instrucoesDecodificadas)[*contador].rt);
        bin_dec(Source, Target, Immediate, &rs, &rt, &immediate);
        if (reg1 == reg2)
            return ((*contador) += immediate);
        else
            return (*contador);    
    }


    else{
        printf("OPCODE ERROR!");
    }
}


// Implementação do deslocamento de memória para instruções lw e sw
int SW(char Source[], char Target[], char Dest[], char *imm) {
    int base_address, immDec;
    bin_dec(Source, imm, NULL, &base_address, &immDec, NULL);
    int effective_address = base_address + immDec; ///MUDAR ISSO AQUI
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

void dec_to_bin(int decimal, char **binaryPtr) {
    char *new_binary = realloc(*binaryPtr, BITS); // Tentativa de realocar com o novo tamanho
    if (new_binary == NULL) {
        fprintf(stderr, "Falha ao realocar memória.\n");
        return; // Falha na realocação
    }
    *binaryPtr = new_binary; // Atualiza o ponteiro original com o novo endereço

    // Inicializa o novo buffer
    memset(*binaryPtr, '0', BITS - 1);
    (*binaryPtr)[BITS - 1] = '\0'; // Terminador nulo

    // Preenche o buffer com a representação binária
    int index = BITS - 2;
    while (decimal > 0 && index >= 0) {
        (*binaryPtr)[index--] = (decimal % 2) ? '1' : '0';
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
