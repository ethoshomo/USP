/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*    Trabalho 3 - Simulador de Escalonamento de Processos     *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>

///////////////////////////////BLOCO DAS DEFINIÇÕES
typedef struct lista_t lista;
typedef struct no_t no;

///////////////////////////////BLOCO DAS STRUCTS
struct no_t{
    int c;
    int te;
    int tr;
    int p;
    no *anterior, *proximo;
};

struct lista_t{
    int tamanho;
    int nivelPrioridade;
    no *inicio, *processador, *fim;    
};

///////////////////////////////DECLARAÇÃO DAS FUNÇÕES
lista *criar_encadeada();
void liberar_encadeada(lista *l);
int inserir_encadeada(lista *l, int c, int tr, int te, int p);
int buscar_encadeada(lista *l, int elemento);
int remover_encadeada(lista *l, lista *e, int elemento);
void imprimir_impressao(lista *l);

void cicloRoundRobin(lista *d, lista *e, lista *i, int *controle);
void processa_entrada(lista *d, lista *e, int controle);
int inserir_escalonador(lista *e, int codigo, int tr, int te, int prioridade);
void gravar_arquivo(lista *i);

///////////////////////////////FUNÇÃO MAIN
int main(){

    //Declara variáveis e cria listas todas inicializadas.
    lista *escalonador = NULL, *entradas = NULL, *impressao = NULL;
    int codigo = 0, tempoReconhecimento = 0, tempoExecucao = 0, prioridade = 0, controle = 0, quantum = 1;
    entradas = criar_encadeada();
    escalonador = criar_encadeada();
    impressao = criar_encadeada();

    // Coleta dos dados de entrada
    while (controle != EOF){
        controle = scanf("%d %d %d %d", &codigo, &tempoReconhecimento, &tempoExecucao, &prioridade);
        if (controle == EOF){break;}
        inserir_escalonador(entradas, codigo, tempoReconhecimento, tempoExecucao, prioridade);
    }

    //Realiza o Ciclo Round Robin, grava em Arquivo e Imprime Resultado
    cicloRoundRobin(entradas, escalonador, impressao, &quantum);
    gravar_arquivo(impressao);
    imprimir_impressao(impressao);
    
    // Bloco de Desalocação de Memória
    liberar_encadeada(impressao);
    liberar_encadeada(entradas);
    liberar_encadeada(escalonador);
    
    return 0;
}
///////////////////////////////CRIAR LISTA ENCADEADA
// Finalidade: aloca memória e inicializa lista encadeada.
// Retorno: retorna o endereço de memória da lista.
// Observações: não há.
lista *criar_encadeada(){
    lista *p;
    p = (lista*)malloc(sizeof(lista));
    p->tamanho = 0;
    p->nivelPrioridade = 0;
    p->inicio = NULL;
    p->processador = NULL;
    p->fim = NULL;
    return p;
}

///////////////////////////////LIBERAR LISTA ENCADEADA
// Finalidade: desalocar memória alocada pela funções criar
// lista e inserir elementos.
// Retorno: não há.
// Observações: não há.
void liberar_encadeada(lista *l){
    if (l != NULL){
        no *auxiliar = l->inicio;
        while (auxiliar != NULL){
            l->inicio = l->inicio->proximo;
            free(auxiliar);
            auxiliar = l-> inicio;
        }
        free (l);
    }
}

///////////////////////////////INSERIR EM LISTA ENCADEADA
// Finalidade: adicionar elementos em uma lista encadeada. 
// Retorno: retorna 1 para sucesso e 0 para fracasso.
// Observações: o primeiro elemento será o último da lista.
// essa função é usada apenas para criar a lista de impressão.
int inserir_encadeada(lista *l, int codigo, int tr, int te, int prioridade){
    if (l == NULL){
        printf("Erro no acesso a lista de prioridades.");
        return 0;
    }
    else{
        no *p = (no*)malloc(sizeof(no));
        p->c = codigo;
        p->te = te;
        p->tr = tr;
        p->p = prioridade;
        p->proximo = NULL;
        p->anterior = NULL;

        // Verifica se é o primeiro elemento
        if ((l->inicio == NULL)&&(l->fim == NULL)){
            l->inicio = p;
            l->fim = p;
            l->tamanho += 1;
        }
        // Caso não seja, adiciona na lista.
        else{ 
            no *auxiliar = l->inicio;
            auxiliar->anterior = p;
            p->proximo = l->inicio;
            l->inicio = p;
            l->tamanho += 1;
        }
    }
    return 1;
}

