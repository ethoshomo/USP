#include <stdio.h>
#include <stdlib.h>
#include "generalizada.h"

int main(){

    no *l1 = concat(atomo (3), atomo(4));
    no *l2 = sublista(l1);
    l2 = concat(l2, atomo(2));
    no *l = concat(atomo(1), l2);
    imprimir(l); // imprime (1, (3,4), 2)

    libera(l);

    return 0;
}