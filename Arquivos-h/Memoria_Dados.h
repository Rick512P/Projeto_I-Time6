#ifndef MEMORIA_DADOS_H
#define MEMORIA_DADOS_H


#include "bibliotecas.h"



void escreveDado(MemoriaDados *mem, int endereco, char *valor);
char lerDado(MemoriaDados *mem, int endereco);
void memoriaDados(MemoriaDados *md, int opcao, char valor[], int contador);
<<<<<<< HEAD
void imprimeDados(MemoriaDados md, int tamLinhas);
void escreverArquivoMemoria(MemoriaDados md);
=======
void memDados(MemoriaDados *md);
void escreverArquivoMemoria(MemoriaDados *md);
>>>>>>> 7a76bb33eb4eccac2bf10c9e6ef2c0e62e42e597

#endif
