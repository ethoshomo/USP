#include <stdio.h>


int main()
{
    //Criação das variáveis de entrada e de resultado
    double a, n, r;
    double soma, enesimo;

    //Faz a leitura da base e do expoente
    scanf("%lf %lf %lf", &a, &r, &n);

    //Loop de operações
    for (int i=0; i<n; i++)
    {
        enesimo = a + (n-1)*r;
    }

    soma = ((a+enesimo)*n)/2;

    //Imprime o resultado da potenciação
    printf("%.00lf\n%.00lf", enesimo, soma);

    return 0;
}
