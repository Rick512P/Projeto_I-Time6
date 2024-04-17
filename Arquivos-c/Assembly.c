#include "../Arquivos-h/Assembly.h"

void Asm(type_instruc *traduzido){
    char Opcode[5], rd[4], rs[4], rt[4], funct[4], operacao[6], imediato[7];
    for (int i = 0; i<sizeof(Assembly); i++){
        //Register Source
        if (strcmp('000',traduzido[i].rs))
        {
            strcpy(rs,'$t0');
        }
        else if (strcmp('001',traduzido[i].rs))
        {
            strcpy(rs,'$t1');
        }
        else if (strcmp('010',traduzido[i].rs))
        {
            strcpy(rs,'$t2');
        }
        else if (strcmp('011',traduzido[i].rs))
        {
            strcpy(rs,'$t3');
        }
        else if (strcmp('100',traduzido[i].rs))
        {
            strcpy(rs,'$t4');
        }
        else if (strcmp('101',traduzido[i].rs))
        {
            strcpy(rs,'$t5');
        }
        else if (strcmp('110',traduzido[i].rs))
        {
            strcpy(rs,'$t6');
        }
        else if (strcmp('111',traduzido[i].rs))
        {
            strcpy(rs,'$t7');
        }
        
        //Register Target
        if (strcmp('000',traduzido[i].rt))
        {
            strcpy(rt,'$t0');
        }
        else if (strcmp('001',traduzido[i].rt))
        {
            strcpy(rt,'$t1');
        }
        else if (strcmp('010',traduzido[i].rt))
        {
            strcpy(rt,'$t2');
        }
        else if (strcmp('011',traduzido[i].rt))
        {
            strcpy(rt,'$t3');
        }
        else if (strcmp('100',traduzido[i].rt))
        {
            strcpy(rt,'$t4');
        }
        else if (strcmp('101',traduzido[i].rt))
        {
            strcpy(rt,'$t5');
        }
        else if (strcmp('110',traduzido[i].rt))
        {
            strcpy(rt,'$t6');
        }
        else if (strcmp('111',traduzido[i].rt))
        {
            strcpy(rt,'$t7');
        }

        // Tipo R
        if (strcmp('0000',traduzido[i].opcode))
        {
            //Register Destiny
            if (strcmp('000',traduzido[i].rd))
            {
                strcpy(rd,'$t0');
            }
            else if (strcmp('001',traduzido[i].rd))
            {
                strcpy(rd,'$t1');
            }
            else if (strcmp('010',traduzido[i].rd))
            {
                strcpy(rd,'$t2');
            }
            else if (strcmp('011',traduzido[i].rd))
            {
                strcpy(rd,'$t3');
            }
            else if (strcmp('100',traduzido[i].rd))
            {
                strcpy(rd,'$t4');
            }
            else if (strcmp('101',traduzido[i].rd))
            {
                strcpy(rd,'$t5');
            }
            else if (strcmp('110',traduzido[i].rd))
            {
                strcpy(rd,'$t6');
            }
            else if (strcmp('111',traduzido[i].rd))
            {
                strcpy(rd,'$t7');
            }

            // função

            if (strcmp('000',traduzido[i].funct)){
                strcmpy(Opcode,'add ');
            }
            else if (strcmp('010',traduzido[i].funct)){
                strcmpy(Opcode,'sub ');
            }
            else if (strcmp('100',traduzido[i].funct)){
                strcmpy(Opcode,'and ');
            }
            else if (strcmp('101',traduzido[i].funct)){
                strcmpy(Opcode,'or ');
            }

            //concatenação
            strcat(A[i].InstructsAssembly,Opcode);
            strcat(A[i].InstructsAssembly,rd);
            strcat(A[i].InstructsAssembly,", ");
            strcat(A[i].InstructsAssembly,rs);
            strcat(A[i].InstructsAssembly,", ");
            strcat(A[i].InstructsAssembly,rt);
            strcat(A[i].InstructsAssembly,", ");
        }
        else if (strcmp('0100',traduzido[i].opcode)){
            /* addi */
            strcat(A[i].InstructsAssembly, "addi ");
            strcat(A[i].InstructsAssembly, rt);
            strcat(A[i].InstructsAssembly,", ");
            strcat(A[i].InstructsAssembly, rs);
            strcat(A[i].InstructsAssembly,", ");
            strcat(A[i].InstructsAssembly,imediato);
        }
        else if (strcmp('1011',traduzido[i].opcode))
        {
            /* lw */
            strcat(A[i].InstructsAssembly, "lw ");
            strcat(A[i].InstructsAssembly, rt);
            strcat(A[i].InstructsAssembly,", ");
            strcat(A[i].InstructsAssembly, imediato);
            strcat(A[i].InstructsAssembly,"(");
            strcat(A[i].InstructsAssembly,rs);
            strcat(A[i].InstructsAssembly,")");
        }
        else if (strcmp('1111',traduzido[i].opcode))
        {
            /* sw */
            strcat(A[i].InstructsAssembly, "sw ");
            strcat(A[i].InstructsAssembly, rt);
            strcat(A[i].InstructsAssembly,", ");
            strcat(A[i].InstructsAssembly, imediato);
            strcat(A[i].InstructsAssembly,"(");
            strcat(A[i].InstructsAssembly,rs);
            strcat(A[i].InstructsAssembly,")");
        }
        else if (strcmp('1000',traduzido[i].opcode))
        {
            /* beq */
            strcat(A[i].InstructsAssembly, "beq ");
            strcat(A[i].InstructsAssembly, rt);
            strcat(A[i].InstructsAssembly,", ");
            strcat(A[i].InstructsAssembly, rs);
            strcat(A[i].InstructsAssembly,", ");
            strcat(A[i].InstructsAssembly,imediato);
        }
        else if (strcmp('0010',traduzido[i].opcode))
        {
            /* Jump */
            strcat(A[i].InstructsAssembly, "beq ");
            strcat(A[i].InstructsAssembly, traduzido[i].rs);
            strcat(A[i].InstructsAssembly, traduzido[i].rt);
            strcat(A[i].InstructsAssembly, traduzido[i].imm);
        }
    }
}

int SaveASM(){
    /*Salvar arquivo .asm*/
    FILE *arquivo;

    // Abre o arquivo para escrita (se não existir, será criado)
    arquivo = fopen("Instructs.asm", "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }
    for (int i = 0; i<sizeof(Assembly); i++){
        // Escreve o valor no arquivo
        if (i < (sizeof(Assembly)-1)){
            fprintf(arquivo, "%s\n", A[i].InstructsAssembly);
        }
        else{
            fprintf(arquivo, "%s", A[i].InstructsAssembly);
        }
        // Fecha o arquivo
        fclose(arquivo);
    }
    printf("Arquivo asm salvo com sucesso!\n");
    return 0;
}

void imprimirASM(){
    /*Realizar Impressão da Struct ASM*/
    for (int i = 0; i<sizeof(Assembly); i++){
        puts(A[i].InstructsAssembly);
        printf("\n");
    }
}