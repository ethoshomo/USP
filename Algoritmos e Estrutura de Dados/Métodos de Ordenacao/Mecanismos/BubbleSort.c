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