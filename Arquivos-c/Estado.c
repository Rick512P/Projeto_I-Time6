#include "../Arquivos-h/Estado.h"

int retorna_estado(MemoriaDados **md, int **regs){
    FILE *data;
    int PC=0;
    char *nome_arquivo = "Log/log.dat";

    if ((data = fopen(nome_arquivo, "rb")) == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    // Busca o final do arquivo
    fseek(data, -sizeof(int), SEEK_END);

    // Lê o estado
    fread(&PC, sizeof(int), 1, data);

    // Retrocede para ler o program_counter
    fseek(data, -sizeof(int), SEEK_CUR);
    fscanf(data, "%d", &PC);

    // Retrocede para ler a MemoriaDados
    fseek(data, -sizeof(MemoriaDados), SEEK_CUR);
    fread(*md, sizeof(MemoriaDados), 1, data);

    // Retrocede para ler os registradores
    // Supondo que regs seja uma matriz de inteiros 2D
    fseek(data, -sizeof(int) * 64, SEEK_CUR);
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            fread(&regs[i][j], sizeof(int), 1, data);
        }
    }

    fclose(data);

    return PC;
}

int salva_estado(int PC, MemoriaDados **md, int **regs, int *Last_State){

    FILE *data;
    char *nome_arquivo = "Log/log.dat";

    if ((data = fopen(nome_arquivo, "ab")) == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    // Escrever Estado
    fwrite(Last_State, sizeof(int), 1, data);

    // Escrever program_counter
    fprintf(data, "%d", PC);

    // Escrever MemoriaDados
    fwrite(*md, sizeof(MemoriaDados), 1, data);

    // Escrever registradores
    // Supondo que regs seja uma matriz de inteiros 2D
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            fwrite(&regs[i][j], sizeof(int), 1, data);
        }
    }


    fclose(data);
}

void DeleteLast_State(int Last_State){
    //d
}