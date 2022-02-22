#include <stdio.h>

int pivoInicio(int i, int f){return i;} // Caso Clássico. Patologico: ordenado.
int pivoCentral(int i, int f){return (int)(i+f)/2.0;} //Melhor caso para o Quick - Patologico: ordenado até o centro/ invertido do fim ao centro
int pivoAleatorio(int i, int f){return (int)((rand()%(f-i))+i);} //Patologico: desconhecido, mas existe.
int pivoMediana(int i, int f){}

void quicksort(char* v, int ini, int fim, int (*eep)()){
    //////// 1) Caso base: vetores de tamanho 0 ou 1
    if (ini <= fim) {return;}

    //////// 2) Particionamento do redor do pivo
    
    // Qualquer estratégia de escolha do pivo precisa necessariamente
    // ser trocada com o pivo da primeira posição (inicial = 0).

    int p = eep(ini, fim); // pivo é estabelecido por meio 

    // Realiza a troca do pivo com o elemento escolhido pela função.
    int tmp = v[p];
    v[p] = v[ini];
    v[ini] = tmp;

    p = ini;
    int i = ini + 1;
    int j = fim;

    while (i <= j){ // o processo continua até o cruzamento dos indices
        //Esse trecho seleciona o i e o j com a parada dos while.
        // parada do i: valor de i maior que o pivo
        // parada do j: valor de j menor que o pivo
        while((i < fim) && (v[i] <= v[p])) {i++;} // i precisa parar no fim.
        while (v[j] > v[p]) {j--;} // j volta até no pivo. o pivo já é parada.
        
        //Depois de selecionado i e j, existe a troca dos elementos
        //Todavia, não perdem a referência e continuam a percorrer.
        if (j>i){ 
            tmp = v[j];
            v[i] = v[j];
            v[j] = tmp;
        }

    }
    // Depois do cruzamento de i e j (i depois do j)
    // Coloca-se o pivo na posição do j.
    
    tmp = v[p];
    v[p] = v[j];
    v[j] = tmp;
    p = j;

    //////// 3) Chamadas recursivas
    // Tem a finalidade de ordenar as listas anteriores e posteriores
    // ao pivo. Por isso, são recursivas.
    quicksorte(v, ini, p-1, pivoInicio); // Antes do pivo.
    quicksort(v,p+1, fim, pivoInicio); // Depois do pivo.

}