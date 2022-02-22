/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*                      nUSP 12542630                          *
***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

int main(){
    char frase[100], erro[20], correto[20];
    int saida = 0;

    while(saida != EOF){
        iniciaVetor(frase, 100);
        saida = scanf("%[^\n]", frase);
        if (saida == EOF) {break;}
        getchar();
        frase[strlen(frase)] = '\0';

        iniciaVetor(erro, 20);
        saida = scanf("%[^\n]", erro);
        if (saida == EOF) {break;}
        getchar();
        erro[strlen(erro)] = '\0';
        
        iniciaVetor(correto, 20);    
        saida = scanf("%[^\n]", correto);
        if (saida == EOF) {break;}
        getchar();
        correto[strlen(correto)] = '\0';

        corrigindoErro(frase, erro, correto);
    }

    return 0;
}
