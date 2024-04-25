#include "../Arquivos-h/carregaMemoriaDados.h"


void carregamd(MemoriaDados **md){
    FILE *setmd = fopen("../memoria/md.dat", "r");
    char linha[1024];
    int contador_de_linhas = 0;
    if (setmd){
        
        //primeiro, conto quantas linhas de dados terei no arquivo
        while(fgets(linha, sizeof(linha), setmd) != NULL){
            contador_de_linhas++;
        }

        
        if (md == NULL)
            *md = malloc(256 * sizeof(MemoriaDados));
        
        rewind(setmd);

        for (int i=0;i<contador_de_linhas;i++){
            if (fgets(linha, sizeof(linha), setmd) == NULL)
                   break;

            linha[strcspn(linha, "\r\n")] = '\0';

            // Copia a linha para a estrutura memoriaInst
            strncpy((*md)[i].dados, linha, 17);
            (*md)[i].dados[sizeof((*md)[i].dados) - 1] = '\0'; // certifica-se de que a string termina com null terminator
            
        }
        fclose(setmd);
        printf("Arquivo lido com sucesso!");
        
    }
    else
        printf("Erro ao abrir arquivo md.dat");


}