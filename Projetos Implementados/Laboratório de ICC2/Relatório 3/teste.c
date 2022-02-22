#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanhoD 50000


typedef struct{
	int key;
	int value;
	//outros atributos
} Record;

typedef struct node{
	Record elem;
	struct node* next;
} Node;

typedef struct bucket{
	Node* begin;
	Node* end;
} Bucket;

/*
	De forma geral, os melhores algoritmos de compara��o s�o n.log(n)
	Bucket Sort � fundamentado em listas encadeadas chamadas de bucket
	Cada lista esta associada a uma chave espec�fica
	O ganho na complexidade f(n) < n.log(n) vem com o custo adicional de aloca��o de mem�ria auxiliar.
	
	Exemplo : [1 5 0 0 5 1 2 5 3 1]
	
	1) Percorrer as chaves e verificar o m�nimo e m�ximo (m�nimo = 0; m�ximo = 5)
	2) Cria��o de um vetor adicional de listas (buckets):
		 0 1 2 3 4 5
		[           ]
	3) Percorrer o vetor e preencher os buckets de acordo com as chaves:
		 0 1 2 3 4 5
		[           ]
		 | | | | | |
		 0 1 2 3   5
		 0 1       5
		   1       5
	4) Posicionar os elementos no vetor original, retirando elementos da lista:
		original			 bucket
	 0 1 2 3 4 5 6 7 8 9       0      1       2   3   4  5
	[1 5 0 0 5 1 2 5 3 1]	 [(0, 0) (1 1 1) (2) (3) () (5 5 5)]
	[0 5 0 0 5 1 2 5 3 1]	 [(0)    (1 1 1) (2) (3) () (5 5 5)]
	[0 0 0 0 5 1 2 5 3 1]	 [()     (1 1 1) (2) (3) () (5 5 5)]
	[0 0 1 0 5 1 2 5 3 1]	 [()     (1 1)   (2) (3) () (5 5 5)]
	[0 0 1 1 5 1 2 5 3 1]	 [()     (1)     (2) (3) () (5 5 5)]
	[0 0 1 1 1 1 2 5 3 1]	 [()     ()      (2) (3) () (5 5 5)]
	[0 0 1 1 1 2 2 5 3 1]	 [()     ()      ()  (3) () (5 5 5)]
	[0 0 1 1 1 2 3 5 3 1]	 [()     ()      ()  ()  () (5 5 5)]
	[0 0 1 1 1 2 3 5 3 1]	 [()     ()      ()  ()  () (5 5)  ]
	[0 0 1 1 1 2 3 5 5 1]	 [()     ()      ()  ()  () (5)    ]
	[0 0 1 1 1 2 3 5 5 5]	 [()     ()      ()  ()  () ()     ]
	
	Complexidade:
	- 1) n
	- 2) 
	- 3) n
	- 4) k + n
	
	Ent�o: f(n) = 3n + k; O(n+k)
	
	Observa��o:
	- chaves discretas e desejavelmente inteiros
	- aloca��o de mem�ria auxiliar
	- em termos de mem�ria gastamos um pouco mais, pois temos uma lista encadeada com ponteiros
*/
/*
void bucketFERNANDO(Record* vetor, int tamanho){
	int max, min;
	max = min = vetor[0].key;
	int i = 0;
	for(i = 0; i<tamanho; i++){
		if (vetor[i].key > max) max = vetor[i].key;
		if (vetor[i].key < min) min = vetor[i].key;
	}
	
	Bucket* B = (Bucket*) calloc(max-min+1, sizeof(Bucket));
	
	for(i = 0; i<tamanho; i++){
		int posicaoKey = vetor[i].key - min;
		
		Node* novo = malloc(sizeof(Node));
		novo->elem = vetor[i];
		novo->next = NULL;
		
		if (B[posicaoKey].begin == NULL)
			B[posicaoKey].begin = novo;
		else
			(B[posicaoKey].end)->next = novo;
		B[posicaoKey].end = novo;
	}

	int j = 0;
	for(i = 0; i<=(max-min); i++){
		Node* posicao;
		posicao = B[i].begin;
		while(posicao != NULL){
			vetor[j] = posicao->elem;
			j++;
			
			Node *deletar = posicao;
			posicao = posicao->next;
			B[i].begin = posicao;
			free(deletar);
		}
	}
	free(B);
}
*/


void countingsortFERNANDO(Record* vetor, int tamanho){
	Record* vetorAux = (Record*) malloc(tamanho * sizeof(Record));
	int max, min;
	max = min = vetor[0].key;
	int i = 0;
	for(i = 1; i<tamanho; i++){
		if (vetor[i].key > max) max = vetor[i].key;
		if (vetor[i].key < min) min = vetor[i].key;
		vetorAux[i] = vetor[i];
	}

	int* vetorContagem = (int*) calloc(max-min+1, sizeof(int));
	
	for(i = 0; i<tamanho; i++){
		int posicaoKey = vetor[i].key - min;
		vetorContagem[posicaoKey]++;
	}
	
	int total = 0;
	for(i = 0; i<=(max-min); i++){
		int contagemAnterior = vetorContagem[i];
		vetorContagem[i] = total;
		total = total + contagemAnterior;
	}
	
	for(i = 0; i<tamanho; i++){
		int posicaoOrdenada = vetorContagem[vetorAux[i].key-min];
		vetor[posicaoOrdenada] = vetorAux[i];
		vetorContagem[vetorAux[i].key-min]++;
	}
	
	free(vetorContagem);
	free(vetorAux);
}







