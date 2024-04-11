#include "../Arquivos-h/Memoria_Dados.h"

void save_data_to_file(int data[], int size) {
 
    FILE *file = fopen("DATA.mem", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Escreve os dados no arquivo
    fwrite(data, sizeof(int), size, file);

   
    fclose(file);

    printf("Dados salvos com sucesso em DATA.mem\n");
}
