#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 50


typedef enum
{
   INFO,
   MEC,
   MAMB,
   TADS,
   TGA,
   CSOC
} Ecurso;


typedef struct
{


   char *nome;
   Ecurso curso;
   int ano;


} Tturma;


typedef enum
{


   Goleiro,
   AlaD,
   AlaE,
   Fixo,
   Pivo
} Eposicao;


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
   Eposicao *posicao; // TALVEZ TENHA QUE SER PONTEIRO POR QUE UM JOGADOR PODE JOGAR EM MAIS DE UMA POSICAO
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
   int pos_jogador;
   int pos_turma;


} Ttime;


void imprime_Erro();          // função de mensagem de erro
void menuPrincipal();         // Menu Turma e Time
int op_MenuPrincipal(int op); // Chama as funções de cada opção
void menuTurma();             // Ramifica nas opções de Turma
int op_MenuTurma(int op);     // Chama as funções de cada opção
void incluirTurma();          // Alocação de memória e Inclusão no vetor global
Tturma criarTurma();          // Lê os dados do Usuário
void imprimeTurma();
void menu_ListarTurma();
void op_MenuListTurmas(int op);
void listaTurmas();
void menu_AlteraTurma();
void alterarTurma(int op, int turma);
int confirmaEscolha();
void menuExclui_Turma();
void excluirTurma();
char *leitorString(char **string);
void incluirTime();
Ttime criarTime();
void menuTime();         // Ramifica nas opções de Time
int op_MenuTime(int op); // Chama as funções de cada opção
void incluirJogador(int pos);
Tjogador criaJogador();
void menu_ListTime();
void op_MenuListTime(int op);
void listaTimes();
void imprimeTime();
void imprimeJogador();
void freeMemory();      // Ao fim libera as memórias ou recebe o argumento da memória que de ve ser liberada
void checkNull(int op); // Recebe argumento do ponteiro que deve ser checado
int validaData(int dia, int mes, int ano);
void confirmar();
void menuJogador(int pos_time);
int comparaTurma(Tturma turma1, Tturma turma2);
int limiteTurmas_Time(int pos, Tturma turma);
void menuAlteraTime();
void op_MenuAlteraTime(int op);
void alteraNomeTime();
void alteraNomeTecnico();
void menuAtualizaJogador();
void op_AtualizaJogador(int op);
void menuAlteraJogador();
void op_MenuAlteraJogador();
int menu_QualJogador(int i);
int menu_QualTime();
void altera_NomeJogador();
void altera_MatriculaJogador();
void altera_CamisaJogador();
void menu_alteraPosicao();
void op_MenuAlteraPosicao(int op);
void incluirPosicao();
void excluirPosicao();
void alterarPosicao();
void altera_DtNascJogador();
void altera_TurmaJogador();
void adicionarJogador();
void excluirTime();
void excluirJogador();
int mensagemPadraoTurma(int i);
void imprimeEnum(int op);
void imprimePosicao(int op);


Ttime *_Times;
Tturma *_Turmas;
int pos_Turma = 0;
int pos_Time = 0;


int main()
{
   menuPrincipal();
}


void menuPrincipal()
{
   int op = 1;


   while (op != 3)
   {
       if (op < 1 || op > 2)
       {
           imprime_Erro(1);
       }
       printf("\nLIGA CORUJA DE FUTSAL\n");
       printf("1. TURMA\n");
       printf("2. TIME\n");
       printf("3. SAIR\n");
       printf("OPCAO: ");
       scanf("%d", &op);


       if (op == 3)
       {
           confirmar();
       }


       op_MenuPrincipal(op);
   }
}


int op_MenuPrincipal(int op)
{
   switch (op)
   {
   case 1:
       menuTurma();
       break;
   case 2:
       menuTime();
       break;
   default:
       break;
   }
}


void menuTurma()
{


   int op = 1;


   while (op != 5)
   {
       if (op < 1 || op > 5)
       {
           imprime_Erro(1);
       }


       printf("\nMENU TURMA\n");
       printf("1. INCLUIR\n");
       printf("2. ALTERAR\n");
       printf("3. EXCLUIR\n");
       printf("4. LISTAR\n");
       printf("5. VOLTAR\n");
       printf("OPCAO: ");
       scanf("%d", &op);
       fflush(stdin);
       op_MenuTurma(op);
   }
}


int op_MenuTurma(int op)
{
   int i;
   switch (op)
   {
   case 1:
       incluirTurma();
       break;
   case 2:
       menu_AlteraTurma();
       break;
   case 3:
       excluirTurma();
       break;
   case 4:
       menu_ListarTurma();
       break;
   default:
       break;
   }
}


void incluirTurma()
{
   if (pos_Turma == 0)
   {
       _Turmas = (Tturma *)malloc(1 * sizeof(Tturma));


       checkNull(1);
   }
   else
   {
       //_Turmas = (Tturma *)realloc(_Turmas, 1 * sizeof(Tturma));
       _Turmas = (Tturma *)realloc(_Turmas, (pos_Turma + 1) * sizeof(Tturma));


       checkNull(1);
   }


   _Turmas[pos_Turma++] = criarTurma();


   checkNull(1);
}


Tturma criarTurma()
{
   Tturma turma;
   char string[50];


   printf("\n");
   printf("TURMA [%d] - \n", pos_Turma);
   printf("Nome da Turma: ");
   turma.nome = leitorString(&turma.nome);
   printf("- INFO (1)\t- TADS (4)\n- MEC  (2)\t- TGA  (5)\n- MAMB (3)\t- CSOC (6)\n");
   printf("Curso: ");
   scanf("%d", &turma.curso);
   printf("Ano: ");
   scanf("%d", &turma.ano);


   return turma;
}


