//////////////////////////////////////////////// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////////////////////////////////////////////// BLOCO DE STRUCT
typedef struct cadastro{
    long unsigned int identificador;
    char nome[50];
    char curso[50];
    int idade;
} ficha;


//////////////////////////////////////////////// DECLARAÇÃO DE FUNÇÕES
void consultaIdentificador(long unsigned int numero, int quantidadeAlunos);
void consultaCurso(char nome[50], int quantidadeAlunos);
void impressaoTotal(int quantidadeAlunos);
int realocarMemoria();


//////////////////////////////////////////////// VARIAVEIS GLOBAIS
int const string = 49;
ficha *controle;


//////////////////////////////////////////////// MAIN
int main()
{
    int contador, operacao, fim, quantidadeAlunos, cIdentificador;
    char cCurso[string];

    ////////////// Atualização das Variáveis e Alocação de Memória
    quantidadeAlunos = 1;
    operacao = 0;
    controle = (struct cadastro*)malloc(quantidadeAlunos*sizeof(struct cadastro));
    fim = 0;
    contador = 0;

    //////////////Laço de repetição para alimentar o sistema com as entradas
    do
    {
        //Realoca espaço de memória
        if ((contador+1) > quantidadeAlunos)
        {
            quantidadeAlunos = realocarMemoria(quantidadeAlunos);
        }

        //Leitura do identificador
        scanf("%ld", &controle[contador].identificador);
        getchar();//despreza \n
        if (controle[contador].identificador == -1)
        {
            fim = -1;
            break;
        }

        //Leitura do nome, curso e idade
        scanf("%49[^\n]s", controle[contador].nome);
        getchar(); //Despreza o \n
        scanf("%49[^\n]s", controle[contador].curso);
        getchar(); // Despreza o \n
        scanf("%d", &controle[contador].idade);

        contador += 1;

    }while (fim != -1);


    ////////////// Laço de repeticao para as operações esperadas
    fim = 0;
    do{
        scanf("%d", &operacao);
        getchar(); //Despreza o \n

        switch (operacao){

        case 1: //Faz a leitura do identificador e Imprime a Ficha
            scanf("%d", &cIdentificador);
            consultaIdentificador(cIdentificador, contador);
            break;

        case 2: // Faz a leitura do Curso e Imprime todas as fichas daquele curso
            scanf("%49[^\n]s", cCurso);
            consultaCurso(cCurso, contador);
            break;

        case 3: // Imprime todos os cadastros
            impressaoTotal(contador);
            break;

        case -1: // Sai do programa
            fim = -1;
            break;

        default:
            printf("Operacao invalida.");
            break;
        }

    }while(fim != -1);


    ////////////// Desaloca memória heap
    free(controle);

    return 0;
}


/*

As funções descritas abaixo seguem exatamente a descrição contida no switch.

*/

int realocarMemoria(int tamanho)
{
    tamanho += 1;
    controle = (struct cadastro*)realloc(controle, tamanho*sizeof(struct cadastro));
    return tamanho;
}

void consultaIdentificador(long unsigned int numero, int quantidadeAlunos)
{

    for(int contador = 0; contador<quantidadeAlunos; contador++)
    {
        if (numero == controle[contador].identificador)
        {
            printf("Nome: %s\n", controle[contador].nome);
            printf("Curso: %s\n", controle[contador].curso);
            printf("N USP: %ld\n", controle[contador].identificador);
            printf("IDADE: %d\n", controle[contador].idade);
            printf("\n");
        }
    }


}


void consultaCurso(char curso[50], int quantidadeAlunos)
{

  for(int contador = 0; contador<quantidadeAlunos; contador++)
    {
        if (strcmp(curso, controle[contador].curso) == 0)
        {
            printf("Nome: %s\n", controle[contador].nome);
            printf("Curso: %s\n", controle[contador].curso);
            printf("N USP: %ld\n", controle[contador].identificador);
            printf("IDADE: %d\n", controle[contador].idade);
            printf("\n");
        }
    }

}

void impressaoTotal(int quantidadeAlunos)
{

  for(int contador = 0; contador<quantidadeAlunos; contador++)
    {
        printf("Nome: %s\n", controle[contador].nome);
        printf("Curso: %s\n", controle[contador].curso);
        printf("N USP: %ld\n", controle[contador].identificador);
        printf("IDADE: %d\n", controle[contador].idade);
        printf("\n");
    }
}

