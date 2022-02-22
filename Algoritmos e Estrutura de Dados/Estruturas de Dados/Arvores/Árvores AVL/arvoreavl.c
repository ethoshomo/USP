#include <stdio.h>
#include <stdlib.h>
#include "arvoreavl.h"

/*
ÁRVORE BINÁRIA DE BUSCA NÃO APRESENTA ELEMENTOS REPETIDOS.
ALGUMAS IMPLEMENTAÇÕES INSEREM UMA VARIÁVEL NA STRUCT PARA
MOSTRAR QUANTAS VEZES UM MESMO ELEMENTO FOI INSERIDO.

OS MAIORES ELEMENTOS ESTÃO SEMPRE À DIREITA E OS MENORES
ESTÃO SEMPRE À ESQUERDA. NOS EXTREMOS, TEREMOS O MAIOR E
MENOR DOS ELEMENTOS.
*/

struct no_t {
    no *esquerda, *direita;
    int fatorbalanceamento;
    elem informacao;
};

arvore *criarArvore(){
    arvore *a = (arvore*)malloc(sizeof(arvore));
    a->raiz = NULL;
    return a;
}

int estaVazia(arvore *a){
    if (a->raiz == NULL) {return 1;}
    return 0;
}

// Consiste na busca de um nó folha e sua desalocação, retornando 
// logo em seguida para o nó anterior de forma recursiva.
void podarArvore(no *raiz){
    if (raiz != NULL){
        podarArvore(raiz->esquerda);
        podarArvore(raiz->direita);
        free(raiz);
    }
}

void imprimir(no *raiz){
    if (raiz != NULL){
        printf("%d(", raiz->informacao);
        imprimir(raiz->esquerda);
        printf(",");
        imprimir(raiz->direita);
        printf(")");
    }
    else {
        printf("NULL");
    }

}

int alturaArvore(no *raiz){
    if (raiz == NULL) {return 0;}

    int alturaEsquerda = 1 + alturaArvore(raiz->esquerda);
    int alturaDireita = 1 + alturaArvore(raiz->direita);

    if (alturaEsquerda > alturaDireita) {return alturaEsquerda;}
    else {return alturaDireita;}
}

// A busca consiste na comparação da chave com o elemento raiz.
// Pode ocorrer 4 casos distintos:
// a) árvore vazia: raiz = NULL
// b) chave == elemento raiz: a chave está na raiz.
// c) chave < elemento: ou seja, a chave está à esquerda da raiz.
// d) chave > elemento: ou seja, a chave está à direita da raiz.
no *busca(no *raiz, elem procurado){
    if (raiz == NULL) {return NULL;}
    else if (raiz->informacao == procurado){return raiz;}
    else if (procurado < raiz->informacao){return busca(raiz->esquerda, procurado);}
    return busca(raiz->direita, procurado);
}



// ROTACOES DE ÁRVORE:
// As rotações de árvore são interessantes, porém complexas.
// A ideia é balancear a árvore, sempre que algum elemento atinge fator
// de balanceamento 2 ou -2. fatorBalanceamento = nosEsquerda - nosDireita 
// (olhando os ramos mais longos).
//
// Quando o nó desbalanceado e seu filho (do mesmo lado da inserção) tiverem 
// o mesmo sinal (ou positivo, ou negativo), faz-se rotações simples (EE OU DD).
// Essa rotação significa descer um nivel o nó desbalanceado e subir seu filho. 
// Se para a esquerda, o nó filho à esquerda sobe. Caso contrário, à direita.
// Eventual elemento que sobrar será inserido no ponteiro de rompimento vazio.
//
// Mas, se apresentarem fatores de balanceamento com sinais contrários, precisa
// analisar para ver se a rotação será ED (esquerda direita) ou DE (direita esquerda).
// Isto é, se o pai desbalanceado tem sinal diferente de seu filho, rotaciona-se o 
// filho de acordo com  fator de balanceamento: se for positivo, a arvores à esquerda está
// maior, logo precisa rotacionar à direita; por outro lado, se for negativo, significa
// que a árvore a direita está maior e, por isso, precisa rotacionar à esquerda. Essas 
// rotações são as simples. Logo em seguida, rotaciona o pai, de acordo com o seu fator
// de balanceamento. O processo é o mesmo de seu filho. Mas, como tem sinal diferente,
// vai rotacionar para o lado diferente.
//
no *rotacao_EE(no *desbalanceado){
    no *auxiliar = desbalanceado->direita;
    desbalanceado->direita = auxiliar->esquerda;
    auxiliar->esquerda = desbalanceado;
    return auxiliar;
}

no *rotacao_DD(no *desbalanceado){
    no *auxiliar = desbalanceado->esquerda;
    desbalanceado->esquerda = auxiliar->direita;
    auxiliar->direita = desbalanceado;
    return auxiliar;
}