int mensagemPadraoTurma(int msg)
{
   int i = 0;


   if (pos_Turma > 1)
   {
       i = -1;
       while (i < 0 || i >= pos_Turma)
       {
           printf("\n");
           switch (msg)
           {
           case 1:
               printf("Qual turma deseja alterar? ");


               break;
           case 2:
               printf("Qual turma deseja excluir? ");


               break;
           case 3:
               printf("Qual turma deseja listar? ");
               break;
           }
           scanf("%d", &i);
           i--;


           if (i < 0 || i >= pos_Turma)
           {
               imprime_Erro(3);
           }
       }
   }
   return i;
}


void menu_AlteraTurma()
{


   int i, atr = 0;
   char op = 's', conf;


   if (pos_Turma == 0)
   {
       imprime_Erro(4);
   }
   else
   {
       system("cls");
       printf("\nALTERACAO DE TURMA - \n");
       listaTurmas();


       i = mensagemPadraoTurma(1);
       printf("\n");
       printf("1. Nome\n");
       printf("2. Curso\n");
       printf("3. Ano\n");
       while (atr < 1 || atr > 3)
       {
           printf("Qual atributo deseja alterar? ");
           scanf("%d", &atr);
           fflush(stdin);
           if (atr < 1 || atr > 3)
           {
               imprime_Erro(5);
           }
       }
       printf("\n");
       alterarTurma(atr, i);
   }
}


void alterarTurma(int atr, int i)
{
   char string[50];
   int curso, ano;


   printf("TURMA [%d] - \n", i + 1);


   switch (atr)
   {
   case 1:
       printf("Nome: ");
       scanf("%s", &string);
       fflush(stdin);
       if (confirmaEscolha() == 1)
       {
           _Turmas[i].nome = (char *)malloc((strlen(string) + 1) * sizeof(char));


           if (_Turmas[i].nome == NULL)
           {
               imprime_Erro(2);
           }


           strcpy(_Turmas[i].nome, string);
           printf("Alteracao concluida!\n");
       }
       break;
   case 2:
       printf("- INFO (1)\t- TADS (4)\n- MEC  (2)\t- TGA  (5)\n- MAMB (3)\t- CSOC (6)\n");
       printf("Curso: ");
       scanf("%d", &curso);
       if (confirmaEscolha() == 1) // if else só de uam linha
       {
           _Turmas[i].curso = curso;
           printf("Alteracao concluida!\n"); // mensagem dentro da função confirmar escolha
       }
       break;
   case 3:
       printf("Ano: ");
       scanf("%d", &ano);
       if (confirmaEscolha() == 1)
       {
           _Turmas[i].ano = ano;
           printf("Alteracao concluida!\n");
       }
       break;
   default:
       break;
   }
}


void menuExclui_Turma()
{
}


void excluirTurma()
{
   int j, pos;


   if (pos_Turma == 0)
   {
       imprime_Erro(4);
   }
   else
   {


       printf("\nEXCLUSAO DE TURMAS - \n");
       listaTurmas();
       pos = mensagemPadraoTurma(2);


       printf("\n");
   }


   if (confirmaEscolha() == 1)
   {


       if (pos == 0 && pos_Turma == 1) // if (posJ == 0 && _Times[posT].pos_jogador == 1)
       {


           pos_Turma--;
           free(_Turmas);
       }
       else if ((pos_Turma - 1) == pos)
       {
           pos_Turma--;
           _Turmas = (Tturma *)realloc(_Turmas, pos_Turma * sizeof(Tturma));


           if (_Turmas == NULL)
           {
               imprime_Erro(13);
               freeMemory();
               exit(1);
           }
       }
       else
       {
           for (j = pos; j < pos_Turma; j++)
           {
               _Turmas[pos] = _Turmas[pos + 1];
           }
           pos_Turma--;


           _Turmas = (Tturma *)realloc(_Turmas, pos_Turma * sizeof(Tturma));


           if (_Turmas == NULL)
           {
               imprime_Erro(13);
               freeMemory();
               exit(1);
           }
           printf("\nTurma Excluida Com Sucesso!\n"); // DEEJA CONTINUAR EXCLUINDO?
       }
   }
}


void menu_ListarTurma()
{
   int op = 1;


   if (pos_Turma == 0)
   {
       printf("\n");
       imprime_Erro(4);
   }
   else
   {


       while (op != 3)
       {
           if (op < 1 || op > 2)
           {
               imprime_Erro(1);
           }
           printf("\nMENU LISTAR TURMA - \n");
           printf("1. LISTAR TURMA\n");
           printf("2. LISTAR TODAS AS TURMAS\n");
           printf("3. VOLTAR\n");
           printf("OPCAO: ");
           scanf("%d", &op);
           op_MenuListTurmas(op);
       }
   }
}


void op_MenuListTurmas(int op)
{
   switch (op)
   {
   case 1:
       imprimeTurma();
       break;
   case 2:
       listaTurmas();
       break;
   default:
       break;
   }
}


void imprimeTurma()
{
   int i = -1;


   i = mensagemPadraoTurma(3);
   printf("TURMA [%d]\n", i + 1);
   printf("Nome - %s\n", _Turmas[i].nome);
   printf("Ano - %d\n", _Turmas[i].ano);
   imprimeEnum(_Turmas[i].curso);
}


void listaTurmas()
{
   int i;


   for (i = 0; i < pos_Turma; i++)
   {
       printf("\nTURMA [%d] - \n", i + 1);
       printf("Nome - %s\n", _Turmas[i].nome);
       printf("Ano - %d\n", _Turmas[i].ano);
       imprimeEnum(_Turmas[i].curso);
       printf("\n");
   }
}


