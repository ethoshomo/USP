/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "rotacao.h"

int main(){
    int quantidadeCasos = 0, tamanhoLista = 0;
    int quantidadeRotacoes = 0, numero = 0, contador = 0;
    lista *l = NULL;

    scanf("%d", &quantidadeCasos);
    for(int i = 0; i < quantidadeCasos; i++){
        l= criarLista();
        scanf("%d", &tamanhoLista);
        scanf("%d", &quantidadeRotacoes);
        for(int j = 0; j < tamanhoLista; j++){
            scanf(" %d", &numero);
            inserirLista(l, numero);
        }
        rotacoes(l, quantidadeRotacoes);
        imprimir(l);
        destruirLista(l);
        contador += 1;
        if (contador != quantidadeCasos) {printf("\n");}
    }
    
    return 0;
}