#include <stdio.h>

int main()
{
   // Define as vari�veis de quantas vezes o gato brincou com a bolinha (n1) e quantas vezes mordeu na ra��o na semana (n2) e o resultado
   int n1, n2, resultado;

   // Leitura das vari�veis
   scanf("%d %d", &n1, &n2);

   resultado = (3*n2)-(5*n1);

   //Condicional para verificar se o gato atingiu a meta, n�o atingiu mas emagreceu ou engordou
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



