#include <stdio.h>


int main()
{
    //Criação da variável digitada
    char c=0;

    //Criação das variáveis de controle sobre o loop e a quantidade de cliques de cada letra
    int w=0, s=0, a=0, d=0;


    //Leitura dos 6 valores de entrada e código de soma
    for (int i=0; i<6; i++)
    {

        scanf("%c", &c);
        fflush(stdin);

        if (c == 'w' || c == 'W')
            {
                w=w+1;
            }
        if (c == 's' || c == 'S')
            {
                s=s+1;
            }
        if (c == 'a' || c == 'A')
            {
                a=a+1;
            }
        if (c == 'd' || c == 'D')
            {
                d=d+1;
            }
    }

    //Imprime a media com uma precisão de 4 unidades decimais
    printf("%d %d\n", 1*d-1*a, 1*w-1*s);

    return 0;
}
