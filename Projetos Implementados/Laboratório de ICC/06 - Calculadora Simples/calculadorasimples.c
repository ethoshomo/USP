#include <stdio.h>

int main()
{
   // Variáveis reais que serão lidas (numero 1, numero 2), assim como variavel e char (operação)
   float a, b;
   char op;

   // Leitura da variável
   scanf("%f %c %f", &a, &op, &b);

   //Condicional para verificar se o ano é bissexto com consequente impressão
   switch(op)
   {
   case '+':
       printf("%.6f", a+b);
       break;
   case '-':
       printf("%.6f", a-b);
       break;
   case '*':
       printf("%.6f", a*b);
       break;
   case '/':
       printf("%.6f", a/b);
       break;
   case '%':
       printf("%.6f", a/(b/100));
       break;
   }

return 0;

}



