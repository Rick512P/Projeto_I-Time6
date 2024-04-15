#ifndef __REGISTRADORES_H__
#define __REGISTRADORES_H__

#include "memoria_instruc.h"
#include "decode.h"
#include "ULA.h"
#include "bibliotecas.h"


typedef struct{
    int reg0;
    int reg1;
    int reg2;
    int reg3;
    int reg4;
    int reg5;
    int reg6;
    int reg7;
}registradores;

void Registradores (registradores *regs, int valor, char posicao[], int opcao);
int escritaRegistradores(registradores *regs, int valor, char posicao[]);

#endif