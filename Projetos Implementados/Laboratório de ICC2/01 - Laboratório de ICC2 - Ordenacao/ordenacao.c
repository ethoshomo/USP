#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

//////////////////////////// STRUCTS DO PROGRAMA
struct conchas_nt {
    double diametro;
    char *cor, *textura;
};

struct listas_conchas {
    int qConchas;
    itens *conchas;
};

//////////////////////////// FUNÇÃO SHELLSORT
// Finalidade: promover a ordenação da lista de conchas
// com base no tamanho de diâmetro.
// Retorno: não há.
void shellSort(lista *l, int n) {
  // Divide o conjunto de conchas em trechos virtuais (pela metade) até que o intervalo seja igual a 1.
  for (int intervalo = n / 2; intervalo > 0; intervalo /= 2) {     
    for (int i = intervalo; i < n; i++) {
        itens temporario = l->conchas[i]; //
        int j;
        for (j = i; j >= intervalo && l->conchas[j-intervalo].diametro > (temporario.diametro); j -= intervalo){
            l->conchas[j] = l->conchas[j-intervalo];
        }
        l->conchas[j] = temporario;
        }
    }
}

//////////////////////////// FUNÇÃO CRIAR LISTA
// Finalidade: criar uma lista de conchas de acordo com quantidade
// fornecida pelos usuário (recebida por parâmetro). Além disso,
// a função inicializa todas as variáveis da estrutura.
// Retorno: retorna para a main() a lista criada.
lista *criarLista(lista *l, int quantidadeConchas){
    if (quantidadeConchas < 1){
        printf("E impossivel criar uma lista com a quantidade de conchas indicada.");
        return l;
    }
    l = (lista*)malloc(sizeof(lista));
    
    l->qConchas = 0; // Esse valor sempre aponta para o próximo valor livre
    l->conchas = (itens*)malloc(quantidadeConchas*sizeof(itens));
    
    for(int contador = 0; contador < quantidadeConchas; contador++){
        l->conchas[contador].cor = NULL;
        l->conchas[contador].textura = NULL;
        l->conchas[contador].diametro = 0;
    }
    return l;
}

//////////////////////////// FUNÇÃO DESTRUIR LISTA
// Finalidade: desaloca todos os ponteiros que possuem memória dinâmica
// alocada (cores, texturas e structs).
// Retorno: não há.
void destruirLista(lista *l){
    if (l == NULL){printf("Erro na destruicao da lista."); return;}

    for(int contador = 0; contador < l->qConchas; contador++){
        if (l->conchas[contador].cor != NULL){free(l->conchas[contador].cor);}
        if (l->conchas[contador].textura != NULL){free(l->conchas[contador].textura);}
    }

    if (l->conchas != NULL){free(l->conchas);}
    if (l != NULL) {free(l);}
}

//////////////////////////// FUNÇÃO PREENCHER STRING
// Finalidade: preenche as strings exigidas pelo programa (tais como
// os nomes de cores e de texturas), sendo certo que aloca memória
// para cumprir com seus propósitos.
// Retorno: retorna para a função readline() a string preenchida.
char* preencherStrings(){
      char *string = NULL;
      int tamanho = 0;
      char caracter = '%';

      while(caracter){
          string = (char*)realloc(string, (tamanho+1)*sizeof(char));
          caracter = getchar();
          string[tamanho] = caracter;
          tamanho += 1;
          if ((caracter == '\n') || (caracter == ' ')) {break;}
      }
      string[tamanho-1] = '\0';
      return string;
}

//////////////////////////// FUNÇÃO READLINE
// Finalidade: faz a leitura da linha de entrada, coletando
// o diâmetro, a cor e a textura. Esses dados são armazenados
// na struct lista, que, por sua vez, tem uma lista de itens.
// Retorno: retorna a lista que foi enviada.
lista* readline(lista *l, int indice){
    scanf("%lf", &l->conchas[indice].diametro);
    getchar(); //Dispensa o espaço
    l->conchas[indice].cor = preencherStrings();
    l->conchas[indice].textura = preencherStrings();
    l->qConchas += 1;
    return l;
}

//////////////////////////// FUNÇÃO IMPRIMIR
// Finalidade: imprime todas as structs conchas que estão
// armazenadas na lista de conchas.
// Retorno: não há.
void imprimir(lista *l, int quantidadeLinhas){
    for(int contador = 0; contador < quantidadeLinhas; contador++){
        printf("%.3lf ", l->conchas[contador].diametro);
        printf("%s ", l->conchas[contador].cor);
        printf("%s\n", l->conchas[contador].textura);
    }
}