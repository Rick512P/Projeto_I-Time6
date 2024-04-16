#ifndef MEMORIA_DADOS_H
#define MEMORIA_DADOS_H


#include "bibliotecas.h"



void escreveDado(MemoriaDados *mem, int endereco, char *valor);
char lerDado(MemoriaDados *mem, int endereco);
void memoriaDados(MemoriaDados *md, int opcao, char valor[], int contador);
void imprimeDados(MemoriaDados md, int tamLinhas);
void escreverArquivoMemoria(MemoriaDados md);

#endif
