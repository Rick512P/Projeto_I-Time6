#include "../Arquivos-h/bibliotecas.h"

void removeLog(){
    char *nome_arquivo = "Log/log.dat";
    if (access(nome_arquivo, F_OK) != -1) {
        // O arquivo existe, então podemos excluí-lo
        system("rm Log/log.dat");
    }
}