void menuTime()
{
   int op = 1;


   if (pos_Turma > 0)
   {
       while (op != 5)
       {
           if (op < 1 || op > 5)
           {
               imprime_Erro(1);
           }


           printf("\nMENU TIME\n");
           printf("1. INCLUIR\n");
           printf("2. ALTERAR\n");
           printf("3. EXCLUIR\n");
           printf("4. LISTAR\n");
           printf("5. VOLTAR\n");


           printf("OPCAO: ");
           scanf("%d", &op);
           op_MenuTime(op);
       }
   }
   else
   {
       imprime_Erro(4);
   }
}


int op_MenuTime(int op)
{
   switch (op)
   {
   case 1:
       incluirTime();
       menuJogador(pos_Time - 1);
       break;
   case 2:
       menuAlteraTime();


       break;
   case 3:
       excluirTime();
       break;
   case 4:
       menu_ListTime();
       break;
   default:
       break;
   }
}


void incluirTime()
{
   int i;
   char op = 's';


   if (pos_Time == 0)
   {
       _Times = (Ttime *)malloc(1 * sizeof(Ttime));


       checkNull(2);
   }
   else
   {
       _Times = (Ttime *)realloc(_Times, (pos_Time + 1) * sizeof(Ttime));


       checkNull(2);
   }


   _Times[pos_Time++] = criarTime();
}


Ttime criarTime()
{
   Ttime time;
   char str[50];
   char op = 's';
   int i;


   printf("\n");
   printf("TIME [%d] - \n", pos_Time);
   printf("Nome do Time: ");
   time.nome = leitorString(&time.nome);


   printf("Nome do Tecnico: ");
   time.tecnico = leitorString(&time.tecnico);


   time.pos_jogador = 0;
   time.pos_turma = 0;


   return time;
}


void menuJogador(int pos_time)
{


   char op = 's';


   printf("JOGADORES - \n");
   while (op == 's' || op == 'S')
   {
       printf("\n");
       printf("Jogador [%d] - \n", _Times[pos_time].pos_jogador + 1);
       incluirJogador(_Times[pos_time].pos_jogador);
       _Times[pos_time].pos_jogador++;
       printf("Adicionar Jogador? [S/qualquer outro caractere para N]: ");
       scanf(" %c", &op);
       fflush(stdin);
   }
}


void incluirJogador(int pos)
{


   if (pos == 0)
   {
       _Times[pos_Time - 1].jogadores = (Tjogador *)malloc(1 * sizeof(Tjogador));
   }
   else
   {
       _Times[pos_Time - 1].jogadores = (Tjogador *)realloc(_Times[pos_Time - 1].jogadores, (pos + 1) * sizeof(Tjogador));
   }


   if (_Times[pos_Time - 1].jogadores == NULL)
   {
       imprime_Erro(2);
       freeMemory(); // ADICIONAR NAS OUTRAS
       exit(1);
   }


   _Times[pos_Time - 1].jogadores[pos] = criaJogador();
}


Tjogador criaJogador()
{


   Tjogador jogador;
   int i, turma, j, true, k;
   char str[50], op = 's';


   jogador.pos_posicao = 0;


   printf("Nome do Jogador: ");
   jogador.nome = leitorString(&jogador.nome); // TESTAR SE A FUNCAO SÓ RETORNANDO NAO FUNCIONA (É MAIS SEGURO PRO CODIGO)


   printf("Matricula: ");
   jogador.matricula = leitorString(&jogador.matricula);


   printf("Numero da Camisa: ");
   scanf("%d", &jogador.num_Camisa);


   while (op == 's' || op == 'S')
   {


       if (jogador.pos_posicao == 0)
       {
           jogador.posicao = (Eposicao *)malloc(1 * sizeof(Eposicao));
       }
       else
       {
           jogador.posicao = (Eposicao *)realloc(jogador.posicao, (jogador.pos_posicao + 1) * sizeof(Eposicao));
       }


       if (jogador.posicao == NULL)
       {
           imprime_Erro(2);
           freeMemory(); // ADICIONAR NAS OUTRAS
           exit(1);
       }
       jogador.pos_posicao++;


       printf("Posicao - \n");
       do
       {
           printf("- Goleiro (1)\t- AlaE (4)\n- AlaD (2)\t- Fixo  (5)\n- Pivo (3)\n");
           scanf("%d", &jogador.posicao[jogador.pos_posicao - 1]);
           if (jogador.posicao[jogador.pos_posicao - 1] < 1 || jogador.posicao[jogador.pos_posicao - 1] > 5)
           {
               imprime_Erro(14);
           }
           true = 0;
           for (j = 0; j < (jogador.pos_posicao - 1); j++)
           {
               for (int k = 0; k <= (jogador.pos_posicao - 1); k++)
               {
                   if (jogador.posicao[j] == jogador.posicao[k])
                   {
                       true ++;
                   }
               }
               if (true > 1)
               {
                   imprime_Erro(15);
                   break;
               }
               true = 0;
           }


       } while (jogador.posicao[jogador.pos_posicao - 1] < 1 || jogador.posicao[jogador.pos_posicao - 1] > 5 || true > 1);


       printf("Deseja adicionar outra posicao? [S/qualquer outro caractere para N]: ");
       scanf(" %c", &op);
       fflush(stdin);
   }


   do
   {
       printf("Data de Nascimento - \n");
       printf("Ano: ");
       scanf("%d", &jogador.data_Nasc.ano);
       printf("Mes: ");
       scanf("%d", &jogador.data_Nasc.mes);
       printf("Dia: ");
       scanf("%d", &jogador.data_Nasc.dia);
       if (validaData(jogador.data_Nasc.dia, jogador.data_Nasc.mes, jogador.data_Nasc.ano) == 0)
       {
           imprime_Erro(7);
       }


   } while (validaData(jogador.data_Nasc.dia, jogador.data_Nasc.mes, jogador.data_Nasc.ano) == 0);


   printf("\nTurmas Cadastradas - \n");
   for (i = 0; i < pos_Turma; i++)
   {
       printf("\n");
       printf("Turma [%d] -\n", i + 1);
       printf("Nome - %s\n", _Turmas[i].nome);
       printf("\n");
   }


   do
   {
       printf("Turma do Jogador: ");
       scanf("%d", &turma);
       turma--;
       if (turma < 0 || turma > (pos_Turma - 1))
       {
           imprime_Erro(6);
       }


   } while ((turma < 0 || turma > (pos_Turma - 1)) || (limiteTurmas_Time(_Times[pos_Time - 1].pos_turma, _Turmas[turma]) == 1));


   jogador.turma = _Turmas[turma];
   if (limiteTurmas_Time(_Times[pos_Time - 1].pos_turma, _Turmas[turma]) == 0)
   {
       _Times[pos_Time - 1].turmas[_Times[pos_Time - 1].pos_turma++] = _Turmas[turma];
   }


   return jogador;
}


