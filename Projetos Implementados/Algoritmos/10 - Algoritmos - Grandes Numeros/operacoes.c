#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grandesNumeros.h"

//////////////////Função Big Sem Sinal
// Finalidade: analisa se o primeiro numero é maior que
// o segundo em valor (sem considerar o sinal dos dois 
// numeros).
// Retorno: existem três retornos: 
//              - 0: se n1 < n2
//              - 1: se n1 > n2
//              - 2: se n1 = n2
// Observação: Foi necessário o número dois porque a lógica
// não permitia decidir o sinal do zero (nas outras funções).
int bigSemSinal(numero *n1, numero *n2){

    no *auxiliarN1 = n1->fim;
    no *auxiliarN2 = n2->fim;

    if (tamanho(n1) > tamanho(n2)){return 1;}
    if (tamanho(n1) < tamanho(n2)){return 0;}
    if (igual(n1, n2) == 1){return 2;} // Foge da Lógica
    else{
       
        while((auxiliarN1 != NULL) && (auxiliarN2 != NULL)){
            
            if (auxiliarN1->numero > auxiliarN2->numero) {return 1;}
            if (auxiliarN1->numero < auxiliarN2->numero) {return 0;}

            if (auxiliarN1 != NULL) {auxiliarN1 = auxiliarN1->anterior;}            
            if (auxiliarN2 != NULL) {auxiliarN2 = auxiliarN2->anterior;}
        }
    }        
    return 0;
}

//////////////////Função Big
// Finalidade: verifica se o numero 1 é maior em valor
// que o numero 2.
// Retorno: existem dois retornos: 0 (se n1 < n2) e 1 
// (se n1 > n2)
int big(numero *n1, numero *n2){
    int retorno = 0;
    // Confere se é possível verificar a relação de maioridade pelo sinal
    if ((n1->sinal == 'p') && (n2->sinal == 'n')){return 1;}
    else if ((n1->sinal == 'n') && (n2->sinal == 'p')){return 0;}
    
    // Caso impossível, considera o sinal.
    else if ((n1->sinal == 'n') && (n2->sinal == 'n')){
        retorno = bigSemSinal(n1, n2);
        if (retorno == 0) {return 1;}
        if (retorno == 1) {return 0;}
        if (retorno == 2) {return 0;}
    }
    else if ((n1->sinal == 'p') && (n2->sinal == 'p')){
        retorno = bigSemSinal(n1, n2);
        if (retorno == 0) {return 0;}
        if (retorno == 1) {return 1;}
        if (retorno == 2) {return 0;}
    }

    return 0;
}

//////////////////Função Small
// Finalidade: verifica se o número 1 é menor em
// valor que o número 2.
// Retorno: existem dois retornos: 0 (se n1 < n2) e 1 
// (se n1 > n2)
int small(numero *n1, numero *n2){
    int retorno = 0;

    // Confere se é possível verificar a relação de menoridade pelo sinal
    if ((n1->sinal == 'p') && (n2->sinal == 'n')){return 0;}
    else if ((n1->sinal == 'n') && (n2->sinal == 'p')){return 1;}
    
    // Caso impossível, considera o sinal.    
    else if ((n1->sinal == 'n') && (n2->sinal == 'n')){
        retorno = bigSemSinal(n1, n2);
        if (retorno == 0) {return 0;}
        if (retorno == 1) {return 1;}
        if (retorno == 2) {return 0;}
    }
    else if ((n1->sinal == 'p') && (n2->sinal == 'p')){
        retorno = bigSemSinal(n1, n2);
        if (retorno == 0) {return 1;}
        if (retorno == 1) {return 0;}
        if (retorno == 2) {return 0;}
    }    
    return 0;
}

//////////////////Função Igual
// Finalidade: verifica se os números são iguais (considerando),
// inclusive, se possuem o mesmo sinal.
// Retorno: existem dois retornos: 0 (se n1 != n2) e 1 
// (se n1 = n2)
int igual(numero *n1, numero *n2){
    no *auxiliarN1 = n1->inicio;
    no *auxiliarN2 = n2->inicio;
    int diferentes = 0;

    //Confere se os sinais são diferentes ou iguais
    if (n1->sinal != n2->sinal){
        return 0;
    }

    //Confere todos os algarismos.
    while(diferentes == 0){
        if ((auxiliarN1 == NULL) && (auxiliarN2 == NULL)){break;}

        //Caso algum numero seja maior que o outro, o a e o b estarão preenchidos.
        int a = 15, b = 14; // Os numeros de teste possuem um algarismo apenas.
        if (auxiliarN1 != NULL){a = auxiliarN1->numero;}
        if (auxiliarN2 != NULL){b = auxiliarN2->numero;}

        //Teste se o "a" e o "b" são diferentes
        if (a != b) {diferentes += 1;}

        //Passa para o próximo algarismo ou permanece em NULL
        if (auxiliarN1 != NULL){auxiliarN1 = auxiliarN1->proximo;}
        if (auxiliarN2 != NULL){auxiliarN2 = auxiliarN2->proximo;}
    }
    
    if (diferentes == 0){       
        return 1;
    }
    return 0;
}

