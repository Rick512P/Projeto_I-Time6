
#include "../Arquivos-h/bibliotecas.h"
#include "../Arquivos-h/Memoria_Dados.h"
//EXEMPLO

void escreveDado(MemoriaDados **mem, int *contador, char *valor) {

    if (*contador >= 0 && *contador < 256) {
        strcpy((*mem)[*contador].dados, valor);
    } else {
        fprintf(stderr, "Tentativa de escrita fora dos limites da memória no endereço %d\n", *contador);
    }
}

void imprimeDados(MemoriaDados *md, int tamLinhas){
	for (int i = 0; i < tamLinhas; i++) {
		printf("\nDado armazenado no endereco %d da Memoria de Dados: %s\n", i, md[i].dados);
	}
}

void escreverArquivoMemoria(MemoriaDados *md) {
	FILE *arquivo;
	arquivo = fopen("DATA.mem", "w");
	
	if(arquivo==NULL){
		fprintf(stderr, "Erro ao abrir o arquivo DATA.mem\n");
	}
	
	for (int i=0; i<256; i++){
		fprintf(arquivo, "%s\n", md[i].dados);
	}
	
	fclose(arquivo);
	printf("\nArquivo criado com sucesso!\n\n");
}
