#include <stdio.h>
#include <math.h>


int main()
{
    //Cria��o das vari�veis de entrada e de resultado
    float a, q;
    int n;
    float soma, enesimo;


    //Faz a leitura das vari�veis
    scanf("%f %f %d", &a, &q, &n);

    //Loop de opera��es
    for (int i=0; i<n; i++)
    {
        enesimo = a*pow(q,n-1);
    }

    soma = (a*(pow(q,n)-1))/(q-1);

    //Imprime o resultado da potencia��o
    printf("%.02f\n%.02f", enesimo, soma);

    return 0;
}
