#include <stdio.h>
#include <stdlib.h>
#include "busca.h"

/*
ÁRVORE BINÁRIA DE BUSCA NÃO APRESENTA ELEMENTOS REPETIDOS.
ALGUMAS IMPLEMENTAÇÕES INSEREM UMA VARIÁVEL NA STRUCT PARA
MOSTRAR QUANTAS VEZES UM MESMO ELEMENTO FOI INSERIDO.

OS MAIORES ELEMENTOS ESTÃO SEMPRE À DIREITA E OS MENORES
ESTÃO SEMPRE À ESQUERDA. NOS EXTREMOS, TEREMOS O MAIOR E
MENOR DOS ELEMENTOS.
*/

struct no_t {
    no *esquerda, *direita;
    elem informacao;
};

arvore *criarArvore(){
    arvore *a = (arvore*)malloc(sizeof(arvore));
    a->raiz = NULL;
    return a;
}

int estaVazia(arvore *a){
    if (a->raiz == NULL) {return 1;}
    return 0;
}

// Consiste na busca de um nó folha e sua desalocação, retornando 
// logo em seguida para o nó anterior de forma recursiva.
void podarArvore(no *raiz){
    if (raiz != NULL){
        podarArvore(raiz->esquerda);
        podarArvore(raiz->direita);
        free(raiz);
    }
}

void imprimir(no *raiz){
    if (raiz != NULL){
        printf("%d(", raiz->informacao);
        imprimir(raiz->esquerda);
        printf(",");
        imprimir(raiz->direita);
        printf(")");
    }
    else {
        printf("NULL");
    }

}

int alturaArvore(no *raiz){
    if (raiz == NULL) {return 0;}

    int alturaEsquerda = 1 + alturaArvore(raiz->esquerda);
    int alturaDireita = 1 + alturaArvore(raiz->direita);

    if (alturaEsquerda > alturaDireita) {return alturaEsquerda;}
    else {return alturaDireita;}
}

// A busca consiste na comparação da chave com o elemento raiz.
// Pode ocorrer 4 casos distintos:
// a) árvore vazia: raiz = NULL
// b) chave == elemento raiz: a chave está na raiz.
// c) chave < elemento: ou seja, a chave está à esquerda da raiz.
// d) chave > elemento: ou seja, a chave está à direita da raiz.
no *busca(no *raiz, elem procurado){
    if (raiz == NULL) {return NULL;}
    else if (raiz->informacao == procurado){return raiz;}
    else if (procurado < raiz->informacao){return busca(raiz->esquerda, procurado);}
    return busca(raiz->direita, procurado);
}

// A função inserção sempre insere elementos como folhas. Para tanto, procura o lugar
// certo e o insere. Comparando a chave com o nó raiz, pode acontecer 4 casos:
// a) árvore vazia: raiz = NULL
// b) chave == elemento raiz: a chave está na raiz. Não faz nada. Fim algoritmo.
// c) chave < elemento: ou seja, insere à esquerda da raiz.
// d) chave > elemento: ou seja, insere à direita da raiz.
int inserir(no **raiz, elem x){
    if (*raiz == NULL) {
        *raiz = (no*)malloc(sizeof(no));
        (*raiz)->informacao = x;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
        return 1;
    }
    else if((*raiz)->informacao == x){
        return 0;
    }
    else if((*raiz)->informacao > x){
        return inserir(&(*raiz)->esquerda, x);
    }
    else if((*raiz)->informacao < x){
        return inserir(&(*raiz)->direita, x);
    }

    return 0;
}

// a) Antes de começar a remoção é necessário verificar se não há elementos
//    ou chave não existe (afinal, o processo é recursivo).
// b) Remoção Nó Folha: libera memória e seta para NULL
// c) Remoção de Nó Pai com um Filho: arruma ponteiros e libera memória.
// d) Remoção de Nó Pai com dois Filhos: é a situação mais complexa, pois
//    dependerá da escolha da subárvore (não remove propriamente):
//      - Esquerda: precisa buscar a maior chave. (OPÇÃO ABAIXO)
//      - Direita: precisa buscar a menor chave.
//      Observação: a info da raiz é maior ou menor que as infos das subarvores.
//    Em seguida, copia os dados da maior chave no lugar daquele que se
//    deseja remover. Remoção recursiva do elemento copiado?
int remover(no **raiz, elem x){
    // A busca é feita por meio das seguintes etapas:
    if (*raiz == NULL) {// Houve procura, mas não encontrou ou a arvore não existe.
        return 0;
    }
    else if(x < (*raiz)->informacao){ // Procura no lado esquerdo (menores elementos)
        return remover(&(*raiz)->esquerda, x);
    }
    else if(x > (*raiz)->informacao){ // Procura no lado direito (mnaiores elementos)
        return remover(&(*raiz)->direita, x);
    }
    else{//Inicia Propriamente a Remoção
        if (((*raiz)->direita == NULL)&&((*raiz)->esquerda == NULL)){
            free(*raiz);
            *raiz = NULL;
            return 1;
        }
        else if ((*raiz)->esquerda == NULL){
            no* auxiliar = *raiz;
            *raiz = (*raiz)->direita;
            free(auxiliar);
            return 1;
        }
        else if ((*raiz)->direita == NULL){
            no* auxiliar = *raiz;
            *raiz = (*raiz)->esquerda;
            free(auxiliar);
            return 1;
        }
        else{
            no* auxiliar = (*raiz)->esquerda; // Escolha da subárvore à esquerda

            while(auxiliar->direita != NULL){
                auxiliar = auxiliar->direita;
            }

            (*raiz)->informacao = auxiliar->informacao;
            return remover(&(*raiz)->esquerda, auxiliar->informacao);
        }
    }
    return 0;
}

// Antes do Percurso: verifica se a árvore é vazia.
// Percurso: visita o nó raiz primeiro e depois as subárvores da esquerda
// e da direita (nessa ordem).
void preOrdem(no *raiz){
    if (raiz != NULL){
        printf("%d", raiz->informacao);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

// Percurso: visita a subárvore da esquerda primeiro, depois nó raiz e a
// subárvore da direita (nessa ordem).
void emOrdem(no *raiz){
    if (raiz != NULL){
        emOrdem(raiz->esquerda);
        printf("%d", raiz->informacao);
        emOrdem(raiz->direita);
    }
}

// Percurso: visita a subárvore da esquerda primeiro, depois subárvore da
// direita e, por fim, o nó raiz (nessa ordem).
void posOrdem(no *raiz){
    if (raiz != NULL){
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d", raiz->informacao);
    }
}
