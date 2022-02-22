#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct ponto_t {
    int x, y;
} ponto;

int main(){
    pilha *p;

    p = criarPilha(sizeof(ponto));

    ponto ponto;
    for(int i = 0; i < 10; i++){
        ponto.x = i;
        ponto.y = -i;
        push(p, &ponto);
    }

    while(!pilhaVazia(p)){
        pop(p, &ponto);
        printf(" (%d %d) ", ponto.x, ponto.y);

    }



    destruirPilha(p);

    return 0;
}