#include <stdio.h>



int main()
{
    int a, b;

    // O programa trabalha na inst�ncia de bits, transformando os valores decimais em bits.

    scanf("%d %d", &a, &b);
    printf("%d\n", a&b); // opera��o de A and B;
    printf("%d\n", a|b); // opera��o de A ou B
    printf("%d\n", a^b); // opera��o de exclusivo OU
    printf("%d\n", ~a); // complemento de a
    printf("%d\n", ~b); // complemento de b
    printf("%d\n", a>>2); // deslocamento a direita
    printf("%d\n", b<<2); // deslocamento a esquerda


}
