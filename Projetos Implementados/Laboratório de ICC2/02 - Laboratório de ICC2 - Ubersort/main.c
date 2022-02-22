/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ubersort.h"

int main(){
    int quantidadeElementos = 0;
    int escolhaPivo = 0;
    int *vetor = NULL;
    srand(42);

    scanf(" %d", &quantidadeElementos);
    scanf(" %d", &escolhaPivo);

    vetor = criaVetor(quantidadeElementos);
    lerVetor(vetor, quantidadeElementos);
    ubersort(vetor, 0, quantidadeElementos-1, escolhaPivo);
    imprimirVetor(vetor, quantidadeElementos);
    destruirVetor(vetor);
    
    return 0;
}