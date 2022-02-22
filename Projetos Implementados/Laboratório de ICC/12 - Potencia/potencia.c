#include <stdio.h>


int main()
{
    //Criação das variáveis de entrada e de resultado
    int a, b;
    int resultado=1;

    //Faz a leitura da base e do expoente
    scanf("%d %d", &a, &b);



    //Loop de operações
    for (int i=0; i<b; i++)
    {
            resultado = resultado*a;

        if (b==0)
           resultado = 1;

        if (b==1)
           resultado = a;
    }

    //Imprime o resultado da potenciação
    printf("%d\n", resultado);

    return 0;
}
