
#include "../Arquivos-h/bibliotecas.h"
#include "../Arquivos-h/Memoria_Dados.h"
//EXEMPLO
void memoriaDados(MemoriaDados *md, int opcao, char valor[], int contador){
    switch (opcao)
    {
    case 0:
        escreveDado(md, contador, valor);
        break;
    
    case 1:
        lerDado(md, contador);
        
	case 2:
		escreverArquivoMemoria(md);
		break;
    }

}

char lerDado(MemoriaDados *mem, int endereco) {
    if (endereco >= 0 && endereco < 256) {
        return mem->dados[endereco];
    }
    fprintf(stderr, "Acesso inválido à memória de dados no endereço %d\n", endereco);
    return 0;
}

void escreveDado(MemoriaDados *mem, int endereco, char *valor) {
    if (endereco >= 0 && endereco < 256) {
        mem->dados[endereco] = *valor;
    } else {
        fprintf(stderr, "Tentativa de escrita fora dos limites da memória no endereço %d\n", endereco);
    }
}

void memDados(MemoriaDados *md){
	printf("Memória de Dados:\n");
	for (int i = 0; i < 256; i++) {
		printf("Endereço %d: %d\n", i, md->dados[i]);
	}
}

void escreverArquivoMemoria(MemoriaDados *md) {
	FILE *arquivo;
	arquivo = fopen("DATA.mem", "w");
	
	if(arquivo==NULL){
		fprintf(stderr, "Erro ao abrir o arquivo DATA.mem\n");
		return;
	}
	
	for (int i=0; i<256; i++){
		fprintf(arquivo, "%d\n", md->dados[i]);
	}
	
	fclose(arquivo);
}
