#include "../Arquivos-h/Assembly.h"

void AsmCopy(type_instruc *InstrucoesDecodificadas, Assembly **A, int tamLinhas){
    char Opcode[5], rd[4], rs[4], rt[4], funct[4], operacao[6], imediato[7];
    A = malloc(tamLinhas * sizeof(Assembly));
    for (int i = 0; i<tamLinhas; i++){
        //Register Source
        if (strcmp("000",InstrucoesDecodificadas[i].rs))
        {
            strcpy(rs,"$t0");
        }
        else if (strcmp("001",InstrucoesDecodificadas[i].rs))
        {
            strcpy(rs,"$t1");
        }
        else if (strcmp("010",InstrucoesDecodificadas[i].rs))
        {
            strcpy(rs,"$t2");
        }
        else if (strcmp("011",InstrucoesDecodificadas[i].rs))
        {
            strcpy(rs,"$t3");
        }
        else if (strcmp("100",InstrucoesDecodificadas[i].rs))
        {
            strcpy(rs,"$t4");
        }
        else if (strcmp("101",InstrucoesDecodificadas[i].rs))
        {
            strcpy(rs,"$t5");
        }
        else if (strcmp("110",InstrucoesDecodificadas[i].rs))
        {
            strcpy(rs,"$t6");
        }
        else if (strcmp("111",InstrucoesDecodificadas[i].rs))
        {
            strcpy(rs,"$t7");
        }
        
        //Register Target
        if (strcmp("000",InstrucoesDecodificadas[i].rt))
        {
            strcpy(rt,"$t0");
        }
        else if (strcmp("001",InstrucoesDecodificadas[i].rt))
        {
            strcpy(rt,"$t1");
        }
        else if (strcmp("010",InstrucoesDecodificadas[i].rt))
        {
            strcpy(rt,"$t2");
        }
        else if (strcmp("011",InstrucoesDecodificadas[i].rt))
        {
            strcpy(rt,"$t3");
        }
        else if (strcmp("100",InstrucoesDecodificadas[i].rt))
        {
            strcpy(rt,"$t4");
        }
        else if (strcmp("101",InstrucoesDecodificadas[i].rt))
        {
            strcpy(rt,"$t5");
        }
        else if (strcmp("110",InstrucoesDecodificadas[i].rt))
        {
            strcpy(rt,"$t6");
        }
        else if (strcmp("111",InstrucoesDecodificadas[i].rt))
        {
            strcpy(rt,"$t7");
        }

        // Tipo R
        if (strcmp("0000",InstrucoesDecodificadas[i].opcode))
        {
            //Register Destiny
            if (strcmp("000",InstrucoesDecodificadas[i].rd))
            {
                strcpy(rd,"$t0");
            }
            else if (strcmp("001",InstrucoesDecodificadas[i].rd))
            {
                strcpy(rd,"$t1");
            }
            else if (strcmp("010",InstrucoesDecodificadas[i].rd))
            {
                strcpy(rd,"$t2");
            }
            else if (strcmp("011",InstrucoesDecodificadas[i].rd))
            {
                strcpy(rd,"$t3");
            }
            else if (strcmp("100",InstrucoesDecodificadas[i].rd))
            {
                strcpy(rd,"$t4");
            }
            else if (strcmp("101",InstrucoesDecodificadas[i].rd))
            {
                strcpy(rd,"$t5");
            }
            else if (strcmp("110",InstrucoesDecodificadas[i].rd))
            {
                strcpy(rd,"$t6");
            }
            else if (strcmp("111",InstrucoesDecodificadas[i].rd))
            {
                strcpy(rd,"$t7");
            }

            // função

            if (strcmp("000",InstrucoesDecodificadas[i].funct)){
                strcpy(Opcode,"add");
            }
            else if (strcmp("010",InstrucoesDecodificadas[i].funct)){
                strcpy(Opcode,"sub");
            }
            else if (strcmp("100",InstrucoesDecodificadas[i].funct)){
                strcpy(Opcode,"and");
            }
            else if (strcmp("101",InstrucoesDecodificadas[i].funct)){
                strcpy(Opcode,"or");
            }

            //concatenação
            strcat((*A)[i].InstructsAssembly,Opcode);
            strcat((*A)[i].InstructsAssembly,rd);
            strcat((*A)[i].InstructsAssembly,", ");
            strcat((*A)[i].InstructsAssembly,rs);
            strcat((*A)[i].InstructsAssembly,", ");
            strcat((*A)[i].InstructsAssembly,rt);
            strcat((*A)[i].InstructsAssembly,", ");
        }
        else if (strcmp("0100",InstrucoesDecodificadas[i].opcode)){
            /* addi */
            strcat((*A)[i].InstructsAssembly, "addi ");
            strcat((*A)[i].InstructsAssembly, rt);
            strcat((*A)[i].InstructsAssembly,", ");
            strcat((*A)[i].InstructsAssembly, rs);
            strcat((*A)[i].InstructsAssembly,", ");
            strcat((*A)[i].InstructsAssembly,imediato);
        }
        else if (strcmp("1011",InstrucoesDecodificadas[i].opcode))
        {
            /* lw */
            strcat((*A)[i].InstructsAssembly, "lw ");
            strcat((*A)[i].InstructsAssembly, rt);
            strcat((*A)[i].InstructsAssembly,", ");
            strcat((*A)[i].InstructsAssembly, imediato);
            strcat((*A)[i].InstructsAssembly,"(");
            strcat((*A)[i].InstructsAssembly,rs);
            strcat((*A)[i].InstructsAssembly,")");
        }
        else if (strcmp("1111",InstrucoesDecodificadas[i].opcode))
        {
            /* sw */
            strcat((*A)[i].InstructsAssembly, "sw ");
            strcat((*A)[i].InstructsAssembly, rt);
            strcat((*A)[i].InstructsAssembly,", ");
            strcat((*A)[i].InstructsAssembly, imediato);
            strcat((*A)[i].InstructsAssembly,"(");
            strcat((*A)[i].InstructsAssembly,rs);
            strcat((*A)[i].InstructsAssembly,")");
        }
        else if (strcmp("1000",InstrucoesDecodificadas[i].opcode))
        {
            /* beq */
            strcat((*A)[i].InstructsAssembly, "beq ");
            strcat((*A)[i].InstructsAssembly, rt);
            strcat((*A)[i].InstructsAssembly,", ");
            strcat((*A)[i].InstructsAssembly, rs);
            strcat((*A)[i].InstructsAssembly,", ");
            strcat((*A)[i].InstructsAssembly,imediato);
        }
        else if (strcmp("0010",InstrucoesDecodificadas[i].opcode))
        {
            /* Jump */
            strcat((*A)[i].InstructsAssembly, "beq ");
            strcat((*A)[i].InstructsAssembly, InstrucoesDecodificadas[i].rs);
            strcat((*A)[i].InstructsAssembly, InstrucoesDecodificadas[i].rt);
            strcat((*A)[i].InstructsAssembly, InstrucoesDecodificadas[i].imm);
        }
    }
}

int SaveASM(Assembly *A, int tamLinhas){
    /*Salvar arquivo .asm*/
    FILE *arquivo;

    // Abre o arquivo para escrita (se não existir, será criado)
    arquivo = fopen("Instructs.asm", "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }
    for (int i = 0; i<tamLinhas; i++){

        fprintf(arquivo, "%s\n", A[i].InstructsAssembly);


        // Fecha o arquivo
        fclose(arquivo);
    }
    printf("Arquivo asm salvo com sucesso!\n");
}

void imprimirASM(Assembly *A, int tamLinhas){
    /*Realizar Impressão da Struct ASM*/
    for (int i = 0; i<tamLinhas; i++){
        printf("\nInstrucao em Assembly: %s", A[i].InstructsAssembly);
        printf("\n");
    }
}