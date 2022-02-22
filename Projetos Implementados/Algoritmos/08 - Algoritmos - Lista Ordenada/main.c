/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(){
    
    int saida = 0;
    listaCadastro *l = criarLista();
    while (saida != 1){saida = resolveLinha(l);}       
    liberarLista(l);
    return 0;
}