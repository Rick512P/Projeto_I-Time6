#include"controller.h"

int controller(int op){
    __DECODE_H__;
    __MEMORIA_INSTRUC_H__;
    ULA_H

    int numeroLinhas, i, address, program_counter = 0;
    char rd[4];
    type_instruc *traduzido;
    
    numeroLinhas=memInstruc();

    switch (op)
    {
    case 1:
        //Run   
        for (i = 0; i < numeroLinhas; i++)
        {
            program_counter = increment_PC(program_counter, 0);   
            if ((strcmp(traduzido[program_counter].opcode,"0000")))
            {
                strcpy(rd,ULA(program_counter));
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(traduzido[program_counter].opcode,"0100"))){
                strcpy(rd,ULA(program_counter));
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(traduzido[program_counter].opcode,"1011"))){
                //enviar address para Memória de Dados, juntamente do valor a ser posto
                address = ULA(program_counter);
            }
            else if ((strcmp(traduzido[program_counter].opcode,"1111"))){
                //enviar address para Memória de Dados, e receber como retorno o valor presente na célula
                address = ULA(program_counter);
            }
            else if ((strcmp(traduzido[program_counter].opcode,"0010"))){
                program_counter = ULA(program_counter);
            }
            increment_PC(program_counter, 1);
        }
        break;
    case 2:
        //Run by Step
        if (numeroLinhas < get_PC()){
            program_counter = increment_PC(program_counter, 0);   
            if ((strcmp(traduzido[program_counter].opcode,"0000")))
            {
                strcpy(rd,ULA(program_counter));
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(traduzido[program_counter].opcode,"0100"))){
                strcpy(rd,ULA(program_counter));
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(traduzido[program_counter].opcode,"1011"))){
                //enviar address para Memória de Dados, juntamente do valor a ser posto
                address = ULA(program_counter);
            }
            else if ((strcmp(traduzido[program_counter].opcode,"1111"))){
                //enviar address para Memória de Dados, e receber como retorno o valor presente na célula
                address = ULA(program_counter);
            }
            else if ((strcmp(traduzido[program_counter].opcode,"0010"))){
                program_counter = ULA(program_counter);
            }
            increment_PC(program_counter, 1);
        }
        main();
        break;
    case 3:
        //Return Run by Step
        if (numeroLinhas <= get_PC()){
            program_counter = increment_PC(program_counter, 0);   
            if ((strcmp(traduzido[program_counter].opcode,"0000")))
            {
                strcpy(rd,ULA(program_counter));
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(traduzido[program_counter].opcode,"0100"))){
                strcpy(rd,ULA(program_counter));
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(traduzido[program_counter].opcode,"1011"))){
                //enviar address para Memória de Dados, juntamente do valor a ser posto
                address = ULA(program_counter);
            }
            else if ((strcmp(traduzido[program_counter].opcode,"1111"))){
                //enviar address para Memória de Dados, e receber como retorno o valor presente na célula
                address = ULA(program_counter);
            }
            else if ((strcmp(traduzido[program_counter].opcode,"0010"))){
                program_counter = ULA(program_counter);
            }
            increment_PC(program_counter, 2);
        }
        main();
        break;
    default:
        break;
    }
}
