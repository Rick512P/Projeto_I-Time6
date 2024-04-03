#ifndef ULA_H
#define ULA_H
#define BITS 16 

void ULA(char opc[5], char fc[4], char Source[4], char Target[4], char Dest[4]);
void bin_dec(char Source[], char Target[], char Dest[], int *rs, int *rt, int *rd);
char* dec_to_bin(int decimal, char binary[]);
void AND(char Source[], char Target[], char Dest[]);
void OR(char Source[], char Target[], char Dest[]);

#endif