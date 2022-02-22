#include <stdio.h>

int main()
{
    //Criação de quatro variáveis
    double a, b, c, d;

    //Criação de variável de valor min e da variável resultado da media
    double min, media;


    //Leitura dos 4 valores de entrada
    for (int k=0; k<4; k++)
    {
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    }

    //Comparativa de dois números e utilização da variável min para comparar com as demais
   if (a<b)
   {
       min = a;
   }
   else
   {
       min= b;
   }

   if (c<min)
   {
       min = c;
   }

   if (d< min)
   {
       min = d;
   }

    //Fórmula que descarta o valor min e faz a media dos demais
    media = (a+b+c+d-min)/3;

    //Imprime a media com uma precisão de 4 unidades decimais
    printf("%.04lf\n", media);

    return 0;
}
