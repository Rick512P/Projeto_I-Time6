#include "../Arquivos-h/PC.h"

int program_counter = 0;

// Função para incrementar o contador de programa
void increment_PC() {
    program_counter++;
}

// Função para retornar o valor atual do contador de programa
int get_PC() {
    return program_counter;
}
