#include <stdio.h>
#include <stdlib.h>

double buscaSequencial(double x, double n, double v[]){
    for(int i = 0; i < n; i++)
        if (v[i] == x) {return i;}

    return -1;
}

double buscaBinaria(double x, double n, double v[]){
    int esquerda = -1, direita = n;
    while(esquerda < (direita-1)){
        int meio = (esquerda+direita)/(2);
        if (v[meio] < x) {esquerda = meio;}
        else {direita = meio;}
    }
    return direita;
}