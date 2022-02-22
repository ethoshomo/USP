/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grandesNumeros.h"

int main(){
    int quantidadeEntradas = 0;
    
    scanf("%d", &quantidadeEntradas);
    verificarBarraRN();
    
    for(int i = 0; i < quantidadeEntradas; i++)
        resolveEntrada();

    return 0;
}