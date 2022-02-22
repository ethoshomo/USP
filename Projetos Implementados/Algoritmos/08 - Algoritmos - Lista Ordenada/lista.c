#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

///////////////////////////// STRUCTS
// Criam a estrutura de uma lista duplamente encadeada
// que contém cadastros como nó. Cada nó, por sua vez,
// possui as informações de nome e código armazenadas.
struct cadastro_t{
    char nome[51];
    int codigo;
    cadastro *anterior, *proximo;
};

struct lista_t{
    cadastro *inicio, *fim;
    int quantidadeCadastros;
};

///////////////////////////// Função Criar Lista
// Finalidade: cria uma lista de cadastros. Dispõe de dois
// ponteiros (inicio e fim) e uma variável para controlar
// a quantidade de cadastros constante na lista.
// Retorno: retorna o endereço de uma lista criada dinamicamente.
listaCadastro *criarLista(){
    listaCadastro *l;
    l = (listaCadastro*)malloc(sizeof(listaCadastro));
    l->inicio = NULL;
    l->fim = NULL;
    l->quantidadeCadastros = 0;
    return l;
}

///////////////////////////// Função Liberar Lista
// Finalidade: cada cadastro, assim como a própria lista
// são alocados dinamicamente. Por isso, ao final do
// programa, é necessário desalocar a memória ocupada.
// Retorno: não há.
void liberarLista(listaCadastro *l){
    if (l != NULL){
        cadastro *auxiliar = l->inicio;
        while (auxiliar != NULL){
            l->inicio = l->inicio->proximo;
            free(auxiliar);
            auxiliar = l-> inicio;
        }
        free (l);
    }
}

///////////////////////////// Função Verificar Cadastro
// Finalidade: verifica se um código já foi ou não inserido no
// na lista de cadastros.
// Retorno: existem dois retornos: caso encontre o código na 
// lista, retorna 1; caso contrário, retorna 0. 
int verificarCadastro(listaCadastro *l, int codigo){
    if (l == NULL){printf("Erro na verificacao de cadastro."); exit(1);}

    cadastro *termoAux = NULL;
    termoAux = l->inicio;
    while (termoAux != NULL){
        if (termoAux->codigo == codigo) {
            return 1;
        }
        termoAux = termoAux->proximo;
    }
    return 0;
}

///////////////////////////// Função Inserir 
// Finalidade: insere um novo cadastro na lista encadeada.
// Primeiro verifica se o codigo está em uso por outra entrada.
// Depois, percorre a lista até na posição ordenada e insere
// o elemento de acordo com o tamanho da lista.
// Retorno: retorna 1 para sucesso e 0 para fracasso.
int inserir(listaCadastro *l, int codigo, char nome[]){
    if (l == NULL){printf("Erro ao inserir cadastro."); exit(1);}
    cadastro *p = (cadastro*)malloc(sizeof(cadastro));
    for(int i = 0; i< 51; i++)
        p->nome[i] = ' ';

    p->codigo = codigo;
    strcpy(p->nome, nome);
    p->proximo = NULL;
    p->anterior = NULL;

    cadastro *auxiliar, *anterior;
    anterior = NULL;
    auxiliar = l->inicio;

    //Caso de existência de cadastro
    if (verificarCadastro(l, codigo) == 1){
        free(p);
        printf("INVALIDO\n");
        return 0;
    }

    // Percorre até a posição ordenada
    while ((auxiliar != NULL) && (codigo > auxiliar->codigo)){
        anterior = auxiliar;
        auxiliar = auxiliar->proximo;
    }

    //Lista vazia ou lista com elementos
    if (anterior == NULL){
        p->proximo = l->inicio;
        if (l->inicio != NULL) {l->inicio->anterior = p;}
        l->inicio = p;
        l->quantidadeCadastros += 1;
    }
    else{
        p->proximo = anterior->proximo;
        anterior->proximo = p;
        
        if (p->proximo != NULL) {p->proximo->anterior = p;}
        else {l->fim = p;}
        p->anterior = anterior;
        l->quantidadeCadastros += 1;
    }

    return 1;
}

