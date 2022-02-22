#include <stdio.h>

int main()
{
   // Variável que será lida
   int a;

   // Leitura da variável
   scanf("%d", &a);

   //Condicional para verificar se o ano é bissexto com consequente impressão
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



