#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    fila *f;
    tipoDado x;

    f = criarFila();

    for(int i = 0; i < 10; i++){
        filaInserir(f, i);
    }

    while(!filaVazia(f)){
        filaRemover(f, &x); 
        printf("%d ", x);
    }
    printf("\n");

    destruirFila(f);
    
    return 0;
}