///////////////////////////////BUSCA DE ELEMENTO NA LISTA
// Finalidade: busca elemento em uma lista encadeada.
// Retorno: retorna a quantidade de vezes que foi encontrado.
// Observações: não há.
int buscar_encadeada(lista *l, int elemento){
    no *auxiliar = l->fim;
    int retorno = 0;
    while(auxiliar != NULL){
        if (auxiliar->c == elemento) retorno += 1;
        auxiliar = auxiliar->anterior;
    }
    return retorno;
}

///////////////////////////////FUNÇÃO REMOVER ELEMENTO DA LISTA
// Finalidade: remover elementos de uma lista encadeada
// Retorno: retorna 1 para sucesso e 0 para fracasso.
// Observações: foi necessário receber duas listas porque existem
// momentos no codigo em que a remoção de elementos de uma lista
// interfere na prioridade de execução de outra.
int remover_encadeada(lista *l, lista *e, int elemento){
    if (l == NULL){
        printf("Erro na abertura da lista.");
        return 0;
    }
    no *auxiliar = l->inicio;
    if (auxiliar != NULL){
        if (auxiliar->c == elemento){
            //Remove o único elemento da lista
            if ((auxiliar->proximo == NULL)&&(auxiliar->anterior == NULL)){
                l->inicio = NULL;
                l->fim = NULL;
                e->nivelPrioridade = 0;
                free(auxiliar);
                return 1;
            }
            //Remove o primeiro elemento da lista
            else{
                auxiliar->proximo->anterior = NULL;
                l->inicio = auxiliar->proximo;
                e->nivelPrioridade = e->inicio->p;
                free(auxiliar);
                return 1;
            }
        }

        //Percorre a lista para remover elementos da lista
        auxiliar = auxiliar->proximo;
        if (auxiliar != NULL){
            // Enquanto percorre, verifica se é elemento intermediário
            // ou se é elemento do final da lista.
            while(auxiliar != NULL){
                if (auxiliar->c == elemento){
                    if ((auxiliar->anterior != NULL)&&(auxiliar->proximo == NULL)){
                        auxiliar->anterior->proximo = NULL;
                        l->fim = auxiliar->anterior;
                        e->nivelPrioridade = e->inicio->p;
                        free(auxiliar);
                        return 1;
                    }
                    else {
                        auxiliar->anterior->proximo = auxiliar->proximo;
                        auxiliar->proximo->anterior = auxiliar->anterior;
                        e->nivelPrioridade = e->inicio->p;
                        free(auxiliar);
                        return 1;
                    }
                }
                auxiliar = auxiliar->proximo;
            }            
        }
        printf("Não há elementos a serem removidos.");}
    else{printf("Impossível remover elementos de lista inexistente.");}    
    return 0;
}

///////////////////////////////IMPRIMIR IMPRESSÃO
// Finalidade: imprimir a lista encadeada impressão.
// Retorno: não há.
// Observações: não há.
void imprimir_impressao(lista *l){
    no *auxiliar = l->fim;
    while(auxiliar != NULL){
        printf("%d %d\n", auxiliar->c, auxiliar->te);
        auxiliar = auxiliar->anterior;
    }
}

///////////////////////////////FUNÇÃO CICLO DE ROUND ROBIN
// Finalidade: realiza um ciclo de Round Robin.
// Retorno: não há diretamente, porém retorna, por referência,
// a lista de impressão que será gravada em um arquivo.
// Observações: 
void cicloRoundRobin(lista *d, lista *e, lista *i, int *controle){
    no *verificaRI = NULL; // Verifica Remoção/Insercao
    do{
        //Processa dados e diminui o tempo de execução em um quantum.
        processa_entrada(d, e, *controle);
        e->processador->te -= 1;
        verificaRI = e->processador;

        //Adaptação para tornar a lista circular.
        e->processador = e->processador->proximo;
        if (e->processador == NULL){e->processador = e->inicio;}

        //Insere elemento na lista de impressão e remove do escalonador
        if (verificaRI->te == 0){            
            inserir_encadeada(i, verificaRI->c, 0, *controle, 0);
            remover_encadeada(e, e, verificaRI->c);
            e->tamanho -= 1;
        } 
        *controle += 1;
    }while(e->tamanho != 0);
}

