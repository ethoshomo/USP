#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "listaDuplamente.h"


typedef struct no_t no;


struct no_t{
    elemento info;
    no *anterior, *proximo;
};


struct lista_t{
    no *inicio, *fim;    
};


lista *criarLista(){
    lista *p;
    p = (lista*)malloc(sizeof(lista));
    p->inicio = NULL;
    p->fim = NULL;

    return p;
}

void liberarLista(lista *l){
    if (l != NULL){
        no *auxiliar = l->inicio;
        while (auxiliar != NULL){
            l->inicio = l->inicio->proximo;
            free(auxiliar);
            auxiliar = l-> inicio;
        }
        free (l);
    }
}


/*
    A inserção  na lista é o procedimento mais complicado
    pois, a princípio, deseja-se deixar a lista ordenada.
    Por isso, existem 4 casos que precisam ser analisados
    antes de realizar a inserção:

    1) a lista é vazia l->fim == l-> inicio == NULL?
    2) a inserção vai acontecer no início?
    3) a inserção vai acontecer no meio?
    4) a inserção vai acontecer no fim?

*/
int inserir(lista *l, elemento x){
    assert(l != NULL);
    no *p = (no*)malloc(sizeof(no));

    p->info = x;
    p->proximo = NULL;
    p->anterior = NULL;

    no *auxiliar, *anterior;
    anterior = NULL;
    auxiliar = l->inicio;

    while (auxiliar != NULL && x > auxiliar->info){
        anterior = auxiliar;
        auxiliar = auxiliar->proximo;
    }

    //Caso onde X existe
    if (auxiliar != NULL && x == auxiliar->info){
        free(p);
        return 0;
    }

    //Lista vazia ou lista com elementos
    if (anterior == NULL){
        p->proximo = l->inicio;
        if (l->inicio != NULL) l->inicio->anterior = p;
        l->inicio = p;
    }
    else{
        p->proximo = anterior->proximo;
        anterior->proximo = p;
        
        if (p->proximo != NULL) p->proximo->anterior = p;
        else l->fim = p;
        p->anterior = anterior;
    }
    return 1;
}

int remover(lista *l, elemento x){
    assert(l != NULL);

    no *p = l->inicio;
    no *anterior = NULL;

    while (p != NULL && x > p->info){
        anterior = p;
        p = p->proximo;
    }

    if (p == NULL) {
        return 0;
    }

    //Remoção do primeiro elemento
    if (anterior == NULL){
        l->inicio = l->inicio->proximo;
        if (l->inicio != NULL) l->inicio->anterior = NULL;
        else l->fim = NULL;
        free(p);
    }
    //Remove elemento no meio ou no fim
    else{
        if (p->proximo == NULL){ //remover do fim da lista
            l->fim = p->anterior;
            anterior->proximo = NULL;
            free(p);
        }
        else { // remover do meio da lista
            anterior->proximo = p->proximo;
            p->proximo->anterior = anterior;
            free(p);
        }
    }

    return 1;
}

void imprimir(lista *l){
    assert(l != NULL);
    no *p = l->inicio;
    
    while (p != NULL){
        printf("%d", p->info);
        p= p->proximo;
    }
    printf("\n");
}

void imprimirInverso(lista *l){
    assert(l != NULL);
    no *p = l->fim;
    
    while (p != NULL){
        printf("%d", p->info);
        p= p->anterior;
    }
    printf("\n");
}