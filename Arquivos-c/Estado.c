#include "../Arquivos-h/Estado.h"

int retorna_estado(MemoriaDados **md, int **regs) {
    FILE *data;
    int PC;
    char *nome_arquivo = "Log/log.dat";
    
    if ((data = fopen(nome_arquivo, "r")) == NULL) {
        printf("Erro ao abrir o arquivo para leitura do log.");
        return 1;
    }
    
    // Encontrar a última linha do arquivo
    char linha[1000];
    while (fgets(linha, sizeof(linha), data) != NULL) {
        // Ignorar linhas em branco
        if (linha[0] != '\n') {
            // Remover o caractere de nova linha da última linha
            strtok(linha, "\n");
        }
    }
    
    // Fechar o arquivo
    fclose(data);
    
    // Agora 'linha' contém a última linha do arquivo
    // Vamos analisá-la para extrair os dados necessários
    
    char *token = strtok(linha, ";");
    int index = 0;
    while (token != NULL) {
        if (index == 0) {
            // Ler e armazenar os dados da memória
            char *memoria_token = strtok(token, ".");
            for (int i = 0; i < 256; i++) {
                strcpy((*md)[i].dados,memoria_token);
                memoria_token = strtok(NULL, ".");
            }
        } else if (index == 1) {
            // Ler o PC
            PC = atoi(token);
        } else if (index == 2) {
            // Ler os registradores
            char *reg_token = strtok(token, ".");
            for (int i = 0; i < 8; i++) {
                (*regs)[i] = atoi(reg_token);
                reg_token = strtok(NULL, ".");
            }
        }
        token = strtok(NULL, ";");
        index++;
    }

    //DeleteLast_State();
    
    printf("\nPC = %d", PC);
    return PC;
}

int salva_estado(int *program_counter, MemoriaDados **md, int **regs) {
    FILE *data;
    char *nome_arquivo = "Log/log.dat", dados[9];
    int PC = *program_counter, registradores;

    if ((data = fopen(nome_arquivo, "a")) == NULL) {
        printf("Erro ao abrir o arquivo para salvar estado.");
        return 1;
    }

    // Escrever MemoriaDados
    for (int i = 0; i < 256; i++) {
        strcpy(dados,(*md)[i].dados);
        fprintf(data, "%s.", dados);
    }
    fprintf(data, ";");

    // Escrever program_counter
    fprintf(data, "%d;", PC);

    // Escrever registradores
    for (int i = 0; i < 8; i++) {
        registradores = (*regs)[i];
        fprintf(data, "%d.", registradores);
    }
    fprintf(data, ";");

    // Adicionar uma nova linha para indicar o fim do estado
    fprintf(data, "\n");

    fclose(data);

    return 0;
}

void DeleteLast_State() {
    FILE *data;
    char *nome_arquivo = "Log/log.dat";

    if ((data = fopen(nome_arquivo, "r")) == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    // Obtém o tamanho do último estado (int + program_counter + MemoriaDados + registradores)
    long tamanho_ultimo_estado = sizeof(int) + sizeof(int) + sizeof(MemoriaDados) * 256 + sizeof(int) * 64;

    // Move o ponteiro para a posição do início do último estado
    fseek(data, -tamanho_ultimo_estado, SEEK_END);

    // Trunca o arquivo nesse ponto, excluindo todos os dados após o último estado
    ftruncate(fileno(data), ftell(data));

    fclose(data);
}
