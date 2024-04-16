
#include "../Arquivos-h/controller.h"

int controller(int op, instrucao **inst, int tamLinhas, int **regs, MemoriaDados *md){
    //ESTA FALTANDO A INSTRUÇÃO 1000 (BEQ)

    int numeroLinhas, RD, RT, i, address, program_counter = 0;

    char rd[4];

    type_instruc *instrucoesDecodificadas;
    
    instrucoesDecodificadas = memInstruc(program_counter, 3, inst, &tamLinhas); //COMEÇA COM 0

    if (instrucoesDecodificadas == NULL) {
        fprintf(stderr, "Falha ao obter instruções decodificadas.\n");
        return -1;
    }
    
    switch (op)
    {
    case 1:

        for (i = 0; i < tamLinhas; i++)
        {
            printf("\nOPCODE da instrucao: %s", instrucoesDecodificadas[program_counter].opcode);
            if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0000")) == 0)
            {
                printf("\nposicao do program_counter: %d em 0000", program_counter);
                RD = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RD, instrucoesDecodificadas[program_counter].rd, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0100")) == 0){
                printf("\nposicao do program_counter: %d em 0100", program_counter);
                RT = ULA(instrucoesDecodificadas, program_counter, md); 
                printf("\nValor de RT: %d", RT);
                printf("\nposicao do program_counter: %d", program_counter);
                Registradores(regs, RT, instrucoesDecodificadas[program_counter].rt, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"1011")) == 0){ //ARRUMAR 1011
                //enviar address para Memória de Dados, juntamente do valor a ser posto
                printf("\nposicao do program_counter: %d em 1011", program_counter);
                RT = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RT, instrucoesDecodificadas[program_counter].rt, 0);
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"1111")) == 0){ //ARRUMAR 1111
                //enviar address para Memória de Dados, e receber como retorno o valor presente na célula
                printf("\nposicao do program_counter: %d em 1111", program_counter);
                address = ULA(instrucoesDecodificadas, program_counter, md);
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0010")) == 0){
                printf("\nposicao do program_counter: %d em 0010", program_counter);
                program_counter = ULA(instrucoesDecodificadas, program_counter, md);
                
            }
            printf("\nprogram_counter antes: %d", program_counter);
            increment_PC(&program_counter, 1); //MANDA O ENDEREÇO DE PROGRAM_COUNTER PARA QUE ELE SEJA ATUALIZADO
            //EM TODO O PROGRAMA
            printf("\nprogram_counter depois: %d\n\n", program_counter);
        }
        break;
    case 2:
        //Run by Step
       // if (tamLinhas){ ARRUMAR IF
            increment_PC(&program_counter, 0);  //FUNÇÃO QUE ESTA NO PC.C 
            if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0000")) == 0)
            {
                
                RD = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RD, instrucoesDecodificadas[program_counter].rd, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0100")) == 0){
                
                RT = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RT, instrucoesDecodificadas[program_counter].rt, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"1011")) == 0){
                //enviar address para Memória de Dados, juntamente do valor a ser posto
                RT = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RT, instrucoesDecodificadas[program_counter].rt, 0);
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
        break;
    case 3:
        //Return Run by Step
        //if (tamLinhas <= get_PC()){arrumar if
            increment_PC(&program_counter, 0);  //FUNÇÃO QUE ESTA NO PC.C 
            if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0000")) == 0) //TIPO R
            {
                
                RD = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RD, instrucoesDecodificadas[program_counter].rd, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0100")) == 0){ //TIPO I
                
                RT = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RT, instrucoesDecodificadas[program_counter].rt, 0);
                //enviar rd para Banco de Registradores
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"1011")) == 0){ //TIPO I
                //enviar address para Memória de Dados, juntamente do valor a ser posto
                RT = ULA(instrucoesDecodificadas, program_counter, md);
                Registradores(regs, RT, instrucoesDecodificadas[program_counter].rt, 0);
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"1111")) == 0){ //TIPO I
                //enviar address para Memória de Dados, e receber como retorno o valor presente na célula
                address = ULA(instrucoesDecodificadas, program_counter, md);
            }
            else if ((strcmp(instrucoesDecodificadas[program_counter].opcode,"0010")) == 0){ //TIPO J
                program_counter = ULA(instrucoesDecodificadas, program_counter, md);
            }
            increment_PC(&program_counter, 2); //MANDA O ENDEREÇO DE PROGRAM_COUNTER PARA QUE ELE SEJA ATUALIZADO
            //EM TODO O PROGRAMA
       // }
        break;

    case 4: //caso 4, ele ira printar as intrucoes decodificadas
        imprimeSimulador(tamLinhas, instrucoesDecodificadas, inst, regs);
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
