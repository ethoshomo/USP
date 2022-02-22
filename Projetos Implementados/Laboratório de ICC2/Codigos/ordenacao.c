/*
	Os algoritmos abaixo foram copiados da internet, especificamente
	do site da Wikipedia (https://pt.wikipedia.org/). Porém, pode ter
	acontecido de terem sido alterados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"

///////////////////////////////////////////////FUNÇÕES DE APOIO
void copiarVetor(int *v, int *u, int tamanho){
	for (int i = 0; i < tamanho; i++){
		u[i] = v[i];
	}
}

void imprimir(int *v, int tamanho){
	for (int i = 0; i < tamanho; i++){
		printf("%d ", v[i]);
	}
	printf("\n\n");
}

void trocaVariavel(int *um, int *dois){ 
    int temporario = *um; 
    *um = *dois; 
    *dois = temporario; 
}


/////////////////////////////////////// BUBBLE SORT
// Funcionamento: ocorre por meio de recursão, percorrendo o vetor
// trocando as posições dos valores mais altos pelos mais baixos
// tantas vezes quantas forem necessárias para ordená-lo.
//
// @param "n": é o tamanho do vetor.
// @param "v": é o vetor
void bubbleSort(int *v, int n){ 
    n = n-1;

    if (n < 1) {return;}
 
    for (int contador = 0; contador < n; i++){
        if (v[contador] > v[contador+1]){
            trocaVariavel(&v[contador], &v[contador+1]);
		}
	}
    bubbleSort(v, n); 
}


/////////////////////////////////////// INSERTION SORT
// É criada uma estrutura na qual, um a um, são inseridos os
// novos valores, de forma ordenada.
// @param "v": estrutura de dados na forma de vetor.
// @param "n": trata-se do tamanho da estrutura de dados.
void insertionSort(int* v, int n) {
	int i = 1;

	while (i < n) {
		int el = v[i];
		int j = i-1;

		while (j >= 0 && el < v[j]) {
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = el;
		i++;
	}
}

/////////////////////////////////////// SELECTION SORT
// Ordena o vetor colocando os menores valores nas posições
// iniciais, sendo que o mecanismo é controlado por um laço
// externo (que permanece no menor índice) e um laço interno 
// (seleciona menor valor no restante do vetor).
//
// @param "num": estrutura de dados na forma de vetor.
// @param "tam": trata-se do tamanho da estrutura de dados.
void selectionSort(int *v, int n) { 
  int i, j, min, aux;
  for (i = 0; i < (n-1); i++) 
  {
     min = i;
     for (j = (i+1); j < n; j++) {
       if(v[j] < v[min]) 
         min = j;
     }
     if (i != min) {
       aux = v[i];
       v[i] = v[min];
       v[min] = aux;
     }
  }
}


/////////////////////////////////////// SELECTION SORT
// Trata-se da ordenação mais rápida, que acontece por meio de um pivo,
// a partir do qual são ordenadas porções a direita e a esquerda. O
// método é recursivo e muito eficiente.
//
// @param "v": estrutura de dados na forma de vetor.
// @param "began": trata-se do inicio que será ordenado.
// @param "end": trata-se do fim que será ordenado.
void quickSort(int *v, int began, int end){
	int i, j, pivo, aux;
	i = began;
	j = end-1;
	pivo = v[(began + end) / 2];
	while(i <= j)
	{
		while(v[i] < pivo && i < end)
		{
			i++;
		}
		while(v[j] > pivo && j > began)
		{
			j--;
		}
		if(i <= j)
		{
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
		}
	}
	if(j > began)
		quickSort(v, began, j+1);
	if(i < end)
		quickSort(v, i, end);
}


/////////////////////////////////////// SHELL SORT
// Trata-se de uma ordenação que é derivada da Insertion Sort.
// O algoritmo divide o vetor em vários segmentos e faz o método
// Insertion Sort em cada um deles.
//
// @param "vet": estrutura de dados na forma de vetor.
// @param "size": trata-se do tamanho do vetor a ser ordenado.
void shellSort(int *vet, int size){
    int i, j, value;
 
    int h = 1;
    while(h < size) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < size; i++) {
            value = vet[i];
            j = i;
            while (j > h-1 && value <= vet[j - h]) {
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = value;
        }
        h = h/3;
    }
}