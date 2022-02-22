/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"

int main(){
    int quantidadeConchas;
    lista *l = NULL;
    
    scanf("%d", &quantidadeConchas);
    l = criarLista(l, quantidadeConchas);

    for (int contador = 0; contador < quantidadeConchas; contador++)
        l = readline(l, contador);

    shellSort(l, quantidadeConchas);
    imprimir(l, quantidadeConchas);
    destruirLista(l);

    return 0;
}