#include <stdio.h>

#include "./Arquivos-h/menu.h"

int main(){
    int escolha;
    while(escolha != 0){
        printf("\n 1 - Carregar memória\n 2 - Imprimir memória\n 3 - Imprimir registradores\n 4 - Imprimir todo o simulador\n 5 - Salvar .asm\n");
        printf("6 - Salvar .mem\n 7 - Executa Programa (run)\n 8 - Executa instrucao (step)\n 9 - Volta uma instrucao (back)\n 0 - Sair\n\n");
        scanf("%d", &escolha);

        swtich(escolha)
        {
            case 0:
                break;
            case 1:
                
        }
    }

    return 0;
}
