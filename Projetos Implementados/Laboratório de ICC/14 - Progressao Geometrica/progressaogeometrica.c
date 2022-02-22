#include <stdio.h>
#include <math.h>


int main()
{
    //Criação das variáveis de entrada e de resultado
    float a, q;
    int n;
    float soma, enesimo;


    //Faz a leitura das variáveis
    scanf("%f %f %d", &a, &q, &n);

    //Loop de operações
    for (int i=0; i<n; i++)
    {
        enesimo = a*pow(q,n-1);
    }

    soma = (a*(pow(q,n)-1))/(q-1);

    //Imprime o resultado da potenciação
    printf("%.02f\n%.02f", enesimo, soma);

    return 0;
}