no *rotacao_ED(no *desbalanceado){
    desbalanceado->esquerda = rotacao_EE(desbalanceado->esquerda);
    desbalanceado = rotacao_DD(desbalanceado);
    return desbalanceado;
}

no *rotacao_DE(no *desbalanceado){
    desbalanceado->direita = rotacao_DD(desbalanceado->direita);
    desbalanceado = rotacao_EE(desbalanceado);
    return desbalanceado;
}

no *insere_avl (no *raiz, elem x, int *flag){
    if (raiz == NULL){
        raiz = (no*)malloc(sizeof(no));
        raiz->informacao = x;
        raiz->esquerda = NULL;
        raiz->direita = NULL;
        raiz->fatorbalanceamento = 0;
    }
    else{
        if (x < raiz->informacao){
            raiz->esquerda = insere_avl(raiz->esquerda, x, flag);
            if (*flag == 1){
                switch(raiz->fatorbalanceamento){
                    // Nesse caso, já existia elemento à direita. 
                    // FATOR = subesquerda - subdireita = -1.
                    case -1: 
                        raiz->fatorbalanceamento = 0;
                        *flag = 0;
                        break;

                    // Nesse caso, a árvore aumentou um nível.
                    // Ou seja, precisa avaliar os antecessores.
                    // FATOR = subesquerda - subdireita = 0.
                    case 0:
                        raiz->fatorbalanceamento = 1;
                        *flag = 1;
                        break;
                    
                    // Nesse caso, haverá o desbalanceamento.
                    case 1:
                        if (raiz->esquerda->fatorbalanceamento == 1){
                            raiz = rotacao_DD(raiz);
                            raiz->direita->fatorbalanceamento = 0;
                            raiz->fatorbalanceamento = 0;
                        }
                        else{
                            raiz = rotacao_ED(raiz);
                            if (raiz->fatorbalanceamento == -1){
                                raiz->esquerda->fatorbalanceamento = 1;
                                raiz->direita->fatorbalanceamento = 0;
                                raiz->fatorbalanceamento = 0;   
                            }
                            else if (raiz->fatorbalanceamento == 1){
                                raiz->esquerda->fatorbalanceamento = 0;
                                raiz->direita->fatorbalanceamento = -1;
                                raiz->fatorbalanceamento = 0;   
                            }
                            else {//raiz->fatorbalanceamento == 0
                                raiz->direita->fatorbalanceamento = 0;
                                raiz->esquerda->fatorbalanceamento = 0;
                                raiz->fatorbalanceamento = 0;
                            }
                        }
                        *flag = 0;
                        break;
                    default:
                        break;
                }
            }
        }
        else if (x > raiz->informacao){
            raiz->direita = insere_avl(raiz->direita, x, flag);
        }
        else{
            printf("Elemento existente.\n");
        }
    }
    return raiz;
}

void inserir(arvore *a, elem x){
    int flag = 0;
    a->raiz = insere_avl(a->raiz, x, &flag);
}

// a) Antes de começar a remoção é necessário verificar se não há elementos
//    ou chave não existe (afinal, o processo é recursivo).
// b) Remoção Nó Folha: libera memória e seta para NULL
// c) Remoção de Nó Pai com um Filho: arruma ponteiros e libera memória.
// d) Remoção de Nó Pai com dois Filhos: é a situação mais complexa, pois
//    dependerá da escolha da subárvore (não remove propriamente):
//      - Esquerda: precisa buscar a maior chave. (OPÇÃO ABAIXO)
//      - Direita: precisa buscar a menor chave.
//      Observação: a info da raiz é maior ou menor que as infos das subarvores.
//    Em seguida, copia os dados da maior chave no lugar daquele que se
//    deseja remover. Remoção recursiva do elemento copiado?
int remover(no **raiz, elem x){

    return 0;
}

// Antes do Percurso: verifica se a árvore é vazia.
// Percurso: visita o nó raiz primeiro e depois as subárvores da esquerda
// e da direita (nessa ordem).
void preOrdem(no *raiz){
    if (raiz != NULL){
        printf("%d", raiz->informacao);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

// Percurso: visita a subárvore da esquerda primeiro, depois nó raiz e a
// subárvore da direita (nessa ordem).
void emOrdem(no *raiz){
    if (raiz != NULL){
        emOrdem(raiz->esquerda);
        printf("%d", raiz->informacao);
        emOrdem(raiz->direita);
    }
}

// Percurso: visita a subárvore da esquerda primeiro, depois subárvore da
// direita e, por fim, o nó raiz (nessa ordem).
void posOrdem(no *raiz){
    if (raiz != NULL){
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d", raiz->informacao);
    }
}
