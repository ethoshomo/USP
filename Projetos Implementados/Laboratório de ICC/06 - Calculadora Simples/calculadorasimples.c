#include <stdio.h>

int main()
{
   // Vari�veis reais que ser�o lidas (numero 1, numero 2), assim como variavel e char (opera��o)
   float a, b;
   char op;

   // Leitura da vari�vel
   scanf("%f %c %f", &a, &op, &b);

   //Condicional para verificar se o ano � bissexto com consequente impress�o
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



