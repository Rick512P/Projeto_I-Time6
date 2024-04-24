#include "../Arquivos-h/bin_to_decimal.h"

void bin_decimal(int *indice, char *posicao){
    if(indice)
        (*indice) = bin_to_decimal(posicao);

}

int bin_to_decimal(const char *decimal) {
    int dec = 0;
    int base = 1;
    int len = strlen(decimal);

    for (int i = len - 1; i >= 0; i--) {
        if (decimal[i] == '1') {
            dec += base;
        }
        base *= 2;
    }

    return dec;
}