#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Criação das variáveis utilizadas no programa
    int quantidadeCentavos, *umReal, *cinquentaCentavos, *vintecincoCentavos, *dezCentavos, *cincoCentavos, *umCentavo, real, centavos50, centavos25, centavos10, centavos5, centavos1;


//Funcao que serve para contabilizar o troco
int contabilizarTroco(int quantidade, int *umRealF, int *cinquentaCentavosF, int *vintecincoCentavosF, int *dezCentavosF, int *cincoCentavosF, int *umCentavoF)
{
    *umRealF = (quantidade)/(100);
    *cinquentaCentavosF = (quantidade)%(100)/(50);
    *vintecincoCentavosF = (quantidade)%(100)%(50)/25;
    *dezCentavosF = (quantidade)%(100)%(50)%25/10;
    *cincoCentavosF = (quantidade)%(100)%(50)%25%10/5;
    *umCentavoF = (quantidade)%(100)%(50)%25%10%5;

    return 0;
}


int main () {

    //Faz a leitura da entrada: tempo em segundos e nome do planeta
    scanf("%d", &quantidadeCentavos);

    //Inicia ponteiro para transferir o valor por referência
    umReal = &real;
    cinquentaCentavos = &centavos50;
    vintecincoCentavos = &centavos25;
    dezCentavos = &centavos10;
    cincoCentavos = &centavos5;
    umCentavo = &centavos1;

    //Inicia a função que vai contabilizar o tempo
    contabilizarTroco(quantidadeCentavos, umReal, cinquentaCentavos, vintecincoCentavos, dezCentavos, cincoCentavos, umCentavo);

    //Imprime a saída conforme orientações.
    printf("O valor consiste em %d moedas de 1 real\n", real);
    printf("O valor consiste em %d moedas de 50 centavos\n", centavos50);
    printf("O valor consiste em %d moedas de 25 centavos\n", centavos25);
    printf("O valor consiste em %d moedas de 10 centavos\n", centavos10);
    printf("O valor consiste em %d moedas de 5 centavos\n", centavos5);
    printf("O valor consiste em %d moedas de 1 centavo\n", centavos1);

    return (0);
}
