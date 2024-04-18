#include "../Arquivos-h/Memoria_Dados.h"

// Função para salvar os dados de memória em um vetor
int* salvar_dados_memoria(int *dados_memoria) {
    int *vetor = (int*)malloc(256 * sizeof(int)); // tamanho_vetor substituido de forma provisória pela constante 256 para testes

    if (vetor == NULL) {
    
        return NULL;
    }

    for (int i = 0; i < 256; i++) {
        vetor[i] = dados_memoria[i]; // Copia os dados de memória para o vetor
    }

    return vetor;
}