/*int true = 0, j;


   for (j = 0; j < jogador.pos_posicao; j++)
   {
       for (int k = 0; k <= jogador.pos_posicao; k++)
       {
           if (jogador.posicao[j] == jogador.posicao[k]) // 0 - 1 &&
           {
               true ++;
           }
       }
       if (true > 1)
       {
           imprime_Erro(15);


           break;
       }
       true = 0;
   }*/


int limiteTurmas_Time(int pos, Tturma turma)
{


   if (pos == 0)
   {
       _Times[pos_Time - 1].turmas = (Tturma *)malloc(1 * sizeof(Tturma));
       if (_Times[pos_Time - 1].turmas == NULL)
       {
           imprime_Erro(2);
           exit(1);
       }
       return 0;
   }
   else if (pos == 1)
   {


       if (comparaTurma(_Times[pos_Time - 1].turmas[0], turma) == 1)
       {
           _Times[pos_Time - 1].turmas = (Tturma *)realloc(_Times[pos_Time - 1].turmas, 2 * sizeof(Tturma));
           if (_Times[pos_Time - 1].turmas == NULL)
           {
               imprime_Erro(2);
               exit(1);
           }
           return 0;
       }
       else
       {
           2;
       }
   }
   else
   {
       if (comparaTurma(_Times[pos_Time - 1].turmas[0], turma) == 1 && comparaTurma(_Times[pos_Time - 1].turmas[1], turma) == 1)
       {
           imprime_Erro(12);
           return 1;
       }
       else
       {
           return 2;
       }
   }
}


int comparaTurma(Tturma turma1, Tturma turma2)
{


   return ((turma1.curso == turma2.curso) && (turma1.ano == turma2.ano) && (strcmp(turma1.nome, turma2.nome) == 0)) ? 0 : 1;
}


void menu_ListTime()
{
   int op;


   if (!_Times[pos_Time - 1].jogadores)
   {
       printf("Nao Alocou Memoria\n");
       exit(1);
   }


   if (pos_Time == 0)
   {
       printf("\n");
       imprime_Erro(8);
   }
   else
   {
       printf("\nMENU LISTAR TIME - \n");
       printf("1. LISTAR TIME\n");
       printf("2. LISTAR TODOS OS TIMES\n");
       printf("3. VOLTAR\n");
       printf("OPCAO: ");
       scanf("%d", &op);
       op_MenuListTime(op);
   }
}


void op_MenuListTime(int op)
{
   switch (op)
   {
   case 1:
       imprimeTime();
       break;
   case 2:
       listaTimes();
       break;
   default:
       break;
   }
}


void imprimeTime() // DA PARA MELHORAR ESSA FUNCAO
{
   int i = -1, j;


   if (pos_Time == 1)
   {
       i = 0;
       printf("\n");
       printf("TIME [%d]\n", i + 1);


       printf("Nome - %s\n", _Times[i].nome);
       printf("Tecnico - %s\n\n", _Times[i].tecnico);
       printf("JOGADORES - \n\n", _Times[i].jogadores);


       for (j = 0; j < _Times[i].pos_jogador; j++)
       {
           printf("Jogador [%d] \n", j + 1);
           printf("Nome - %s\n", _Times[i].jogadores[j].nome);
           printf("\n");
       }
   }
   else
   {
       while (i < 0 || i >= pos_Time)
       {
           printf("\n");
           printf("Qual time deseja listar? ");
           scanf("%d", &i);
           i--;
           if (i < 0 || i >= pos_Time)
           {
               imprime_Erro(9);
           }
       }
       printf("\n");
       printf("TIME [%d]\n", i + 1);
       printf("Nome - %s\n", _Times[i].nome);
       printf("Tecnico - %s\n\n", _Times[i].tecnico);
       printf("JOGADORES - \n\n", _Times[i].jogadores);
       for (j = 0; j < _Times[i].pos_jogador; j++)
       {
           printf("Jogador [%d] \n", j + 1);
           printf("Nome - %s", _Times[i].jogadores[j].nome);
           printf("\n");
       }
   }
}


