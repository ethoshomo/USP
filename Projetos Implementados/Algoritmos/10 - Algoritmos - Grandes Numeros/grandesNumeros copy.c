#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grandesNumeros.h"

typedef struct no_t no;

struct no_t{
    elemento numero;
    no *anterior, *proximo;
};

struct numero_t{
    char sinal;
    elemento vaiUm;
    no *inicio, *fim;    
};


//Na impossibilidade de usar bibliotecas,
//foi necessário criar essa função para converter
//char em int.
int retornaNumero(char caracter){
    switch(caracter){
        case 48: return 0;
        case 49: return 1;
        case 50: return 2;
        case 51: return 3;
        case 52: return 4;
        case 53: return 5;
        case 54: return 6;
        case 55: return 7;
        case 56: return 8;
        case 57: return 9;
        default: break;
    }
    return -1;
}

void lerNumero(numero *n1, numero *n2){
    char ch;
    ch = getchar();
    //Verifica Sinal do Numero 1
    ch = getchar();
    if (ch == '-'){n1->sinal = 'n';}
    else if (ch == ' '){}
    else {ungetc(ch, stdin);}
    //Coleta os algarismos do Numero 1
    while (ch != EOF){
        ch = getchar();
        if ((ch == ' ') || (ch == '\r')){break;}
        inserir(n1, retornaNumero(ch));
    } 
    
    // Verifica Sinal do Numero 2
    ch = getchar();
    if (ch == '-'){n2->sinal = 'n';}
    else if (ch == ' '){}
    else {ungetc(ch, stdin);}
    //Coleta os algarismos do Numero 2
    while (ch != EOF){
        ch = getchar();
        if ((ch == ' ') || (ch == '\r')){break;}
        inserir(n2, retornaNumero(ch));
    } 
    verificarBarraRN();
}

void verificarBarraRN(){
    char ch = ' ';
    ch = getchar();
    if (ch != '\r'){ungetc(ch, stdin);}
    ch = getchar();
    if (ch != '\n'){ungetc(ch, stdin);}
}

int resolveEntrada(){
    int saida = 0;
    char comando[5];
    numero *numero1 = criarNumero();
    numero *numero2 = criarNumero();
    numero *resultado = criarNumero();

    saida = scanf("%5[^,' ']s", comando);
    
    if (saida == EOF){
        liberarNumero(numero1);
        liberarNumero(numero2);
        liberarNumero(resultado);
        return 1;
    }
    else if(strcmp(comando, "SUM") == 0) {
        lerNumero(numero1, numero2);
        soma(numero1, numero2, resultado);
    }
    else if(strcmp(comando, "BIG") == 0) {
        lerNumero(numero1, numero2);    
        printf("%d\n", big(numero1, numero2));
    }
    else if(strcmp(comando, "SML") == 0) {
        lerNumero(numero1, numero2);
        printf("%d\n", small(numero1, numero2));   
    }
    else if(strcmp(comando, "EQL") == 0) {
        lerNumero(numero1, numero2);
        printf("%d\n", igual(numero1, numero2));
    }

    liberarNumero(numero1);
    liberarNumero(numero2);
    liberarNumero(resultado);

    return 0;
}

numero *criarNumero(){
    numero *p;
    p = (numero*)malloc(sizeof(numero));
    p->vaiUm = 0;
    p->sinal = 'p';
    p->inicio = NULL;
    p->fim = NULL;
    return p;
}

void liberarNumero(numero *n){
    if (n != NULL){
        no *auxiliar = n->inicio;
        while (auxiliar != NULL){
            n->inicio = n->inicio->proximo;
            free(auxiliar);
            auxiliar = n-> inicio;
        }
        free(n);
    }
}

int inserir(numero *n, elemento x){
    if (n != NULL){
        no *p = (no*)malloc(sizeof(no));
        
        if (n->inicio == NULL && n->fim == NULL){
            p->numero = x;
            p->proximo = NULL;
            p->anterior = NULL;
            n->inicio = p;
            n->fim = p;
        }
        else{
            n->inicio->anterior = p;
            p->numero = x;
            p->proximo = n->inicio;
            p->anterior = NULL;
            n->inicio = p;
        }
        
        return 1;
    }
    return 0;
}

int tamanho(numero *n){
    if (n != NULL){
        int tamanho = 0;
        no *p = n->fim;
        while (p != NULL){
            if (p->numero != 0)
                tamanho += 1;
            p = p->anterior;
        }
        return tamanho;
    }
    return 0;
}

void imprimir(numero *n){
    if(n != NULL){
        no *p = n->inicio;
        
        while (p != NULL){
            printf("%d", p->numero);
            p = p->proximo;
        }
        printf("\n");
    }
}

void imprimirInverso(numero *n){
    if (n != NULL){
        no *p = n->fim;
        while (p != NULL){
            printf("%d", p->numero);
            p = p->anterior;
        }
        printf("\n");
    }
}