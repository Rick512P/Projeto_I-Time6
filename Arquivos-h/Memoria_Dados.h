#ifndef MEMORIA_DADOS_H
#define MEMORIA_DADOS_H


#include "bibliotecas.h"

void escreveDado(MemoriaDados **mem, int *contador, char *valor);
char lerDado(MemoriaDados *mem, int endereco);
void imprimeDados(MemoriaDados *md, int tamLinhas);
void escreverArquivoMemoria(MemoriaDados *md);


#endif