void listaTimes()
{
   int i, j;


   printf("\n");
   for (i = 0; i < pos_Time; i++)
   {
       printf("TIME [%d]\n", i + 1);
       printf("Nome: %s\n", _Times[i].nome);
       printf("Tecnico: %s\n\n", _Times[i].tecnico);
       printf("%s\n", _Times[i].pos_jogador > 0 ? "JOGADORES - " : "[SEM JOGADORES]");
       for (j = 0; j < _Times[i].pos_jogador; j++)
       {
           imprimeJogador(i, j);
           printf("\n");
       }
   }
}


void imprimeJogador(int i, int j)
{
   int k;
   printf("Jogador [%d] - \n", j + 1);
   printf("Nome - %s\n", _Times[i].jogadores[j].nome);
   printf("Matricula - %s\n", _Times[i].jogadores[j].matricula);
   printf("Numero da Camisa - %d\n", _Times[i].jogadores[j].num_Camisa);
   printf("Posicao - ");


   for (k = 0; k < _Times[i].jogadores[j].pos_posicao; k++)
   {
       imprimePosicao(_Times[i].jogadores[j].posicao[k]);
       if (k == (_Times[i].jogadores[j].pos_posicao - 1))
       {
           printf("\n");
       }
       else
       {
           printf(", ");
       }
   }
   printf("Data de Nascimento - %d/%d/%d\n", _Times[i].jogadores[j].data_Nasc.dia, _Times[i].jogadores[j].data_Nasc.mes, _Times[i].jogadores[j].data_Nasc.ano);
   printf("Turma - %s\n", _Times[i].jogadores[j].turma.nome);
}


void menuAlteraTime()
{


   int op = 1;


   while (op != 4)
   {
       if (op < 1 || op > 4)
       {
           imprime_Erro(1);
       }


       printf("\n");
       printf("MENU ALTERAR TIME\n");
       printf("1. Nome do Time\n");
       printf("2. Nome do Tecnico\n");
       printf("3. Jogadores\n");
       printf("4. Voltar\n");
       printf("OPCAO: ");
       scanf("%d", &op);
       op_MenuAlteraTime(op);
   }
}


void excluirTime()
{
   int pos, j;


   printf("\nTimes Cadastrados - \n");
   listaTimes();
   pos = menu_QualTime(); //
   if (confirmaEscolha() == 1)
   {


       if (pos == 0 && pos_Time == 1) // if (posJ == 0 && _Times[posT].pos_jogador == 1)
       {


           pos_Time--;
           free(_Times);
       }
       else if ((pos_Time - 1) == pos)
       {
           pos_Time--;
           _Times = (Ttime *)realloc(_Times, pos_Time * sizeof(Ttime));


           if (_Times == NULL)
           {
               imprime_Erro(13);
               freeMemory();
               exit(1);
           }
       }
       else
       {
           for (j = pos; j < pos_Time; j++)
           {
               _Times[pos] = _Times[pos + 1];
           }
           pos_Time--;


           _Times = (Ttime *)realloc(_Times, pos_Time * sizeof(Ttime));


           if (_Times == NULL)
           {
               imprime_Erro(13);
               freeMemory();
               exit(1);
           }
       }
   }
   printf("\nTurma Excluida Com Sucesso!\n");
}


void op_MenuAlteraTime(int op)
{


   int i;
   switch (op)
   {
   case 1:
       printf("\nALTERACAO DE NOME DO TIME - \n\n");
       alteraNomeTime();
       break;
   case 2:
       printf("\nALTERACAO DE NOME DO TECNICO - \n\n");
       alteraNomeTecnico();
       break;
   case 3:
       menuAtualizaJogador();
       break;
   default:
       break;
   }
}


int menu_QualTime()
{
   int i = 0;
   if (pos_Time > 1)
   {
       i = -1;
       while (i < 0 || i >= pos_Time)
       {
           printf("Qual o time? ");
           scanf("%d", &i);
           (i)--;


           if (i < 0 || i >= pos_Time)
           {
               imprime_Erro(9);
           }
       }
   }
   return i;
}




void alteraNomeTime()
{


   int i;


   i = menu_QualTime();


   printf("\n");
   printf("TIME [%d] - \n", i + 1);
   printf("Nome do Time: ");
   _Times[i].nome = leitorString(&_Times[i].nome);
}


void alteraNomeTecnico()
{


   int i;


   i = menu_QualTime();


   printf("\n");
   printf("TIME [%d] - \n", i + 1);
   printf("Nome do Tecnico: ");
   _Times[i].tecnico = leitorString(&_Times[i].tecnico);
}


void menuAtualizaJogador()
{


   int op = 1;


   while (op != 4)
   {
       if (op < 1 || op > 4)
       {
           imprime_Erro(1);
       }


       printf("\n");
       printf("MENU ATUALIZAR JOGADORES\n");
       printf("1. Incluir Novo Jogador\n");
       printf("2. Alterar Jogador\n");
       printf("3. Excluir Jogador\n");
       printf("4. Voltar\n");
       printf("OPCAO: ");
       scanf("%d", &op);
       op_AtualizaJogador(op);
   }
}


void op_AtualizaJogador(int op)
{
   switch (op)
   {
   case 1:
       printf("\nINCLUSAO DE JOGADOR -\n\n");
       adicionarJogador();
       break;
   case 2:
       menuAlteraJogador();
       break;
   case 3:
       printf("\nEXCLUSAO DE JOGADOR -\n\n");
       excluirJogador();
       break;
   default:
       break;
   }
}


void adicionarJogador()
{


   int i;


   i = menu_QualTime();
   printf("TIME [%d] - \n", i + 1);
   menuJogador(i);
}


