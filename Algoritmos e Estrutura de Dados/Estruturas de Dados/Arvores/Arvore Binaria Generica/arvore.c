#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

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

no *busca(no *raiz, elem procurado){
    if (raiz == NULL) {return NULL;}
    if (raiz->informacao == procurado) {return raiz;}

    no *p = busca(raiz->esquerda, procurado);
    if (p == NULL){p = busca(raiz->direita, procurado);}

    return p;
}

no *buscaPai(no *raiz, elem procurado){
    if (raiz == NULL) {return NULL;}
    if (raiz->esquerda != NULL && raiz->esquerda->informacao == procurado){return raiz;}
    if (raiz->direita != NULL && raiz->direita->informacao == procurado){return raiz;}

    no *p = buscaPai(raiz->esquerda, procurado);
    if (p == NULL){p = buscaPai(raiz->direita, procurado);}

    return p;
}

// A função inserir funciona da seguinte forma: se pai == -1, insere na raiz
// mas, caso contrário, insere do lado esquerdo do pai.
int inserirEsquerda(arvore *a, elem elementoInserir, elem pai){
    no *p = (no*)malloc(sizeof(no));
    p->esquerda = NULL;
    p->direita = NULL;
    p->informacao = elementoInserir;

    if (pai == -1){
        if (a->raiz == NULL) {a->raiz = p;}
        else {
            free(p);
            return 0;
        }
    }
    else{
        no *auxiliar = busca(a->raiz, pai);
        if (auxiliar != NULL && auxiliar->esquerda == NULL){auxiliar->esquerda = p;}
        else {
            free(p);
            return 0;
        }
    }
    return 1;
}

int inserirDireita(arvore *a, elem elementoInserir, elem pai){
    no *p = (no*)malloc(sizeof(no));
    p->esquerda = NULL;
    p->direita = NULL;
    p->informacao = elementoInserir;

    if (pai == -1){
        if (a->raiz == NULL) {a->raiz = p;}
        else {
            free(p);
            return 0;
        }
    }
    else{
        no *auxiliar = busca(a->raiz, pai);
        if (auxiliar != NULL && auxiliar->direita == NULL){auxiliar->direita = p;}
        else {
            free(p);
            return 0;
        }
    }
    return 1;
}

// A função remover trabalha com dois ponteiros: pai (pai) e o elemento a ser removido (p).
// Isso gera as seguintes relações:
// a) Elemento Raiz: terá o ponteiro p apontado para si mesmo e o pai para NULL.
// b) Elemento Interno: terá o ponteiro p apontado para si mesmo e o pai para o ascendente.
// c) Elemento Folha: terá o ponteiro p apontando para si e o pai para seu ascendente.
// d) Elemento Inexistente: terá o ponteiro p e o pai apontado para NULL.
// É de se anotar que o elemento interno deverá ter tratamento diferente do elemento folha,
// uma vez que ele terá descendentes, o que o diferencia do outro (que aponta para a direita
// e para a esquerda para NULL).

int removerElemento(arvore *a, elem elementoRemover){
    no *p, *pai;
    int flagPosicao = 0; // Será 0 se estiver na direita e 1 se estiver na esquerda.

    // Primeira Etapa: setar os ponteiros p e pai.
    if ((a->raiz != NULL) && (a->raiz->informacao == elementoRemover)){
        p = a->raiz;
        pai = NULL;
    }
    else {
        pai = buscaPai(a->raiz, elementoRemover);
        if (pai != NULL){
            if (pai->esquerda != NULL && pai->esquerda->informacao == elementoRemover){
                p = pai->esquerda;
                flagPosicao = 1;
            }
            else{
                p = pai->direita;
                flagPosicao = 0;
            }
        }
        else { // Não busca o elemento raiz (linhas acima), mas, sim, elemento inexistente.
            p = NULL;
        }
    }

    // Segunda Etapa: fazer a remoção de p
    if (p == NULL){return 0;}
    else{
        //Remocao de p como folha. Precisa verificar elemento folha e elemento raiz.
        if(p->esquerda == NULL && p->direita == NULL){ 
            if (pai == NULL){a->raiz = NULL;}
            else{
                if (flagPosicao == 1){pai->esquerda = NULL;}
                else{pai->direita = NULL;}
            }
            free(p);
            return 1;
        }
        // Remoção de p sem ser folha.
        // Para evitar ter de lidar com todos os ponteiros que ficariam soltos,
        // promove-se a troca do ponteiro pai com o ponteiro filho (folha). Caso
        // não seja folha, troca-se recursivamente até transformá-lo em folha.
        else{ // Esse else somente será acessado se esquerda e/ou direita existirem.
            if (p->esquerda != NULL){
                p->informacao = p->esquerda->informacao;
                p->esquerda->informacao = elementoRemover;
            }
            else{
                p->informacao = p->direita->informacao;
                p->direita->informacao = elementoRemover;
            }
            return removerElemento(a, elementoRemover);
        }
    }
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
