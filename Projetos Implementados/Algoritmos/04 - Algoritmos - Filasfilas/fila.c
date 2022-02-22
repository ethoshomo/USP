/////////////////////////// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

////////////////////////// STRUCTS
struct pessoa_t{
    char *nome;
    int idade, saude;
};

struct fila_t{
    int inicio, fim, total;
    pessoa *posicaoFila;
};

////////////////////////// Função Criar Fila
// A função cria uma Fila HEAP (alocação dinâmica).
// Contém ponteiro que indica o inicio, o fim e o total da fila.
// Além disso, cria um vetor com 100 espaços, cada qual
// guardando informações de uma pessoal: nome, idade e
// condicao de saúde. Retorna a fila totalmente inicializada.
fila* criarFila(fila* f){
    f = (fila*)malloc(sizeof(fila));
    if (f != NULL) {
        f->inicio = 0;
        f->fim = 0;
        f->total = 0;
        f->posicaoFila = (pessoa*)malloc(tamanhoFila*sizeof(pessoa));
        
        for (int i = 0; i < tamanhoFila; i++){
            f->posicaoFila[i].nome = (char*)malloc(sizeof(char));
            f->posicaoFila[i].nome[0] = '\0';
            f->posicaoFila[i].idade = 0;
            f->posicaoFila[i].saude = -1;
        }
    }
    else{printf("Erro. Vetor NULL.");}
    return f;
}

////////////////////////// Função Destrói Fila
// Desaloca todos os espaços alocados na criação da fila.
// O retorno é vazio.
void destruirFila(fila *f){
    if (f != NULL) {
        for(int i = 0; i < tamanhoFila; i++)
                free(f->posicaoFila[i].nome);

        free(f->posicaoFila);        
        free(f);
    }
}

////////////////////////// Função de Classificação de Prioridade
// A função é responsável por classificar pessoas que serão
// inseridas na fila. A prioridade é determinada pela idade
// e pelo da condição de saúde demonstrar comorbidade.
// O retorno simboliza a prioridade para inserção na fila,
// sendo que, quanto maior o retorno, mais adiante será inserido.
int classificacao(int idade, int saude){
    if ((idade >= 60) && (saude == 1)) {return 4;}
    else if ((idade < 60) && (saude == 1)) {return 3;}
    else if ((idade >= 60) && (saude == 0)) {return 2;}
    else{return 1;}
    return -1; // Erro
}

////////////////////////// Função de Troca de Posição
// Na análise de prioridade, com consequente ordenação, é necessário
// trocar posições da fila. Portanto, tem finalidade acessória.
void trocaPosicao (fila* f, int posicaoA, int posicaoB){
    pessoa temporario;
    temporario = f->posicaoFila[posicaoA];
    f->posicaoFila[posicaoA] = f->posicaoFila[posicaoB];
    f->posicaoFila[posicaoB] = temporario;
}

////////////////////////// Função que Ordena a Fila
// A pessoa que chega é inserida no último lugar. Porém, existe uma ordem
// de prioridade de atendimento que segue uma classificação. Por isso,
// Depois de classificadas duas posições, se o ultimo tiver prioridade,
// trocará de lugar com o penultimo e assim sucessivamente até chegar na
// posição onde irá permanecer. Não há retorno.
void ordenaFila(fila* f){
    int classificacaoA = 0; int classificacaoB = 0;

    for (int i = f->fim-1; i>= f->inicio + 1; i--){
        classificacaoA = classificacao(f->posicaoFila[i-1].idade, f->posicaoFila[i-1].saude);
        classificacaoB = classificacao(f->posicaoFila[i].idade, f->posicaoFila[i].saude);
         
         if (classificacaoA < classificacaoB){
             trocaPosicao(f, i-1, i);
         }
    }
}

////////////////////////// Função Resolve Linha
// É a função responsável por fazer a leitura da linha e extrair
// informações numéricas e textuais que serão usadas no programa.
// Por isso, é uma função um pouco mais extensa, que, inclusive,
// Provoca indiretamente a inserção, a classificação e a ordenação 
// da fila. Não apresenta retorno.
void resolveLinha(fila *f){
    char *auxiliar;
    char comando[50];
    int acao = 0; 
    
    scanf("%[^\r,\n,0-9]s", comando);
    if (0 == strcmp(comando, "SAI")){
        getchar(); // dispensa o \r
        getchar(); // dispensa o \n
        acao = 2;
    }
    else{
        scanf(" %d", &f->posicaoFila[f->fim].idade);
        scanf(" %d", &f->posicaoFila[f->fim].saude);
        getchar(); // dispensa o \r
        getchar(); // dispensa o \n   

        auxiliar = strtok(comando, " ");
        if (0 == strcmp(auxiliar, "ENTRA")) {acao = 1;}

        auxiliar = strtok(NULL, " ");
        f->posicaoFila[f->fim].nome = (char*)realloc(f->posicaoFila[f->fim].nome, (strlen(auxiliar)+1)*sizeof(char));
        strcpy (f->posicaoFila[f->fim].nome, auxiliar);
    }
        
    switch(acao){   
        case 1: // INCREMENTA FILA (FINAL DA FINAL)
            if (f->total == 99) {printf("FILA CHEIA\n");}
            else{
                f->fim += 1;
                f->total += 1;
                ordenaFila(f);
            }
            break;

        case 2: // DECREMENTA FILA (INICIO DA FILA)
            if (f->total <= 0){
                printf("FILA VAZIA\n");
            }
            else{
                printf("%s ", f->posicaoFila[f->inicio].nome);
                printf("%d ", f->posicaoFila[f->inicio].idade);
                printf("%d\n", f->posicaoFila[f->inicio].saude);
                f->inicio += 1;
                f->total -= 1;
            }
            break;

        default:
            printf("Opcao invalida.");
            break;
    }
}