
#include "../Arquivos-h/controller.h"

int controller(int op, instrucao **memoriaInst, int tamLinhas, int **regs, MemoriaDados **md, int *program_counter, Assembly **AssemblyInst, type_instruc **instrucoesDecodificadas){
    //ESTA FALTANDO A INSTRUÇÃO 1000 (BEQ)
    int numeroLinhas, jump, RD, RT, i, address;

    char rd[4];
    
    switch (op)
    {
    case 1:

        for ((*program_counter) = 0; (*program_counter) < tamLinhas; increment_PC(program_counter, 1))
        {   
            (*instrucoesDecodificadas)[*program_counter] = memInstruc(program_counter, memoriaInst, &tamLinhas);
            if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"0000")) == 0)
            {
                RD = ULA(instrucoesDecodificadas, program_counter, md, regs);
                escritaRegistradores(regs, RD, (*instrucoesDecodificadas)[*program_counter].rd);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"0100")) == 0){ //ADDI
                RT = ULA(instrucoesDecodificadas, program_counter, md, regs); 
                escritaRegistradores(regs, RT, (*instrucoesDecodificadas)[*program_counter].rt);
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"1011")) == 0){  //LW
                RT = ULA(instrucoesDecodificadas, program_counter, md, regs); 
                escritaRegistradores(regs, RT, (*instrucoesDecodificadas)[*program_counter].rt);
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"1111")) == 0){ //SW
                ULA(instrucoesDecodificadas, program_counter, md, regs); 
            }
            else if (strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"1000") == 0) //BEQ
            {
                (*program_counter) = ULA(instrucoesDecodificadas, program_counter, md, regs);
            }            
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"0010")) == 0){ //JUMP

                jump = ULA(instrucoesDecodificadas, program_counter, md, regs);
                (*program_counter)+=jump;
            }
                            //MANDA O ENDEREÇO DE PROGRAM_COUNTER PARA QUE ELE SEJA ATUALIZADO
                            //EM TODO O PROGRAMA
        }
        break;

    case 2:
        //Run by Step
            printf("Instrucao %d", *program_counter);
            increment_PC(program_counter, 0);  //FUNÇÃO QUE ESTA NO PC.C 
            (*instrucoesDecodificadas)[*program_counter] = memInstruc(program_counter, memoriaInst, &tamLinhas);
            if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"0000")) == 0)
            {
                
                RD = ULA(instrucoesDecodificadas, program_counter, md, regs);
                escritaRegistradores(regs, RD, (*instrucoesDecodificadas)[*program_counter].rd);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"0100")) == 0){
                
                RT = ULA(instrucoesDecodificadas, program_counter, md, regs);
                escritaRegistradores(regs, RT, (*instrucoesDecodificadas)[*program_counter].rt);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"1011")) == 0){
                //enviar address para Memória de Dados, juntamente do valor a ser posto
                RT = ULA(instrucoesDecodificadas, program_counter, md, regs);
                escritaRegistradores(regs, RT, (*instrucoesDecodificadas)[*program_counter].rt);
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"1111")) == 0){
                //enviar address para Memória de Dados, e receber como retorno o valor presente na célula
                address = ULA(instrucoesDecodificadas, program_counter, md, regs);
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"0010")) == 0){
                (*program_counter) = ULA(instrucoesDecodificadas, program_counter, md, regs);
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"1000")) == 0){ //beq
                (*program_counter) = ULA(instrucoesDecodificadas, program_counter, md, regs);

            }
            increment_PC(program_counter, 1); //MANDA O ENDEREÇO DE PROGRAM_COUNTER PARA QUE ELE SEJA ATUALIZADO
            //EM TODO O PROGRAMA
      //  }
        break;
    case 3:
        //Return Run by Step
            increment_PC(program_counter, 2); //MANDA O ENDEREÇO DE PROGRAM_COUNTER PARA QUE ELE SEJA ATUALIZADO
            //EM TODO O PROGRAMA
            if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"0000")) == 0) //TIPO R
            {
                
                RD = ULA(instrucoesDecodificadas, program_counter, md, regs);
                escritaRegistradores(regs, RD, (*instrucoesDecodificadas)[*program_counter].rd);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"0100")) == 0){ //TIPO I
                
                RT = ULA(instrucoesDecodificadas, program_counter, md, regs);
                escritaRegistradores(regs, RT, (*instrucoesDecodificadas)[*program_counter].rt);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"1011")) == 0){ //TIPO I
                //enviar address para Memória de Dados, juntamente do valor a ser posto
                RT = ULA(instrucoesDecodificadas, program_counter, md, regs);
                escritaRegistradores(regs, RT, (*instrucoesDecodificadas)[*program_counter].rt);
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"1111")) == 0){ //TIPO I
                //enviar address para Memória de Dados, e receber como retorno o valor presente na célula
                address = ULA(instrucoesDecodificadas, program_counter, md, regs);
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"0010")) == 0){ //TIPO J
                (*program_counter) = ULA(instrucoesDecodificadas, program_counter, md, regs);
            }
            
        break;

    }

    return 0;
}
