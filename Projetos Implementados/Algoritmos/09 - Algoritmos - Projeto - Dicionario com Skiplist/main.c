/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dicionario.h"

int main() {
    int saida = 0;
    char verbete[51], definicao[141];

    skiplist *dicionario = NULL;
    dicionario = criarSkiplist(dicionario);
    while (saida != 1){saida = resolverLinha(dicionario, verbete, definicao);}
    destruirSkiplist(dicionario);
    
    return 0;
}