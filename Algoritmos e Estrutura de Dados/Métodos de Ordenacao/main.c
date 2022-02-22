#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

int main(){

    srand(time(NULL));
    long unsigned int tamanhoVetor;
    int c1, c2, x;
    double tempoExecucao;

    printf("Digite o tamanho do vetor:\n");
    scanf("%ld", &tamanhoVetor);
    int vetor[tamanhoVetor], bubble[tamanhoVetor], insertion[tamanhoVetor];
	int selection[tamanhoVetor], quick[tamanhoVetor], shell[tamanhoVetor];

    for (int i = 0; i < tamanhoVetor; i++){
        x = (rand()%50); // % limita os valores
        vetor[i] = (int)x;
        printf("%d ", vetor[i]);
    }


    ///////////////////////// Bubble Sort
    c1 = 0;
    c2 = 0;
    
    c1 = clock();
	copiarVetor(vetor, bubble, tamanhoVetor);
    bubbleSort(bubble, tamanhoVetor);
    c2 = clock();
    tempoExecucao = ((c2-c1)*1000.0)/(CLOCKS_PER_SEC);
    
    printf("\n\nBubble Sort:\nO vetor ordenado: ");
	imprimir(bubble, tamanhoVetor);
    printf("O tempo de execucao foi de %lf ms.\n\n", tempoExecucao);

	 
	///////////////////////// Insertion Sort
    c1 = 0;
    c2 = 0;
    
    c1 = clock();
	copiarVetor(vetor, insertion, tamanhoVetor);
    insertionSort(insertion, tamanhoVetor);
    c2 = clock();
    tempoExecucao = ((c2-c1)*1000.0)/(CLOCKS_PER_SEC);
    
    printf("\n\nInsertion Sort:\nO vetor ordenado: ");
	imprimir(insertion, tamanhoVetor);
    printf("O tempo de execucao foi de %lf ms.\n\n", tempoExecucao);
 
 
 	///////////////////////// Selection Sort
    c1 = 0;
    c2 = 0;
    
    c1 = clock();
	copiarVetor(vetor, selection, tamanhoVetor);
    selectionSort(selection, tamanhoVetor);
    c2 = clock();
    tempoExecucao = ((c2-c1)*1000.0)/(CLOCKS_PER_SEC);
    
    printf("\n\nSelection Sort:\nO vetor ordenado: ");
	imprimir(selection, tamanhoVetor);
    printf("O tempo de execucao foi de %lf ms.\n\n", tempoExecucao);
 
 
 	///////////////////////// Quick Sort
    c1 = 0;
    c2 = 0;
    
    c1 = clock();
	copiarVetor(vetor, quick, tamanhoVetor);
    quickSort(quick, 0, tamanhoVetor);
    c2 = clock();
    tempoExecucao = ((c2-c1)*1000.0)/(CLOCKS_PER_SEC);
    
    printf("\n\nQuick Sort:\nO vetor ordenado: ");
	imprimir(quick, tamanhoVetor);
    printf("O tempo de execucao foi de %lf ms.\n\n", tempoExecucao);


	///////////////////////// Shell Sort
    c1 = 0;
    c2 = 0;
    
    c1 = clock();
	copiarVetor(vetor, shell, tamanhoVetor);
    shellSort(shell, tamanhoVetor);
    c2 = clock();
    tempoExecucao = ((c2-c1)*1000.0)/(CLOCKS_PER_SEC);
    
    printf("\n\nShell Sort:\nO vetor ordenado: ");
	imprimir(shell, tamanhoVetor);
    printf("O tempo de execucao foi de %lf ms.\n\n", tempoExecucao);

    return 0;
}