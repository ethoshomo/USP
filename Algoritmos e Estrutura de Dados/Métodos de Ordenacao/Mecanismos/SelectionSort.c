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