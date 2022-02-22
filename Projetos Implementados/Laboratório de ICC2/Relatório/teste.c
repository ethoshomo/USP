#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

void bubbleSort(int *v, int n){ 
    n = n-1;

    if (n < 1) {return;}
 
    for (int contador = 0; contador < n; contador++){
        if (v[contador] > v[contador+1]){
            trocaVariavel(&v[contador], &v[contador+1]);
		}
	}
    bubbleSort(v, n); 
}


void insertionSort(int *v, int n) {
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


void intercala(int *vetor, int inicio, int centro, int fim){
    int* vetorAux = (int*)malloc(sizeof(int) * (fim-inicio)+1);
    int i = inicio;
    int j = centro+1;
    int k = 0;
    while(i <= centro && j <= fim){
        if (vetor[i] <= vetor[j]){ 
            vetorAux[k] = vetor[i];
            i++; 
        }
        else{
            vetorAux[k] = vetor[j];
            j++;
        }
        k++;
    }
    while(i <= centro){
        vetorAux[k] = vetor[i];
        i++;
        k++;
    }
    while(j <= fim){
        vetorAux[k] = vetor[j];
        j++;
        k++;
    }
    for(i = inicio, k = 0; i <= fim; i++,k++)
        vetor[i] = vetorAux[k];
    free(vetorAux);
}

void mergeSort(int *vetor, int inicio, int fim){
    if (fim <= inicio) return;
    int centro = (int)((inicio+fim)/2.0);
    mergeSort(vetor, inicio, centro);
    mergeSort(vetor, centro+1, fim);
    intercala(vetor, inicio, centro, fim);
}




int* criarPiorCaso(int *piorCaso, int tamanhoVetor){
    printf("\n\nPior caso (vetor):\n");
    int controle = tamanhoVetor;
    for (int i = 0; i < tamanhoVetor; i++){
        piorCaso[i] = (int)controle;
        controle -= 1;
        printf("%d ", piorCaso[i]);
    }
    printf("\n\n");
    return piorCaso;
}

int* criarMelhorCaso(int *melhorCaso, int tamanhoVetor){
    //Cria vetor melhor caso
    printf("\n\nMelhor caso (vetor):\n");
    for (int i = 0; i < tamanhoVetor; i++){
        melhorCaso[i] = (int)i;
        printf("%d ", melhorCaso[i]);
    }
    printf("\n\n");
    return melhorCaso;
}


int main(){

    srand(time(NULL));
    long unsigned int tamanhoVetor;
    int c1, c2;// x;
    double tempoExecucao;

    printf("Digite o tamanho do vetor:\n");
    scanf("%ld", &tamanhoVetor);
    int vetor[tamanhoVetor], bubble[tamanhoVetor], insertion[tamanhoVetor];
	int merge[tamanhoVetor];// melhorCaso[tamanhoVetor], piorCaso[tamanhoVetor];

    //Cria o vetor aleatorio
    //printf("\n\nCaso Aleatorio (vetor):\n");
    //for (int i = 0; i < tamanhoVetor; i++){
    //    x = (rand()%100); // % limita os valores
    //    vetor[i] = (int)x;
    //    //printf("%d ", vetor[i]);
    //}
    criarPiorCaso(vetor, tamanhoVetor);
    copiarVetor(vetor, bubble, tamanhoVetor);
    copiarVetor(vetor, insertion, tamanhoVetor);
	copiarVetor(vetor, merge, tamanhoVetor);

    ///////////////////////// Bubble Sort
    c1 = 0;
    c2 = 0;
    c1 = clock();
    bubbleSort(bubble, tamanhoVetor);
    c2 = clock();
    tempoExecucao = ((c2-c1)*1000.0)/(CLOCKS_PER_SEC);
    printf("\n\nBubble Sort:\nO vetor aleatorio ordenado: ");
	//imprimir(bubble, tamanhoVetor);
    printf("O tempo de execucao foi de %lf ms.\n\n", tempoExecucao);

    
	///////////////////////// Insertion Sort
    c1 = 0;
    c2 = 0;
    
    c1 = clock();
    insertionSort(insertion, tamanhoVetor);
    c2 = clock();
    tempoExecucao = ((c2-c1)*1000.0)/(CLOCKS_PER_SEC);
    
    printf("\n\nInsertion Sort:\nO vetor aleatório ordenado: ");
	//imprimir(insertion, tamanhoVetor);
    printf("O tempo de execucao foi de %lf ms.\n\n", tempoExecucao);
 
    
    ///////////////////////// Merge Sort   
    c1 = 0;
    c2 = 0;
    c1 = clock();
    mergeSort(merge, 0, tamanhoVetor);
    c2 = clock();
    tempoExecucao = ((c2-c1)*1000.0)/(CLOCKS_PER_SEC);
    printf("\n\nMerge Sort:\nO vetor aleatorio ordenado: ");
	//imprimir(bubble, tamanhoVetor);
    printf("O tempo de execucao foi de %lf ms.\n\n", tempoExecucao);
    
    return 0;
}