#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lista.h" 

int main(){

    tipoDado numero;
    lista *l;

    l = criarLista();
    while(numero != -1){
        scanf("%d", &numero);
        inserirLista(l, numero);
    }
    
    printf("\n\n Tamanho da Lista: %d\n\n Lista: \n", tamanhoLista(l));
    
    imprimir(l);

    while(numero != 2){
        scanf(" %d", &numero);
        removerLista(l, numero);
    }    

    printf("\n\n Tamanho da Lista: %d\n\n Lista: \n", tamanhoLista(l));
    
    imprimir(l);

    destruirLista(l);

    return 0;
}