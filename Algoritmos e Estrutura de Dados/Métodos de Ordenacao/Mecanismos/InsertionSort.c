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