#include <stdio.h>
#include <stdlib.h>
#include "busca.h"

int main(){
    arvore *a = criarArvore();

    inserir(&a->raiz,5);
    inserir(&a->raiz,3);
    inserir(&a->raiz,7);
    inserir(&a->raiz,9);
    inserir(&a->raiz,8);
    inserir(&a->raiz,2);

    imprimir(a->raiz);
    remover(&a->raiz, 5);
    printf("\n");
    imprimir(a->raiz);
    printf("\n");
    preOrdem(a->raiz);
    printf("\n");
    emOrdem(a->raiz);
    printf("\n");
    posOrdem(a->raiz);
    printf("\n");
    
    podarArvore(a->raiz);
    free(a);
    
    return 0;
}