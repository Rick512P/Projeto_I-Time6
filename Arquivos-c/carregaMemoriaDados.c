#include "../Arquivos-h/carregaMemoriaDados.h"


void carregamd(MemoriaDados **md){
    FILE *setmd;
    char linha[1024], nome_arquivo[200];
    int contador_de_linhas = 0, opcao;

    printf("Digite 1 para utilizar o diretorio padrao ou 2 para entrar com o diretorio do arquivo: ");
    scanf("%d", &opcao);
    if(opcao == 1)
        setmd = fopen("./memoria/md.dat", "r");
    else if(opcao == 2){
        printf("Entre com o caminho/nome do arquivo incluindo a extenção .dat\n");
        scanf(" %[^\n]", nome_arquivo);
        setmd = fopen(nome_arquivo, "r");
    }
    else{
        printf("Opcao inexistente. Utilizando o diretorio padrao.");
        setmd = fopen("./memoria/md.dat", "r");
    }


    if (setmd){
        
        //primeiro, conto quantas linhas de dados terei no arquivo
        while(fgets(linha, sizeof(linha), setmd) != NULL){
            if (strlen(linha) > 8)
                printf("Linha %d tem mais de 8 bits: %s\n", contador_de_linhas, linha);
            contador_de_linhas++;
        }

        
        if (md == NULL)
            *md = malloc(256 * sizeof(MemoriaDados));
        
        rewind(setmd);
        
        for (int i=0;i<contador_de_linhas;i++){
            if (fgets(linha, sizeof(linha), setmd) == NULL)
                   break;

            linha[strcspn(linha, "\r\n")] = '\0';

            // Copia a linha para a estrutura memoria de Dados
            strncpy((*md)[i].dados, linha, 9);
            (*md)[i].dados[sizeof((*md)[i].dados) - 1] = '\0'; // certifica-se de que a string termina com null terminator
            
        }
        fclose(setmd);
        printf("Arquivo lido com sucesso!");
        
    }
    else
        printf("Erro ao abrir arquivo md.dat");


}