void menuAlteraJogador()
{


   int op = 1;


   while (op != 7)
   {
       if (op < 1 || op > 7)
       {
           imprime_Erro(1);
       }


       printf("\n");
       printf("MENU ALTERAR JOGADORES\n");
       printf("1. Nome\n");
       printf("2. Matricula\n");
       printf("3. Numero da Camisa\n");
       printf("4. Posicoes\n");
       printf("5. Data de Nascimento\n");
       printf("6. Turma\n");
       printf("7. Voltar\n");
       printf("OPCAO: ");
       scanf("%d", &op);
       op_MenuAlteraJogador(op);
   }
}


void op_MenuAlteraJogador(int op)
{


   switch (op)
   {
   case 1:
       printf("\nALTERACAO DE NOME DO JOGADOR - \n\n");
       altera_NomeJogador();
       break;
   case 2:
       printf("\nALTERACAO DE MATRICULA DO JOGADOR - \n\n");
       altera_MatriculaJogador();
       break;
   case 3:
       printf("\nALTERACAO DE NUMERO DE CAMISA DO JOGADOR - \n\n");
       altera_CamisaJogador();
       break;
   case 4:
       printf("\nALTERACAO DE POSICAO DO JOGADOR - \n\n");
       menu_alteraPosicao();
       break;
   case 5:
       printf("\nALTERACAO DE DATA DE NASCIMENTO DO JOGADOR - \n\n");
       altera_DtNascJogador();
       break;
   case 6:
       printf("\nALTERACAO DE TURMA DO JOGADOR - \n\n");
       altera_TurmaJogador();
       break;
   default:
       break;
   }
}


int menu_QualJogador(int i)
{
   int j = 0;


   if (_Times[i].pos_jogador == 0)
   {
       imprime_Erro(10);
   }
   else
   {
       if (_Times[i].pos_jogador > 1)
       {
           j = -1;
           while (j < 0 || j >= _Times[i].pos_jogador)
           {
               printf("\n");
               printf("Qual o jogador? ");
               scanf("%d", &j);
               j--;


               if (j < 0 || j >= _Times[i].pos_jogador)
               {
                   imprime_Erro(11);
               }
           }
       }
   }


   return j;
}


void altera_NomeJogador()
{
   char str[50];
   int i, j;


   i = menu_QualTime();
   j = menu_QualJogador(i);


   printf("\n");
   printf("TIME [%d] - JOGADOR [%d] \n", i + 1, j + 1);
   printf("Nome: ");
   _Times[i].jogadores[j].nome = leitorString(&_Times[i].jogadores[j].nome);
}


void altera_MatriculaJogador()
{


   char str[50];
   int i, j;


   i = menu_QualTime();
   j = menu_QualJogador(i);


   printf("\n");
   printf("TIME [%d] - JOGADOR [%d] \n", i + 1, j + 1);
   printf("Matricula: ");
   _Times[i].jogadores[j].matricula = leitorString(&_Times[i].jogadores[j].matricula);
}


void altera_CamisaJogador()
{


   int i, j;


   i = menu_QualTime();
   j = menu_QualJogador(i);


   printf("\n");
   printf("TIME [%d] - JOGADOR [%d] \n", i + 1, j + 1);
   printf("Numero da Camisa: ");
   scanf("%d", &_Times[i].jogadores[j].num_Camisa);
   fflush(stdin);
}


void menu_alteraPosicao()
{


   int op = 1;


   while (op != 4)
   {
       if (op < 1 || op > 4)
       {
           imprime_Erro(1);
       }


       printf("\n");
       printf("MENU ALTERAR POSICOES\n");
       printf("1. Incluir Posicao\n");
       printf("2. Excluir Posicao\n");
       printf("3. Alterar Posicao\n");
       printf("4. Voltar\n");
       printf("OPCAO: ");
       scanf("%d", &op);
       op_MenuAlteraPosicao(op);
   }
}


void op_MenuAlteraPosicao(int op)
{


   switch (op)
   {
   case 1:
       // incluirPosicao();
       break;
   case 2:
       // excluirPosicao();
       break;
   case 3:
       // alterarPosicao();
       break;
   default:
       break;
   }
}


void alterarPosicao()
{


   int i, j;
   char op = 's';


   i = menu_QualTime();
   j = menu_QualJogador(i);


   printf("\n");
   printf("TIME [%d] - JOGADOR [%d] \n", i + 1, j + 1);
   printf("\n");
   printf("- Goleiro (1)\t- AlaE (4)\n- AlaD (2)\t- Fixo  (5)\n- Pivo (3)\n");


   /*
       while (op == 's' || op == 'S')
       {
           incluirPosicao(i, _Times[i].jogadores[j].pos_posicao);
           printf("Posicao - \n");


           do
           {
               printf("- Goleiro (1)\t- AlaE (4)\n- AlaD (2)\t- Fixo  (5)\n- Pivo (3)\n");
               scanf("%d", &_Times[i].jogadores[j].pos_posicao);
               if (_Times[i].jogadores[j].pos_posicao < 1 || _Times[i].jogadores[j].pos_posicao > 5)
               {
                   imprime_Erro(14);
               }
           } while (_Times[i].jogadores[j].pos_posicao < 1 || _Times[i].jogadores[j].pos_posicao > 5);
       }
       */
}


