#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimeVetor(int* vetor, int tamanhoVetor){
	if (tamanhoVetor <= 100){
		int i;
		for (i=0; i<tamanhoVetor; i++){
			printf("%i ", vetor[i]);
		}
	}
	printf("\n");
}

int* insertionSort(int* vetor, int tamanho){
	int j;
	for(j = 1; j < tamanho; j++){//o elemento na posi��o 0 n�o precisa analisar
		int chave = vetor[j]; //vari�vel auxiliar, tempor�ria para armazenar o valor do momento
		int i = j - 1; //armazenar a posi��o de an�lise do momento
		while (i >= 0 && vetor[i] > chave){//final do vetor ; valor do vetor � maior que a chave de an�lise
			vetor[i+1] = vetor[i];
			i--;
		}
		vetor[i+1] = chave;
	}
	
	return vetor;
}

void mergeSort(int* vetor, int inicio, int fim){
	//caso base
	if (fim <= inicio) return; //falso durante o processo de divis�o; 
	//verdadeiro quando o processo de divis�o n�o pode ser mais executado!!! --> possibilita a intercala��o

	//processo de divis�o
	int centro = (int)((inicio+fim)/2.0);
	mergeSort(vetor, inicio, centro);
	mergeSort(vetor, centro+1, fim);

	//processo de conquista
	//intercala��o
	int* vetorAux = (int*)malloc(sizeof(int) * (fim-inicio)+1);

	int i = inicio;	// indice da primeira lista ordenada
	int j = centro+1; //indice da segunda lista ordenada
	int k = 0; //indice do vetor auxiliar

	//compara e intercala os elementos do menor para o maior
	while(i <= centro && j <= fim){
		
		if (vetor[i] <= vetor[j]){ //verifica qual � o elemento menor entre as duas listas
			vetorAux[k] = vetor[i];
			i++; //proximo elemento da primeira metade
		}
		else{
			vetorAux[k] = vetor[j];
			j++; //proximo elemento da segunda metade
		}
		k++;
	}

	while(i <= centro){//h� elementos na primeira metade ainda?
		vetorAux[k] = vetor[i];
		i++;
		k++;
	}

	while(j <= fim){//h� elementos na segunda metade ainda?
		vetorAux[k] = vetor[j];
		j++;
		k++;
	}

	//atualizando o vetor original com o vetor auxiliar
	for(i = inicio, k = 0; i <= fim; i++,k++)
		vetor[i] = vetorAux[k];
	free(vetorAux);
}

int* bubbleSort(int* vetor, int tamanho){
	int i, j;
	for(i = 0; i < tamanho-1; i++){
		for(j = 0; j < tamanho-1-i; j++){
			if (vetor[j] > vetor[j+1]){
				int aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;		
			}
		}
	}
	
	return vetor;
}

void quickSort(int* vetor, int inicio, int fim){
	//primeira etapa: verificar caso base (vetores unit�rios ou nulos)
	if (fim <= inicio)
		return;

	//int pivo = inicio;//piv� no in�cio
	//int pivo = (int)((inicio+fim)/2); //piv� central
	int pivo = (int)(rand()%(fim-inicio))+inicio; //piv� aleat�rio

	//segunda etapa: parti��o em rela��o ao piv�
	int i = inicio+1; //percorre o vetor aumentando seu valor
	int j = fim;//percorre o vetor diminuindo seu valor

	//encontrando os elementos que contradizem as regras dos elementos da lista:
	//- elementos � esquerda do piv� devem ser <= a ele ou chegar ao final do vetor
	//- elementos � direita do piv� devem ser > que ele ou chegar ao in�cio do vetor
	int aux;
	while (i <= j){//quantas vezes forem necess�rias, ou seja, at� que as duas listas cruzam
		while (i <= fim && vetor[i] <= vetor[pivo]) i++; 
		while (vetor[j] > vetor[pivo]) j--; //quando j==pivo, a compara��o � falsa (encontrou o inicio do vetor)

		if (j > i){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
		}
	}

	pivo = j;
	aux = vetor[pivo]; //reposicionado o piv�
	vetor[pivo] = vetor[inicio];
	vetor[inicio] = aux;

	//terceira etapa: recurs�o
	quickSort(vetor, inicio, pivo-1); //j � a nova posi��o do piv�
	quickSort(vetor, pivo+1, fim);	
}

void heapifyMax(int* vetor, int pai, int tamanho);
void heapSort(int* vetor, int tamanho);

