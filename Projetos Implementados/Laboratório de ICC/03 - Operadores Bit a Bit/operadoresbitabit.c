#include <stdio.h>



int main()
{
    int a, b;

    // O programa trabalha na instância de bits, transformando os valores decimais em bits.

    scanf("%d %d", &a, &b);
    printf("%d\n", a&b); // operação de A and B;
    printf("%d\n", a|b); // operação de A ou B
    printf("%d\n", a^b); // operação de exclusivo OU
    printf("%d\n", ~a); // complemento de a
    printf("%d\n", ~b); // complemento de b
    printf("%d\n", a>>2); // deslocamento a direita
    printf("%d\n", b<<2); // deslocamento a esquerda


}
