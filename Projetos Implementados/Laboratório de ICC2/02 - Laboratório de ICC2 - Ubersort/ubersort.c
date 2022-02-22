#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ubersort.h"

/////////////////////////// Função Cria Vetor
// Finalidade: tem a finalidade de criar um vetor
// que irá receber os dados a serem ordenados pelo
// ubersort. Alocação dinâmica.
// Retorno: retorna o vetor criado.
int* criaVetor(int quantidade){
    int* vetor = NULL;
    vetor = (int*)malloc(quantidade*sizeof(int));
    return vetor;
}

/////////////////////////// Função Destruir Vetor
// Finalidade: desalocação da memória alocada. 
// Ou seja, tem a finalidade de destruir o vetor
// que foi usado na ordenação pelo ubersort.
// Retorno: não há.
void destruirVetor(int* vetor){
    free(vetor);
}

/////////////////////////// Função Ler Vetor
// Finalidade: tem a finalidade de ler os dados de
// entrada e preenhcer o vetor alocado dinamicamente.
// Retorno: não há.
void lerVetor(int* vetor, int quantidade){
    for(int i = 0; i < quantidade; i++)
        scanf(" %d", &vetor[i]);
}

/////////////////////////// Função Imprimir Vetor
// Finalidade: tem a finalidade de imprimir o vetor
// ordenado de acordo com as instruções de saída.
// Retorno: retorna o vetor criado.
void imprimirVetor(int* vetor, int quantidade){    
    for(int i = 0; i < quantidade; i++)    
        printf("%d\n", vetor[i]);
}

/////////////////////////// Função Calcular Mediana
// A função abaixo compara os valores das variáveis 
// por meio de uma relação lógica AND. Por isso, 
// compara os três elementos e conclui qual é a indice 
// que deverá ser usado na função do quicksort.
// Retorno: retorna a mediana calculada.
int pivoMediana(int *vetor, int inicio, int fim){
    int meio = (inicio + fim) / 2;
    int a = vetor[inicio];
    int b = vetor[meio];
    int c = vetor[fim];
    int indice;
    
    if (a < b) {
        if (b < c) {indice = meio;} 
        else {
            if (a < c) {indice = fim;}
            else {indice = inicio;}
        }
    }
    else {
        if (c < b) {indice = meio;}
        else {
            if (c < a) {indice = fim;}
            else {indice = inicio;}
        }
    }
    return indice;
}

/////////////////////////// Função Pivo Aleatorio
// Finalidade: tem a finalidade de calcular um indice
// aleatorio para o pivo da função de partição.
// Retorno: retorna um inteiro.
int pivoAleatorio(int i, int f){
    return (int)((rand()%(f-i))+i);
}

/////////////////////////// Função Swap (Troca)
// Promove a troca de posição de elementos.
// Retorno: não há.
void swap(int* vetor, int elementoA, int elementoB){
    int temp = vetor[elementoA];
    vetor[elementoA] = vetor[elementoB];
    vetor[elementoB] = temp;
}

///////////////////////////Função Insertion Sort
// Finalidade: ordena o vetor pelo método de ordenação
// Insertion Sort.
// Retorno: não há.
void insertionSort(int* vetor, int inicio, int fim){
	int i = inicio + 1;

	while (i <= fim) {
		int chave = vetor[i];
		int j = i-1;

		while (j >= 0 && chave < vetor[j]) {
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = chave;
		i++;
	}
}

/////////////////////////// Função UBERSORT
// OBSERVAÇÃO: a função Ubsersort poderia ter sido otimizada
// dividindo-a em várias outras funções. Porém, optei por
// fazer um código para ubersort_aleatorio e outro para
// ubersort_mediana afinal, dessa forma, o codigo ficou mais 
// claro e limpo, facilitando a leitura e a correção da função,
// especialmente nas primeiras execuções que apresentaram erros.
//
//                          VERSÕES:
//
// UBERSORT DE PIVO ALEATÓRIO CONSORCIADO COM INSERTION SORT
int partition_aleatorio(int *vetor, int inicio, int fim){
    int pivo = pivoAleatorio(inicio, fim);
    swap(vetor, pivo, fim);
    pivo = vetor[fim];

    int i, j;
    i = inicio-1;
    
    for(j = inicio; j <= fim-1; j++){
        if (vetor[j] < pivo){
            i++;
            swap(vetor, i, j);
        }
    }
    swap(vetor, i+1, fim);
    return i+1;   
}
void ubersort_aleatorio(int *vetor, int inicio, int fim){

    if (fim < inicio){return;}
    else if (fim-inicio <= 10){
        insertionSort(vetor, inicio, fim);
    }
    else{
        int pivo = partition_aleatorio(vetor, inicio, fim);            
        ubersort_aleatorio(vetor, inicio, pivo - 1);
        ubersort_aleatorio(vetor, pivo + 1, fim);
    }
}
//
//
// UBERSORT DE PIVO A MEDIANA CONSORCIADO COM INSERTION SORT
int partition_mediana(int *vetor, int inicio, int fim){
    int pivo = pivoMediana(vetor, inicio, fim);
    swap(vetor, pivo, fim);
    pivo = vetor[fim];
    
    int i, j;
    i = inicio-1;
    
    for(j = inicio; j <= fim-1; j++){
        if (vetor[j] < pivo){
            i++;
            swap(vetor, i, j);
        }
    }
    swap(vetor, i+1, fim);
    return i+1;   
}
void ubersort_mediana(int *vetor, int inicio, int fim){
    if (fim < inicio){return;}
    else if (fim-inicio <= 10){
        insertionSort(vetor, inicio, fim);
    }
    else{
        int pivo = partition_mediana(vetor, inicio, fim);            
        ubersort_mediana(vetor, inicio, pivo - 1);
        ubersort_mediana(vetor, pivo + 1, fim);
    }
}
//
//
// FUNÇÃO UBERSORT QUE ESCOLHE O TIPO DE PIVO QUE SERÁ USADO
void ubersort(int *vetor, int inicio, int fim, int escolhaPivo){
    switch(escolhaPivo){
        case 1:
            ubersort_mediana(vetor, inicio, fim);
            break;
        case 2: 
            ubersort_aleatorio(vetor, inicio, fim);
            break;
    }
}