int main(int argc, char* argv[]){
	int geracaoVetor = atoi(argv[1]);
	int tamanhoVetor = atoi(argv[2]);
	clock_t inicio, final;
	
	//gera��o dos elementos
	int *vetorInsertion = malloc(tamanhoVetor * sizeof(int));
	int *vetorMerge = malloc(tamanhoVetor * sizeof(int));
	int *vetorBubble = malloc(tamanhoVetor * sizeof(int));
	int *vetorQuick = malloc(tamanhoVetor * sizeof(int));
	int *vetorHeap = malloc((tamanhoVetor+1) * sizeof(int));
	srand(time(NULL));
	
	int i;
	vetorHeap[0] = -1;
	for (i=0; i<tamanhoVetor; i++){
		if (geracaoVetor == 0) //aleat�rio
			vetorInsertion[i] = rand() % 1000;
		else if (geracaoVetor == 1) //ordenado
			vetorInsertion[i] = i;
		else if (geracaoVetor == 2) //invertido
			vetorInsertion[i] = tamanhoVetor - i;
		else if (geracaoVetor == 3 && i<=tamanhoVetor/2) //primeira metade ordenada e o restante aleat�rio
			vetorInsertion[i] = i;
		else if (geracaoVetor == 3) //primeira metade ordenada e o restante aleat�rio
			vetorInsertion[i] = (rand() % 1000) + i;
		vetorMerge[i] = vetorInsertion[i];
		vetorBubble[i] = vetorInsertion[i];
		vetorQuick[i] = vetorInsertion[i];
		vetorHeap[i+1] = vetorInsertion[i];
	}
	
	printf("Insertion Gerado: ");
	imprimeVetor(vetorInsertion, tamanhoVetor);
	inicio = clock();
	vetorInsertion = insertionSort(vetorInsertion, tamanhoVetor);
	final = clock();
	printf("Insertion Ordenado: ");
	imprimeVetor(vetorInsertion, tamanhoVetor);
	printf("Tempo de ordenacao Insertion: %lfs\n\n", (final-inicio)/(double)CLOCKS_PER_SEC);
	free(vetorInsertion);

	printf("Merge Gerado: ");
	imprimeVetor(vetorMerge, tamanhoVetor);
	inicio = clock();
	mergeSort(vetorMerge, 0, tamanhoVetor-1);
	final = clock();
	printf("Merge Ordenado: "); 
	imprimeVetor(vetorMerge, tamanhoVetor);
	printf("Tempo de ordenacao Merge: %lfs\n\n", (final-inicio)/(double)CLOCKS_PER_SEC);
	free(vetorMerge);

	printf("Bubble Gerado: ");
	imprimeVetor(vetorBubble, tamanhoVetor);
	inicio = clock();
	bubbleSort(vetorBubble, tamanhoVetor);
	final = clock();
	printf("Bubble Ordenado: "); 
	imprimeVetor(vetorBubble, tamanhoVetor);
	printf("Tempo de ordenacao Bubble: %lfs\n\n", (final-inicio)/(double)CLOCKS_PER_SEC);
	free(vetorBubble);

	printf("Quick Gerado: ");
	imprimeVetor(vetorQuick, tamanhoVetor);
	inicio = clock();
	quickSort(vetorQuick, 0, tamanhoVetor-1);
	final = clock();
	printf("Quick Ordenado: "); 
	imprimeVetor(vetorQuick, tamanhoVetor);
	printf("Tempo de ordenacao Quick: %lfs\n\n", (final-inicio)/(double)CLOCKS_PER_SEC);
	free(vetorQuick);

	printf("Heap Gerado: ");
	imprimeVetor(vetorHeap, tamanhoVetor);
	inicio = clock();
	heapSort(vetorHeap, tamanhoVetor-1);
	final = clock();
	printf("Heap Ordenado: "); 
	imprimeVetor(vetorHeap, tamanhoVetor);
	printf("Tempo de ordenacao Heap: %lfs\n\n", (final-inicio)/(double)CLOCKS_PER_SEC);
	free(vetorHeap);

	return 0;	
}
/*
	Objetiva manter a consist�ncia MaxHeap para uma sub-�rvore qualquer ()
*/

void heapifyMax(int* vetor, int pai, int tamanho){
	//verificar os filhos da "posi��o", se ferir a condi��o trocar o maior filho com o pai
	int filho = pai*2;//filho da esquerda
	//filho da direita = filho+1; pai*2+1

	//garantir que o n�-filho da esquerda existe
	if (filho > tamanho) return;

	//verificar a condi��o de heap em rela��o aos filhos
	//1 - o filho da esquerda � maior que o pai
	//2 - existe o filho da direita
	//3 - o filho da direita � maior que o pai
	//printf("Pai: %i. Esquerda %i.\n", vetor[pai], vetor[filho]);
	if (vetor[filho] > vetor[pai] || (filho+1 <= tamanho && vetor[filho+1] > vetor[pai])){
		//1 - existe o filho da direita
		//2 - o filho da direita � maior que o filho da esquerda
		if (filho+1 <= tamanho && vetor[filho+1] > vetor[filho])
			filho = filho+1;

		//troca o pai com o maior filho
		//***se o maior filho � o da esquerda, ele j� se encontra em "filho"
		int aux = vetor[pai];
		vetor[pai] = vetor[filho];
		vetor[filho] = aux;

		//atualizar poss�veis "netos" restantes
		heapifyMax(vetor, filho, tamanho);
	}
}

void heapSort(int* vetor, int tamanho){
	//Constru��o Heap
	int ultimoPai = (int)tamanho/2.0;
	int i;
	for (i = ultimoPai; i>=1; i--) //i=1 � o n� raiz
		heapifyMax(vetor, i, tamanho);
	//--- Aqui temos o vetor representado em uma estrutura de MaxHeap

	//processo ordena��o
	while (tamanho >= 2){
		//maior elemento est� sempre na raiz vetor[1]
		int maior = vetor[1];
		vetor[1] = vetor[tamanho];
		vetor[tamanho] = maior;

		tamanho--; // reduzimos o tamanho do Heap
		heapifyMax(vetor, 1, tamanho);//verificamos a consist�ncia do Heap para o n�-raiz!
	}
}