#include "../Arquivos-h/PC.h"

// Função para incrementar o contador de programa
int increment_PC(int *program_counter, int op) {//PROGRAM_COUNTER COMO PONTEIRO POIS ELE RECEBERÁ O ENDEREÇO DE PROGRAM_COUNTER
    switch (op)
    {
     case 1:
        *program_counter++;
    case 2:
        *program_counter--;
    default:
        break;
    }
    return (*program_counter); //retorna para o controller
    //TEM Q TER PARENTESES SE NAO, VALOR NÃO ATUALIZA :/
}