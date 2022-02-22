/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*            Árvores Binárias - Soma de Nós Filhos            *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_arvore node;
typedef struct dados_arvore arvore;

struct node_arvore{
    int i; // Informação armazenada
    int p; // Prioridade armazenada
    int nivel;
    node *e, *d; // Ponteiros à esquerda e à direita.
};

struct dados_arvore{
    node *r; // Ponteiros que aponta para o node raiz.
};


void inicializa_vetor(char vetor[], int tamanho){
    for(int contador= 0; contador < tamanho; contador++)
        vetor[contador] = ' ';
}

void verificarBarraRN(){
    char ch = ' ';
    ch = getchar();
    //printf("%d\n", ch);
    if (ch != '\r'){ungetc(ch, stdin);}
    ch = getchar();
    //printf("%d\n", ch);
    if (ch != '\n'){ungetc(ch, stdin);}
}

arvore *criar_arvore(arvore *a){
    a = (arvore*)malloc(sizeof(arvore));
    a->r = NULL;
    return a;
}

node *criar_node(int elemento, int prioridade){
    node *n = (node*)malloc(sizeof(node));
    n->i = elemento;
    n->p = prioridade;
    n->nivel = 0;
    n->e = NULL;
    n->d = NULL;
    return n;
}

void desalocar_nodes(node *node){
    if (node == NULL){return;}
    else{
        desalocar_nodes(node->d);
        desalocar_nodes(node->e);
    }
    free(node);
}

void destruir_arvore(arvore *a){
    desalocar_nodes(a->r);
    free(a);
}


void desalocar_nodes_lista(node *node){
    if (node == NULL){return;}
    else{desalocar_nodes_lista(node->d);}
    free(node);
}

void destruir_lista(arvore *a){
    desalocar_nodes_lista(a->r);
    free(a);
}

void impressao_preordem(node *node){    
    if (node == NULL) return;
    printf("(%d, %d)", node->i, node->p);
    impressao_preordem(node->e);
    impressao_preordem(node->d);
}

void impressao_emordem(node *node){    
    if (node == NULL) return;    
    impressao_emordem(node->e);
    printf("(%d, %d)", node->i, node->p);
    impressao_emordem(node->d);
}

void impressao_posordem(node *node){
    if (node == NULL) return;    
    impressao_posordem(node->e);
    impressao_posordem(node->d);
    printf("(%d, %d)", node->i, node->p);
}

void impressao_largura_lista(node *raiz){
    if (raiz == NULL) return;
    printf("(%d, %d)", raiz->i, raiz->p);
    impressao_largura_lista(raiz->d);
}

void impressao_largura_criar_lista(node *raiz, arvore *l, int* nivel){
    *nivel += 1;
    //printf("IMPRESSÃO LARGURA. Nivel: %d\n", *nivel);

    if (raiz == NULL) {
        *nivel -= 1;
        return;
    }

    impressao_largura_criar_lista(raiz->e, l, nivel);
    impressao_largura_criar_lista(raiz->d, l, nivel);

    node *p = criar_node(raiz->i, raiz->p);
    p->nivel = *nivel;

    node *auxiliar, *anterior;
    anterior = NULL;
    auxiliar = l->r;

    while (auxiliar != NULL && p->nivel >= auxiliar->nivel){
        anterior = auxiliar;
        auxiliar = auxiliar->d;
    }

    //Lista vazia ou lista com elementos
    if (anterior == NULL){
        p->d = l->r;
        if (l->r != NULL) l->r->e = p;
        l->r = p;
        //printf("PRIMEIRO ELEMENTO: info: %d prio: %d nivel: %d\n", l->r->i, l->r->p, l->r->nivel);
    }
    else{
        p->d = anterior->d;
        anterior->d = p;
        
        if (p->d != NULL) p->d->e = p;
        p->e = anterior;
    }
    
    *nivel -= 1;
}

node *rotacao_esquerda(node *desbalanceado){
    node *auxiliar = desbalanceado->d;
    desbalanceado->d = auxiliar->e;
    auxiliar->e = desbalanceado;
    return auxiliar;
}

node *rotacao_direita(node *desbalanceado){
    node *auxiliar = desbalanceado->e;
    desbalanceado->e = auxiliar->d;
    auxiliar->d = desbalanceado;
    return auxiliar;
}

