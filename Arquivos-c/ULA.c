#include "../Arquivos-h/ULA.h"


int ULA(type_instruc **instrucoesDecodificadas, int *contador, MemoriaDados **md, int **regs) {
  
    int address, rs, rt, rd;

    if (strcmp((*instrucoesDecodificadas)[*contador].opcode, "0000") == 0 ) {
        char Target[9];
        char Dest[9];
        char Source[9];
        Target[8] = '\0';
        Dest[8] = '\0';
        Source[8] = '\0';

        rs = retornoRegs(regs, (*instrucoesDecodificadas)[*contador].rs);
        rt = retornoRegs(regs, (*instrucoesDecodificadas)[*contador].rt);

        if (strcmp((*instrucoesDecodificadas)[*contador].funct, "000") == 0 ){
            rd = rs + rt;
            if (rd > 127 || rd < -128){
                fprintf(stderr, "Overflow. Registrador RD com numero maior que a capacidade suportada.");
                return -1;
            }
            int local_decimal = rd;

            return rd; //RETORNA PARA O CONTROLLER O INTEIRO PARA O MESMO ARMAZENAR NO REGISTRADOR   
        }

        else if (strcmp((*instrucoesDecodificadas)[*contador].funct, "010") == 0 ){
            //"sub -> rs - rt = rd";
            rd = rs - rt;
            if (rd > 127 || rd < -128){
                fprintf(stderr, "Overflow. Registrador RD com numero maior que a capacidade suportada.");
                return -1;
            }

            return rd; //RETORNA PARA O CONTROLLER O INTEIRO PARA O MESMO ARMAZENAR NO REGISTRADOR
        }

        else if (strcmp((*instrucoesDecodificadas)[*contador].funct, "100") == 0 ){
            //"and -> rs and rt = rd";
            decimalToBinary(rt, Target);
            decimalToBinary(rs, Source);
            AND(Source, Target, Dest);
            rd = bin_to_decimal(Dest);
            if (rd > 127 || rd < -128){
                fprintf(stderr, "Overflow. Registrador RD com numero maior que a capacidade suportada.");
                return -1;
            }
            return rd;
        }

        else if (strcmp((*instrucoesDecodificadas)[*contador].funct, "101") == 0 ){
            //"or -> rs or rt = rd";
            decimalToBinary(rt, Target);
            decimalToBinary(rs, Source);
            OR(Source, Target, Dest);
            rd = bin_to_decimal(Dest);
            if (rd > 127 || rd < -128){
                fprintf(stderr, "Overflow. Registrador RD com numero maior que a capacidade suportada.");
                return -1;
            }
            return rd;
        }
    }

    else if(strcmp((*instrucoesDecodificadas)[*contador].opcode,"0100") == 0){// addi -> rs + immediate = rt
        int immediate, rs, rt;
        immediate = bin_to_decimal((*instrucoesDecodificadas)[*contador].imm);
        rs = retornoRegs(regs, (*instrucoesDecodificadas)[*contador].rs);
        if ((immediate + rs) > 127 || (immediate + rs) < -128){
                fprintf(stderr, "Overflow. Registrador RD com numero maior que a capacidade suportada.");
                return -1;
        }
        return (immediate + rs); //RETORNA PARA O CONTROLLER O INTEIRO PARA O MESMO ARMAZENAR NO REGISTRADOR
    }

    else if(strcmp((*instrucoesDecodificadas)[*contador].opcode,"1011") == 0){// lw GRAVA CONTEUDO DA MEMORIA NOS REGISTRADORES
        //$rt = M[$rs + imm]
        int immediate, dados;
        immediate = bin_to_decimal((*instrucoesDecodificadas)[*contador].imm);
        //Agora sei qual a posicao Immediate em decimal:
        dados = bin_to_decimal((*md)[immediate].dados);
        //Agora sei qual o valor contido na posição 4 da memoria em decimal:
        return dados;
    }

    else if(strcmp((*instrucoesDecodificadas)[*contador].opcode,"1111") == 0){// sw GRAVA CONTEUDO NA MEMORIA DE DADOS
        //M[$rs + imm] = $rt
        int immediate, conteudo;
        char conteudo_bin[9];
        conteudo_bin[8] = '\0';
        conteudo = retornoRegs(regs, (*instrucoesDecodificadas)[*contador].rt);
        if (conteudo > 127 || conteudo < -128){
            fprintf(stderr, "OVERFLOW. Numero a ser escrito na memoria de dados ultrapassa os 8 bits.");
            return -1;
        }
        decimalToBinary(conteudo, conteudo_bin);
        immediate = bin_to_decimal((*instrucoesDecodificadas)[*contador].imm);
        escreveDado(md, &immediate, conteudo_bin);
    }

    else if(strcmp((*instrucoesDecodificadas)[*contador].opcode,"0010") == 0){ // j -> jump to specified address
        address = bin_to_decimal((*instrucoesDecodificadas)[*contador].addr);
        if(address < 0){
            address *= -1; //transforma um possivel valor negativo para positvo, ja que a memoria de dados nao tem posicao negativa.
        }

        if(((*contador+1)+address) > 255){
            fprintf(stderr, "OVERFLOW. Salto para posicao de memoria inexistente.");
            return -1;
        }
        return address;
    }

    else if(strcmp((*instrucoesDecodificadas)[*contador].opcode,"1000") == 0){ //BEQ
        int immediate;
        int reg1 = retornoRegs(regs, (*instrucoesDecodificadas)[*contador].rs);
        int reg2 = retornoRegs(regs, (*instrucoesDecodificadas)[*contador].rt);
        immediate = bin_to_decimal((*instrucoesDecodificadas)[*contador].imm);
        if(immediate < 0){
            immediate *= -1; //transforma um possivel valor negativo para positvo, ja que a memoria de dados nao tem posicao negativa.
        }
        if (reg1 == reg2){
            if(((*contador+1) + immediate) > 255){
                fprintf(stderr, "OVERFLOW. PC ultrapassou limite de espaços de memória.");
                return -1;
            }
                return ((*contador) += immediate);
        }
        else
            return (*contador);    
    }


    else{
        fprintf(stderr, "OPCODE ERROR!");
    }
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

void dec_to_bin(int decimal, char *binaryPtr) {
    // Índice para percorrer o array binário da direita para a esquerda
    int index = 7;

    // Preenche o array binário da direita para a esquerda
    while (index >= 0) {
        binaryPtr[index--] = (decimal % 2) ? '1' : '0';
        decimal /= 2;
    }

    // Adiciona o caractere nulo ao final do array
    binaryPtr[8] = '\0';
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
