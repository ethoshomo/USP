#include <stdio.h>

int main()
{
    //Cria��o de quatro vari�veis
    double a, b, c, d;

    //Cria��o de vari�vel de valor min e da vari�vel resultado da media
    double min, media;


    //Leitura dos 4 valores de entrada
    for (int k=0; k<4; k++)
    {
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    }

    //Comparativa de dois n�meros e utiliza��o da vari�vel min para comparar com as demais
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

    //F�rmula que descarta o valor min e faz a media dos demais
    media = (a+b+c+d-min)/3;

    //Imprime a media com uma precis�o de 4 unidades decimais
    printf("%.04lf\n", media);

    return 0;
}
