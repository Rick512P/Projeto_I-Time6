#include "../Arquivos-h/menu.h"

int main(){
    menu();
    return 0;
}

int menu(){
    Assembly *AssemblyInst;
    MemoriaDados *md;
    unsigned int escolha, tamLinhas, program_counter = 0; //UNSIGNED IMPOSSIBILITA QUE PROGRAM_COUNTER CHEGUE A MENOR QUE 0
    instrucao *memoriaInst; //RESPONSAVEL POR COLETAR  A INSTRUÇÃO
    int *regs; //registradores como um inteiro mesmo
    regs = (int*)malloc(8 * sizeof(int));
    for (int i=0;i<8;i++){ //zerando registradores, caso contrario dá números inconsistentes
        regs[i] = 0;
    }

    type_instruc **instrucoesDecodificadas = malloc(sizeof(type_instruc*));
    md = (MemoriaDados*)calloc(256, sizeof(MemoriaDados));

    printf("\n___________________________________________ ==ATENÇÃO== ____________________________________________\n\n");
    printf("| + TODOS OS ARQUIVOS DE INSTRUÇÂO DEVEM ESTAR NA PASTA 'memoria' COM O SEGUINTE NOME E EXTENSÂO + |\n");
    printf("__________________________________________ =INSTRUCT.mem= __________________________________________");
    do{
        printf("\n\n");
        printf("                              _____________________________________\n");
        printf("                              |1  +  Carregar memória instruções   +|\n");
        printf("                              |2  +    Carregar memoria dados      +|\n");
        printf("                              |3  +        Imprimir memória        +|\n");
        printf("                              |4  +      Imprimir registradores    +|\n");
        printf("                              |5  +      Imprimir estatisticas     +|\n");
        printf("                              |6  +  Imprimir instrucoes Assembly  +|\n");
        printf("                              |7  +    Imprimir todo o simulador   +|\n");
        printf("                              |8  +          Salvar .asm           +|\n");
        printf("                              |9  +          Salvar .dat           +|\n");
        printf("                              |10 +     Executa Programa (run)     +|\n");
        printf("                              |11 +    Executa instrucao (step)    +|\n");
        printf("                              |12 +   Volta uma instrucao (back)   +|\n");
        printf("                              |0  +              Sair              +|\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 0:
            free(md);
            free(memoriaInst);
            free(regs);
            free(AssemblyInst);
            free(instrucoesDecodificadas);
            system("clear");
            removeLog();
            printf("Programa Encerrado!\n");
            break;
            
        case 1: //Carregar memória de Instruções
            parser(&memoriaInst, &tamLinhas);
            *instrucoesDecodificadas = malloc(tamLinhas * sizeof(type_instruc));
            if (*instrucoesDecodificadas == NULL) {
                fprintf(stderr, "Falha ao alocar memória para instruções decodificadas.\n");
                return -1;
            }
            
            AssemblyInst = calloc((tamLinhas + 1), sizeof(Assembly));

            if (*instrucoesDecodificadas == NULL) {
                fprintf(stderr, "Falha ao alocar memória para instrucoes assembly.\n");
                return -1;
            }
            break;

        case 2: //Carregar Memória de Dados
            if (program_counter == 0)
                carregamd(&md);
            else 
                printf("Programa nao deve ter sido inicializado.");
            break;

        case 3: //Imprimir memória de instruções e memória de dados
            imprimeMemInstruc(memoriaInst, tamLinhas);
            imprimeDados(md, tamLinhas);
            break;

        case 4: //Imprimir registradores
            imprimeRegistradores(regs);
            break;

        case 5: //Imprimir estatísticas como: quantas intruc, classes, etc;
            imprimeEstatisticas(memoriaInst, tamLinhas, instrucoesDecodificadas);
            break;
            
        case 6: // Imprimir Assembly
            imprimirASM(AssemblyInst, tamLinhas);
            break;

        case 7: //imprimir todo o simulador
            imprimeEstatisticas(memoriaInst, tamLinhas, instrucoesDecodificadas);
            imprimeSimulador(tamLinhas, instrucoesDecodificadas, memoriaInst);
            imprimeDados(md, tamLinhas);
            imprimeRegistradores(regs);
            imprimirASM(AssemblyInst, tamLinhas);
            break;

        case 8: //salvar arquivo .asm (com as instruções traduzidas para a linguagem intermediária Assembly)
            SaveASM(AssemblyInst, tamLinhas);
            break;

        case 9: //Salvar arquivo DATA.dat
            escreverArquivoMemoria(md);
            break;

        case 10: //Chamar função responsável pela execução do programa
            program_counter = 0;
            controller(1, &memoriaInst, tamLinhas, &regs, &md, &program_counter, instrucoesDecodificadas);
            AsmCopy(instrucoesDecodificadas, &AssemblyInst, tamLinhas);
            break;

        case 11: //Chamar função responsável pela execução do programa passo a passo
            controller(2, &memoriaInst, tamLinhas, &regs, &md, &program_counter, instrucoesDecodificadas);
            AsmCopy(instrucoesDecodificadas, &AssemblyInst, tamLinhas);
            break;

        case 12: //Chamar função responsável por retornar uma instrução (PC--)
            controller(3, &memoriaInst, tamLinhas, &regs, &md, &program_counter, instrucoesDecodificadas);
            break;
            
        default:
            break;
        }
    }while(escolha != 0);

    return 0;
}
