#include <stdio.h>


int main()
{
    //Cria variável referente aos dias do mês
    int dias[30];
    int somaUm, entrada;

    //Faz a leitura da entrada
    scanf("%d", &entrada);


    somaUm=1;

    for (int i=0; i<30; i++)
    {
            dias[i] = somaUm;
            somaUm = somaUm+1;
    }

    printf("         Abril 2021         \n");
    printf(" Do  Se  Te  Qu  Qu  Se  Sa \n");
    printf("                ");

    for (int contador=0; contador<3; contador++)
    {

            if (dias[contador] == entrada)
                {
                printf("( %d)", dias[contador]);
                }
            else
                {
                printf("  ");
                printf("%d", dias[contador]);
                printf(" ");
                }
    }

    printf("\n");


    for (int contador=3; contador<10; contador++)
    {
        if (dias[contador]==10 && dias[contador]==entrada)
                {
                printf("(%d)", dias[contador]);
                }
        else if (dias[contador]==10)
                {
                printf(" ");
                printf("%d", dias[contador]);
                printf(" ");
                }

        else if (dias[contador]!=10 && entrada == dias[contador])
                {
                printf("( %d)", dias[contador]);
                }
        else
                {
                printf("  ");
                printf("%d", dias[contador]);
                printf(" ");
                }
    }


    printf("\n");


    for (int contador=10; contador<17; contador++)
    {

            if (dias[contador] == entrada)
                {
                printf("(%d)", dias[contador]);
                }
            else
                {
                printf(" ");
                printf("%d", dias[contador]);
                printf(" ");
                }
    }


    printf("\n");


    for (int contador=17; contador<24; contador++)
    {
            if (dias[contador] == entrada)
                {
                printf("(%d)", dias[contador]);
                }
            else
                {
                printf(" ");
                printf("%d", dias[contador]);
                printf(" ");
                }
    }


    printf("\n");


    for (int contador=24; contador<30; contador++)
    {
            if (dias[contador] == entrada)
                {
                printf("(%d)", dias[contador]);
                }
            else
                {
                printf(" ");
                printf("%d", dias[contador]);
                printf(" ");
                }
    }
        printf("\n");


    return 0;
}
