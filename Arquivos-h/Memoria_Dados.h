#ifndef MEMORIA_DADOS_H
#define MEMORIA_DADOS_H


#include "bibliotecas.h"

typedef struct {
    char dados[TAMANHO_MEM_DADOS];
} MemoriaDados;

void escreveDado(MemoriaDados *mem, int endereco, char valor);
char lerDado(MemoriaDados *mem, int endereco);
void memoriaDados(int endereco, char valor[]);

#endif
