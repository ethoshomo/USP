#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lista.h"

struct no_t {
    tipoDado info;
    no *proximoNo;
};


struct lista_t {
    struct no_t *inicio, *fim;
    int tamanhoLista;
};

lista* criarLista(){
    lista *l;
    l = (lista*)malloc(sizeof(lista));
    assert(l != NULL);

    l->inicio = NULL;
    l->fim = NULL;
    l->tamanhoLista = 0;

    return l;
}

void destruirLista(lista *l){
    if (l != NULL){
        
        no *p = NULL;
        p = l->inicio;
        
        while(p != NULL){
            l->inicio = p->proximoNo;
            free(p);
            p = l->inicio;
        }
        free(l);
    }
}

int inserirLista(lista *l, tipoDado x){
    assert(l != NULL);

    //Essa condição serve para verificar se o elemento já existe na lista
    if (elementoLista(l, x) == 1){return 0;}

    no *p = (no*)malloc(sizeof(no));
    p->info = x;
    p->proximoNo = NULL;

    //Primeiro caso: lista vazia
    if (l->inicio == NULL){l->inicio = p;}
    //Segundo caso: lista com mais de um nó
    else{l->fim->proximoNo = p;}

    l->fim = p;

    l->tamanhoLista += 1;

    return 1;
}

int tamanhoLista(lista *l){
    assert(l != NULL);
    return l->tamanhoLista;
}

void imprimir(lista *l){
    assert(l != NULL);

    no *p = l->inicio;

    while (p != NULL){
        printf("%d ", p->info);
        p = p->proximoNo;
    }
    
    printf("\n");

}

int elementoLista(lista *l, tipoDado x){
    assert(l != NULL);

    no *p = NULL;
    p = l->inicio;
    while (p != NULL){
        if (p->info == x) {return 1;}
        p = p->proximoNo;
    }

    return 0;
}

void removerLista(lista *l, tipoDado x){
    assert(l != NULL);
    
    no *auxiliar = NULL;
    no *p = l->inicio;

    while(p != NULL){
        if (p->info == x) {

            //Primeiro caso: remove nó inicial
            if(p == l->inicio){
                l->inicio = l->inicio->proximoNo;
                free(p);
            }

            //Segundo caso: remove nó final
            else if(p == l->fim){
                l->fim = auxiliar;
                l->fim->proximoNo = NULL;
                free(p);
            }

            //Terceiro caso: remove nó intermediário
            else{
                auxiliar->proximoNo = p->proximoNo;
                free(p);
                
            }

        }
        else {
            auxiliar = p;
            p = p->proximoNo;
        }

    }

}