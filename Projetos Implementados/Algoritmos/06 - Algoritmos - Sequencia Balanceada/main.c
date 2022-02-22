/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "balanceada.h"

int main(){
    int contador = 0;
    int retorno = 0;

    do{ 
        if (contador != 0){printf("\n");}
        retorno = leituraPilha();
        contador += 1;
    }while (retorno != EOF);

    return 0;
}