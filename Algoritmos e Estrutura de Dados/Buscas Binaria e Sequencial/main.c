#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "buscas.h"


int main(){

    srand(time(NULL));
    long unsigned int tamanhoVetor;
    double numeroBuscado, resultado, c1, c2;
    double x, tempoExecucao;

    printf("Digite o tamanho do vetor:\n");
    scanf("%ld", &tamanhoVetor);
    double vetor[tamanhoVetor];

    for (int i = 0; i < tamanhoVetor; i++){
        x = x + (rand()%5); // % limita os valores
        vetor[i] = (int)x;
        printf("%.lf ", vetor[i]);
    }

    printf("Digite o numero que deseja buscar:\n");
    scanf("%lf", &numeroBuscado);


    ///////////////////////// Busca Sequencial
    c1 = 0;
    c2 = 0;
    resultado = 0;
    
    c1 = clock();
    resultado = buscaSequencial(numeroBuscado, tamanhoVetor, vetor);
    c2 = clock();
    tempoExecucao = ((c2-c1)*1000.0)/(CLOCKS_PER_SEC);
    
    printf("\n\nBusca Sequencial:\n");
    if (resultado == -1) {printf("O numero não foi encontrado.");}
    else{ printf("Foi encontrado o valor %lf na posicao %lf.\n", numeroBuscado, resultado);}
    printf("O tempo de execucao foi de %lf ms.\n\n", tempoExecucao);
   

    ///////////////////////// Busca Binária
    c1 = 0;
    c2 = 0;
    resultado = 0;
    
    c1 = clock();
    resultado = buscaBinaria(numeroBuscado, tamanhoVetor, vetor);
    c2 = clock();
    tempoExecucao = ((c2-c1)*1000.0)/(CLOCKS_PER_SEC);
    
    printf("Busca Binaria:\n");
    printf("Foi encontrado o valor %lf na posicao %lf.\n", numeroBuscado, resultado);
    printf("O tempo de execucao foi de %lf ms\n\n", tempoExecucao);

    return 0;
}