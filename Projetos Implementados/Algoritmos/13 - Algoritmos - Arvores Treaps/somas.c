#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "somas.h"

////////////////////////////// Função Criar Árvore
// Finalidade: adicionar um node de arvore na árvore.
// Retorno: retorna endereço de memória com o node criado.
arvore *criar_arvore(int id, int info, int id_e, int id_d){
    arvore *nova = (arvore*)malloc(sizeof(arvore));
    nova->id = id;
    nova->info = info;
    nova->id_e = id_e;
    nova->id_d = id_d;
    nova->e = NULL;
    nova->d = NULL;
    return nova;
}

////////////////////////////// Função Criar Lista de Dados
// Finalidade: cria uma lista para armazenar os dados de entrada.
// Retorno: retorna o endereço de memória da lista.
dados *criar_lista_dados(){
    dados *nova = (dados*)malloc(sizeof(dados));
    nova->erro = 0;
    nova->inicio = NULL;
    nova->fim = NULL;
    return nova;
}

////////////////////////////// Função Inserir Lista de Dados
// Finalidade: inserir dados de entrada na lista de Dados.
// Retorno: 1 para sucesso e 0 para fracasso.
int inserir_lista_dados(dados *lista, int id, int info, int id_e, int id_d){
    if (lista == NULL){
        printf("Erro na abertura da lista de dados.");
        return 0;
    }
    arvore *nova = (arvore*)malloc(sizeof(arvore));
    nova->id = id;
    nova->info = info;
    nova->id_e = id_e;
    nova->id_d = id_d;
    nova->e = NULL;
    nova->d = NULL;

    arvore *auxiliar = lista->inicio, *anterior = NULL;

    if (auxiliar == NULL){
        lista->inicio = nova;
        return 1;
    }
    else{
        if (auxiliar->d == NULL){
            auxiliar->d = nova;
            return 1;
        }
        while (auxiliar != NULL){
            anterior = auxiliar;
            auxiliar = auxiliar->d;            
        }
        anterior->d = nova;
    }
    return 1;
}

////////////////////////////// Função Buscar Lista de Dados
// Finalidade: buscar node que possui o id procurado.
// Retorno: retorna o endereço de memória do node.
arvore *buscar_lista_dados(dados *lista, int id){
    arvore *anterior = NULL, *auxiliar = lista->inicio;

    while(auxiliar != NULL){
        anterior = auxiliar;
        if (auxiliar->id == id) {return anterior;}
        auxiliar = auxiliar->d;
    }

    return NULL;
}

////////////////////////////// Função Destruir Listas e Dados
// Finalidade: realiza a desalocação de memória que foi usada no programa.
// Retorno: não há.
void destruir_lista_dados(dados *lista, arvore *dados){
    if (lista == NULL){
        printf("Erro na abertura da lista.");
        return;
    }

    arvore *auxiliar = lista->inicio;
    arvore *anterior = NULL;

    while(auxiliar != NULL){
        anterior = auxiliar;
        auxiliar = auxiliar->d;
        free(anterior);
    }

    destruirArvore(dados);
    free(lista);
}

////////////////////////////// Função Montar Árvore
// Finalidade: criar uma estrutura em forma de árvore binária.
// Retorno: retorna o endereço do node zero.
// Observação: a montagem é de acordo com os dados de entrada.
arvore *montar_arvore(dados *lista, int id){
    arvore *auxiliar = buscar_lista_dados(lista, id);
    arvore *node = (arvore*)malloc(sizeof(arvore));
    if(auxiliar != NULL){
        node->id = auxiliar->id;
        node->info = auxiliar->info;
        node->id_d = auxiliar->id_d;
        node->id_e = auxiliar->id_e;
        node->d = NULL;
        node->e = NULL;
   
        if (node->id_e != -1) node->e = montar_arvore(lista, node->id_e);
        if (node->id_d != -1) node->d = montar_arvore(lista, node->id_d);

        if(soma_pais_filhos(node, node->e, node->d) != 0){lista->erro = 1;}
        return node;
    }
    return NULL;
}

////////////////////////////// Função Soma Pais e Filhos
// Finalidade: soma os dados do nó pai e soma o inverso da soma dos filhos.
// Retorno: retorna o valor da soma.
// Observação: na função de montagem da árvore, caso o valor seja diferente
// de zero, o fato será registrado para posterior impressão dos dados de saída.
int soma_pais_filhos(arvore* node, arvore *esquerda, arvore *direita){

    int resultado = 0;
    
    if ((esquerda == NULL)&&(direita == NULL)){
        return resultado;
    }
    else if ((esquerda == NULL)&&(direita != NULL)){
        resultado = ((node->info) - (direita->info));
        return resultado;
    }
    else if ((esquerda != NULL)&&(direita == NULL)){
        resultado = ((node->info) - (esquerda->info));
        return resultado;    
    }
    
    resultado = ((node->info) - (esquerda->info) - (direita->info));
    return resultado;
}

////////////////////////////// Função Verifica VF Somas
// Finalidade: verificar se alguma soma deu resultado diferente de 0.
// Retorno: não há.
void verifica_vf_somas(int erro){
    if (erro == 1){printf("FALSO");}
    else {printf("VERDADEIRO");}
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