/*
typedef struct {
	int key; // campo chave - ordenacao e busca
	float value1;
	char value2;
} Record;

// tipo para lista encadeada
typedef struct node {
	Record elem;
	struct node* next;
} Node;

// tipo para fila (com fim e inicio da lista)
typedef struct bucket {
	Node* begin;
	Node* end;
} Bucket;

 Algoritmo countingsort com registros
 * Parametros:
 * 	Record* v: vetor de structs com campo chave=key
 * 	int N: tamanho do vetor

void countingsort_rec(Record* v, int N) {
	
	// 1.o - Alocar memoria para manter uma copia
	// 	 do vetor original
	Record* vcop = (Record*) malloc(N * sizeof(Record));

	// 2.o - Alocar vetor de contagem (acumulada)
	// 	 antes disso, encontrar o intervalo de chaves
	// 	 [min, max] -> alocar vetor com menor tamanho
	//         0   ultima

	// encontra maior, menor, faz copia
	int max, min;
	max = min = v[0].key; // chave inicial
	for (int i = 0; i < N; i++) {
		if (v[i].key > max) max = v[i].key; // maior
		if (v[i].key < min) min = v[i].key; // menor
		vcop[i] = v[i]; // copia "rasa" da struct (cuidado aqui)
	}

	// aloca vetor de contagem
	int* C = (int *) calloc( (max-min)+1, sizeof(int) );
	
	// 3.o - contagem acumulada das chaves
	// contagem de cada chave  
	for (int i = 0; i < N; i++) {
		int pos_key = v[i].key-min; // desloca min=0
		C[pos_key]++; // incrementa ocorrencia da chave
	}

	// acumular a contagem (cada posicao indica quantos
	// valores no vetor sao menores do que aquela chave)
	//  2  3  4  5  6 => chaves
	//  0, 1, 2, 3, 4 => posicoes
	// [2, 6, 1, 0, 2]  contagem
	//
	// [0, 2, 8, 9, 9]  contagem acumulada
	int tot = 0;
	for (int j = 0; j <= (max-min); j++) {
		int c_ant = C[j]; // guardo n.o chaves anterior
		C[j] = tot; // acumulado antes de j
		tot = tot + c_ant; // atualizo total acumulado
	}

	// 4 - percorrer o vetor de copia e produzir
	//     o posicionamento correto no vetor original
	for (int i = 0; i < N; i++) {
		int pos_ord = C[vcop[i].key-min];

		// atribui a posicao correta no vetor original
		v[pos_ord] = vcop[i];

		// atualiza a proxima posicao da chave
		C[vcop[i].key-min]++;
	}

	free(vcop);
	free(C);
}



//https://github.com/viviana-ra/algoritmoBucketSort/blob/main/bucketSort.c
int getMax(int a[], int n){  
  int max = a[0];  
  for (int i = 1; i < n; i++)  
    if (a[i] > max)  
      max = a[i];  
  return max;  
}  

void bucket2(int a[], int n){  
  int max = getMax(a, n); 
  int bucket[max];  
  for (int i = 0; i <= max; i++){  
    bucket[i] = 0;  
  }  
  for (int i = 0; i < n; i++){  
      bucket[a[i]]++;  
  }  
  for (int i = 0, j = 0; i <= max; i++){  
    while (bucket[i] > 0){  
        a[j++] = i;  
        bucket[i]--;  
    }  
  }  
}

*/






//https://www.javatpoint.com/counting-sort

int getMaxC(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; //maximum element from the array  
}  

void counting_sort_teste(int a[], int n) // function to perform counting sort  
{  
   int output[n+1];  
   int max = getMaxC(a, n);  
   int count[max+1]; //create count array with size [max+1]  
   
  for (int i = 0; i <= max; ++i){  
    count[i] = 0; // Initialize count array with all zeros  
  }  
    
  for (int i = 0; i < n; i++) // Store the count of each element  
  {  
    count[a[i]]++;  
  }  
  
   for(int i = 1; i<=max; i++)   
      count[i] += count[i-1]; //find cumulative frequency  
  
  /* This loop will find the index of each element of the original array in count array, and 
   place the elements in output array*/  
  for (int i = n - 1; i >= 0; i--) {  
    output[count[a[i]] - 1] = a[i];  
    count[a[i]]--; // decrease count for same numbers  
}  
  
   for(int i = 0; i<n; i++) {  
      a[i] = output[i]; //store the sorted elements into main array  
   }  
} 

