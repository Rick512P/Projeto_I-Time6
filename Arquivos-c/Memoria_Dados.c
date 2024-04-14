#define TAMANHO_MEM_DADOS 256  // Tamanho da memória de dados

//EXEMPLO
void memoriaDados(int endereco, char valor[]){
    MemoriaDados md;
    memset(md.dados, 0, TAMANHO_MEM_DADOS);

    escreveDado(&md, valor, contador);  // Escreve 255 no endereço 10
    char valor = lerDado(&md, 10);  // Lê o valor no endereço 10
}


char lerDado(MemoriaDados *mem, int endereco) {
    if (endereco >= 0 && endereco < TAMANHO_MEM_DADOS) {
        return mem->dados[endereco];
    }
    fprintf(stderr, "Acesso inválido à memória de dados no endereço %d\n", endereco);
    return 0;
}

void escreveDado(MemoriaDados *mem, int endereco, char valor) {
    if (endereco >= 0 && endereco < TAMANHO_MEM_DADOS) {
        mem->dados[endereco] = valor;
    } else {
        fprintf(stderr, "Tentativa de escrita fora dos limites da memória no endereço %d\n", endereco);
    }
}
