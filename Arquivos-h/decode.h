#ifndef __DECODE_H__
#define __DECODE_H__

#include "memoria_instruc.h"
#include "bibliotecas.h"


typedef struct{
    char opcode[5];

    //TIPO R OU I
    char rs [4];
    char rt [4];

    //TIPO R
    char rd [4];
    char funct [4];

    //TIPO I
    char imm [6];

    //TIPO J
    char addr[8];

}type_instruc;

type_instruc decoder(instrucao *inst, int i);

#endif