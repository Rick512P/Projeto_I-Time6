#ifndef MEMORIA_DADOS_H
#define MEMORIA_DADOS_H


#include "bibliotecas.h"

typedef struct {
    char dados[256];
} MemoriaDados;

void escreveDado(MemoriaDados *mem, int endereco, char valor);
char lerDado(MemoriaDados *mem, int endereco);
void memoriaDados(MemoriaDados *md, int opcao, char valor[], int contador);

#endif
