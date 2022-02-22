/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main(){
    fila *f = NULL;
    int quantidadeAcoes;
    
    f = criarFila(f); //Cria fila única
    
    //Quantidade de linhas de entradas
    scanf("%d", &quantidadeAcoes); 
    getchar(); // dispensa o \r
    getchar(); // dispensa o \n

    //Cada linha de entrada tem: comando, nome, idade e condicao saude.
    for(int i = 0; i < quantidadeAcoes; i++){
        resolveLinha(f);
    }

    //Destroi a fila criada
    destruirFila(f);

    return 0;
}