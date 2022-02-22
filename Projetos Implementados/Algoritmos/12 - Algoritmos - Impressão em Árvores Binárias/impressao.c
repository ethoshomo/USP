
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "impressao.h"

struct node_arvore{
    int info;
    arvore *e, *d;
};

/////////////////////////////// Função Inicializa Vetor
// Inicializa valores no vetor para evitar erros de memória.
// Retorno: Não há.
void inicializa_vetor(char vetor[], int tamanho){
    for(int contador= 0; contador < tamanho; contador++)
        vetor[contador] = ' ';
}

/////////////////////////////// Função Verificar Barra RN
// Faz o tratamento do \r \n depois da leitura do scanf
// Retorno: Não há.
void verificarBarraRN(){
    char ch = ' ';
    ch = getchar();
    if (ch != '\r'){ungetc(ch, stdin);}
    ch = getchar();
    if (ch != '\n'){ungetc(ch, stdin);}
}

/////////////////////////////// Função Menu Inserção
// É responsável por inserir um elemento na árvore. Se for o primeiro (a == NULL),
// cria o primeiro elemento. Caso contrário, chama a função de inserir elemento.
// Retorno: retorna o endereço de memória da árvore criada.
arvore *menu_insercao(arvore *a){
    int numero = 0;

    scanf(" %d", &numero);
    verificarBarraRN();
    
    if (a == NULL){a = criar_arvore(numero);}
    else{inserir_arvore(a, numero);}
    
    return a;
}

/////////////////////////////// Função Criar Node de Árvore
// É responsável por receber um elemento (como parâmetro) e
// alocar memória de um node da árvore para o armazenar.
// Retorno: retorna o endereço de memória do node criado.
arvore *criar_arvore(int elemento){
    arvore *p = (arvore*)malloc(sizeof(arvore));
    p->info = elemento;
    p->e = NULL;
    p->d = NULL;
    return p;
}

/////////////////////////////// Função Inserção em Arvore Binária
// É responsável por inserir um elemento na árvore. Para efetuar a inserção,
// a função promove uma busca recursiva pelo elemento atrás do ponteiro NULL. 
// Assim que o encontra, cria uma folha com o elemento para o adicionar.
// Retorno: não há retorno.
// Observações: As arvores binárias de buscas possuem em relação à raiz os
// elementos menores à esquerda e os maiores à direita.
void inserir_arvore(arvore *a, int elemento){

    if (elemento > a->info){
        if (a->d == NULL){
            a->d = criar_arvore(elemento);
            return;
        }
        else{inserir_arvore(a->d, elemento);}
    }

    if (elemento < a->info){
        if (a->e == NULL){
            a->e = criar_arvore(elemento);
            return;
        }
        else{inserir_arvore(a->e, elemento);}
    }
}

/////////////////////////////// Função Menu Impressão
// É responsável por organizar as formas de impressão na árvore. Suporta as
// seguintes opções: em-ordem, pré-ordem e pós-ordem.
// Retorno: caso a arvore seja inexistente (NULL), imprime vazia.
void menu_impressao(arvore *a){
    int saida = 0;
    char tipoImpressao[20];
    inicializa_vetor(tipoImpressao, 20);

    getchar();// Despreza Espaço
    saida = scanf("%20[^,\r,\n,' ']s", tipoImpressao);
    verificarBarraRN();
        
    if (saida == EOF){return;}
    else if(a == NULL){printf("VAZIA\n");}
    else if(strcmp(tipoImpressao, "pre-ordem") == 0) {
        impressao_preordem(a);
        printf("\n");
    }
    else if(strcmp(tipoImpressao, "em-ordem") == 0) {
        impressao_emordem(a);
        printf("\n");
    }
    else if(strcmp(tipoImpressao, "pos-ordem") == 0) {
        impressao_posordem(a);
        printf("\n");
    }
}

/////////////////////////////// Função Impressão em Pre-Ordem
// Imprime a árvore em pre-ordem.
// Retorno: exceto as impressões, não há.
// Observação: a ordem pré-ordem significa imprimir a raiz, o ponteiro
// à esquerda e o ponteiro à direita. O resultado recursivo é a pré-ordem.
void impressao_preordem(arvore *a){    
    if (a == NULL) return;
    printf("%d ", a->info);
    impressao_preordem(a->e);
    impressao_preordem(a->d);
}

/////////////////////////////// Função Impressão em Em-Ordem
// Imprime a árvore em em-ordem.
// Retorno: exceto as impressões, não há.
// Em ordem: a sequência em-ordem significa percorrer a arvore
// primeiro pelo ponteiro à esquerda e depois raiz e ponteiro à direita.
// Recursivamente, o resultado é Em-Ordem.
void impressao_emordem(arvore *a){    
    if (a == NULL) return;    
    impressao_emordem(a->e);
    printf("%d ", a->info);
    impressao_emordem(a->d);
}

/////////////////////////////// Função Impressão em Pos-Ordem
// Imprime a árvore em pos-ordem.
// Retorno: exceto as impressões, não há.
// Pós-Ordem: imprime o ponteiro à esquerda e depois o à direita. 
// Ao final, a raiz. Recursivamente, o resultado é Pos-Ordem.
void impressao_posordem(arvore *a){
    if (a == NULL) return;    
    impressao_posordem(a->e);
    impressao_posordem(a->d);
    printf("%d ", a->info);
}

////////////////////////////// Função Destruir Árvore
// Finalidade: realizar a desalocação dos nodes da árvore.
// Retorno: não há.
void destruirArvore(arvore *a){
    if (a == NULL){return;}
    else{
        destruirArvore(a->d);
        destruirArvore(a->e);
    }
    free(a);
}