//////////////////Função Soma
// Finalidade: a função soma realiza a soma de dois
// números grandes e escreve o resultado em r. Isto é,
// realiza a soma: r = n1 + n2.
// Observação: a função completa foi dividida em:
//    -somaMesmoSinal: soma numeros de mesmo sinal.
//    -somaSinalDiferente: subtrai o número com menos
//      algarismos daquele de mais algarismos.
//    -soma: função principal que recebe a soma ou a
//      subtração e avalia o sinal.
// Retorno: a função principal não tem retorno, pois
// imprime o resultado. As outras duas funções retornam
// 0 para sinal positivo e 1 para sinal negativo. O resul-
// tado é transferido por referência.
int somaMesmoSinal(numero *n1, numero *n2, numero *r){
    int a = 0, b = 0;
    no *auxiliarN1 = n1->inicio;
    no *auxiliarN2 = n2->inicio;

    while(a+b == 0){
        if (auxiliarN1 != NULL){a = auxiliarN1->numero;}
        if (auxiliarN2 != NULL){b = auxiliarN2->numero;}
        if ((a+b+(r->vaiUm)) >= 10){
            inserir(r, (a+b+(r->vaiUm))-10);
            r->vaiUm = 1;
        }
        else {
            inserir(r, (a+b+(r->vaiUm)));
            r->vaiUm = 0;
        }
        if (auxiliarN1 != NULL){auxiliarN1 = auxiliarN1->proximo;}
        if (auxiliarN2 != NULL){auxiliarN2 = auxiliarN2->proximo;}
            
        if ((auxiliarN1 == NULL) && (auxiliarN2 == NULL)){break;}
        a = 0; 
        b = 0;
    }

    if (r->vaiUm == 1){inserir(r, 1);}

    if (n1->sinal == 'n') {return 1;}
    return 0;
}

int somaSinalDiferente(numero *n1, numero *n2, numero *r){
       
    no *auxiliarN1 = NULL;
    no *auxiliarN2 = NULL;
    int sinal = 0;
       
    if (tamanho(n1)>tamanho(n2)){
        auxiliarN1 = n1->inicio;
        auxiliarN2 = n2->inicio;
        if (n1->sinal == 'p'){sinal = 0;}
        else {sinal = 1;}
    }
    else if (tamanho(n1)<tamanho(n2)){
        auxiliarN1 = n2->inicio;
        auxiliarN2 = n1->inicio;
        if (n2->sinal == 'p'){sinal = 0;}
        else {sinal = 1;}
    }
    else if (igual(n1, n2) == 1){
        inserir(r, 0);
        return 0;
    }

    int a = 0, b = 0;
    while(a-b == 0){
        if (auxiliarN1 != NULL){a = auxiliarN1->numero;}
        if (auxiliarN2 != NULL){b = auxiliarN2->numero;}
        
            if (a-(b+(r->vaiUm)) >= 0){
                inserir(r, (a-(b+(r->vaiUm))));
                r->vaiUm = 0;
            }
            else {
                inserir(r, ((a+10)-(b+(r->vaiUm))));
                r->vaiUm = 1;
            }
            if (auxiliarN1 != NULL){auxiliarN1 = auxiliarN1->proximo;}
            if (auxiliarN2 != NULL){auxiliarN2 = auxiliarN2->proximo;}
                    
            if ((auxiliarN1 == NULL) && (auxiliarN2 == NULL)){break;}
            a = 0; 
            b = 0;
        }

    return sinal;
}

void soma(numero *n1, numero *n2, numero *r){
    int sinal = 0;
    if ((n1 != NULL) && (n2 != NULL) && (r != NULL)){
        if (n1->sinal == n2->sinal) {sinal = somaMesmoSinal(n1, n2, r);}
        if (n1->sinal != n2->sinal) {sinal = somaSinalDiferente(n1, n2, r);}
        if (sinal == 1){printf("-");}
        removerZerosInversa(r);
        imprimir(r);
    }
}