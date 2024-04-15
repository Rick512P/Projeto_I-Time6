
#include "../Arquivos-h/bibliotecas.h"
#include "../Arquivos-h/Memoria_Dados.h"
//EXEMPLO
void memoriaDados(MemoriaDados *md, int opcao, char valor[], int contador){
    switch (opcao)
    {
    case 0:
        escreveDado(&md, valor, contador);
        break;
    
    case 1:
        lerDado(&md, contador);
    }

}

char lerDado(MemoriaDados *mem, int endereco) {
    if (endereco >= 0 && endereco < 256) {
        return mem->dados[endereco];
    }
    fprintf(stderr, "Acesso inválido à memória de dados no endereço %d\n", endereco);
    return 0;
}

void escreveDado(MemoriaDados *mem, int endereco, char *valor) {
    if (endereco >= 0 && endereco < 256) {
        mem->dados[endereco] = *valor;
    } else {
        fprintf(stderr, "Tentativa de escrita fora dos limites da memória no endereço %d\n", endereco);
    }
}
