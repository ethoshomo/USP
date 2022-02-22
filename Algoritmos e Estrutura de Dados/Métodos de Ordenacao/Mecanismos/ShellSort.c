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