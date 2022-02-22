#include <stdio.h>
#include <stdlib.h>


int fatorial(int n){
    if (n == 0) return 1;
    return n* fatorial(n-1);
}

// @param n é o numero de operações fibonacci
int fibonacci(int n){
    int F = 0;
    int Ft = 1;

    for(int k = 0; k < n; k++){
        F += Ft;
        Ft = F-Ft;
    }
    return F;
}

// @param n é o numero de operações fibonacci
int fibonacciRecursivo(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int exponenciacao(int a, int b){
    int resultado = 1;

    while(b>0){
        resultado *= a;
        b-= 1;
    }
    return resultado;
}

int exponenciacaoRecursiva (int a, int b){
    if (b == 1) {return a;}
    if((b%2) == 0) {return exponenciacaoRecursiva (a*a, b/2);}
    else {return a*exponenciacaoRecursiva (a, b-1);}
}

int soma(int a, int b){
    return a+b;
}

int subtracao(int a, int b){
    return a-b;
}

int multiplicacao(int a, int b){
    return a*b;
}

double divisao(int a, int b){
    return a/b;
}

// @param a é o numero que sera avaliado se é primo
void primoInterativo(int a){
    int primo = 1;
    for (int i = 2; i < a; i++){
        if ((a % i) == 0){
            primo = 0;
            break;
        }
    }

    if (primo == 1) {printf("\nPrimo!\n");}
    else {printf("\nNao primo!\n");}
}

// @param a é o numero que sera avaliado se é primo
// @param a é o numero que sera avaliado se é primo
void primoRecursivo(int n, int d){
    if (n % d == 0) {printf("\nNao primo!\n");}
    else if (n > d+1) {primoRecursivo(n, d+1);}
    else {printf("\nPrimo!\n");}
}


//Função de fatoração de um número
// @param n: é o numero que será decomposto em fatores primos
// A função já imprime os valores fatorados, como se fosse o MMC
int minprimfac(int n){
    int i;
    for(i=2; i <= n; i++)
        if(n%i == 0) return i;
}

void fatoresPrimos(int n){
    int m = n;
    do{
        printf("%d ", m = minprimfac(n));
        n = n/m;
    }while (n>1);
}