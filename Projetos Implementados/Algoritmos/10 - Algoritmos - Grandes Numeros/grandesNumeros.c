#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grandesNumeros.h"

/*
Essa porção do código está relacionada com a criação, destruição
e manipulação de listas ligadas que são utilizadas para o armazenamento
dos algarismos de um número muito grande. As funções aqui relacionadas
estão mais ligadas à estrutura dos números.

Por ser uma lista duplamente ligada, é possível fazer remoção de zeros
da esquerda para a direita ou vice-versa, bem como, da mesma forma, é
possível fazer a impressão de números na ordem direta ou inversa.
*/

numero *criarNumero(){
    numero *p;
    p = (numero*)malloc(sizeof(numero));
    p->vaiUm = 0;
    p->sinal = 'p';
    p->inicio = NULL;
    p->fim = NULL;
    return p;
}

void liberarNumero(numero *n){
    if (n != NULL){
        no *auxiliar = n->inicio;
        while (auxiliar != NULL){
            n->inicio = n->inicio->proximo;
            free(auxiliar);
            auxiliar = n-> inicio;
        }
        free(n);
    }
}

int inserir(numero *n, elemento x){
    if (n != NULL){
        no *p = (no*)malloc(sizeof(no));
        
        if (n->inicio == NULL && n->fim == NULL){
            p->numero = x;
            p->proximo = NULL;
            p->anterior = NULL;
            n->inicio = p;
            n->fim = p;
        }
        else{
            n->inicio->anterior = p;
            p->numero = x;
            p->proximo = n->inicio;
            p->anterior = NULL;
            n->inicio = p;
        }
        
        return 1;
    }
    return 0;
}

void removerZeros(numero *n){    
    no *p = n->fim;

    while (p != NULL && p->numero == 0){
        if (p != NULL && p->numero == 0){
            if (p->anterior == NULL){return;}
            else{
                n->fim = p->anterior;
                p->anterior->proximo = NULL;
                free(p);
            }
            p = n->fim;
        }
    }
}

void removerZerosInversa(numero *n){    
    no *p = n->inicio;

    while (p != NULL && p->numero == 0){
        if (p != NULL && p->numero == 0){
            if (p->proximo == NULL){return;}
            else{
                n->inicio = p->proximo;
                p->proximo->anterior = NULL;
                free(p);
            }
            p = n->inicio;
        }
    }
}

int tamanho(numero *n){
    if (n != NULL){
        int tamanho = 0;
        no *p = n->fim;
        while (p != NULL){
            tamanho += 1;
            p = p->anterior;
        }
        return tamanho;
    }
    return 0;
}

void imprimir(numero *n){
    if(n != NULL){
        no *p = n->inicio;
        
        while (p != NULL){
            printf("%d", p->numero);
            p = p->proximo;
        }
        printf("\n");
    }
}

void imprimirInverso(numero *n){
    if (n != NULL){
        no *p = n->fim;
        while (p != NULL){
            printf("%d", p->numero);
            p = p->anterior;
        }
        printf("\n");
    }
}