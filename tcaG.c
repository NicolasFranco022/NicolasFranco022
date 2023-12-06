#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM 50

typedef enum
{
    INFO = 1,
    MEC,
    MAMB,
    TADS,
    TGA,
    CSOC
} enum_curso;

typedef struct
{
    char *nome;
    enum_curso curso;
    int ano;
} Tturma;

typedef enum
{
    Goleiro = 1,
    AlaD,
    AlaE,
    Fixo,
    Pivo
} enum_posicao;

typedef struct
{

    int dia;
    int mes;
    int ano;
} Tdata;

typedef struct
{

    char *nome;
    char *matricula;
    int num_Camisa;
    enum_posicao **posicao;
    Tdata data_Nasc;
    Tturma turma;
    int pos_posicao;
} Tjogador;

typedef struct
{

    char *nome;
    char *tecnico;
    Tjogador *jogadores;
    Tturma *turmas;
    int posicao_jogador;
    int posicao_turma;
} Ttime;

Tturma *pTurma;
Ttime *pTime;
int num_turmas = 0;
int num_times = 0;

void menssagem_ACERTO(int codigoACERTO);   // Acertos
void menssagem_ERRO(int codigoERRO);       // Erros
void MENU_main();                          // Mostra as opções (MAIN)
void MENU_turma();                         // Mostra as opções (TURMA)
void MENU_lista_turma();                   // Mostra as opções de listamento (TURMA)
int MENU_alterar_turma();                  // Mostra as opções de alteração (TURMA)
void MENU_time();                          // Mostra as opções (TIME)
void dispara_MENU_main(int opcao);         // Dispara as opções escolhidas (MAIN)
void dispara_MENU_turma(int opcao);        // Dispara as opções escolhidas (TURMA)
void dispara_MENU_lista_turma(int opcao);  // Dispara as opções escolhidas de listar (TURMA)
void dispara_MENU_time(int opcao);         // Dispara as opções escolhidas (TIME)
int inclusao_turma();                      // Dispara função para incluir turma
Tturma cria_turma();                       // Cria uma turma
void imprime_turma(Tturma turma);          // Imprime uma música
void lista_turma();                        // Lista todas as turmas
void salvar_arquivo_turma();               // Salva os dados da turma no arquivo
void recupera_dado_turma();                // Recupera os dados da turma
int alteracao_turma();                     // Dispara função para alterar turma
int altera_turma(int opcao_alt);           // Funcinalidade de alterar uma turma
int exclusao_turma();                      // Dispara função para excluir turma
void excluir_turma(int opcao_excl);        // Funcionalidade de excluir uma turma
void reorganizar_turma(int opcao_excl);    // Reorganiza lista de turma, depois de excluir
int validaData(int dia, int mes, int ano); // Valida data
int MenuTime0();
int MenuTime();
void IncluirTime();
void IncluirJogador(int time, int jogador);
void AtribuiTurma(int time, int jogador);
void AtribuiPosicao(int op1, int op2);
int VerificaTurma(int time, int turmaAux);
void DisparaAlterarTime();
void AlterarTime(int op1, int op2);
void DisparaMenuJogadores(int time);
int MenuJogadores();
int MenuJogadores0();
void DisparaAlterarJogador(int time);
void AlterarJogador(int op1, int op2, int time);
void DisparaMenuPosicao(int time, int jogador);
int MenuPosicao();
int MenuPosicao0();
int MenuPosicaoFinal();
void AlterarPosicao(int time, int jogador);
void ExcluirPosicao(int time, int jogador);
void DisparaExcluirJogador(int time);
void ExcluirJogador(int op, int time);
void ListaJogadoresBasico(int time);
void DisparaExcluirTime();
void ExcluirTime(int op);
void DisparaListarTimes();
void DisparaListarUmTime();
void ListaTimesBasico();
void ListarTodosTimes();
void ListarUmTime(int op);
void ListarTodosJogadores(int time);
void ListarUmJogador(int op, int time);
void ListarPosicao(int posicao, int op, int jogador);

int main()
{
    int opcao;
    recupera_dado_turma();
    fflush(stdin);
    while (opcao != 3)
    {
        MENU_main();
        scanf("%d", &opcao);

        if (opcao < 1 || opcao > 3)
        {
            menssagem_ERRO(0);
            system("pause");
            system("cls");
        }

        if (opcao == 3)
        {
            if (num_turmas > 0)
            {
                salvar_arquivo_turma();
            }
            system("cls");
            menssagem_ACERTO(2);
            system("pause");
            break;
        }

        dispara_MENU_main(opcao);
    }
}

void MENU_main()
{

    system("cls");
    printf("LIGA CORUJA DE FUTSAL\n");
    printf("(1) - TURMA\n");
    printf("(2) - TIME\n");
    printf("(3) - SAIR\n\n");
    printf("Escolha a opcao: ");
}

void dispara_MENU_main(int opcao)
{

    if (opcao == 1)
    {
        MENU_turma();
    }
    else if (opcao == 2)
    {
        MENU_time();
    }
}

