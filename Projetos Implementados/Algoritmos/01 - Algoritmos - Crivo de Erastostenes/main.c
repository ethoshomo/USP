/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*                      nUSP 12542630                          *
***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "crivo.h"

int main(){
    int *listaCompleta = NULL, *listaPrimos = NULL;
    int tamanhoPrimos = 0, quantosImprimir = 0, indices = 0;

    // Aloca memória e preenche o vetor listaCompleta (de 2 a 10.000)
    listaCompleta = preencherLista(listaCompleta);

    //Percorre o vetor listaCompleta em todas suas posições.
    //Em cada uma delas, verifica se o número é primo.
    //Caso seja, adiciona o valor no vetor listaPrimos.
    for(int i = 0; i < 9999; i++){
        if(listaCompleta[i] == 2) {
            listaPrimos = alocaMemoria(listaPrimos, &tamanhoPrimos);
            listaPrimos[i] = 2;
        }
        else {
            listaPrimos = verificaPrimo(listaPrimos, listaCompleta[i], &tamanhoPrimos);
        }
    }
    
    //Coleta quantos numeros deverá imprimir
    scanf("%d", &quantosImprimir);
    
    //Coleta os índices e os imprime seus valores
    for(int i = 0; i < quantosImprimir; i++){
        scanf(" %d", &indices);
        printf("%d ", listaPrimos[indices-1]);
    }

    //Desaloca Memória HEAP.
    free(listaCompleta);
    free(listaPrimos);

    return 0;
}

