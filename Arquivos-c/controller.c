#include"controller.h"

int controller(int op){
    int numeroLinhas, i, contador;
    numeroLinhas=memInstruc();
    switch (op)
    {
    case 1:
        //Run
        __DECODE_H__;
        __MEMORIA_INSTRUC_H__;
        type_instruc *traduzido;
        for (i = 0; i < numeroLinhas; i++)
        {
            contador = get_PC();   
            if ((strcmp(traduzido[contador].opcode,"0000")))
            {
                ULA(contador);
            }
            
            PC_H(1);
        }
        break;
    case 2:
        //Run by Step
        if (numeroLinhas < get_PC()){
            PC_H(1);
        }
        break;
    case 3:
        //Return Run by Step
        if (numeroLinhas <= get_PC()){
            PC_H(2);
        }
        break;
    default:
        break;
    }
}
