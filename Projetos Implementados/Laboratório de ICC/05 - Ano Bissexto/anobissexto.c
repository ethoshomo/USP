#include <stdio.h>

int main()
{
   // Vari�vel que ser� lida
   int a;

   // Leitura da vari�vel
   scanf("%d", &a);

   //Condicional para verificar se o ano � bissexto com consequente impress�o
   if (a%4==0)
   {
       printf("SIM\n");
   }
   else
   {
       printf("NAO\n");
   }


return 0;

}



