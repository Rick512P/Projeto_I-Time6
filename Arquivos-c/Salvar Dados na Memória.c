#include "Memoria_Dados.h"

// Função para salvar os dados de memória em um vetor
int* salvar_dados_memoria(int *dados_memoria) {
    int *vetor = (int*)malloc(tamanho_vetor * sizeof(int)); // quem é tamanho_vetor?

    if (vetor == NULL) {
    
        return NULL;
    }

    for (int i = 0; i < tamanho_vetor; i++) {
        vetor[i] = dados_memoria[i]; // Copia os dados de memória para o vetor
    }

    return vetor;
}
