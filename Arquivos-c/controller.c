
#include "../Arquivos-h/controller.h"

int controller(int op, instrucao **memoriaInst, int tamLinhas, int **regs, MemoriaDados **md, int *program_counter, Assembly **AssemblyInst){
    //ESTA FALTANDO A INSTRUÇÃO 1000 (BEQ)
    int numeroLinhas, jump, RD, RT, i, address;

    char rd[4];

    type_instruc *instrucoesDecodificadas;
    instrucoesDecodificadas = (type_instruc*)malloc(tamLinhas * sizeof(type_instruc));

    if (instrucoesDecodificadas == NULL) {
        fprintf(stderr, "Falha ao obter instruções decodificadas.\n");
        return -1;
    }
    
    switch (op)
    {
    case 1:

        for ((*program_counter) = 0; (*program_counter) < tamLinhas; increment_PC(program_counter, 1))
        {   
            instrucoesDecodificadas = memInstruc(program_counter, 0, memoriaInst, &tamLinhas);
            if ((strcmp(instrucoesDecodificadas[*program_counter].opcode,"0000")) == 0)
            {
                RD = ULA(instrucoesDecodificadas, program_counter, md, regs);
                Registradores(regs, RD, instrucoesDecodificadas[*program_counter].rd, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[*program_counter].opcode,"0100")) == 0){ //ADDI
                RT = ULA(instrucoesDecodificadas, program_counter, md, regs); 
                Registradores(regs, RT, instrucoesDecodificadas[*program_counter].rt, 0);
                //enviar rt para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[*program_counter].opcode,"1011")) == 0){ //ARRUMAR 1011
                //enviar address para Memória de Dados, juntamente do valor a ser posto

                RT = ULA(instrucoesDecodificadas, program_counter, md, regs);
                Registradores(regs, RT, instrucoesDecodificadas[*program_counter].rt, 0);
            }
            else if ((strcmp(instrucoesDecodificadas[*program_counter].opcode,"1111")) == 0){ //ARRUMAR 1111
                //enviar address para Memória de Dados, e receber como retorno o valor presente na célula

                address = ULA(instrucoesDecodificadas, program_counter, md, regs);
            }
            else if (strcmp(instrucoesDecodificadas[*program_counter].opcode,"1000") == 0)
            {
                //if ( $rs == $rt ) then PC = PC + imm * 2 
                char Target[4];
                char Source[4];
                char Immediate[7];
                int immediate, rs, rt;
                strcpy(Target, instrucoesDecodificadas[*program_counter].rt);
                strcpy(Source, instrucoesDecodificadas[*program_counter].rs);
                strcpy(Immediate, instrucoesDecodificadas[*program_counter].imm);
                bin_dec(Source, Target, Immediate, &rs, &rt, &immediate);
                if (rs == rt) {
                    printf("Branching to address: %s\n", instrucoesDecodificadas[*program_counter].imm);
                    // Implementação do salto para o endereço especificado
                    bin_dec(Source, Target, instrucoesDecodificadas[*program_counter].imm, &rs, &rt, &immediate);
                    *program_counter = *program_counter + immediate * 2; // Atualiza o contador de programa com o endereço especificado
                    printf("Jumped to address: %d\n", *program_counter); // Exibe o novo endereço
                } else {
                    printf("Branch not taken.\n");
                }
            }            
            else if ((strcmp(instrucoesDecodificadas[*program_counter].opcode,"0010")) == 0){

                jump = ULA(instrucoesDecodificadas, program_counter, md, regs);
                (*program_counter)+=jump;
            }
                            //MANDA O ENDEREÇO DE PROGRAM_COUNTER PARA QUE ELE SEJA ATUALIZADO
                            //EM TODO O PROGRAMA
        }
        break;

    case 2:
        //Run by Step
       // if (tamLinhas){ ARRUMAR IF
            increment_PC(program_counter, 0);  //FUNÇÃO QUE ESTA NO PC.C 
            instrucoesDecodificadas = memInstruc(program_counter, 0, memoriaInst, &tamLinhas);
            if ((strcmp(instrucoesDecodificadas[*program_counter].opcode,"0000")) == 0)
            {
                
                RD = ULA(instrucoesDecodificadas, program_counter, md, regs);
                Registradores(regs, RD, instrucoesDecodificadas[*program_counter].rd, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[*program_counter].opcode,"0100")) == 0){
                
                RT = ULA(instrucoesDecodificadas, program_counter, md, regs);
                printf("RT: %d", RT);
                Registradores(regs, RT, instrucoesDecodificadas[*program_counter].rt, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[*program_counter].opcode,"1011")) == 0){
                //enviar address para Memória de Dados, juntamente do valor a ser posto
                RT = ULA(instrucoesDecodificadas, program_counter, md, regs);
                Registradores(regs, RT, instrucoesDecodificadas[*program_counter].rt, 0);
            }
            else if ((strcmp(instrucoesDecodificadas[*program_counter].opcode,"1111")) == 0){
                //enviar address para Memória de Dados, e receber como retorno o valor presente na célula
                address = ULA(instrucoesDecodificadas, program_counter, md, regs);
            }
            else if ((strcmp(instrucoesDecodificadas[*program_counter].opcode,"0010")) == 0){
                (*program_counter) = ULA(instrucoesDecodificadas, program_counter, md, regs);
            }
            increment_PC(program_counter, 1); //MANDA O ENDEREÇO DE PROGRAM_COUNTER PARA QUE ELE SEJA ATUALIZADO
            //EM TODO O PROGRAMA
      //  }
        break;
    case 3:
        //Return Run by Step
        //if (tamLinhas <= get_PC()){arrumar if
            increment_PC(program_counter, 0);  //FUNÇÃO QUE ESTA NO PC.C 
            if ((strcmp(instrucoesDecodificadas[*program_counter].opcode,"0000")) == 0) //TIPO R
            {
                
                RD = ULA(instrucoesDecodificadas, program_counter, md, regs);
                Registradores(regs, RD, instrucoesDecodificadas[*program_counter].rd, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[*program_counter].opcode,"0100")) == 0){ //TIPO I
                
                RT = ULA(instrucoesDecodificadas, program_counter, md, regs);
                Registradores(regs, RT, instrucoesDecodificadas[*program_counter].rt, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[*program_counter].opcode,"1011")) == 0){ //TIPO I
                //enviar address para Memória de Dados, juntamente do valor a ser posto
                RT = ULA(instrucoesDecodificadas, program_counter, md, regs);
                Registradores(regs, RT, instrucoesDecodificadas[*program_counter].rt, 0);
            }
            else if ((strcmp(instrucoesDecodificadas[*program_counter].opcode,"1111")) == 0){ //TIPO I
                //enviar address para Memória de Dados, e receber como retorno o valor presente na célula
                address = ULA(instrucoesDecodificadas, program_counter, md, regs);
            }
            else if ((strcmp(instrucoesDecodificadas[*program_counter].opcode,"0010")) == 0){ //TIPO J
                (*program_counter) = ULA(instrucoesDecodificadas, program_counter, md, regs);
            }
            increment_PC(program_counter, 2); //MANDA O ENDEREÇO DE PROGRAM_COUNTER PARA QUE ELE SEJA ATUALIZADO
            //EM TODO O PROGRAMA
       // }
        break;

    case 4: //caso 4, ele ira printar as intrucoes decodificadas
        imprimeSimulador(tamLinhas, instrucoesDecodificadas, memoriaInst, regs);
        break;

    case 5:
        AsmCopy(instrucoesDecodificadas, AssemblyInst, tamLinhas);
        break;
    }

    if (instrucoesDecodificadas) {
        free(instrucoesDecodificadas);
        instrucoesDecodificadas = NULL; // Evita o uso de ponteiro pendente
    }

    return 0;
}
