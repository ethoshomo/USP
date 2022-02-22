#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

void iniciaVetor(char vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++)
        vetor[i] = ' ';
}

void corrigindoErro(char frase[], char erro[], char correto[]){
    char *indicaIndice;
    int tamanhoFrase, tamanhoErro, tamanhoCorreto;
    int flagRetorno;
    
    tamanhoFrase = strlen(frase);
    tamanhoErro = strlen(erro);
    tamanhoCorreto = strlen(correto);
    flagRetorno = 10;

    char copiaFrase[tamanhoFrase];
    strcpy(copiaFrase, frase);
    
    for(int i = 0; i < tamanhoFrase; i++){
        if (i < (tamanhoFrase - tamanhoErro)) {indicaIndice = &frase[i];}  
        flagRetorno = strncmp(erro, indicaIndice, tamanhoErro*sizeof(char));

        if (flagRetorno == 0){  
            frase[i] = '\0';
            strcat(frase, correto);
            int tamanho = tamanhoFrase-tamanhoErro-i;
            strncpy(&frase[i+tamanhoCorreto], &copiaFrase[i+tamanhoErro], tamanho);
            frase[i+tamanhoCorreto+tamanho] = '\0';
        }
    }
    printf("%s\n", frase);
}