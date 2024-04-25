
#include "../Arquivos-h/bibliotecas.h"
#include "../Arquivos-h/Memoria_Dados.h"
//EXEMPLO

void escreveDado(MemoriaDados **mem, int *contador, char *valor) {
	// Copiando os 8 bits menos significativos
	char transforma8Bits[9];
    for (int i = 0; i < 8; i++) {
        transforma8Bits[i] = valor[8 + i];
    }
    transforma8Bits[8] = '\0';


    if (*contador >= 0 && *contador < 256) {
        strcpy((*mem)[*contador].dados, transforma8Bits);
    } else {
        fprintf(stderr, "Tentativa de escrita fora dos limites da memória no endereço %d\n", *contador);
    }
}

void imprimeDados(MemoriaDados *md, int tamLinhas){
	for (int i = 0; i < tamLinhas+2; i++) {
		printf("\nDado armazenado no endereco %d da Memoria de Dados: %s\n", i, md[i].dados);
	}
}

void escreverArquivoMemoria(MemoriaDados *md) {
	FILE *arquivo;
	arquivo = fopen("DATA.dat", "w");
	
	if(arquivo==NULL){
		fprintf(stderr, "Erro ao abrir o arquivo DATA.mem\n");
	}
	
	for (int i=0; i<256; i++){
		fprintf(arquivo, "%s\n", md[i].dados);
	}
	
	fclose(arquivo);
	printf("\nArquivo criado com sucesso!\n\n");
}
