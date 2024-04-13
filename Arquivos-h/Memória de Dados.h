#ifndef MEMORIA_DADOS_H
#define MEMORIA_DADOS_H

#include "bibliotecas.h"

// Definindo o tamanho do vetor
#define tamanho_vetor 256

// Função para salvar os dados de memória em um vetor
int* salvar_dados_memoria(int *dados_memoria);

// Função para salvar os dados em um arquivo
void save_data_to_file(int data[], int size);

#endif
