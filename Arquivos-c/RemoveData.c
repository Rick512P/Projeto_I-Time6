#include <stdio.h>

int removedata() {
    char filename[] = "../memoria/DATA.mem";

    // Tentativa de apagar o arquivo
    if (remove(filename) == 0) {
       return 0;
    } else {
        printf("Erro ao apagar o arquivo %s.\n", filename);
        return 0;
    }
}
