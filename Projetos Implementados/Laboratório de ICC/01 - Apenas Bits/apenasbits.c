#include <stdio.h>

int main()
{
   // Vari�vel que ser� lida
   int a, byte1, byte2, byte3, byte4;

   // Leitura da vari�vel
   scanf("%i", &a);

   byte1= (a>>24)&(255);
   byte2= (a>>16)&(255);
   byte3= (a>>8)&(255);
   byte4= (a)&(255);

   //Impress�o das sa�das desejadas ap�s processamento da vari�vel
   printf("%c", (char)byte1);
   printf("%c", (char)byte2);
   printf("%c", (char)byte3);
   printf("%c", (char)byte4);

return 0;

}



