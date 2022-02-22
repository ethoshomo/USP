
/////////////////////////// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

/////////////////////////// DECLARAÇÕES
struct fila_t{
    int inicio, fim, total;
    tipoDado itens[tamanhoFila];
};

/////////////////////////// Função Criar Fila (Create)
// Finalidade: criar uma alocação dinâmica para armazenar dados da fila
// Retorno: retorna uma struct com os dados.
fila* criarFila(){
    fila *f;
    f = (fila*)malloc(sizeof(fila));
    if (f != NULL) {
        f->inicio = 0;
        f->fim = 0;
        f->total = 0;
    }
    else{printf("Erro. Vetor NULL.");}
    return f;
}

/////////////////////////// Função Esvaziar Fila (Empty)
// Finalidade: desalocar a fila criada dinamicamente. Acaba por destruí-la.
// Retorno: vazio.
void destruirFila(fila *f){
    if (f != NULL) {free(f);}
}

/////////////////////////// Função Fila Vazia (IsEmpty)
// Finalidade: verifica se a fila está vazia.
// Retorno: retorna 1 para verdadeiro e 0 para falso (não é booleano).
int filaVazia(fila *f){
    if (f !=NULL){ if (f->total == 0) {return 1;}}
    return 0;
}

/////////////////////////// Função Fila Cheia (IsFull)
// Finalidade: verifica se a fila está cheia.
// Retorno: retorna 1 para verdadeiro e 0 para falso e -1 erro.
int filaCheia(fila *f){
    if (f !=NULL){ if (f->total == tamanhoFila) {return 1;}}
    else {return -1;}
    return 0;
}

/////////////////////////// Função Inserir (Insert)
// Finalidade: adiciona um elemento ao final da fila. Quando atinge o limite do vetor,
//             retorna para a primeira célula ("faz a curva").
// Retorno: se a fila estiver cheia, retorna 0 (para mostrar que não)
//          houve adição). Ao final, retorna 1 para denotar sucesso do procedimento.
int filaInserir(fila *f, tipoDado x){
    if (filaCheia(f) == 1) {return 0;}
    f->itens[f->fim] = x;
    f->fim = (f->fim + 1) % tamanhoFila; //Porcentagem serve para dar circularidade no vetor
    f->total += 1;

    return 1;
}

/////////////////////////// Função Remover (Remove)
// Finalidade: retira o elemento do inicio da fila. Quando chega
//             ao final do vetor, volta para o inicio para continuar.
// Retorno: 1 para sucesso e 0 para procedimento não realizado.
int filaRemover(fila *f, tipoDado *x){
    if (filaVazia(f) == 1)
        return 0;
    
    *x = f->itens[f->inicio];
    f->inicio = f->itens[f->inicio + 1] % tamanhoFila; //Porcentagem traz circularidade ao vetor.
    f->total = f->total - 1;

    return 1;
}