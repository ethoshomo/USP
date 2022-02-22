/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavras.h" 

int main(){
    //Bloco de declaração de variáveis
    int saida = 0, imprimir = 0;
    char texto[400];
    int tamanhoLista, quantidadeImpressoes;
    lista *l;

    while(saida != EOF){
        //Prepara as variáveis, inclusive para próximos loops.
        l = NULL;
        quantidadeImpressoes = 0;
        tamanhoLista = 0;
        
        //Coleta e prepara os dados do texto
        iniciaVetor(texto, 400);
        saida = scanf("%[^\r\n]", texto);
        if (saida == EOF) {break;}
        if (imprimir !=0) {printf("\n");}
        getchar(); // coleta o \r
        getchar(); // coleta o \n
        texto[strlen(texto)] = '\0';
        l = criarLista(texto, &tamanhoLista); // Cria a lista contabilizando palavras
        ordenaListaNumero(l, &tamanhoLista); // Ordena por quantidade de vezes
        ordenaListaLetra(l, &tamanhoLista); // Ordena por ordem alfabetica as empatadas

        //Coleta e imprime a quantidade de impressões que deverão ser feitas
        saida = scanf("%d", &quantidadeImpressoes);
        getchar(); // coleta o \r
        getchar(); // coleta o \n
        imprimirLista(l, quantidadeImpressoes, tamanhoLista, &imprimir);
        
        //Bloco de desalocação, que também prepara o programa ao próximo loop
        for (int i = 0; i < tamanhoLista; i++)
            free(l[i].palavra);
    
        free(l);
    }

    return 0;
}