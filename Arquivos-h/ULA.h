#ifndef ULA_H
#define ULA_H
#define BITS 17

#include "decode.h"
#include "memoria_instruc.h"
#include "parser.h"
#include "Memoria_Dados.h"
#include "bibliotecas.h"
#include "bin_to_decimal.h"
#include "decimal_to_bin.h"


int ULA(type_instruc **instrucoesDecodificadas, int *contador, MemoriaDados **md, int **regs);
/*void bin_dec(char Source[], char Target[], char Dest[], int *rs, int *rt, int *rd);*/
int bin_to_dec(const char *bin);
void bin_dec(const char Source[], const char Target[], const char Dest[], int *rs, int *rt, int *rd);
void dec_to_bin(int decimal, char *binaryPtr);
void AND(char Source[], char Target[], char *Dest);
void OR(char Source[], char Target[], char *Dest);

#endif

