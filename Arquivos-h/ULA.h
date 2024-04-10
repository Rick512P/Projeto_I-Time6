#ifndef ULA_H
#define ULA_H
#define BITS 16 
#include "memoria_instruc.h"
#include "decode.h"
#include "parser.h"

void ULA(type_instruc *traduzido, int contador);
void bin_dec(char Source[], char Target[], char Dest[], int *rs, int *rt, int *rd);
char* dec_to_bin(int decimal, char binary[]);
void AND(char Source[], char Target[], char Dest[]);
void OR(char Source[], char Target[], char Dest[]);
void lw_sw_offset(char Source[], char Target[], char Dest[], int offset);

#endif