node *inserir_elemento(node *r, int elemento, int prioridade){
    //if (r == NULL) printf("NULL\n");
    //else printf("Elemento: %d. Prioridade: %d. Elemento para Inserir: %d. Prioridade: %d\n", r->i, r->p, elemento, prioridade);
    //printf("IMPRESSAO EM ORDEM: ");
    //impressao_emordem(r);
    //printf("\n");

    if (r == NULL){
        r = criar_node(elemento, prioridade);
        //printf("ELEMENTO INSERIDO: %d. Prioridade: %d.\n\n", r->i, r->p);
    }
    else{
        if (elemento < r->i){
            //printf("Entrou à direita.\n");
            r->e = inserir_elemento(r->e, elemento, prioridade);
            if (r->p < r->e->p){r = rotacao_direita(r);}
        }
        else if (elemento > r->i){
            //printf("Entrou à esquerda. Inserir: %d. Prioridade: %d\n", elemento, prioridade);
            r->d = inserir_elemento(r->d, elemento, prioridade);
            if (r->p < r->d->p){r = rotacao_esquerda(r);}
        }
        else{ // (Elemento = r->i)
            printf("Elemento ja existente\n");
        }
    }
    //printf("SAINDO. Atual: %d Prioridade: %d. Flag: %d\n", r->i, r->p);
    return r;
}

int remover_elemento(node *r, int elemento){
    
    /* se a chave não for encontrada deve-se imprimir: Chave nao localizada */
    
    return 1;    
}


int buscar_elemento(node *r, int buscado){
    printf("BUSCANDO ELEMENTO: %d!!\n", buscado);
    if (r == NULL){
        return 0;
    }
    else{
        if (buscado == r->i){
            return 1;
        }
        else if(buscado < r->i){
            return buscar_elemento(r->e, buscado);
        }
        else if(buscado > r->i){
            return buscar_elemento(r->d, buscado);    
        }
    }
    return 1;
}







void entrada_insercao(arvore *a){
    //printf("Entrou na INSERCAO!!\n");
    int elemento = 0, prioridade = 0;
    scanf(" %d %d", &elemento, &prioridade);
    //printf("Numero a ser inserido: %d. Prioridade: %d.\n", elemento, prioridade);
    a-> r = inserir_elemento(a->r, elemento, prioridade);
    verificarBarraRN();
}

void entrada_remocao(arvore *a){
    printf("Entrou na REMOCAO!!\n");
    int elemento = 0;
    scanf(" %d", &elemento);
    //printf("Numero a ser removido: %d.\n", elemento);
    remover_elemento(a->r, elemento);
    verificarBarraRN();
}

void entrada_buscar(arvore *a){
    //printf("Entrou na BUSCA!!\n");
    int buscado = 0;
    
    scanf(" %d ", &buscado);
    printf("%d\n", buscar_elemento(a->r, buscado));
    verificarBarraRN();
}

void entrada_impressao(arvore *a){
    //printf("Entrou na IMPRESSAO!!\n");

    int saida = 0;
    char tipoImpressao[20];
    inicializa_vetor(tipoImpressao, 20);

    getchar();// Despreza Espaço
    saida = scanf("%20[^,\r,\n,' ']s", tipoImpressao);
    verificarBarraRN();
        
    if (saida == EOF){return;}
    //else if(a->r == NULL){printf("VAZIA\n");}
    else if(strcmp(tipoImpressao, "preordem") == 0) {
        printf("IMPRESSAO PRE-ORDEM: ");
        impressao_preordem(a->r);
        printf("\n");
    }
    else if(strcmp(tipoImpressao, "ordem") == 0) {
        printf("IMPRESSAO EM-ORDEM: ");
        impressao_emordem(a->r);   
        printf("\n");
    }
    else if(strcmp(tipoImpressao, "posordem") == 0) {
        printf("IMPRESSAO POS-ORDEM: ");
        impressao_posordem(a->r);
        printf("\n");
    }
    else if(strcmp(tipoImpressao, "largura") == 0) {
        printf("IMPRESSAO LARGURA: ");
        arvore *lista = NULL;
        lista = criar_arvore(lista);
        int nivel = 0;
        impressao_largura_criar_lista(a->r, lista, &nivel);
        impressao_largura_lista(lista->r);
        destruir_lista(lista);
        printf("\n");
    }
    else{
        printf("IMPRESSAO NÃO PREVISTA: %s\n", tipoImpressao);
    }
}

arvore *processamento_entrada(arvore *a){
    int saida = 0;
    char comando[20];
    inicializa_vetor(comando, 20);
    
    do{
        saida = scanf("%20[^,\r,\n,' ']s", comando);
        if (saida == EOF){break;}
        else if(strcmp(comando, "insercao") == 0)  {entrada_insercao(a);}
        else if(strcmp(comando, "remocao") == 0)   {entrada_remocao(a);}
        else if(strcmp(comando, "buscar") == 0)    {entrada_buscar(a);}
        else if(strcmp(comando, "impressao") == 0) {entrada_impressao(a);}        
    }while(saida != EOF);

    return a;
}

int main(){

    int quantidadeEntradas = 0;
    arvore *dados = NULL;
    
    dados = criar_arvore(dados);

    scanf("%d", &quantidadeEntradas);
    //printf("Quantidade de entradas: %d\n", quantidadeEntradas);
    verificarBarraRN();

    for(int contador = 0; contador < quantidadeEntradas; contador++){
        dados = processamento_entrada(dados);
    }
    destruir_arvore(dados);

    return 0;
}