void altera_DtNascJogador()
{
   int i, j;


   i = menu_QualTime();
   j = menu_QualJogador(i);


   printf("\n");
   printf("TIME [%d] - JOGADOR [%d] \n", i + 1, j + 1);


   do
   {
       printf("Data de Nascimento - \n");
       printf("Ano: ");
       scanf("%d", &_Times[i].jogadores[j].data_Nasc.ano);
       printf("Mes: ");
       scanf("%d", &_Times[i].jogadores[j].data_Nasc.mes);
       printf("Dia: ");
       scanf("%d", &_Times[i].jogadores[j].data_Nasc.dia);
       if (validaData(_Times[i].jogadores[j].data_Nasc.dia, _Times[i].jogadores[j].data_Nasc.mes, _Times[i].jogadores[j].data_Nasc.ano) == 0)
       {
           imprime_Erro(7);
       }


   } while (validaData(_Times[i].jogadores[j].data_Nasc.dia, _Times[i].jogadores[j].data_Nasc.mes, _Times[i].jogadores[j].data_Nasc.ano) == 0);
}


void altera_TurmaJogador()
{


   int i, j, k;
   int turma;


   i = menu_QualTime();
   j = menu_QualJogador(i);


   printf("\n");
   printf("TIME [%d] - JOGADOR [%d] \n\n", i + 1, j + 1);


   printf("Turmas Cadastradas - \n");


   for (k = 0; k < pos_Turma; k++)
   {
       printf("\n");
       printf("Turma [%d] -\n", k + 1);
       printf("Nome - %s\n", _Turmas[k].nome);
       printf("\n");
   }


   do
   {
       printf("Turma do Jogador: ");
       scanf("%d", &turma);
       turma--;


       if (turma < 0 || turma > (pos_Turma - 1))
       {
           imprime_Erro(6);
       }


   } while ((turma < 0 || turma > (pos_Turma - 1)) || (limiteTurmas_Time(_Times[i].pos_turma, _Turmas[turma]) == 1));


   _Times[i].jogadores[j].turma = _Turmas[turma];


   if (limiteTurmas_Time(_Times[i].pos_turma, _Turmas[turma]) == 0)
   {
       _Times[i].turmas[_Times[i].pos_turma++] = _Turmas[turma];
   }
}


void excluirJogador()
{
   int posJ, posT, j;


   printf("\nJogadores Cadastrados - \n");
   listaTimes();
   posT = menu_QualTime();
   posJ = menu_QualJogador(posT);


   if (confirmaEscolha() == 1)
   {
       if (posJ == 0 && _Times[posT].pos_jogador == 1)
       {
           _Times[posT].pos_jogador--;
           free(_Times[posT].jogadores);
       }
       else if ((_Times[posT].pos_jogador - 1) == posJ)
       {


           _Times[posT].pos_jogador--;
           _Times[posT].jogadores = (Tjogador *)realloc(_Times[posT].jogadores, _Times[posT].pos_jogador * sizeof(Tjogador));


           if (_Times[posT].jogadores == NULL)
           {
               imprime_Erro(13);
               freeMemory();
               exit(1);
           }
       }
       else
       {
           for (j = posJ; j < _Times[posT].pos_jogador; j++)
           {
               _Times[posT].jogadores[j] = _Times[posT].jogadores[j + 1];
           }
           _Times[posT].pos_jogador--;


           _Times[posT].jogadores = (Tjogador *)realloc(_Times[posT].jogadores, _Times[posT].pos_jogador * sizeof(Tjogador));


           if (_Times[posT].jogadores == NULL)
           {
               imprime_Erro(13);
               freeMemory();
               exit(1);
           }
       }
       printf("\nJogador Excluido Com Sucesso!\n");
   }
}


void imprime_Erro(int erro)
{


   switch (erro)
   {
   case 1:
       printf("ERRO - Opcao Inexistente!\n");
       break;
   case 2:
       printf("ERRO - Erro ao Alocar Memoria!\n");
       break;
   case 3:
       printf("ERRO - Turma Inexistente!\n");
       break;
   case 4:
       printf("ERRO - Sem Turmas Cadastradas!\n");
       break;
   case 5:
       printf("ERRO - Atributo Inexistente!\n");
       break;
   case 6:
       printf("ERRO - Turma Nao Cadastrada!\n");
       break;
   case 7:
       printf("ERRO - Data Invalida! Digite Novamente -\n");
       break;
   case 8:
       printf("ERRO - Sem Times Cadastrados!\n");
       break;
   case 9:
       printf("ERRO - Time Inexistente!\n");
       break;
   case 10:
       printf("ERRO - Time Sem Jogadores!\n");
       break;
   case 11:
       printf("ERRO - Jogador Inexistente!\n");
       break;
   case 12:
       printf("ERRO - Limite de Turmas Atingido! [2]\n");
       break;
   case 13:
       printf("ERRO - Erro ao Realocar Memoria!\n");
       break;
   case 14:
       printf("ERRO - Posicao Inexistente!\n");
       break;
   case 15:
       printf("ERRO - Posicao Ja Cadastrada!\n");
       break;
   default:
       break;
   }
}


int confirmaEscolha() // MUDAR RETURNS PARA VERDADEIRO E FALSO FUNÇÃO BOOLEANA TALVEZ
{


   char op;


   printf("Confirmar escolha? [S/qualquer outro caractere para N] - ");
   scanf(" %c", &op);
   if (op == 's' || op == 'S')
   {
       return 1;
   }
   else
   {
       return 0;
   }
}


void freeMemory()
{
   int i, j;
   free(_Turmas);
   free(_Times);


   for (i = 0; i < pos_Time; i++)
   {
       free(_Times[i].jogadores);
   }


   for (int i = 0; i < pos_Time; i++)
   {
       for (int j = 0; j < 1; j++)
       {
           free(_Times[i].jogadores[j].nome);
           free(_Times[i].jogadores[j].posicao);
       }
       free(_Times[i].jogadores);
   }


   for (i = 0; i < pos_Turma; i++)
   {
       free(_Turmas[i].nome);
   }
}


