#include <stdio.h>

int main()
{
   // Variável que será lida
   int a, byte1, byte2, byte3, byte4;

   // Leitura da variável
   scanf("%i", &a);

   byte1= (a>>24)&(255);
   byte2= (a>>16)&(255);
   byte3= (a>>8)&(255);
   byte4= (a)&(255);

   //Impressão das saídas desejadas após processamento da variável
   printf("%c", (char)byte1);
   printf("%c", (char)byte2);
   printf("%c", (char)byte3);
   printf("%c", (char)byte4);

return 0;

}



