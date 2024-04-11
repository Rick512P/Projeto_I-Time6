#include "../Arquivos-h/PC.h"

// Função para incrementar o contador de programa
int increment_PC(int op, int program_counter) {
    switch (op)
    {
     case 1:
        program_counter++;
    case 2:
        program_counter--;
    default:
        break;
    }
    return program_counter;
}