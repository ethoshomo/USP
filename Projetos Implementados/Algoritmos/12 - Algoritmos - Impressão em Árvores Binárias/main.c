/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*            Árvores Binárias - Impressão de ABB              *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "impressao.h"

int main(){
    
    int saida = 0;
    char comando[20];
    arvore *raiz = NULL;
    inicializa_vetor(comando, 20);
  
    do{
        saida = scanf("%20[^,\r,\n,' ']s", comando);
        if (saida == EOF){break;}
        else if(strcmp(comando, "impressao") == 0) {menu_impressao(raiz);}
        else if(strcmp(comando, "insercao") == 0) {raiz = menu_insercao(raiz);}
    }while(saida != EOF);

    destruirArvore(raiz);
    return 0;
}