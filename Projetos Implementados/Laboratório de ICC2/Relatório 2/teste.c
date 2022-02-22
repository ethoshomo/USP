#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanhoD 1000000


void quicksort(int values[], int began, int end){
	int i, j, pivo, aux;
	i = began;
	j = end-1;
	pivo = values[(began + end) / 2];
	while(i <= j)
	{
		while(values[i] < pivo && i < end)
		{
			i++;
		}
		while(values[j] > pivo && j > began)
		{
			j--;
		}
		if(i <= j)
		{
			aux = values[i];
			values[i] = values[j];
			values[j] = aux;
			i++;
			j--;
		}
	}
	if(j > began)
		quicksort(values, began, j+1);
	if(i < end)
		quicksort(values, i, end);
}



void peneira(int *vet, int raiz, int fundo);

void heapSort(int *vet, int n) {
	int i, tmp;

	for (i = (n / 2); i >= 0; i--) {
		peneira(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		peneira(vet, 0, i-1);
	}
}

void peneira(int *vet, int raiz, int fundo) {
	int pronto, filhoMax, tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (vet[raiz] < vet[filhoMax]) {
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
    }
	else {
      pronto = 1;
	}
  }
}



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

int* criarPiorCaso(int *piorCaso, int tamanhoVetor){
    //printf("\n\nPior caso (vetor):\n");
    int controle = tamanhoVetor;
    for (int i = 0; i < tamanhoVetor; i++){
        piorCaso[i] = (int)controle;
        controle -= 1;
        //printf("%d ", piorCaso[i]);
    }
    //printf("\n\n");
    return piorCaso;
}

int* criarMelhorCaso(int *melhorCaso, int tamanhoVetor){
    //printf("\n\nMelhor caso (vetor):\n");
    for (int i = 0; i < tamanhoVetor; i++){
        melhorCaso[i] = (int)i;
        //printf("%d ", melhorCaso[i]);
    }
    //printf("\n\n");
    return melhorCaso;
}

//void quickSort(int* vetor, int inicio, int fim);


int main(){

    srand(time(NULL));
    long unsigned int tamanhoVetor = tamanhoD;
    int c1, c2, w;//x;
    double tempoExecucao;

	for(w=0; w < 10; w++){

		int vetor[tamanhoVetor], quicksortV[tamanhoVetor], heapsortV[tamanhoVetor];
		//int melhorCaso[tamanhoVetor];// piorCaso[tamanhoVetor];

		//Cria o vetor aleatorio
		//printf("\n\nCaso Aleatorio (vetor):\n");
		//for (int i = 0; i < tamanhoVetor; i++){
		//	x = (rand()%100); // % limita os valores
		//	vetor[i] = (int)x;
			//printf("%d ", vetor[i]);
		//}
		criarPiorCaso(vetor, tamanhoVetor);
		copiarVetor(vetor, heapsortV, tamanhoVetor);
		copiarVetor(vetor, quicksortV, tamanhoVetor);


		///////////////////////// QuickSort
		c1 = 0;
		c2 = 0;
		//printf("\n\nO vetor antes da ordenação Quicksort:\n");
		//imprimir(quicksortV, tamanhoVetor);
		c1 = clock();
		quicksort(quicksortV, 0, tamanhoVetor);
		c2 = clock();
		tempoExecucao = ((c2-c1)*1000.0)/(CLOCKS_PER_SEC);
		//printf("\nQuickSort Sort:\n");
		//imprimir(quicksortV, tamanhoVetor);
		printf("O tempo de execucao do QuickSort, na execucao %d, foi de %lf ms.\n", w+1, tempoExecucao);

		
		///////////////////////// Heap Sort
		c1 = 0;
		c2 = 0;
		//printf("\n\nO vetor antes da ordenação Heapsort:\n");
		//imprimir(heapsortV, tamanhoVetor);
		c1 = clock();
		heapSort(heapsortV, tamanhoVetor);
		c2 = clock();
		tempoExecucao = ((c2-c1)*1000.0)/(CLOCKS_PER_SEC);
		
		//printf("Heap Sort:\n");
		//imprimir(heapsortV, tamanhoVetor);
		printf("O tempo de execucao do Heap Sort, na execucao %d, foi de %lf ms.\n\n", w+1, tempoExecucao);
	}
    return 0;
}
/*

void quickSort(int* vetor, int inicio, int fim){
	if (fim <= inicio)
		return;

	int pivo = (int)(rand()%(fim-inicio))+inicio;

	int i = inicio+1;
	int j = fim;
	
	int aux;
	while (i <= j){
		while (i <= fim && vetor[i] <= vetor[pivo]) i++; 
		while (vetor[j] > vetor[pivo]) j--; 

		if (j > i){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
		}
	}

	pivo = j;
	aux = vetor[pivo];
	vetor[pivo] = vetor[inicio];
	vetor[inicio] = aux;

	quickSort(vetor, inicio, pivo-1);
	quickSort(vetor, pivo+1, fim);	
}
*/