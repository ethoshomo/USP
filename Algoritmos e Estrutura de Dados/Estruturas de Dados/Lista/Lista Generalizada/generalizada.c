#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "generalizada.h"

void libera(no *p){
    no *auxiliar = NULL;
     while (p != NULL){
         if (p->tipo == 1){
             libera(p->info.sublista);
         }
         auxiliar = p;
         p = p->proximo;
         free(auxiliar);
     }
}

no *atomo(elem x){
    no *p = (no*)malloc(sizeof(no));
    p->tipo = 0;
    p->proximo = NULL;
    p->info.atomo = x;
    return p;
}

no *sublista(no *sublista){
    no *p = (no*)malloc(sizeof(no));
    p->tipo = 1;
    p->proximo = NULL;
    p->info.sublista = sublista;
    return p;
}

no *concat(no *p, no *q){
    assert(p != NULL);
    p->proximo = q;
    return p;
}

info cabeca(no *p, int *tipo){
    assert(p != NULL);
    *tipo = p->tipo;
    return p->info;
}

no *cauda(no*p){
    assert(p != NULL);
    return p->proximo;
}

void imprime(no *p){
    if (p == NULL){return;}

    printf("(");
    while(p != NULL){
        if (p->tipo == 0){printf("%d", p->info.atomo);}
        else {imprime(p->info.sublista);}

        if (p->proximo != NULL) {printf(", ");}
        p = p->proximo;
    }
    printf(")");
}

void imprimir(no *p){
    imprime(p);
    printf("\n");
}
