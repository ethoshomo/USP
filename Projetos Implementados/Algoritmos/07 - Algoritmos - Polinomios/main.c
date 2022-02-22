/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "polinomios.h"

int main(){

    int quantidadeCasosTestes = 0;
    int quantidadePolinomios = 0;
    
    scanf("%d", &quantidadeCasosTestes);

    for(int i = 0; i < quantidadeCasosTestes; i++){

        scanf("%d", &quantidadePolinomios);
        getchar(); // Despreza \r
        getchar(); // Despreza \n

        polinomio* resultado = NULL;
        resultado = criarPolinomioResultado();

        for (int j = 0; j < quantidadePolinomios; j++){
            resultado = readLine(resultado);
        }
        imprimir(resultado);
        destruirPolinomioResultado(resultado);
    }
    
    return 0;
}