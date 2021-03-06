int* criaVetor(int quantidade);
void destruirVetor(int* vetor);
void lerVetor(int* vetor, int quantidade);
void imprimirVetor(int* vetor, int quantidade);
int pivoMediana(int *vetor, int inicio, int fim);
int pivoAleatorio(int i, int f);
void swap(int* vetor, int elementoA, int elementoB);
void insertionSort(int* vetor, int inicio, int fim);
int partition_aleatorio(int *vetor, int inicio, int fim);
void ubersort_aleatorio(int *vetor, int inicio, int fim);
int partition_mediana(int *vetor, int inicio, int fim);
void ubersort_mediana(int *vetor, int inicio, int fim);
void ubersort(int *vetor, int inicio, int fim, int escolhaPivo);