void MENU_turma()
{

    int opcao;

    system("cls");
    printf("Bem-vindo ao Menu (TURMA)\n");
    printf("(1) - Incluir\n");
    printf("(2) - Alterar\n");
    printf("(3) - Excluir\n");
    printf("(4) - Listar\n");
    printf("(5) - Voltar\n");
    printf("Escolha a opcao: ");
    scanf("%d", &opcao);
    fflush(stdin);
    system("cls");
    while (opcao <= 0 || opcao > 5)
    {
        menssagem_ERRO(0);
        system("pause");
        system("cls");
        printf("Bem-vindo ao Menu (TURMA)\n");
        printf("(1) - Incluir\n");
        printf("(2) - Alterar\n");
        printf("(3) - Excluir\n");
        printf("(4) - Listar\n");
        printf("(5) - Voltar\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);
        system("cls");
    }

    dispara_MENU_turma(opcao);
}

void dispara_MENU_turma(int opcao)
{

    if (opcao == 1)
    {
        inclusao_turma();
    }
    else if (opcao == 2)
    {
        if (num_turmas < 1)
        {
            menssagem_ERRO(-2);
            system("pause");
            system("cls");
            MENU_main();
        }
        alteracao_turma();
    }
    else if (opcao == 3)
    {
        if (num_turmas < 1)
        {
            menssagem_ERRO(-2);
            system("pause");
            system("cls");
            MENU_main();
        }
        exclusao_turma();
    }
    else if (opcao == 4)
    {
        if (num_turmas == 0)
        {
            menssagem_ERRO(-2);
            system("pause");
            system("cls");
            MENU_main();
        }
        MENU_lista_turma();
    }
    else if (opcao == 5)
    {
        MENU_main();
    }
}

void MENU_time()
{

    int opcao;

    system("cls");
    printf("Bem-vindo ao Menu (TIME)\n");
    printf("(1) - Incluir\n");
    printf("(2) - Alterar\n");
    printf("(3) - Excluir\n");
    printf("(4) - Listar\n");
    printf("(5) - Voltar\n");
    printf("Escolha a opcao: ");
    scanf("%d", &opcao);
    fflush(stdin);
    system("cls");
    while (opcao <= 0 || opcao > 5)
    {
        menssagem_ERRO(0);
        system("pause");
        system("cls");
        printf("Bem-vindo ao Menu (TIME)\n");
        printf("(1) - Incluir\n");
        printf("(2) - Alterar\n");
        printf("(3) - Excluir\n");
        printf("(4) - Listar\n");
        printf("(5) - Voltar\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);
        system("cls");
    }

    dispara_MENU_time(opcao);
}

void dispara_MENU_time(int opcao)
{

    if (opcao == 1)
    {
        printf("NAO FEITO!!!");
    }
    if (opcao == 2)
    {
        printf("NAO FEITO!!!");
    }
    if (opcao == 3)
    {
        printf("NAO FEITO!!!");
    }
    if (opcao == 4)
    {
        printf("NAO FEITO!!!");
    }
}

int inclusao_turma()
{
    if (num_turmas == 0) // Lista de música vazia
    {
        pTurma = (Tturma *)malloc(1 * sizeof(Tturma));
    }
    else
    {
        pTurma = (Tturma *)realloc(pTurma, (num_turmas + 1) * sizeof(Tturma));
    }

    if (!pTurma)
    {
        menssagem_ERRO(-1);
        system("pause");
        system("cls");
    }

    cria_turma();

    return 1;
}

Tturma cria_turma()
{

    Tturma turma;
    char str_aux[100];

    printf("INCLUSAO DE (TURMA) \n");
    printf("Nome: ");
    gets(str_aux);

    turma.nome = (char *)malloc((strlen(str_aux) + 1) * sizeof(char));
    strcpy(turma.nome, str_aux);
    fflush(stdin);

    printf("Curso: \n");
    printf("(1) - INFO\n");
    printf("(2) - MEC\n");
    printf("(3) - MAMB\n");
    printf("(4) - TADS\n");
    printf("(5) - TGA\n");
    printf("(6) - CSOC\n");
    scanf("%d", &turma.curso);
    fflush(stdin);
    while (turma.curso < 1 || turma.curso > 6)
    {

        menssagem_ERRO(-4);
        printf("Curso: \n");
        printf("(1) - INFO\n");
        printf("(2) - MEC\n");
        printf("(3) - MAMB\n");
        printf("(4) - TADS\n");
        printf("(5) - TGA\n");
        printf("(6) - CSOC\n");
        scanf("%d", &turma.curso);
        fflush(stdin);
    }

    printf("Ano: ");
    scanf("%d", &turma.ano);
    fflush(stdin);
    while (turma.ano <= 0)
    {

        menssagem_ERRO(-4);
        printf("Ano: ");
        scanf("%d", &turma.ano);
        fflush(stdin);
    }

    pTurma[num_turmas] = turma;
    num_turmas++;

    menssagem_ACERTO(1);
    system("pause");
    system("cls");
    MENU_main();

    return turma;
}

void imprime_turma(Tturma turma)
{

    printf("Nome: %s\n", turma.nome);
    fflush(stdin);

    if (turma.curso == 1)
    {
        printf("Curso: INFO\n");
        fflush(stdin);
    }
    else if (turma.curso == 2)
    {
        printf("Curso: MEC\n");
        fflush(stdin);
    }
    else if (turma.curso == 3)
    {
        printf("Curso: MAMB\n");
        fflush(stdin);
    }
    else if (turma.curso == 4)
    {
        printf("Curso: TADS\n");
        fflush(stdin);
    }
    else if (turma.curso == 5)
    {
        printf("Curso: TGA\n");
        fflush(stdin);
    }
    else if (turma.curso == 6)
    {
        printf("Curso: CSOC\n");
        fflush(stdin);
    }

    printf("Ano: %d\n", turma.ano);
    system("pause");
    system("cls");
}

void lista_turma()
{
    int i;

    for (i = 0; i < num_turmas; i++)
    {
        printf("----- TURMA [%d] -----\n", i + 1);
        imprime_turma(pTurma[i]);
    }
}

void MENU_lista_turma()
{
    int opcao;

    system("cls");
    printf("----- MENU LISTAR (TURMA) -----\n");
    printf("(1) - Listar turma\n");
    printf("(2) - Listar todas as turmas\n");
    printf("(3) - Voltar\n");
    scanf("%d", &opcao);
    fflush(stdin);
    system("cls");

    while (opcao <= 0 || opcao > 3)
    {
        menssagem_ERRO(0);
        system("pause");
        system("cls");
        printf("----- MENU LISTAR (TURMA) -----\n");
        printf("(1) - Listar turma\n");
        printf("(2) - Listar todas as turmas\n");
        printf("(3) - Voltar\n");
        scanf("%d", &opcao);
        fflush(stdin);
        system("cls");
    }

    dispara_MENU_lista_turma(opcao);
}

void dispara_MENU_lista_turma(int opcao)
{
    int opcao_aux = 0, i;

    if (opcao == 1)
    {
        if (num_turmas == 1)
        {
            printf("----- TURMA [%d] -----\n", 1);
            imprime_turma(pTurma[0]);
            system("cls");
            MENU_main();
        }
        else
        {
            for (i = 0; i < num_turmas; i++)
            {
                printf("TURMA [%d]\n", i + 1);
            }

            printf("Escolha a opcao: ");
            scanf("%d", &opcao_aux);
            fflush(stdin);

            system("cls");
            printf("----- TURMA [%d] -----\n", opcao_aux);
            imprime_turma(pTurma[opcao_aux - 1]);
        }
    }
    else if (opcao == 2)
    {
        lista_turma();
    }
}

void salvar_arquivo_turma()
{
    int i;
    FILE *pArquivo;

    pArquivo = fopen("C:/VSCODE/coisas/VSCODE-COD/turmas.txt", "w");

    if (pArquivo == NULL)
    {
        menssagem_ERRO(-3);
        system("pause");
        system("cls");
    }

    for (i = 0; i < num_turmas; i++)
    {
        fprintf(pArquivo, "%s;", pTurma[i].nome);
        if (pTurma[i].curso == 1)
        {
            fprintf(pArquivo, "INFO;");
        }
        else if (pTurma[i].curso == 2)
        {
            fprintf(pArquivo, "MEC;");
        }
        else if (pTurma[i].curso == 3)
        {
            fprintf(pArquivo, "MAMB;");
        }
        else if (pTurma[i].curso == 4)
        {
            fprintf(pArquivo, "TADS;");
        }
        else if (pTurma[i].curso == 5)
        {
            fprintf(pArquivo, "TGA;");
        }
        else if (pTurma[i].curso == 6)
        {
            fprintf(pArquivo, "CSOC;");
        }
        fprintf(pArquivo, "%d;", pTurma[i].ano);
        fprintf(pArquivo, "%c", '\n');
    }

    fclose(pArquivo);
}

void recupera_dado_turma()
{
    int i, separador;
    char str_aux[100], caractere;
    FILE *pArquivo;

    pArquivo = fopen("C:/VSCODE/coisas/VSCODE-COD/turmas.txt", "r");

    if (pArquivo)
    {
        i = 0;         // i indexa o str_aux
        separador = 0; // Conta os separadores "";""

        while (!feof(pArquivo))
        {
            caractere = fgetc(pArquivo);

            if ((caractere != '\n') && (caractere != ';') && (caractere != EOF))
            {
                str_aux[i] = caractere;
                i++;
            }
            else if ((caractere == ';') || (caractere == '\n'))
            {
                str_aux[i] = '\0';
                i = 0;

                if (caractere == ';')
                {
                    if (separador == 0)
                    {
                        if (num_turmas == 0)
                        {
                            pTurma = (Tturma *)malloc(1 * sizeof(Tturma));
                        }
                        else
                        {
                            pTurma = (Tturma *)realloc(pTurma, (num_turmas + 1) * sizeof(Tturma));
                        }

                        pTurma[num_turmas].nome = (char *)malloc(strlen(str_aux) + 1 * sizeof(char));
                        strcpy(pTurma[num_turmas].nome, str_aux);
                        separador++;
                    }
                    else if (separador == 1)
                    {
                        if (strcmp(str_aux, "INFO") == 0)
                        {
                            pTurma[num_turmas].curso = INFO;
                        }
                        else if (strcmp(str_aux, "MEC") == 0)
                        {
                            pTurma[num_turmas].curso = MEC;
                        }
                        else if (strcmp(str_aux, "MAMB") == 0)
                        {
                            pTurma[num_turmas].curso = MAMB;
                        }
                        else if (strcmp(str_aux, "TADS") == 0)
                        {
                            pTurma[num_turmas].curso = TADS;
                        }
                        else if (strcmp(str_aux, "TGA") == 0)
                        {
                            pTurma[num_turmas].curso = TGA;
                        }
                        else if (strcmp(str_aux, "CSOC") == 0)
                        {
                            pTurma[num_turmas].curso = CSOC;
                        }
                        separador++;
                    }
                    else if (separador == 2)
                    {
                        pTurma[num_turmas].ano = atoi(str_aux);
                        separador = 0;
                        num_turmas++;
                    }
                }
            }
        }
    }

    fclose(pArquivo);
}

int alteracao_turma()
{
    int opcao_alt = -1, resp;

    while (opcao_alt < 0 || opcao_alt >= num_turmas)
    {
        lista_turma();

        if (num_turmas > 1)
        {
            printf("Digite o atributo que deseja alterar [%d - %d]: ", 1, num_turmas);
            scanf("%d", &opcao_alt);
            fflush(stdin);
            printf("\n");
        }
        else
        {
            opcao_alt = 1;
        }

        opcao_alt--;

        if (opcao_alt < 0 || opcao_alt >= num_turmas)
        {
            menssagem_ERRO(0);
            system("pause");
            system("cls");
        }
        else
        {
            resp = altera_turma(opcao_alt);
        }
    }

    system("cls");
    if (resp > 0)
    {
        menssagem_ACERTO(3);
    }
}

int altera_turma(int opcao_alt)
{
    int atributo = 1, curso_aux = 0;
    char op;

    while (atributo > 0)
    {
        atributo = MENU_alterar_turma();
        switch (atributo)
        {
        case 1:
            system("cls");
            printf("----- Dados da turma -----\n");
            imprime_turma(pTurma[opcao_alt]);

            printf("Novo - Nome da turma: ");
            gets(pTurma[opcao_alt].nome);
            fflush(stdin);
            menssagem_ACERTO(3);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("----- Dados da turma -----\n");
            imprime_turma(pTurma[opcao_alt]);

            printf("Curso: \n");
            printf("(1) - INFO\n");
            printf("(2) - MEC\n");
            printf("(3) - MAMB\n");
            printf("(4) - TADS\n");
            printf("(5) - TGA\n");
            printf("(6) - CSOC\n");
            printf("Novo - Curso da turma: ");
            scanf("%d", &curso_aux);
            fflush(stdin);
            while (curso_aux < 1 || curso_aux > 6)
            {
                menssagem_ERRO(-4);
                system("pause");
                system("cls");
                printf("Dados da turma\n");
                imprime_turma(pTurma[opcao_alt]);

                printf("Curso: \n");
                printf("(1) - INFO\n");
                printf("(2) - MEC\n");
                printf("(3) - MAMB\n");
                printf("(4) - TADS\n");
                printf("(5) - TGA\n");
                printf("(6) - CSOC\n");
                printf("Novo - Curso da turma: ");
                scanf("%d", &curso_aux);
                fflush(stdin);
            }
            if (curso_aux == 1)
            {
                pTurma[opcao_alt].curso = INFO;
            }
            else if (curso_aux == 2)
            {
                pTurma[opcao_alt].curso = MEC;
            }
            else if (curso_aux == 3)
            {
                pTurma[opcao_alt].curso = MAMB;
            }
            else if (curso_aux == 4)
            {
                pTurma[opcao_alt].curso = TADS;
            }
            else if (curso_aux == 5)
            {
                pTurma[opcao_alt].curso = TGA;
            }
            else if (curso_aux == 6)
            {
                pTurma[opcao_alt].curso = CSOC;
            }
            menssagem_ACERTO(3);
            system("pause");
            break;
        case 3:
            system("cls");
            printf("----- Dados da turma -----\n");
            imprime_turma(pTurma[opcao_alt]);

            printf("Novo - Ano da turma: ");
            scanf("%d", &pTurma[opcao_alt].ano);
            fflush(stdin);
            while (pTurma[opcao_alt].ano <= 0)
            {
                menssagem_ERRO(-4);
                system("pause");
                system("cls");
                printf("Dados da turma\n");
                imprime_turma(pTurma[opcao_alt]);

                printf("Novo - Ano da turma: ");
                scanf("%d", &pTurma[opcao_alt].ano);
                fflush(stdin);
            }
            menssagem_ACERTO(3);
            system("pause");
            break;
        case 4:
            return -1;
            break;
        }

        op = 'x';
        while (op != 's' && op != 'n')
        {
            printf("Deseja alterar outro atributo (s/n): ");
            scanf("%c", &op);
            fflush(stdin);
            op = tolower(op);

            if (op != 's' && op != 'n')
            {
                menssagem_ERRO(0);
                system("pause");
                system("cls");
            }
            else if (op == 'n')
            {
                atributo = -1;
            }
        }
    }

    return 1;
}

int MENU_alterar_turma()
{
    int op = -1;

    while (op < 1 || op > 3)
    {
        system("cls");
        printf("----- Digite o atributo a ser alterado -----\n");
        printf("(1) - Nome da turma\n");
        printf("(2) - Curso da turma\n");
        printf("(3) - Ano da turma\n");
        printf("(4) - Voltar\n");
        printf("Escolha o atributo: ");
        scanf("%d", &op);
        fflush(stdin);

        if (op < 1 || op > 4)
        {
            menssagem_ERRO(0);
            system("pause");
            system("cls");
        }
        else
        {
            return op;
        }
    }
}

int exclusao_turma()
{
    int opcao_excl = -1, exc = 0;
    char op;

    while (opcao_excl < 0 || opcao_excl >= num_turmas)
    {
        system("cls");
        if (num_turmas == 1)
        {
            op = 'x';
            while (op != 's' && op != 'n')
            {
                imprime_turma(pTurma[0]);
                printf("Deseja excluir a turma [1] ?");
                scanf("%c", &op);
                fflush(stdin);
                op = tolower(op);

                if (op != 's' && op != 'n')
                {
                    menssagem_ERRO(0);
                    system("pause");
                    system("cls");
                }
            }

            if (op == 's')
            {
                excluir_turma(0);
                exc = 1;
            }

            break;
        }
        else
        {
            lista_turma();
            printf("Digite a turma que deseja excluir [%d - %d]: ", 1, num_turmas);
            scanf("%d", &opcao_excl);
            fflush(stdin);
            opcao_excl--;

            if (opcao_excl < 0 || opcao_excl >= num_turmas)
            {
                menssagem_ERRO(-4);
                system("pause");
                system("cls");
            }
            else
            {
                op = 'x';
                while (op != 's' && op != 'n')
                {
                    imprime_turma(pTurma[opcao_excl]);
                    printf("Deseja excluir a turma [%d]: (s/n): ", opcao_excl + 1);
                    scanf("%c", &op);
                    fflush(stdin);
                    op = tolower(op);

                    if (op != 's' && op != 'n')
                    {
                        menssagem_ERRO(0);
                        system("pause");
                        system("cls");
                    }
                }
                if (op == 's')
                {
                    excluir_turma(opcao_excl);
                    exc = 1;
                }
                else if (op == 'n')
                {
                    break;
                }
            }
        }
    }

    if (exc)
    {
        menssagem_ACERTO(4);
        system("pause");
        system("cls");
    }
}

void excluir_turma(int opcao_excl)
{
    if ((num_turmas == 1) && (opcao_excl == num_turmas))
    {
        free(pTurma);
        num_turmas--;
    }
    else
    {
        reorganizar_turma(opcao_excl);
    }
}

void reorganizar_turma(int opcao_excl)
{
    int i;

    for (i = opcao_excl; i < (num_turmas - 1); i++)
    {
        pTurma[i] = pTurma[i + 1];
    }
    num_turmas--;
}

int validaData(int dia, int mes, int ano)
{

    if (dia < 1 || dia > 31)
    {

        return 0;
    }

    else if (mes < 1 || mes > 12)
    {

        return 0;
    }

    else if (mes < 0)
    {

        return 0;
    }

    else if (mes == 2)
    {

        if (dia > 29)
        {

            return 0;
        }
        else if (!(ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0 && (dia > 28))
        {

            return 0;
        }
    }

    else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia > 30))
    {

        return 0;
    }

    return 1;
}

void menssagem_ACERTO(int codigoACERTO)
{
    switch (codigoACERTO)
    {
    case 1:
        printf("\nInclusao bem sucedida!!!\n");
        break;
    case 2:
        printf("Saindo!!!\n");
        break;
    case 3:
        printf("\nAlteracao bem sucedida!!!\n");
        break;
    case 4:
        printf("\nExclusao bem sucedida!!!\n");
        break;
    default:
        break;
    }
}

void menssagem_ERRO(int codigoERRO)
{

    switch (codigoERRO)
    {
    case 0:
        printf("ERRO: Opcao invalida!!!\n");
        break;
    case -1:
        printf("ERRO: Falha na alocacao de memoria!!!\n");
        break;
    case -2:
        printf("ERRO: Lista de turma vazia!!!\n");
        break;
    case -3:
        printf("ERRO: Falha ao salvar no arquivo!!!\n");
        break;
    case -4:
        printf("ERRO: Digite corretamente!!!\n");
        break;
    default:
        printf("ERRO!!!\n");
        break;
    }
}
void DisparaMenuTime()
{
    if (num_times == 0)
    {
        switch (MenuTime0())
        {
        case 1:
            IncluirTime();
            break;
        case 2:
            DisparaMenuPrincipal();
            break;
        default:
            MensagemErro(0);
            break;
        }
    }
    else
    {
        switch (MenuTime())
        {
        case 1:
            IncluirTime();
            break;
        case 2:
            DisparaAlterarTime();
            break;
        case 3:
            DisparaExcluirTime();
            break;
        case 4:
            DisparaListarTimes();
            break;
        case 5:
            DisparaMenuPrincipal();
            break;
        default:
            MensagemErro(0);
            break;
        }
    }
}

int MenuTime0()
{
    int op;

    printf("MENU TIME\n");
    printf("\t1-INCLUIR\n\t2-VOLTAR\n");
    scanf("%d", &op);
    fflush(stdin);
    return op;
}

int MenuTime()
{
    int op;

    printf("MENU TIME\n");
    printf("\t1-INCLUIR\n\t2-ALTERAR\n\t3-EXCLUIR\n\t4-LISTAR\n\t5-VOLTAR\n");
    scanf("%d", &op);
    fflush(stdin);
    return op;
}

void IncluirTime()
{
    char strAux[30];

    if (num_times == 0)
    {
        pTime = (Ttime *)malloc(sizeof(Ttime));
    }
    else
    {
        pTime = (Ttime *)realloc(pTime, sizeof(Ttime) * (num_times + 1));
    }
    pTime[num_times].posicao_jogador = 0;
    pTime[num_times].posicao_turma = 0;

    printf("NOME DO TIME: \n");
    gets(strAux);
    fflush(stdin);

    pTime[num_times].nome = (char *)malloc(sizeof(char) * strlen(strAux));
    strcpy(pTime[num_times].nome, strAux);

    printf("NOME DO TECNICO: \n");
    gets(strAux);
    fflush(stdin);

    pTime[num_times].tecnico = (char *)malloc(sizeof(char) * strlen(strAux));
    strcpy(pTime[num_times].tecnico, strAux);

    IncluirJogador(num_times, pTime[num_times].posicao_jogador);

    num_times++;
}

void IncluirJogador(int time, int jogador)
{
    char strAux[100];
    if (pTime[time].posicao_jogador == 0)
    {
        pTime[time].jogadores = (Tjogador *)malloc(sizeof(Tjogador));
    }
    else
    {
        pTime[time].jogadores = (Tjogador *)realloc(pTime[time].jogadores, sizeof(Tjogador) * (pTime[time].posicao_jogador + 1));
    }

    if (pTime[time].posicao_turma == 0)
    {
        pTime[time].turmas = (int *)malloc(sizeof(int) * pTime[time].posicao_turma);
    }
    else
    {
        pTime[time].turmas = (int *)realloc(pTime[time].turmas, sizeof(int) * (pTime[time].posicao_turma + 1));
    }

    pTime[time].jogadores[jogador].pos_posicao = 0;
    printf("NOME DO JOGADOR: \n");
    gets(strAux);
    fflush(stdin);
    pTime[time].jogadores[jogador].nome = (char *)malloc(sizeof(char) * strlen(strAux));
    strcpy(pTime[time].jogadores[jogador].nome, strAux);
    printf("MATRICULA DO JOGADOR: \n");
    gets(strAux);
    fflush(stdin);
    pTime[time].jogadores[jogador].matricula = (char *)malloc(sizeof(char) * strlen(strAux));
    strcpy(pTime[time].jogadores[jogador].matricula, strAux);
    printf("NUMERO DA CAMISA: \n");
    do
    {
        scanf("%d", &pTime[time].jogadores[jogador].num_Camisa);
        fflush(stdin);
    } while (pTime[time].jogadores[jogador].num_Camisa < 1);
    AtribuiPosicao(num_times, 0);
    while (1)
    {
        printf("DATA DE NASCIMENTO DO JOGADOR (DD/MM/AAAA): \n)");
        scanf("%d%d%d", &pTime[time].jogadores[jogador].data_Nasc.dia, &pTime[time].jogadores[jogador].data_Nasc.mes,
              &pTime[time].jogadores[jogador].data_Nasc.ano);
        fflush(stdin);
        if (VerificaDt(pTime[time].jogadores[jogador].data_Nasc.dia, pTime[time].jogadores[jogador].data_Nasc.mes, pTime[time].jogadores[jogador].data_Nasc.ano) == 1)
        {
            break;
        }
        else
        {
            MensagemErro(0);
        }
    }

    pTime[num_times].posicao_jogador++;

    AtribuiTurma(time, jogador);
}

void AtribuiTurma(int time, int jogador)
{
    int turmaAux;

    printf("TURMA DO JOGADOR: \n");
    lista_turma();
    while (1)
    {
        scanf("%d", &turmaAux);
        fflush(stdin);
        if (turmaAux < 1 || turmaAux > num_turmas)
        {
            MensagemErro(1);
        }
        else if (VerificaTurma(time, turmaAux) == 0)
        {
            pTime[time].jogadores[jogador].turma = turmaAux;
            break;
        }
        else if (VerificaTurma(time, turmaAux) == 2)
        {
            pTime[time].jogadores[jogador].turma = turmaAux;
            pTime[time].turmas[pTime[time].posicao_turma] = turmaAux;
            pTime[time].posicao_turma++;
            break;
        }
        else
        {
            MensagemErro(3);
        }
    }
}

void AtribuiPosicao(int op1, int op2)
{
    int i;

    printf("POSICAO DO JOGADOR: \n");
    printf("\t1-GOLEIRO\n\t2-FIXO\n\t3-ALA DIREITA\n\t4-ALA ESQUERDA\n\t5-PIVO\n");
    for (i = 0; i < 6; i++)
    {
        pTime[op1].jogadores[op2].pos_posicao++;
        if (pTime[op1].jogadores[op2].pos_posicao == 0)
        {
            pTime[op1].jogadores[op2].posicao = (enum_posicao *)malloc(sizeof(enum_posicao) * pTime[op1].jogadores[op2].pos_posicao);
        }
        else
        {
            pTime[op1].jogadores[op2].posicao = (enum_posicao *)realloc(pTime[op1].jogadores[op2].posicao, sizeof(enum_posicao) * pTime[op1].jogadores[op2].pos_posicao);
        }

        do
        {
            scanf("%d", &pTime[op1].jogadores[op2].posicao[i]);
            fflush(stdin);
            if (pTime[op1].jogadores[op2].posicao[i] > 5 || pTime[op1].jogadores[op2].posicao[i] < 1)
            {
                MensagemErro(0);
            }
        } while (pTime[op1].jogadores[op2].posicao[i] > 5 || pTime[op1].jogadores[op2].posicao[i] < 1);
        printf("DESEJA ADICIONAR MAIS UMA POSICAO: s/n\n");
        if (SimOuNao() == 0)
        {
            break;
        }
    }
}

int VerificaTurma(int time, int turmaAux)
{
    int i, controle = 0;

    for (i = 0; i < pTime[time].posicao_turma; i++)
    {
        if (turmaAux == pTime[time].turmas[i])
        {
            return 0;
        }
        else if (pTime[time].turmas[i] != -1)
        {
            controle++;
        }
    }
    if (controle == 2)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

void DisparaAlterarTime()
{
    int op1 = -1, op2 = 0;

    printf("QUAL TIME GOSTARIA DE ALTERAR?\n");
    ListaTimesBasico();
    printf("\t%d-VOLTAR\n", num_times + 1);
    while (op1 < 1 || op1 > num_times + 1)
    {
        scanf("%d", &op1);
        fflush(stdin);

        if (op1 < 1 || op1 > num_times + 1)
        {
            MensagemErro(4);
        }
        else if (op1 == num_times + 1)
        {
            DisparaMenuTime();
        }
        else
        {
            ListarUmTime(op1);
            printf("O QUE GOSTARIA DE ALTERAR?\n");
            printf("\t1-NOME DO TIME\n\t2-TNOME DO TECNICO\n\t3-JOGADORES\n\t4-VOLTAR\n");
            while (op2 < 1 || op2 > 4)
            {
                scanf("%d", &op2);
                fflush(stdin);

                if (op2 < 1 || op2 > 6)
                {
                    MensagemErro(0);
                }
            }
            AlterarTime(op1, op2);
        }
    }
}

void AlterarTime(int op1, int op2)
{
    char strAux[100];

    switch (op2)
    {
    case 1:
        printf("NOVO NOME DO TIME:\n");
        gets(strAux);
        fflush(stdin);
        printf("TEM CERTEZA QUE QUER MUDAR O NOME DO TIME? s/n\n");

        if (SimOuNao() == 1)
        {
            pTime[op1 - 1].nome = (char *)realloc(NULL, sizeof(char) * strlen(strAux));
            strcpy(pTime[op1 - 1].nome, strAux);
        }
        break;
    case 2:
        printf("NOVO NOME DO TECNICO:\n");
        gets(strAux);
        fflush(stdin);
        printf("TEM CERTEZA QUE QUER MUDAR O NOME DO TECNICO? s/n\n");

        if (SimOuNao() == 1)
        {
            pTime[op1 - 1].tecnico = (char *)realloc(NULL, sizeof(char) * strlen(strAux));
            strcpy(pTime[op1 - 1].tecnico, strAux);
        }
        break;
    case 3:
        DisparaMenuJogadores(op1 - 1);
        break;
    default:
        DisparaMenuTime();
        break;
    }
}

void DisparaMenuJogadores(int time)
{
    if (pTime[time].posicao_jogador == 0)
    {
        switch (MenuJogadores0())
        {
        case 1:
            IncluirJogador(time, pTime[time].posicao_jogador);
            break;
        default:
            DisparaAlterarTime();
            break;
        }
    }
    else
    {
        switch (MenuJogadores())
        {
        case 1:
            IncluirJogador(time, pTime[time].posicao_jogador);
            break;
        case 2:
            DisparaAlterarJogador(time);
            break;
        case 3:
            DisparaExcluirJogador(time);
            break;
        default:
            DisparaAlterarTime();
            break;
        }
    }
}

int MenuJogadores()
{
    int op = 0;
    while (op < 1 || op > 4)
    {
        printf("\t1-INCLUIR JOGADOR\n\t2-ALTERAR JOGADOR\n\t3-EXCLUIR JOGADOR\n\t4-VOLTAR");
        scanf("%d", &op);
        fflush(stdin);
        if (op < 1 || op > 4)
        {
            MensagemErro(0);
        }
    }

    return op;
}

int MenuJogadores0()
{
    int op = 0;
    while (op < 1 || op > 2)
    {
        printf("\t1-INCLUIR JOGADOR\n\t2-VOLTAR");
        scanf("%d", &op);
        fflush(stdin);
        if (op < 1 || op > 2)
        {
            MensagemErro(0);
        }
    }

    return op;
}

void DisparaAlterarJogador(int time)
{
    int op1 = 0, op2 = 0;

    printf("QUAL JOGADOR GOSTARIA DE ALTERAR?\n");
    ListaJogadoresBasico(time);
    printf("\t%d-VOLTAR\n", pTime[time].posicao_jogador + 1);
    while (op1 < 1 || op1 > pTime[time].posicao_jogador + 1)
    {
        scanf("%d", &op1);
        fflush(stdin);

        if (op1 < 1 || op1 > pTime[time].posicao_jogador + 1)
        {
            MensagemErro(5);
        }
        else if (op1 == pTime[time].posicao_jogador + 1)
        {
            DisparaMenuJogadores(time);
        }
        else
        {
            ListarUmJogador(op1, time);
            printf("O QUE GOSTARIA DE ALTERAR?\n");
            printf("\t1-NOME DO JOGADOR\n\t2-MATRICULA\n\t3-NUMERO DA CAMISA\n\t4-POSICOES\n\t5-DATA DE NASCIMENTO\n\t6-TURMA\n\t7-VOLTAR\n");
            while (op2 < 1 || op2 > 7)
            {
                scanf("%d", &op2);
                fflush(stdin);

                if (op2 < 1 || op2 > 7)
                {
                    MensagemErro(0);
                }
            }
            AlterarJogador(op1 - 1, op2, time);
        }
    }
}

void AlterarJogador(int op1, int op2, int time)
{
    char strAux[100];
    int intAux, intAux2, intAux3;

    switch (op2)
    {
    case 1:
        printf("NOVO NOME DO JOGADOR:\n");
        gets(strAux);
        fflush(stdin);
        printf("TEM CERTEZA QUE QUER MUDAR O NOME DO JOGADOR? s/n\n");

        if (SimOuNao() == 1)
        {
            pTime[time].jogadores[op1].nome = (char *)realloc(NULL, sizeof(char) * strlen(strAux));
            strcpy(pTime[time].jogadores[op1].nome, strAux);
        }
        break;
    case 2:
        printf("NOVA MATRICULA DO JOGADOR:\n");
        gets(strAux);
        fflush(stdin);
        printf("TEM CERTEZA QUE QUER MUDAR A MATRICULA DO JOGADOR? s/n\n");

        if (SimOuNao() == 1)
        {
            pTime[time].jogadores[op1].matricula = (char *)realloc(NULL, sizeof(char) * strlen(strAux));
            strcpy(pTime[time].jogadores[op1].matricula, strAux);
        }
        break;
    case 3:
        printf("NOVA CAMISA DO JOGADOR:\n");
        scanf("%d", &intAux);
        fflush(stdin);
        printf("TEM CERTEZA QUE QUER MUDAR CAMISA DO JOGADOR? s/n\n");

        if (SimOuNao() == 1)
        {
            pTime[time].jogadores[op1].num_Camisa = intAux;
        }
        break;
    case 4:
        DisparaMenuPosicao(time, op1);
        break;
    case 5:
        printf("NOVA DATA DE NASCIMENTO DO JOGADOR (DD/MM/AAAA): \n)");
        do
        {
            scanf("%d%d%d", &intAux, &intAux2, &intAux3);
            fflush(stdin);
        } while (VerificaDt(intAux, intAux2, intAux3) == 1);

        if (SimOuNao() == 1)
        {
            pTime[time].jogadores[op1].data_Nasc.dia = intAux;
            pTime[time].jogadores[op1].data_Nasc.mes = intAux2;
            pTime[time].jogadores[op1].data_Nasc.ano = intAux3;
        }
        break;
    case 6:
        AtribuiTurma(time, op1);
        break;
    default:
        DisparaAlterarTime();
        break;
    }
}

void DisparaMenuPosicao(int time, int jogador)
{
    if (pTime[time].jogadores[jogador].pos_posicao == 5)
    {
        switch (MenuPosicaoFinal())
        {
        case 1:
            break;
        default:
            DisparaAlterarTime();
            break;
        }
    }
    else if (pTime[time].jogadores[jogador].pos_posicao == 1)
    {
        switch (MenuPosicao0())
        {
        case 1:
            AtribuiPosicao(time, jogador);
            break;
        default:
            DisparaAlterarTime();
            break;
        }
    }
    else
    {
        switch (MenuPosicao())
        {
        case 1:
            AtribuiPosicao(time, jogador);
            break;
        default:
            DisparaAlterarTime();
            break;
        }
    }
}

int MenuPosicao()
{
    int op = 0;

    printf("\t1-INCLUIR POSICAO\n\t2-ALTERAR POSICAO\n\t3-EXCLUIR POSICAO\n\t4-VOLTAR\n");
    while (op < 1 || op > 4)
    {
        scanf("%d", &op);
        fflush(stdin);
        if (op < 1 || op > 4)
        {
            MensagemErro(0);
        }
    }
    return op;
}

int MenuPosicao0()
{
    int op = 0;

    printf("\t1-INCLUIR POSICAO\n\t2-ALTERAR POSICAO\n\t3-VOLTAR\n");
    while (op < 1 || op > 3)
    {
        scanf("%d", &op);
        fflush(stdin);
        if (op < 1 || op > 3)
        {
            MensagemErro(0);
        }
    }
    return op;
}

int MenuPosicaoFinal()
{
    int op = 0;

    printf("t1-ALTERAR POSICAO\n\t2-EXCLUIR POSICAO\n\t3-VOLTAR\n");
    while (op < 1 || op > 3)
    {
        scanf("%d", &op);
        fflush(stdin);
        if (op < 1 || op > 3)
        {
            MensagemErro(0);
        }
    }
    return op;
}

void AlterarPosicao(int time, int jogador)
{
    int i, posAux;

    printf("NOVA POSICAO DO JOGADOR: \n");
    printf("\t1-GOLEIRO\n\t2-FIXO\n\t3-ALA DIREITA\n\t4-ALA ESQUERDA\n\t5-PIVO\n");
    for (i = 1; 1; i++)
    {
        do
        {
            scanf("%d", &posAux);
            fflush(stdin);
            if (posAux > 5 || posAux < 1)
            {
                MensagemErro(0);
            }
        } while (posAux > 5 || posAux < 1);
        printf("DESEJA ALTERAR A POSICAO: s/n\n");
        if (SimOuNao() == 1)
        {
            pTime[time].jogadores[jogador].posicao = posAux;
        }
        break;
    }
}

void ExcluirPosicao(int time, int jogador)
{
    int i;

    printf("QUAL POSICAO DESEJA EXCLUIR: \n");
    for (i = 0; i < pTime[time].jogadores[jogador].pos_posicao; i++)
    {
        printf("");
    }
}

void DisparaExcluirJogador(int time)
{
    int op = -1;

    printf("QUAL JOGADOR DESEJA EXCLUIR?\n");
    ListaJogadoresBasico(time);
    printf("\t%d-VOLTAR\n", pTime[time].posicao_jogador + 1);

    while (op < 1 || op > pTime[time].posicao_jogador + 1)
    {
        scanf("%d", &op);
        fflush(stdin);

        if (op < 1 || op > pTime[time].posicao_jogador + 1)
        {
            MensagemErro(1);
        }
        else if (op == pTime[time].posicao_jogador + 1)
        {
            DisparaMenuJogadores(time);
        }
    }
    printf("TEM CERTEZA QUE QUER EXCLUIR O JOGADOR %d? s/n\n", op);
    if (SimOuNao() == 1)
    {
        ExcluirJogador(op, time);
    }
}

void ExcluirJogador(int op, int time)
{

    for (int i = op - 1; i < pTime[time].posicao_jogador - 1; i++)
    {
        pTime[time].jogadores[i + 1] = pTime[time].jogadores[i + 1];
    }

    pTime[time].jogadores = (Tjogador *)realloc(pTime[time].jogadores, sizeof(Tjogador) * pTime[time].posicao_jogador--);
}

void ListaJogadoresBasico(int time)
{
    for (int i = 0; i < pTime[time].posicao_jogador; i++)
    {
        printf("jogador %d: %s\n", i + 1, pTime[time].jogadores[i].nome);
    }
}

void DisparaExcluirTime()
{
    int op = -1;

    printf("QUAL TIME DESEJA EXCLUIR?\n");
    ListaTimesBasico();
    printf("\t%d-VOLTAR\n", num_times + 1);

    while (op < 1 || op > num_times + 1)
    {
        scanf("%d", &op);
        fflush(stdin);

        if (op < 1 || op > num_times + 1)
        {
            MensagemErro(1);
        }
        else if (op == num_times + 1)
        {
            DisparaMenuTime();
        }
    }
    printf("TEM CERTEZA QUE QUER EXCLUIR O TIME %d? s/n\n", op);
    if (SimOuNao() == 1)
    {
        ExcluirTime(op);
    }
}

void ExcluirTime(int op)
{
    for (int i = op - 1; i < num_times - 1; i++)
    {
        pTime[i] = pTime[i + 1];
    }

    pTime = (Ttime *)realloc(pTime, sizeof(Ttime) * (num_times--));
}

void DisparaListarTimes()
{
    int op = 0;

    printf("LISTAR TIMES\n");
    printf("\t1-LISTAR UM TIME\n\t2-LISTAR TODOS\n\t3-VOLTAR\n");
    while (op < 1 || op > 3)
    {
        scanf("%d", &op);
        fflush(stdin);
        if (op < 1 || op > 3)
        {
            MensagemErro(0);
        }
    }
    switch (op)
    {
    case 1:
        DisparaListarUmTime();
        break;
    case 2:
        ListarTodosTimes();
        break;
    default:
        DisparaMenuTime();
        break;
    }
}

void DisparaListarUmTime()
{
    int op = -1;

    printf("QUAL TIME VOCE DESEJA LISTAR?\n");
    ListaTimesBasico();
    printf("\t%d-VOLTAR\n", num_times + 1);
    while (op < 1 || op > num_times + 1)
    {
        scanf("%d", &op);
        fflush(stdin);
        if (op < 0 || op > num_times + 1)
        {
            MensagemErro(1);
        }
        else if (op == num_times + 1)
        {
            DisparaListarTimes();
        }
        else
        {
            ListarUmTime(op);
        }
    }
}

void ListaTimesBasico()
{
    int i;

    for (i = 0; i < num_times; i++)
    {
        printf("time %d: %s\n", i + 1, pTime[i].nome);
    }
}

void ListarTodosTimes()
{
    for (int i = 0; i < num_times; i++)
    {
        ListarUmTime(i + 1);
        printf("\n");
    }
}

void ListarUmTime(int op)
{
    printf("\tNOME DO TIME %d: %s\n", op, pTime[op - 1].nome);
    printf("\tNOME DO TECNICO DO TIME %d: %s\n", op, pTime[op - 1].tecnico);
    ListarTodosJogadores(op - 1);
    for (int i = 0; i < pTime[op - 1].posicao_turma; i++)
    {
        printf("\tTURMA %d DO TIME: %s", i + 1, pTurma[i].nome);
    }
}

void ListarTodosJogadores(int time)
{
    for (int i = 0; i < pTime[time].posicao_jogador; i++)
    {
        ListarUmJogador(i, time);
    }
}

void ListarUmJogador(int op, int time)
{
    printf("\tNOME DO JOGADOR %d: %s\n", op + 1, pTime[time].jogadores[op].nome);
    printf("\tMATRICULA DO JOGADOR %d: %s\n", op + 1, pTime[time].jogadores[op].matricula);
    printf("\tDATA DE NASCIMENTO DO JOGADOR %d: %d/%d/%d\n", op + 1, pTime[time].jogadores[op].data_Nasc.dia, pTime[time].jogadores[op].data_Nasc.mes, pTime[time].jogadores[op].data_Nasc.ano);
    printf("\tTURMA DO JOGADOR %d: %s\n", op + 1, pTurma[pTime[time].jogadores[op].turma - 1].nome);
    printf("\tNUMERO DA CAMISA DO JOGADOR %d: %d\n", op + 1, pTime[time].jogadores[op].num_Camisa);
    for (int i = 0; i < pTime[time].jogadores[op].pos_posicao; i++)
    {
        ListarPosicao(pTime[time].jogadores[op].turma, i + 1, op + 1);
    }
}

void ListarPosicao(int posicao, int op, int jogador)
{
    switch (posicao)
    {
    case Goleiro:
        printf("\t%dª POSICAO DO JOGADOR %d: GOLEIRO\n", op, jogador);
        break;
    case Fixo:
        printf("\t%dª POSICAO DO JOGADOR %d: FIXO\n", op, jogador);
        break;
    case AlaD:
        printf("\t%dª POSICAO DO JOGADOR %d: ALA DIREITA\n", op, jogador);
        break;
    case AlaE:
        printf("\t%dª POSICAO DO JOGADOR %d: ALA ESQUERDA\n", op, jogador);
        break;
    case Pivo:
        printf("\t%dª POSICAO DO JOGADOR %d: PIVO\n", op, jogador);
        break;
    }
}