char *leitorString(char **string) // FUNCAO DEVE RECEBER A STRING COMO ARGUMENTO REFERENCIAL
{
   char str[50];


   scanf("%s", str);
   fflush(stdin);


   *string = (char *)malloc((strlen(str) + 1) * sizeof(char));


   if (*string == NULL)
   {
       imprime_Erro(2);
       exit(1);
   }
   else
   {
       strcpy(*string, str);
   }


   return *string;
}


void checkNull(int op)
{


   switch (op)
   {
   case 1:
       if (!_Turmas)
       {
           imprime_Erro(2);
           exit(1);
       }
       break;
   case 2:
       if (!_Times)
       {
           imprime_Erro(2);
           exit(1);
       }
       break;
   }
}


int validaData(int dia, int mes, int ano)
{
   int vetData[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


   if (ano % 4 == 0)
   {
       vetData[2] = 29;
   }


   if (dia > vetData[mes] || dia < 1 || mes < 1 || mes > 12 || ano <= 0 || ano > 2023)
   {
       return 0;
   }
   else
   {
       return 1;
   }
}


void confirmar()
{


   printf("Encerrando Programa\n");
   freeMemory();
}


void imprimeEnum(int op)
{


   switch (op)
   {
   case 1:
       printf("Curso - INFO");
       break;
   case 2:
       printf("Curso - MEC");
       break;
   case 3:
       printf("Curso - MAMB");
       break;
   case 4:
       printf("Curso - TADS");
       break;
   case 5:
       printf("Curso - TGA");
       break;
   case 6:
       printf("Curso - CSOC");
       break;
   default:
       break;
   }
}


void imprimePosicao(int op)
{
   switch (op)
   {
   case 1:
       printf("Goleiro");
       break;
   case 2:
       printf("AlaD");
       break;
   case 3:
       printf("Pivo");
       break;
   case 4:
       printf("AlaE");
       break;
   case 5:
       printf("Fixo");
       break;
   default:
       break;
   }
}


void incluirPosicao()
{
   int i, j;


   i = menu_QualTime();
   j = menu_QualJogador(i);


   printf("\n");
   printf("TIME [%d] - JOGADOR [%d] \n", i + 1, j + 1);


   if (_Times[i].jogadores[j].pos_posicao == 0)
   {
       _Times[i].jogadores[j].posicao = (Eposicao *)malloc(1 * sizeof(Eposicao));
   }
   else
   {
       _Times[i].jogadores[j].posicao = (Eposicao *)realloc(_Times[i].jogadores[j].posicao, (_Times[i].jogadores[j].pos_posicao + 1) * sizeof(Eposicao));
   }


   if (_Times[i].jogadores[j].posicao == NULL)
   {
       imprime_Erro(2);
       freeMemory(); // ADICIONAR NAS OUTRAS
       exit(1);
   }
   _Times[i].jogadores[j].pos_posicao++;


   printf("Posicao - \n");
   do
   {
       printf("- Goleiro (1)\t- AlaE (4)\n- AlaD (2)\t- Fixo  (5)\n- Pivo (3)\n");
       scanf("%d", &jogador.posicao[jogador.pos_posicao - 1]);
       if (jogador.posicao[jogador.pos_posicao - 1] < 1 || jogador.posicao[jogador.pos_posicao - 1] > 5)
       {
           imprime_Erro(14);
       }
       true = 0;
       for (j = 0; j < (jogador.pos_posicao - 1); j++)
       {
           for (int k = 0; k <= (jogador.pos_posicao - 1); k++)
           {
               if (jogador.posicao[j] == jogador.posicao[k])
               {
                   true ++;
               }
           }
           if (true > 1)
           {
               imprime_Erro(15);
               break;
           }
           true = 0;
       }


   } while (jogador.posicao[jogador.pos_posicao - 1] < 1 || jogador.posicao[jogador.pos_posicao - 1] > 5 || true > 1);
}


/*


while (op == 's' || op == 'S')
   {


       if (jogador.pos_posicao == 0)
       {
           jogador.posicao = (Eposicao *)malloc(1 * sizeof(Eposicao));
       }
       else
       {
           jogador.posicao = (Eposicao *)realloc(jogador.posicao, (jogador.pos_posicao + 1) * sizeof(Eposicao));
       }


       if (jogador.posicao == NULL)
       {
           imprime_Erro(2);
           freeMemory(); // ADICIONAR NAS OUTRAS
           exit(1);
       }
       jogador.pos_posicao++;


       printf("Posicao - \n");
       do
       {
           printf("- Goleiro (1)\t- AlaE (4)\n- AlaD (2)\t- Fixo  (5)\n- Pivo (3)\n");
           scanf("%d", &jogador.posicao[jogador.pos_posicao - 1]);
           if (jogador.posicao[jogador.pos_posicao - 1] < 1 || jogador.posicao[jogador.pos_posicao - 1] > 5)
           {
               imprime_Erro(14);
           }
           true = 0;
           for (j = 0; j < (jogador.pos_posicao - 1); j++)
           {
               for (int k = 0; k <= (jogador.pos_posicao - 1); k++)
               {
                   if (jogador.posicao[j] == jogador.posicao[k])
                   {
                       true ++;
                   }
               }
               if (true > 1)
               {
                   imprime_Erro(15);
                   break;
               }
               true = 0;
           }


       } while (jogador.posicao[jogador.pos_posicao - 1] < 1 || jogador.posicao[jogador.pos_posicao - 1] > 5 || true > 1);


       printf("Deseja adicionar outra posicao? [S/qualquer outro caractere para N]: ");
       scanf(" %c", &op);
       fflush(stdin);
   }








CHECAR FUNCAO NULL


*/


