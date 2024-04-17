#ifndef __ASSEMBLY_H__
#define __ASSEMBLY_H__

#include "bibliotecas.h"

void AsmCopy(type_instruc *traduzido, Assembly **A, int tamLinhas);
int SaveASM(Assembly *A, int tamLinhas);
void imprimirASM(Assembly *A, int tamLinhas);
    
#endif