///////////////////////////// Função Remover
// Finalidade: realiza a remoção de cadastros da lista.
// Primeiro verifica se a lista está vazia; depois, verifica
// se o código existe; por fim, se não for nenhum desses casos,
// remove o cadastro da lista.
// Retorno: retorna 0 para fracasso e 1 para sucesso da remoção.
int remover(listaCadastro *l, int codigo){
    if (l == NULL){printf("Erro na remocao de cadastro."); exit(1);}

    cadastro *p = l->inicio;
    cadastro *anterior = NULL;

    if (l->quantidadeCadastros == 0){
        printf("INVALIDO\n"); 
        return 0;
    }
    else if (verificarCadastro(l, codigo) == 0){
        printf("INVALIDO\n"); 
        return 0;
    }
    else{
        while ((p != NULL) && (codigo > p->codigo)){
            anterior = p;
            p = p->proximo;
        }

        //Remoção do primeiro elemento
        if (anterior == NULL){
            l->inicio = l->inicio->proximo;
            if (l->inicio != NULL) {l->inicio->anterior = NULL;}
            else {l->fim = NULL;}
            l->quantidadeCadastros -= 1;
            free(p);
        }
        //Remove elemento no meio ou no fim
        else{
            if (p->proximo == NULL){ //remover do fim da lista
                l->fim = p->anterior;
                anterior->proximo = NULL;
                l->quantidadeCadastros -= 1;
                free(p);
            }
            else { // remover do meio da lista
                anterior->proximo = p->proximo;
                p->proximo->anterior = anterior;
                l->quantidadeCadastros -= 1;
                free(p);
            }
        }
    }//Fecha o else

    return 1;
}

///////////////////////////// Função  Imprimir
// Finalidade: imprime a lista de cadastros.
// Retorno: não há.
void imprimir(listaCadastro *l){
    // FAZER O TRATAMENTO DE NULL
    
    if(l->quantidadeCadastros == 0) {
        printf("VAZIA\n"); 
        return;
    }

    cadastro *p = l->inicio;
    while (p != NULL){
        printf("%d, %s; ", p->codigo, p->nome);
        p= p->proximo;
    }
    printf("\n");
}

///////////////////////////// Função Resolve Linha
// Finalidade: realiza a coleta das informações de entrada
// e dá tratamento às informações coletadas.
// Retorno: o retorno dessa função é vital para a main,
// pois ela está inserida em um loop. De modo que, se
// retornar 1, sairá do loop; mas, se retornar 0, o laço
// continuará indefinidamente.
int resolveLinha(listaCadastro *l){
    char auxiliar[100];
    int codigo = 0, saida = 0;
    char ch = ' ';
        
    saida = scanf("%[^,' ',\r,\n]s", auxiliar);
    if (saida == EOF){return 1;}

    if (0 == strcmp(auxiliar, "IMPRIMIR")){
        ch = getchar(); // dispensa o \r
        if (ch != '\r'){ungetc(ch, stdin);}
        ch = getchar(); // dispensa o \n
        if (ch != '\n'){ungetc(ch, stdin);}
        imprimir(l);
    }
    else if (0 == strcmp(auxiliar, "REMOVE")){
        scanf(" %d", &codigo);
        ch = getchar(); // dispensa o \r
        if (ch != '\r'){ungetc(ch, stdin);}
        ch = getchar(); // dispensa o \n
        if (ch != '\n'){ungetc(ch, stdin);}
        remover(l, codigo);
    }
    else if (0 == strcmp(auxiliar, "INSERE")){
        scanf(" %d", &codigo);
        scanf(" %[^,\r,\n]s", auxiliar);
        ch = getchar(); // dispensa o \r
        if (ch != '\r'){ungetc(ch, stdin);}
        ch = getchar(); // dispensa o \n
        if (ch != '\n'){ungetc(ch, stdin);}
        inserir(l, codigo, auxiliar);
    }
    else{
        printf("INVALIDO\n");
        return 0;
    }

    return 0;     
}