   #include <stdio.h>
   #include <stdlib.h>
   #include "matematico.h"

   int main(){

       int n, a;
/*
    //Fatorial
       printf("Digite um numero para fatorial:");
       scanf("%d", &n);
       printf("%d\n\n", fatorial(n));
    
    //Fibonnaci Recursivo (lento)
       printf("Digite um numero para Fibonacci Recursivo:");
       scanf("%d", &n);
       printf("%d\n\n", fibonacciRecursivo(n));

    //Fibonacci Iterativo (rápido)
       printf("Digite um numero para Fibonacci Iterativo:");
       scanf("%d", &n);
       printf("%d\n\n", fibonacci(n));

    //Operações Clássicas
       printf("Digite dois numeros para eponenciacao (base e expoente):");
       scanf("%d %d", &n, &a);
       printf("Exponenciacao: %d\n", exponenciacao(n, a));
       printf("Soma: %d\n\n", soma(n, a));
       printf("Subtracao: %d\n\n", subtracao(n, a));
       printf("Multiplicacao: %d\n\n", multiplicacao(n, a));
       printf("Divisao: %lf\n\n", divisao(n, a));


       printf("Digite dois numeros para eponenciacao (base e expoente):");
       scanf("%d %d", &n, &a);
       printf("Exponenciacao: %d\n", exponenciacaoRecursiva(n, a));       

    //Verifica Numeros Primos       
       printf("Digite dois numeros (se primo e possivel divisor):");
       scanf("%d %d", &n, &a);
       primoInterativo(n);
       primoRecursivo(n, a);
*/
    //Fatoração em números primos
      printf("Digite um numero para ser fatorado em numeros primos:");  
       scanf("%d", &n);
       fatoresPrimos(n);
       return 0;

   } 