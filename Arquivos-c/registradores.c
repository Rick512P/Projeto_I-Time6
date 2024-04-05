#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Arquivos-h/registradores.h"



int Registradores (int valor, char posicao[]){
    registradores regs = {0, 0, 0, 0, 0, 0, 0, 0};

        if(strcmp(posicao, "000") == 0){ //define em qual registrador o valor sera armazenado
            if (valor != 0){ //Se valor for diferente de 0, ele será armazenado no registrador, caso contrario só ira retornar o reg
                regs.reg0 = valor;
            }
            return regs.reg0;
        }

        else if(strcmp(posicao, "001") == 0){
            if (valor != 0)
                regs.reg1 = valor;
            return regs.reg1;
        }

        else if(strcmp(posicao, "010") == 0){
            if (valor != 0)
                regs.reg2 = valor;
            return regs.reg2;
        }

        else if(strcmp(posicao, "011") == 0){
            if (valor != 0)
                regs.reg3 = valor;
            return regs.reg3;
        }

        else if(strcmp(posicao, "100") == 0){
            if (valor != 0)
                regs.reg4 = valor;
            return regs.reg4;
        }

        else if(strcmp(posicao, "101") == 0){
            if (valor != 0)
                regs.reg5 = valor;
            return regs.reg5;
        }

        else if(strcmp(posicao, "110") == 0){
            if (valor != 0)
                regs.reg6 = valor;
            return regs.reg6;
        }

        else if(strcmp(posicao, "111") == 0){
            if (valor != 0)
                regs.reg7 = valor;
            return regs.reg7;
        }
        else
            printf("ERRO. Nenhum Registrador encontrado.");
    } 