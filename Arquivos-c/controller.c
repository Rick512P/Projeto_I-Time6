
#include "../Arquivos.h/controller.h"

int controller(int op){
    __DECODE_H__;
    __MEMORIA_INSTRUC_H__;
    ULA_H

    int numeroLinhas, RD, i, address, program_counter = 0;

    char rd[4];

    type_instruc *tradu;
    
    tradu = memInstruc(program_counter, 2); //COMEÇA COM 0
    numeroLinhas = sizeof(tradu); //sizeof nao vai pegar as linhas de tradu, apenas o tamanho em bytes

    switch (op)
    {
    case 1:
        //Run   
        for (i = 0; i < numeroLinhas; i++)
        {
            program_counter = increment_PC(program_counter, 0);  //FUNÇÃO QUE ESTA NO PC.C 
            if ((strcmp(tradu[program_counter].opcode,"0000")))
            {
                /*strcpy(rd,ULA(tradu, program_counter)); ACREDITO QUE O RD PARA O REG POSSA SER UM INTEIRO QUE 
                RECEBE O RETORNO DA FUNÇÃO ULA, COM ELA RETORNANDO OS RD'S INTEIROS*/
                RD = ULA(tradu, program_counter);
                Registradores(RD, tradu[program_counter].posicao, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(tradu[program_counter].opcode,"0100"))){
                /*strcpy(rd,ULA(tradu, program_counter));*/
                RD = ULA(tradu, program_counter);
                Registradores(RD, tradu[program_counter].posicao, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(tradu[program_counter].opcode,"1011"))){
                //enviar address para Memória de Dados, juntamente do valor a ser posto
                address = ULA(tradu, program_counter);
            }
            else if ((strcmp(tradu[program_counter].opcode,"1111"))){
                //enviar address para Memória de Dados, e receber como retorno o valor presente na célula
                address = ULA(tradu, program_counter);
            }
            else if ((strcmp(tradu[program_counter].opcode,"0010"))){
                program_counter = ULA(tradu, program_counter);
            }
            increment_PC(&program_counter, 1); //MANDA O ENDEREÇO DE PROGRAM_COUNTER PARA QUE ELE SEJA ATUALIZADO
            //EM TODO O PROGRAMA
        }
        break;
    case 2:
        //Run by Step
        if (numeroLinhas < get_PC()){
            program_counter = increment_PC(program_counter, 0);   
            if ((strcmp(tradu[program_counter].opcode,"0000")))
            {
                /*strcpy(rd,ULA(tradu, program_counter));*/
                RD = ULA(tradu, program_counter);
                Registradores(RD, tradu[program_counter].posicao, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(tradu[program_counter].opcode,"0100"))){
                /*strcpy(rd,ULA(tradu, program_counter));*/
                RD = ULA(tradu, program_counter);
                Registradores(RD, tradu[program_counter].posicao, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(tradu[program_counter].opcode,"1011"))){
                //enviar address para Memória de Dados, juntamente do valor a ser posto
                address = ULA(tradu, program_counter);
            }
            else if ((strcmp(tradu[program_counter].opcode,"1111"))){
                //enviar address para Memória de Dados, e receber como retorno o valor presente na célula
                address = ULA(tradu, program_counter);
            }
            else if ((strcmp(tradu[program_counter].opcode,"0010"))){
                program_counter = ULA(tradu, program_counter);
            }
            increment_PC(&program_counter, 1);
        }
        break;
    case 3:
        //Return Run by Step
        if (numeroLinhas <= get_PC()){
            program_counter = increment_PC(program_counter, 0);   
            if ((strcmp(tradu[program_counter].opcode,"0000")))
            {
                /*strcpy(rd,ULA(tradu, program_counter));*/
                RD = ULA(tradu, program_counter);
                Registradores(RD, tradu[program_counter].posicao, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(tradu[program_counter].opcode,"0100"))){
                /*strcpy(rd,ULA(tradu, program_counter));*/
                RD = ULA(tradu, program_counter);
                Registradores(RD, tradu[program_counter].posicao, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(tradu[program_counter].opcode,"1011"))){
                //enviar address para Memória de Dados, juntamente do valor a ser posto
                address = ULA(tradu, program_counter);
            }
            else if ((strcmp(tradu[program_counter].opcode,"1111"))){
                //enviar address para Memória de Dados, e receber como retorno o valor presente na célula
                address = ULA(tradu, program_counter);
            }
            else if ((strcmp(tradu[program_counter].opcode,"0010"))){
                program_counter = ULA(tradu, program_counter);
            }
            increment_PC(&program_counter, 2);
        }
        break;
    default:
        break;
    }
    return 0;
}
