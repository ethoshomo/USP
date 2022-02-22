#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    pilha *p;
    tipoDado x;

    p = criarPilha();

    for(int i = 0; i < 10; i++){
        scanf("%d", &x);
        push(p, x);
    }

    while(!pilhaVazia(p)){
        pop(p, &x); //Recebe por referência o elemento pop.
        printf("%d ", x);
    }
    printf("\n");

    destruirPilha(p);
    
    return 0;
}