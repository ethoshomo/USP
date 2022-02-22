////////////////////////////////////////////////////// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////// FUNCOES USADAS NO PROGRAMA
void push();
void avaliacaoCaracter(char caracter);
void adicao();
void subtracao();
void multiplicacao();
void divisao();

////////////////////////////////////////////////////// VARIAVEIS GLOBAIS
double *stack = NULL;
double *topoPilha = NULL;
int controle = 0;
int tamanhoPilha = 1;

////////////////////////////////////////////////////// MAIN
int main()
{

    ////////////////////// Variaveis locais
    char caracter = ' ';
    int fim = 0;


    ////////////////////// Alocacao de memoria e atualizacao de variaveis
    stack = (double*)malloc(tamanhoPilha*sizeof(double));
    topoPilha = &stack[0];


    ////////////////////// Laço de repetição para ler a entrada até EOF
    do
    {
        caracter = getchar();
        if (caracter == EOF)
        {
            fim = 1;
            break;
        }
        avaliacaoCaracter(caracter);

    } while(fim != 1);


    ////////////////////// Impressao do resultado final
    printf("Resultado: %.6lf\n", *topoPilha);


    ////////////////////// Desalocação de memoria HEAP
    free(stack);

    return 0;
}

/* Essa funcao promove o empilhamento de dados na "stack" */
void push()
{
    tamanhoPilha += 1;
    stack = (double*)realloc(stack, tamanhoPilha*sizeof(double));
    topoPilha = &stack[tamanhoPilha-1];
}

/* Essa funcao promove o desempilhamento de dados na "stack" */
void pop()
{
    tamanhoPilha -= 1;
    stack = (double*)realloc(stack, tamanhoPilha*sizeof(double));
    topoPilha = &stack[tamanhoPilha-1];
    controle -= 1;
}

/* Essa funcao promove a soma de dois valores antes do sinal + */
void adicao()
{
    double numeroAtual, numeroAnterior;

    numeroAtual = *(topoPilha);
    numeroAnterior = *(topoPilha-1);
    topoPilha = topoPilha - 1;
    *topoPilha = numeroAtual + numeroAnterior;
    pop();

}

/* Essa funcao promove a subtração de dois valores antes do sinal - */
void subtracao()
{
    double numeroAtual, numeroAnterior;

    numeroAtual = *(topoPilha);
    numeroAnterior = *(topoPilha-1);
    topoPilha = topoPilha - 1;
    *topoPilha = numeroAnterior - numeroAtual;
    pop();

}

/* Essa funcao promove a divisao de dois valores antes do sinal / */
void divisao()
{
    double numeroAtual, numeroAnterior;

    numeroAtual = *(topoPilha);
    numeroAnterior = *(topoPilha-1);
    topoPilha = topoPilha - 1;
    *topoPilha = numeroAnterior / numeroAtual;
    pop();

}

/* Essa funcao promove a multiplicacao de dois valores antes do sinal * */
void multiplicacao()
{
    double numeroAtual, numeroAnterior;

    numeroAtual = *(topoPilha);
    numeroAnterior = *(topoPilha-1);
    topoPilha = topoPilha - 1;
    *topoPilha = numeroAtual * numeroAnterior;
    pop();
}

/* Essa funcao avalia o tipo de caracter e encaminha ações de acordo com ele. */
void avaliacaoCaracter(char caracter)
{

    if ((caracter == ' ') || (caracter == '\n') || (caracter == '+') || (caracter == '-') || (caracter == '/') || (caracter == '*'))
    {
        switch(caracter)
        {
            case ' ':
                break;

            case '\n':
                break;

            case '+':
                adicao();
                break;

            case '-':
                subtracao();
                break;

            case '*':
                multiplicacao();
                break;

            case '/':
                divisao();
                break;

            default:
                break;
        }
    }
    else
    {
        if (controle == tamanhoPilha)
        {
            push();
        }

        ungetc(caracter, stdin);
        scanf("%lf", &(*topoPilha));
        controle += 1;
    }
}
