#include <stdio.h>

int main()
{
    //Imprime o tamanho em bytes dos valores que são reservados para variáveis

    unsigned char a;
    char b;
    unsigned int c;
    short int d;
    int e;
    long int f;
    unsigned long int g;
    long long int h;
    float i;
    double j;
    long double k;

    printf("%d\n", (int)sizeof(a));
    printf("%d\n", (int)sizeof(b));
    printf("%d\n", (int)sizeof(c));
    printf("%d\n", (int)sizeof(d));
    printf("%d\n", (int)sizeof(e));
    printf("%d\n", (int)sizeof(f));
    printf("%d\n", (int)sizeof(g));
    printf("%d\n", (int)sizeof(h));
    printf("%d\n", (int)sizeof(i));
    printf("%d\n", (int)sizeof(j));
    printf("%d\n", (int)sizeof(k));

    return 0;
}
