#ifndef __MEMORIA_INSTRUC_H__
#define __MEMORIA_INSTRUC_H__

#include "bibliotecas.h"

typedef struct{
    char instruc[17];

}instrucao;

#include "../Arquivos-h/parser.h" //inclui arquivos de cabeçalho que estao no mesmo diretorio deste arquivo .c
#include "../Arquivos-h/registradores.h"
#include "../Arquivos-h/ULA.h"
#include "../Arquivos-h/decode.h"

type_instruc* memInstruc(int contador, int opcao, instrucao *inst, int *tamLinhas);


#endif