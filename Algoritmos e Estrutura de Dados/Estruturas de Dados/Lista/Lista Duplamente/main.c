#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamente.h"

int main(){

    lista *l = criarLista();

    inserir(l, 5);
    inserir(l, 2);
    inserir(l, 7);
    inserir(l, 8);
    inserir(l, 3);
    inserir(l, 2);
    inserir(l, 4);
    
    imprimir(l);
    imprimirInverso(l);
    
    liberarLista(l);


    return 0;
}