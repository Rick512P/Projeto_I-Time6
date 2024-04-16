#ifndef __REGISTRADORES_H__
#define __REGISTRADORES_H__

#include "memoria_instruc.h"
#include "decode.h"
#include "ULA.h"
#include "bibliotecas.h"


void Registradores (int **regs, int valor, char posicao[], int opcao);
void escritaRegistradores(int **regs, int valor, char posicao[]);

#endif