#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
    arvore *a = criarArvore();

    inserirEsquerda(a, 1, -1);
    inserirEsquerda(a, 2, 1);
    inserirDireita(a, 3, 1);
    inserirEsquerda(a, 4, 3);
    inserirDireita(a, 5, 3);
    inserirEsquerda(a, 6, 4);

    imprimir(a->raiz);
    printf("\n");


    
    return 0;
}