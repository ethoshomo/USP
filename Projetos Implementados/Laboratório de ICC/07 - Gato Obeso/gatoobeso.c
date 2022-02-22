#include <stdio.h>

int main()
{
   // Define as variáveis de quantas vezes o gato brincou com a bolinha (n1) e quantas vezes mordeu na ração na semana (n2) e o resultado
   int n1, n2, resultado;

   // Leitura das variáveis
   scanf("%d %d", &n1, &n2);

   resultado = (3*n2)-(5*n1);

   //Condicional para verificar se o gato atingiu a meta, não atingiu mas emagreceu ou engordou
   if (resultado>0)
   {
       printf("R");
   }
   else if (resultado<=0 && resultado>-30)
   {
       printf("B");
   }
   else if (resultado<=-30)
   {
       printf("P");
   }

return 0;

}



