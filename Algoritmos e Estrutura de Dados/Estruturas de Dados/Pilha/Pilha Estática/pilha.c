///////////////////////////////////// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pilha.h"

///////////////////////////////////// VARIAVEIS GLOBAIS E OUTRAS DEFINIÇÕES

struct pilha_t {
    int topo;
    tipoDado itens[tamanhoPilha];
};

/////////////// Função de Criar Pilha
// Finalidade: criar um pilha nova.
// Retorno: retorna -1.
pilha* criarPilha(){

    pilha *p = (pilha*)malloc(sizeof(pilha));
    assert(p != NULL);

    p->topo = -1;

    return p;
}

/////////////// Função de Esvaziar  Pilha
// Finalidade: eliminar a pilha criada anteriormente.
// Retorno: vazio.
void destruirPilha(pilha *p){
    if(p != NULL){
        free(p);
        p = NULL;
    }
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
int push(pilha *p, tipoDado x){
    
    assert(p != NULL);
    
    if (pilhaCheia(p) == 1){
        return -1;    
    }
    
    p->topo = p->topo + 1; //Acrescenta uma unidade
    p->itens[p->topo] = x; //Adiciona novo valor à pilha
    
    return 0;
}
/////////////// Pop
// Finalidade: remove valores que estão no topo da pilha.
// Retorno: não há valores personalizados.
int pop(pilha *p, tipoDado *x){
    assert(p != NULL);

    if (pilhaVazia(p) == 1){
        return -1;
    }

    *x = p->itens[p->topo]; //Copia o valor para retornar na main
    p->topo -= 1; //Retorna uma posição no array, descartando a última posição.
    return 1;
}

/////////////// Top
// Finalidade: consultar o valor que está no topo da pilha.
// Retorno: o valor consultado é enviado por referência,
//          enquanto o valor de retorno não é personalizado.
int top(pilha *p, tipoDado *x){
    assert(p != NULL);

    if (pilhaVazia(p) == 1){
        return -1;
    }

    *x = p->itens[p->topo]; //Copia o valor para retornar na main
    
    return 1;
}