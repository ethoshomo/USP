///////////////////////////////////// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "pilha.h"

///////////////////////////////////// VARIAVEIS GLOBAIS E OUTRAS DEFINIÇÕES

struct pilha_t {
    int topo;
    void **itens;
    int tamanhoElemento;
};

/////////////// Função de Criar Pilha
// Finalidade: criar um pilha nova.
// Retorno: retorna -1.
pilha* criarPilha(int tamanhoElemento){

    pilha *p = (pilha*)malloc(sizeof(pilha));
    assert(p != NULL);
    
    p->itens = (void**)malloc(tamanhoPilha*sizeof(void*));
    assert(p->itens != NULL);

    p->topo = -1; // Valor escolhido para, quando houver push, adquira valor 0.
    p->tamanhoElemento = tamanhoElemento;

    return p;
}

/////////////// Função de Esvaziar  Pilha
// Finalidade: eliminar a pilha criada anteriormente.
// Retorno: vazio.
void destruirPilha(pilha *p){
    
    while(p->topo >= 0){
        free(p->itens[p->topo]);
        p->topo = p->topo - 1;
    }

    if(p != NULL)
        free(p->itens);

    if(p != NULL)
        free(p);
    
    p = NULL;
}

/////////////// IsFull (Pilha Cheia)
// Finalidade: verificar se a pilha está cheia.
// Retorno: como a linguagem não trabalha nativamente com
//          booleanos, costuma-se atribuir 1 para cheio e 0
//          para pilha não-cheia.
int pilhaCheia(pilha *p){
    assert(p != NULL);
    if (p->topo == (tamanhoPilha-1)){return 1;}
    else {return 0;}
}

/////////////// Função IsEmpty (Pilha Vazia)
// Finalidade: verificar se a pilha está vazia.
// Retorno: como a linguagem não trabalha nativamente com
//          booleanos, costuma-se atribuir 1 para vazio e 0
//          para pilha não-vazia.
int pilhaVazia(pilha *p){
    assert(p != NULL);

    if(p->topo == -1){return 1;}
    else {return 0;}
}

/////////////// Push
// Finalidade: adiciona novos valores no array de empilhamento.
// Retorno: não há valores personalizados.
int push(pilha *p, void *x){
    
    assert(p != NULL);
    
    if (pilhaCheia(p) == 1)
        return -1;    
        
    p->topo = p->topo + 1; //Acrescenta uma unidade
    p->itens[p->topo] = (void*)malloc(p->tamanhoElemento);
    assert(p->itens[p->topo] != NULL);
    memcpy(p->itens[p->topo], x, p->tamanhoElemento); //Adiciona novo valor à pilha
    return 1;
}
/////////////// Pop
// Finalidade: remove valores que estão no topo da pilha.
// Retorno: não há valores personalizados.
int pop(pilha *p, void *x){
    assert(p != NULL);
    
    if (pilhaVazia(p) == 1){
        return -1;
    }

    memcpy(x, p->itens[p->topo], p->tamanhoElemento);
    free(p->itens[p->topo]);
    p->topo = p->topo - 1; //Retorna uma posição no array, descartando a última posição.
    return 1;
}

/////////////// Top
// Finalidade: consultar o valor que está no topo da pilha.
// Retorno: o valor consultado é enviado por referência,
//          enquanto o valor de retorno não é personalizado.
int top(pilha *p, void *x){
    assert(p != NULL);

    if (pilhaVazia(p) == 1){
        return -1;
    }

    memcpy(x, p->itens[p->topo], p->tamanhoElemento); //Copia o valor para retornar na main
    
    return 1;
}