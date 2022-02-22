#include <stdio.h>
#include <stdlib.h>
#include "rotacao.h"

/////////////////////////////// Função Criar Lista Encadeada
// Finalidade: tem a finalidade de criar uma lista
// encadeada para uso durante o programa. Aloca memória
// dinamicamente e estabelece valores iniciais.
// Retorno: retorna a lista encadeada para a main.
lista* criarLista(){
    lista *l;
    l = (lista*)malloc(sizeof(lista));
    if (l == NULL) {
        printf("Erro na Execucao do Programa");
        exit(1);
    }
    else{
        l->inicio = NULL;
        l->fim = NULL;
        l->tamanhoLista = 0;
    }
    return l;
}

/////////////////////////////// Função Destruir Lista Encadeada
// Finalidade: tem a finalidade de destruir uma lista
// encadeada que foi usada durante o programa. Para tanto
// desaloca todos os nós que foram alocados.
// Retorno: não há retorno.
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

/////////////////////////////// Função Inserir Lista Encadeada
// Finalidade: tem a finalidade de inserir novos elementos
// em uma lista encadeada para uso durante o programa. 
// Para tanto, aloca memória de nó e faz alterações necessárias
// para o encadeamento de dados.
// Retorno: retorna 1 para inserção com sucesso e 0 para erro.
int inserirLista(lista *l, int x){
    if (l == NULL) {return 0;}

    no *p = (no*)malloc(sizeof(no));
    p->numero = x;
    p->proximoNo = NULL;
    p->anteriorNo = NULL;

    //Primeiro caso: lista vazia
    if (l->inicio == NULL){
        l->inicio = p;
        l->fim = p;
        l->inicio->anteriorNo = l->fim;
    }
    //Lista com mais de um nó
    else{
        l->fim->proximoNo = p;
        p->anteriorNo = l->fim;
        l->fim = p;
        l->fim->proximoNo = NULL;   
    }

    l->tamanhoLista += 1;

    return 1;
}

/////////////////////////////// Função Imprimir Lista Encadeada
// Finalidade: imprimir a lista encadeada.
// Retorno: não há.
void imprimir(lista *l){
    if (l != NULL){
        no *p = l->inicio;
        while (p != NULL){
            printf("%d ", p->numero);
            p = p->proximoNo;
        }    
    }
}

/////////////////////////////// Função Rotacionar a Lista Encadeada
// Finalidade: tem a finalidade de rotacionar a lista encadeada,
// tantas vezes quantas forem indicadas pelo usuário (numeroRotações),
// de modo que pega o último elemento da lista e o posiciona na
// primeira posição. No processo, é usado um ponteiro auxiliar.
// Retorno: não há.
void rotacoes(lista *l, int numeroRotacoes){

    for(int contador = 0; contador < numeroRotacoes; contador++){
        no *ponteiro = NULL;
        ponteiro = l->fim;
        l->fim = ponteiro->anteriorNo;
        l->fim->proximoNo = NULL;
        l->inicio->anteriorNo = ponteiro;
        ponteiro->anteriorNo = l->fim;
        ponteiro->proximoNo = l->inicio;
        l->inicio = ponteiro;        
    }
    
}