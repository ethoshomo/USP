#include <stdio.h>
#include <stdlib.h>
#include "balanceada.h"

//////////////////////////////////// Função PUSH
// Finalidade: adicionar elementos na pilha e demarcar seu topo.
// Retorno: não há. Valores retornam por referência.
void push(char pilha[], int *tamanho, char caracter, char *topo){
    pilha[*tamanho] = caracter;
    *topo = pilha[*tamanho];
    *tamanho += 1;
}

//////////////////////////////////// Função POP
// Finalidade: remover elementos da pilha e atualizar seu topo.
// Retorno: não há. Valores retornam por referência.
void pop(char pilha[], int *tamanho, char *topo){
    *tamanho -= 1;
    if (*tamanho == 0){*topo = ' ';}
    else if (*tamanho >0){*topo = pilha[*tamanho-1];}
}

//////////////////////////////////// Função Leitura da Pilha
// Finalidade: faz a leitura dos elementos da pilha. Conforme
// vai recebendo os valores, verifica se devem ser inseridos na
// pilha. A exceção é as aspas (que não há lógica para saber se
// sua aparição é para abrir ou fechar a lógica) Elas foram
// contabilizadas e, se estão em duplas, abrem e fecham, mas, se
// não é verificada as duplas, elas não estão balanceadas.
// Retorno: retorna 0 (sinaliza novos laços na main) ou EOF (sai
// laço na main).
int leituraPilha(){
    
    char pilha[400];
    char topoPilha = ' ';
    
    int tamanho = 0, saida = 0, aspas = 0;
    char caracter = ' ';

    while(saida != EOF){

        saida = scanf("%c", &caracter);
        if (saida == EOF) {break;}
        if (caracter == '\r') {getchar(); break;} // getchar para \r\n
        if (caracter == '"') {aspas++;} // contabiliza aspas
        
        if (((caracter == '{') || (caracter == '}') || // Seleciona elementos que podem
            (caracter == '[') || (caracter == ']') ||  // ser colocados na pilha
            (caracter == '(') || (caracter == ')')) &&
            ((caracter != ' ') || (caracter != '"'))){     
                           
            if (((caracter == '}') && (topoPilha == '{')) || // Casos de POP
                ((caracter == ']') && (topoPilha == '[')) ||
                ((caracter == ')') && (topoPilha == '('))) {
                pop(pilha, &tamanho, &topoPilha);
            }
            else if (((caracter == '}') && (topoPilha != '{')) || // Casos desbalanceados
                     ((caracter == ']') && (topoPilha != '[')) ||
                     ((caracter == ')') && (topoPilha != '('))){
                printf("NÃO BALANCEADO");
                do{ // Se a sequência não está balanceada, descarta todos os demais elementos
                    saida = scanf("%c", &caracter); // que aparecem depois.
                    if (saida == EOF){break;}
                }while(caracter != '\n');

                if (saida == EOF) {return EOF;}
                else {return 0;}
            }
            else{push(pilha, &tamanho, caracter, &topoPilha);} // Casos de PUSH
        }
    }

    if (aspas%2 == 0){printf("BALANCEADO");}
    else {printf("NÃO BALANCEADO");}

    if (saida == EOF) {return EOF;}
    else {return 0;}
}