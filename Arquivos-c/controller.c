
#include "../Arquivos-h/controller.h"

int controller(int op, instrucao **memoriaInst, int tamLinhas, int **regs, MemoriaDados **md, int *program_counter, Assembly **AssemblyInst, type_instruc **instrucoesDecodificadas, int *Last_State){
    int numeroLinhas, jump, RD, RT, i, address, PC;
    char rd[4];

    for(int j=0;j<tamLinhas;j++){
        (*instrucoesDecodificadas)[j] = memInstruc(j, memoriaInst, &tamLinhas);
    }
    
    switch (op)
    {
    case 1:

        for ((*program_counter) = 0; (*program_counter) < tamLinhas; increment_PC(program_counter, 1))
        {   
            if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"0000")) == 0) // ADD/SUB/OR/AND
            {
                RD = ULA(instrucoesDecodificadas, program_counter, md, regs);
                escritaRegistradores(regs, RD, (*instrucoesDecodificadas)[*program_counter].rd);
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
            (*Last_State)++;
            PC = *program_counter;
            salva_estado(PC, md, regs, Last_State);
        }
        break;

    case 2:
        //Run by Step
            printf("Instrucao %d", *program_counter);
            increment_PC(program_counter, 0);  //FUNÇÃO QUE ESTA NO PC.C 
            
            if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"0000")) == 0)
            {
                
                RD = ULA(instrucoesDecodificadas, program_counter, md, regs);
                escritaRegistradores(regs, RD, (*instrucoesDecodificadas)[*program_counter].rd);
                //escrevePasso();
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"0100")) == 0){
                
                RT = ULA(instrucoesDecodificadas, program_counter, md, regs);
                escritaRegistradores(regs, RT, (*instrucoesDecodificadas)[*program_counter].rt);
                //escrevePasso();
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"1011")) == 0){

                RT = ULA(instrucoesDecodificadas, program_counter, md, regs);
                escritaRegistradores(regs, RT, (*instrucoesDecodificadas)[*program_counter].rt);
                //escrevePasso();
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"1111")) == 0){

                address = ULA(instrucoesDecodificadas, program_counter, md, regs);
                //escrevePasso();
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"0010")) == 0){
                (*program_counter) = ULA(instrucoesDecodificadas, program_counter, md, regs);
               // escrevePasso();
            }
            else if ((strcmp((*instrucoesDecodificadas)[*program_counter].opcode,"1000")) == 0){ //beq
                (*program_counter) = ULA(instrucoesDecodificadas, program_counter, md, regs);
                //escrevePasso();
            }
            *Last_State++;
            increment_PC(program_counter, 1);
            PC = *program_counter;
            salva_estado(PC, md, regs, Last_State);
        break;
    case 3:
        //Return Run by Step
            if (program_counter <= 0){
                printf("Estamos no início do código!");
            }
            else{
                //program_counter = retorna_estado(*Last_State--);
            }
        break;

    }

    return 0;
}
