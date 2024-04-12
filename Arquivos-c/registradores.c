#include "../Arquivos-h/registradores.h"



int Registradores (int valor, char posicao[]){ //recebe do controle qual registrador usar e o valor a ser salvo
    registradores regs = {0, 0, 0, 0, 0, 0, 0, 0};

        if(strcmp(posicao, "000") == 0){ //define em qual registrador o valor sera armazenado
            if (valor != 0){ //FACILIDADE DE ACESSAR OS REGISTRADORES, BASTA ENTRAR COM O VALOR 0 NA FUNÇÃO E
            //A RESPECTIVA POSIÇÃO DO REGISTRADOR QUE APENAS RETORNARÁ O CONTEUDO DO REGISTRADOR.
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