///////////////////////////////FUNCÃO PROCESSAMENTO DA ENTRADA
// Finalidade: percorre toda lista de dados e processa dados.
// Primeiro reconhece o tempo de inserção, e, conforme faz a leitura,
// inclui os dados ordenados na lista do escalonador. Caso um elemento
// prioritário seja adicionado, seta o ponteiro de processamento para
// o inicio da lista do escalonador, de modo a começar novo ciclo.
// Retorno: não há.
// Observações: não há.
void processa_entrada (lista *d, lista *e, int controle){
    if ((d == NULL) || (e == NULL)){
        printf("Erro na abertura das listas.");
        return;
    }
    else{
        no *auxiliar = d->inicio;
        no *a = auxiliar; //Ponteiro Anterior

        while (auxiliar != NULL){
            a = auxiliar;
            auxiliar = auxiliar->proximo;
            if (a->tr == controle){
                if (a->p > e->nivelPrioridade){
                    inserir_escalonador(e, a->c, a->tr, a->te, a->p);
                    e->processador = e->inicio;
                    e->nivelPrioridade = e->processador->p;
                }
                else{
                    inserir_escalonador(e, a->c, a->tr, a->te, a->p);
                }
            }
        }
    }
}

///////////////////////////////INSERIR EM ORDEM ESCALONADA
// Finalidade: adiciona elementos em uma lista encadeada.
// Retorno: retorna 1 para sucesso e 0 para fracasso.
// Observações: a função verifica se existe elemento repetido (caso sim,
// aumenta em uma unidade seu código), bem como insere ordenado (primeiro 
// prioridade, 4 (maior) e 1(menor); depois código, quando menor o código, 
// maior prioridade tem).
int inserir_escalonador(lista *e, int codigo, int tr, int te, int prioridade){
    no *p = (no*)malloc(sizeof(no));
    p->c = codigo;
    p->tr = tr;
    p->te = te;
    p->p = prioridade;
    p->proximo = NULL;
    p->anterior = NULL;

    //Elemento repetido
    if (buscar_encadeada(e, p->c)>=1){p->c+=1;}

    no *auxiliar = e->inicio;
    no *anterior = NULL;

    if ((auxiliar == NULL) && (anterior == NULL)){
        e->inicio = p;
        e->fim = p;
        e->tamanho += 1;
        e->nivelPrioridade = p->p;
        return 1;
    }
    
    while ((auxiliar != NULL) && ((p->p < auxiliar->p) || ((p->p == auxiliar->p)&&(p->c > auxiliar->c)))){
        anterior = auxiliar;
        auxiliar = auxiliar->proximo;
    }

    //Caso de elemento existente
    if (auxiliar != NULL && ((p->c == auxiliar->c)&&(p->p == auxiliar->p))){
        printf("ELEMENTO REPETIDO");
        free(p);
        return 0;
    }

    //Lista vazia ou lista com elementos
    if (anterior == NULL){
        p->proximo = e->inicio;
        if (e->inicio != NULL) e->inicio->anterior = p;
        e->inicio = p;
        e->tamanho += 1;
        if (p->p > e->nivelPrioridade){e->nivelPrioridade = p->p;}
    }
    else{
        p->proximo = anterior->proximo;
        anterior->proximo = p;        
        if (p->proximo != NULL) p->proximo->anterior = p;
        else e->fim = p;
        p->anterior = anterior;
        e->tamanho += 1;
        if (p->p > e->nivelPrioridade){e->nivelPrioridade = p->p;}
    }    
    return 1;
}

///////////////////////////////FUNÇÃO GRAVAR ARQUIVO
// Finalidade: gravar em um arquivo o conteudo da impressão.
// Retorno: fora o arquivo "saida.out", não há.
// Observações: não há.
void gravar_arquivo(lista *i){
    FILE *cursor = fopen("saida.out", "w");
    if (cursor != NULL){

        no *auxiliar = i->fim;
        while(auxiliar != NULL){
            fprintf(cursor, "%d %d\n", auxiliar->c, auxiliar->te);
            auxiliar = auxiliar->anterior;
        }
    }
    else{
        printf("Erro na gravação de arquivos.");
        exit(1);
    }
    fclose(cursor);
}
