
#include "../Arquivos-h/controller.h"

int controller(int op, instrucao inst, int tamLinhas, registradores *regs, MemoriaDados *md){
    __DECODE_H__;
    __MEMORIA_INSTRUC_H__;
    ULA_H

    int numeroLinhas, RD, RT, i, address, program_counter = 0;

    char rd[4];

    type_instruc *instrucoesDecodificadas;
    
    instrucoesDecodificadas = memInstruc(program_counter, 3, &inst, &tamLinhas); //COMEÇA COM 0

    if (instrucoesDecodificadas == NULL) {
        fprintf(stderr, "Falha ao obter instruções decodificadas.\n");
        return -1;
    }

    switch (op)
    {
    case 1:
        //Run   
        for (i = 0; i < tamLinhas; i++)
        {
            program_counter = increment_PC(&program_counter, 0);  //FUNÇÃO QUE ESTA NO PC.C 
            if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0000")) == 0)
            {
                /*strcpy(rd,ULA(instrucoesDecodificadas, program_counter)); ACREDITO QUE O RD PARA O REG POSSA SER UM INTEIRO QUE 
                RECEBE O RETORNO DA FUNÇÃO ULA, COM ELA RETORNANDO OS RD'S INTEIROS*/
                RD = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RD, instrucoesDecodificadas[program_counter].rd, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0100")) == 0){
                /*strcpy(rd,ULA(instrucoesDecodificadas, program_counter));*/
                RT = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RT, instrucoesDecodificadas[program_counter].rd, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"1011")) == 0){
                //enviar address para Memória de Dados, juntamente do valor a ser posto
                RT = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RT, instrucoesDecodificadas[program_counter].rd, 0);
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"1111")) == 0){
                //enviar address para Memória de Dados, e receber como retorno o valor presente na célula
                address = ULA(instrucoesDecodificadas, program_counter, md);
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0010")) == 0){
                program_counter = ULA(instrucoesDecodificadas, program_counter, md);
            }
            increment_PC(&program_counter, 1); //MANDA O ENDEREÇO DE PROGRAM_COUNTER PARA QUE ELE SEJA ATUALIZADO
            //EM TODO O PROGRAMA
        }
        break;
    case 2:
        //Run by Step
       // if (tamLinhas){ ARRUMAR IF
            program_counter = increment_PC(&program_counter, 0);  //FUNÇÃO QUE ESTA NO PC.C 
            if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0000")) == 0)
            {
                /*strcpy(rd,ULA(instrucoesDecodificadas, program_counter)); ACREDITO QUE O RD PARA O REG POSSA SER UM INTEIRO QUE 
                RECEBE O RETORNO DA FUNÇÃO ULA, COM ELA RETORNANDO OS RD'S INTEIROS*/
                RD = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RD, instrucoesDecodificadas[program_counter].rd, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0100")) == 0){
                /*strcpy(rd,ULA(instrucoesDecodificadas, program_counter));*/
                RT = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RT, instrucoesDecodificadas[program_counter].rd, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"1011")) == 0){
                //enviar address para Memória de Dados, juntamente do valor a ser posto
                RT = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RT, instrucoesDecodificadas[program_counter].rd, 0);
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"1111")) == 0){
                //enviar address para Memória de Dados, e receber como retorno o valor presente na célula
                address = ULA(instrucoesDecodificadas, program_counter, md);
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0010")) == 0){
                program_counter = ULA(instrucoesDecodificadas, program_counter, md);
            }
            increment_PC(&program_counter, 1); //MANDA O ENDEREÇO DE PROGRAM_COUNTER PARA QUE ELE SEJA ATUALIZADO
            //EM TODO O PROGRAMA
      //  }
        break;*/
    case 3: //ARRUMAR GET_PC()
        //Return Run by Step
        //if (tamLinhas <= get_PC()){arrumar if
            program_counter = increment_PC(&program_counter, 0);  //FUNÇÃO QUE ESTA NO PC.C 
            if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0000")) == 0)
            {
                /*strcpy(rd,ULA(instrucoesDecodificadas, program_counter)); ACREDITO QUE O RD PARA O REG POSSA SER UM INTEIRO QUE 
                RECEBE O RETORNO DA FUNÇÃO ULA, COM ELA RETORNANDO OS RD'S INTEIROS*/
                RD = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RD, instrucoesDecodificadas[program_counter].rd, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0100")) == 0){
                /*strcpy(rd,ULA(instrucoesDecodificadas, program_counter));*/
                RT = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RT, instrucoesDecodificadas[program_counter].rd, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"1011")) == 0){
                //enviar address para Memória de Dados, juntamente do valor a ser posto
                RT = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RT, instrucoesDecodificadas[program_counter].rd, 0);
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"1111")) == 0){
                //enviar address para Memória de Dados, e receber como retorno o valor presente na célula
                address = ULA(instrucoesDecodificadas, program_counter, md);
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0010")) == 0){
                program_counter = ULA(instrucoesDecodificadas, program_counter, md);
            }
            increment_PC(&program_counter, 2); //MANDA O ENDEREÇO DE PROGRAM_COUNTER PARA QUE ELE SEJA ATUALIZADO
            //EM TODO O PROGRAMA
       // }
        break;

    case 4: //caso 4, ele ira printar o tradu
        imprimeSimulador(tamLinhas, *instrucoesDecodificadas, &inst);
        break;

    default:
        break;
    }

    if (instrucoesDecodificadas) {
        free(instrucoesDecodificadas);
        instrucoesDecodificadas = NULL; // Evita o uso de ponteiro pendente
    }

    return 0;
}
