/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "quad.h"

int main(){

    int linhas = 0, colunas = 0;
    int **matriz = NULL;

    scanf("%d %d", &linhas, &colunas);
    matriz = lerMatriz(matriz, linhas, colunas);
    verificarQuadrante(matriz, linhas, colunas, 0, 0, linhas);
    printf("\n");

    liberarAlocacoes(matriz, linhas);
    return 0;
}

