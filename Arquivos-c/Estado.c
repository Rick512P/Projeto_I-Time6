#include "../Arquivos-h/Estado.h"

int retorna_estado(MemoriaDados **md, int **regs) {
    FILE *data;
    int PC = 0, ultimo_estado;
    char *nome_arquivo = "Log/log.dat";

    if ((data = fopen(nome_arquivo, "rb")) == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    // Busca o final do arquivo
    fseek(data, -1, SEEK_END); // Move uma posição antes do final do arquivo

    // Move o ponteiro de volta até encontrar a última quebra de linha
    while (fgetc(data) != '\n') {
        fseek(data, -2, SEEK_CUR); // Retrocede dois bytes para evitar ler o caractere '\n'
    }

    // Lê o estado
    fscanf(data, "%d", &PC);

    // Retrocede para ler a MemoriaDados
    fseek(data, -sizeof(MemoriaDados), SEEK_CUR);
    fread(*md, sizeof(MemoriaDados), 1, data);

    // Retrocede para ler os registradores
    // Supondo que regs seja um array de inteiros
    fseek(data, -sizeof(int) * 64, SEEK_CUR);
    fread(*regs, sizeof(int), 64, data);

    fclose(data);

    // Agora que o estado foi completamente lido, podemos excluir o último estado do arquivo
    DeleteLast_State();

    return PC;
}

int salva_estado(int PC, MemoriaDados **md, int *regs, int *Last_State) {
    FILE *data;
    char *nome_arquivo = "Log/log.dat";

    if ((data = fopen(nome_arquivo, "ab")) == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    // Escrever Last_State
    fwrite(Last_State, sizeof(int), 1, data);

    // Escrever program_counter
    fprintf(data, "%d", PC);

    // Escrever MemoriaDados
    fwrite(*md, sizeof(MemoriaDados), 1, data);

    // Escrever registradores
    fwrite(regs, sizeof(int), 64, data);

    // Adicionar uma nova linha para indicar o fim do estado
    fprintf(data, "\n");

    fclose(data);

    return 0;
}

void DeleteLast_State(){
    FILE *data;
    char *nome_arquivo = "Log/log.dat";

    if ((data = fopen(nome_arquivo, "rb+")) == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    // Obtém o tamanho do último estado (int + program_counter + MemoriaDados + registradores)
    long tamanho_ultimo_estado = sizeof(int) + sizeof(int) + sizeof(MemoriaDados) + sizeof(int) * 64;

    // Move o ponteiro para a posição do início do último estado
    fseek(data, -tamanho_ultimo_estado, SEEK_END);

    // Trunca o arquivo nesse ponto, excluindo todos os dados após o último estado
    ftruncate(fileno(data), ftell(data));

    fclose(data);
}
