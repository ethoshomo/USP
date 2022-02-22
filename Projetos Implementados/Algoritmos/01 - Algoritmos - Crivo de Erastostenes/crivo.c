#include <stdio.h>
#include <stdlib.h>
#include "crivo.h"

//////////////////////////////////////////////////////////////////
// A função preencherLista recebe um ponteiro da main (NULL),
// sendo que é responsável por criar um vetor que vai de 2 até
// 10.000. Para tanto, aloca memória HEAP. Ao final, retorna
// o vetor preenchido.
int* preencherLista(int* vetor){
    int tamanhoVetor = 0;

    for (int i = 2; i <= 10000; i++){
        vetor = (int*)realloc(vetor, (tamanhoVetor+1)*sizeof(int));
        vetor[tamanhoVetor] = i;
        tamanhoVetor += 1;
    }

    return vetor;
}

//////////////////////////////////////////////////////////////////
// É responsável pela alocação de memória do ponteiro listaPrimos.
// Retorna um endereço para o ponteiro na main.
int* alocaMemoria(int* vetor, int* tamanho){
    *tamanho += 1;
    return (int*)malloc(sizeof(int));
}

//////////////////////////////////////////////////////////////////
// Essa função recebe o vetor listaPrimos (vetor), o número que
// será verificado se é primo (n) e o tamanhoVetor (tamanho).
// Verifica se é primo, e, caso seja, chama a função adicionaLista 
// para adicioná-lo no vetor de primos. Como retorno, temos que,
// se foi constatado o numero primo, retorna vetor atualizado;
// caso contrário, retorna o vetor como estava.
int* verificaPrimo(int* vetor, int n, int* tamanho){
    int primo = 0;
    for(int i = 1; i <= n; i++)
        if ((n % i) == 0) {primo += 1;}
    
    if (primo == 2) {vetor = adicionaLista(vetor, tamanho, n);}

    return vetor;
}

//////////////////////////////////////////////////////////////////
// É chamada pela função verificaPrimo e serve para adicionar um
// numero primo no vetor listaPrimos (vetor). Para tanto, usa o 
// número primo (n) e o tamanhoVetor (tamanho). Retorna o vetor
// para a função verificaPrimo com valores atualizados.
int* adicionaLista(int *vetor, int* tamanho, int n){
    
    *tamanho += 1;
    vetor = (int*)realloc(vetor, (*tamanho)*sizeof(int));
    vetor[((*tamanho)-1)] = n;
    
    return vetor;
}