/*

//https://www.tutorialspoint.com/c-program-for-radix-sort
int get_max (int a[], int n){
   int max = a[0];
   for (int i = 1; i < n; i++)
      if (a[i] > max)
         max = a[i];
   return max;
}
void radix_sort (int a[], int n){
   int bucket[10][10], bucket_cnt[10];
   int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
   lar = get_max (a, n);
   while (lar > 0){
      NOP++;
      lar /= 10;
   }
   for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }
      for (i = 0; i < n; i++){
         r = (a[i] / divisor) % 10;
         bucket[r][bucket_cnt[r]] = a[i];
         bucket_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            a[i] = bucket[k][j];
            i++;
         }
      }
      divisor *= 10;
   }
}
*/



int findLargestNum(int * array, int size){
  int i;
  int largestNum = -1;
  
  for(i = 0; i < size; i++){
    if(array[i] > largestNum)
      largestNum = array[i];
  }  
  return largestNum;
}

void radixSort(int * array, int size){

  int i;
  int semiSorted[size];
  int significantDigit = 1;
  int largestNum = findLargestNum(array, size);
  
  while (largestNum / significantDigit > 0){  
    int bucket[10] = { 0 };

    for (i = 0; i < size; i++)
      bucket[(array[i] / significantDigit) % 10]++;

    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];    

    for (i = size - 1; i >= 0; i--)
      semiSorted[--bucket[(array[i] / significantDigit) % 10]] = array[i];
    
    for (i = 0; i < size; i++)
      array[i] = semiSorted[i];
    
    significantDigit *= 10;
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

/*
void imprimirBucket(Record *v, int tamanho){
	for (int i = 0; i < tamanho; i++){
		printf("%d ", v[i].key);
	}
	printf("\n\n");
}
*/
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
    int c1, c2, w;//, x;
    double tempoExecucao;

	for(w=0; w < 10; w++){

		int vetor[tamanhoVetor];//,buckets[tamanhoVetor];
		//int melhorCaso[tamanhoVetor];// piorCaso[tamanhoVetor];
		//Record *vetor = (Record*)malloc(sizeof(Record)*tamanhoVetor);
		//Record *buckets = (Record*)malloc(sizeof(Record)*tamanhoVetor);
		//int *raddixs = (int*)malloc(sizeof(int)*tamanhoVetor);
		//int *counts = (int*)malloc(sizeof(int)*tamanhoVetor);

		criarPiorCaso(vetor, tamanhoVetor);
		//Cria o vetor aleatorio
		//printf("\n\nCaso Aleatorio (vetor):\n");
		//for (int i = 0; i < tamanhoVetor; i++){
			//x = (rand()%100); // % limita os valores
			//buckets[i].key = (int)x;
			//vetor[i] = (int)x;
			//buckets[i].key = (int)x;
			//counts[i].key = (int)x;
			//printf("%d ", buckets[i].key);
		//}
		
		//criarPiorCaso(vetor, tamanhoVetor);
		//copiarVetor(vetor, counts, tamanhoVetor);
		//copiarVetor(vetor, buckets, tamanhoVetor);
/*
		//imprimirBucket(buckets, tamanhoVetor);
		///////////////////////// Bucket
		c1 = 0;
		c2 = 0;
		//printf("\n\nO vetor antes da ordenação Bucketsort:\n");
		//imprimirBucket(buckets, tamanhoVetor);
		c1 = clock();
		bucketFERNANDO(buckets, tamanhoVetor);
		c2 = clock();
		tempoExecucao = ((c2-c1)*1000.0)/(CLOCKS_PER_SEC);
		//printf("\nBucket Sort:\n");
		//imprimirBucket(buckets, tamanhoVetor);
		printf("O tempo de execucao do BucketSort, na execucao %d, foi de %lf ms.\n", w+1, tempoExecucao);
*/


		///////////////////////// Counting Sort
		c1 = 0;
		c2 = 0;
		//printf("\n\nO vetor antes da ordenação Counting Sort:\n");
		//imprimir(counts, tamanhoVetor);
		c1 = clock();
		counting_sort_teste(vetor, tamanhoVetor);
		c2 = clock();
		tempoExecucao = ((c2-c1)*1000.0)/(CLOCKS_PER_SEC);
		//printf("Counting Sort:\n");
		//imprimir(vetor, tamanhoVetor);
		printf("O tempo de execucao do Counting Sort, na execucao %d, foi de %lf ms.\n", w+1, tempoExecucao);


/*
		///////////////////////// RaddixSort
		c1 = 0;
		c2 = 0;
		//printf("\n\nO vetor antes da ordenação Raddix:\n");
		//imprimir(raddixs, tamanhoVetor);
		c1 = clock();
		radixSort(raddixs, tamanhoVetor);
		c2 = clock();
		tempoExecucao = ((c2-c1)*1000.0)/(CLOCKS_PER_SEC);
		//printf("Raddix Sort:\n");
		//imprimir(raddixs, tamanhoVetor);
		printf("O tempo de execucao do Raddix, na execucao %d, foi de %lf ms.\n", w+1, tempoExecucao);
*/

	}
    return 0;
}
