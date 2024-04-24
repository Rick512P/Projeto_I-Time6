#ifndef Estado_H
#define Estado_H 

#include "memoria_instruc.h"
#include "parser.h"
#include "Memoria_Dados.h"
#include "bibliotecas.h"


int salva_estado(int program_counter, MemoriaDados **md, int **regs, int *Last_State);
int retorna_estado(MemoriaDados **md, int **regs);
void DeleteLast_State(int Last_State);


#endif