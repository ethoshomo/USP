#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "dicionario.h" 

#define NIVEL_MAXIMO 15
#define FRACAO_REFERENCIA 0.5

struct item_t {
    char verbete[51];
    char definicao[141];
    item **proximo;
};

struct slista_t {
    int nivelMaximo; // Numero máximo de níveis da skiplist
    float fracaoItem; // Fração usada como referência no sorteio
    int novoNivel; // Usado no sorteio de novo nivel
    int nivel; // Nivel atual
    item *inicio; // Ponteiro para a posição "QLEFT"
};


/////////////////////////////// Função Verificar Barra RN
// Finalidade: fazer o tratamento do \r \n depois da leitura
// de uma linha pela função Resolve Linha.
// Retorno: Não há.
void verificarBarraRN(){
    char ch = ' ';
    ch = getchar();
    if (ch != '\r'){ungetc(ch, stdin);}
    ch = getchar();
    if (ch != '\n'){ungetc(ch, stdin);}
}

/////////////////////////////// Função Resolve Linha
// Finalidade: faz a leitura da linha de entrada para coletar o
// comando, o verbete e a sua definição. No caso da impressao,
// coleta os caracteres do começo da palavra que deverá ser 
// impressa. 
// Retorno: o retorno está relacionado principalmente com o fim
// do laço de repetição na main, de modo que, se a saida for 1,
// significa que foi encontrado o EOF. Caso contrário, o laço
// permanecerá em loop indefinido.
int resolverLinha(skiplist *d, char verbete[], char definicao[]){
    int saida = 0;
    char auxiliar[51];

    saida = scanf("%50[^,\r,\n,' ']s", auxiliar);

    if (saida == EOF){return 1;}
    else if(strcmp(auxiliar, "insercao") == 0) {
        saida = scanf(" %50[^,' ',\r,\n]s", verbete);
        saida = scanf(" %140[^,\r,\n]s", definicao);
        inserirSkiplist(d, verbete, definicao);
        verificarBarraRN();
    }
    else if(strcmp(auxiliar, "alteracao") == 0) {
        saida = scanf(" %50[^,' ',\r,\n]s", verbete); 
        saida = scanf(" %140[^,\r,\n]s", definicao);
        alterarSkiplist(d, verbete, definicao);
        verificarBarraRN();

    }
    else if(strcmp(auxiliar, "remocao") == 0) {
        saida = scanf(" %50[^,\r,\n]s", verbete);
        removerSkiplist(d, verbete);
        verificarBarraRN();
    }
    else if(strcmp(auxiliar, "busca") == 0) {   
        saida = scanf(" %50[^,\r,\n]s", auxiliar);
        buscarSkiplist(d, auxiliar);
        verificarBarraRN();
    }
    else if(strcmp(auxiliar, "impressao") == 0) {
        saida = scanf(" %50[^,\r,\n]s", auxiliar);
        imprimirSkiplist(d, auxiliar, strlen(auxiliar));
        verificarBarraRN();
    }
    else{
        printf("OPERACAO INVALIDA\n");
        return 0;
    }
    return 0;
}

/////////////////////////////// Função Inicializa Vetor
// Finalidade: inicializar todas as variáveis de um vetor.
// Retorno: não há.
void inicializaVetor(char vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++)
        vetor[i] = ' ';
}

/////////////////////////////// Função Sorteia Nivel
// Finalidade: realizar sorteio completamente aleatorio do
// nivel que o verbete irá ocupa na sua inserção.
// Retorno: retorna o nivel calculado.
int sorteiaNivel(skiplist *d){
    float randomico = (float)rand()/RAND_MAX;
    int nivel = 0;
    
    while((randomico < d->fracaoItem) && (nivel < d->nivelMaximo)){
        nivel++;
        randomico = (float) rand()/RAND_MAX;
    }

    return nivel;
}

/////////////////////////////// Função Criar Skiplist
// Finalidade: é usada para criar uma skiplist, mais especificamente
// seu ponto inicial "QLEFT". É por meio dele que todas as variáveis 
// são acessadas no sistema de busca. Além disso, inicializa todas
// as suas variáveis com valores base.
// Retorno: retorna a skiplist criada.
skiplist* criarSkiplist(skiplist *d){
    char verbete[51], definicao[141];
    inicializaVetor(verbete, 51);
    inicializaVetor(definicao, 141);

    d = (skiplist*)malloc(sizeof(skiplist));
    if (d != NULL){
        d->nivelMaximo = NIVEL_MAXIMO;
        d->fracaoItem = FRACAO_REFERENCIA;
        d->nivel = 0;
        d->novoNivel = 0;
        d->inicio = (item*)malloc(sizeof(item));
        strcpy(d->inicio->verbete, "QLEFT");
        strcpy(d->inicio->definicao, "Ponto inicial da Skiplist");
        d->inicio->proximo = (item**)malloc((d->nivelMaximo + 1)*sizeof(item*));
        for (int i = 0; i <= d->nivelMaximo; i++) {
            d->inicio->proximo[i] = NULL;
        }
    }   
    return d;
}

/////////////////////////////// Função Destruir Skiplist
// Finalidade: desalocar memoria alocada. A destruição da skiplist 
// resume-se basicamente em percorrer toda a lista encadeada (posicao 
// 0, que possui todas os itens). Desse modo, iremos desalocar todos 
// os itens, um a um. Por fim, iremos desalocar o cabeçalho.
// Retorno: não há.
void destruirSkiplist(skiplist *d){
    if (d == NULL){return;}

    item *itemPassado = NULL, *atual = NULL;
    
    if (d->inicio->proximo[0] != NULL){
        atual = d->inicio->proximo[0];

        while (atual != NULL){
            itemPassado = atual;
            atual = atual->proximo[0];
            free(itemPassado->proximo);
            free(itemPassado);
        }
    }
    free(d->inicio);
    free(d);
}

/////////////////////////////// Função Inserir Skiplist
// Finalidade: inserir itens. A ideia da função é buscar
// a posição de inserção em todos os niveis da skiplist e armazenar
// dados em um array temporário. Será alocada memória para o novo 
// elemento bem como será sorteado quantos niveis ele terá. 
// Caso tenha mais níveis que o atual ocupado, há atualização do array 
// temporário. Em seguida, a função faz a inserção do novo item usando 
// os dados do auxiliar (como se fosse lista encadeada).
// Observações: há tratamento de erro quando tenta inserir verbete 
// que já existe na lista.
// Retorno: retorna 0 para fracasso e 1 para sucesso.
int inserirSkiplist(skiplist *d, char verbete[], char definicao[]){
    if (d == NULL){return 0;}
    int i;

    item *atual = d->inicio; // Ponteiro sentinela usado para percorrer a lista
    
    item **auxiliar = NULL;
    auxiliar = (item**)malloc((d->nivelMaximo +1)*sizeof(item*));
    for (i = 0; i <= d->nivelMaximo; i++)
        auxiliar[i] = NULL;

    for (i = d->nivel; i >= 0; i--){
        while((atual->proximo[i] != NULL) && (strcmp(atual->proximo[i]->verbete, verbete) < 0))
            atual = atual->proximo[i];
        auxiliar[i] = atual;
    }
  
    atual = atual->proximo[0];

    if ((atual != NULL) && (strcmp(atual->verbete, verbete) == 0)){
        printf("OPERACAO INVALIDA\n");
        return 0;
    }
    else{

        item *novo = NULL;
        novo = (item*)malloc(sizeof(item));
        if (novo == NULL){
            free(auxiliar);
            free(novo);
            return 0;
        }
        strcpy(novo->verbete, verbete);
        strcpy(novo->definicao, definicao);
        novo->proximo = (item**)malloc((d->nivelMaximo+1)*sizeof(item*));
        for(int k = 0; k < d->nivelMaximo; k++)
            novo->proximo[k] = NULL;

        //Sorteia nivel maixmo que o item será inserido.        
        d->novoNivel = sorteiaNivel(d);

        //Se o nivel sorteado for maior que o nivel atual
        //é necessário atualizar os novos niveis do auxiliar.
        if (d->novoNivel > d->nivel){
            for(i = d->nivel + 1; i <= d->novoNivel; i++)
                auxiliar[i] = d->inicio;
            d->nivel = d->novoNivel;
        }

        //Insere o novo item nas novas posições em niveis
        for(i = 0; i <= d->novoNivel; i++){
            novo->proximo[i] = auxiliar[i]->proximo[i];
            auxiliar[i]->proximo[i] = novo;
        } 
        free(auxiliar);
    }

    return 1;
}

/////////////////////////////// Função Alterar Skiplist
// Finalidade: tem a finalidade de alterar a definição de um verbete
// anteriormente inserido no dicionário. Seu funcionamento está baseado
// na busca da palavra e confirmacao de sua existência, tal qual a 
// função de inserir novo item na skiplist.
// Observações: No caso de tentar alterar palavra que não existe, será
// exibido output indicando operação inválida.
// Retorno: retorna 1 para sucesso e 0 para fracasso.
int alterarSkiplist(skiplist *d, char verbete[], char definicao[]){
    if (d == NULL){return 0;}

    int i;
    item *atual = d->inicio;
    
    for (i = d->nivel; i >= 0; i--){
        while((atual->proximo[i] != NULL) && (strcmp(atual->proximo[i]->verbete, verbete) < 0))
            atual = atual->proximo[i];
    }
    atual = atual->proximo[0];

    if (strcmp(atual->verbete, verbete) == 0){
        strcpy(atual->definicao, definicao);
    }
    else if (strcmp(atual->verbete, verbete) !=0){
        printf("OPERACAO INVALIDA\n");
    }

    return 1;
}

/////////////////////////////// Função Remover Skiplist
// Finalidade: remover itens inseridos anterioremnte.
// Semelhante a inserção, deve-se buscar em cada nível
// a posição que o verbete se encontra e, por meio de
// um array auxiliar, armazena informações necessárias.
// Porém, se no nivel ZERO o auxiliar aponta para o
// elemento a ser removido, ele deverá apontar para o
// próximo elemento (similar a lista encadeada).
// Retorno: 1 para sucesso e 0 para fracasso.
int removerSkiplist(skiplist *d, char verbete[]){
    if (d == NULL){return 0;}

    int i;
    item *atual = d->inicio;
    item **auxiliar = NULL;
    auxiliar = (item**)malloc((d->nivelMaximo+1)*sizeof(item*));

    for(i = 0; i <= d->nivelMaximo; i++){
        auxiliar[i] = NULL;
    }

    for(i = d->nivel; i >= 0; i--){
        while((atual->proximo[i] != NULL) && (strcmp(atual->proximo[i]->verbete, verbete) < 0))
            atual = atual->proximo[i];
        auxiliar[i] = atual;
    }

    atual = atual->proximo[0];
    
    if((atual != NULL) && (strcmp(atual->verbete, verbete) == 0)){
        for(i = 0; i <= d->nivel; i++){
            if (auxiliar[i]->proximo[i] != atual) {break;}
            auxiliar[i]->proximo[i] = atual->proximo[i];
        }

        while((d->nivel > 0) && (d->inicio->proximo[d->nivel] == NULL))
            d->nivel--;

        free(atual->proximo);
        free(atual);
        free(auxiliar);
        return 1;
    }
    else{
        printf("OPERACAO INVALIDA\n");
    }

    free(auxiliar);
    return 0;
}

/////////////////////////////// Função Buscar Skiplist
// Finalidade: realiza uma busca na skiplist e imprime
// o verbete e a sua definição. Caso o verbete não exista,
// imprime operação inválida.
// Retorno: 1 para sucesso e 0 para fracasso.
int buscarSkiplist(skiplist *d, char verbete[]){
    if (d == NULL) {return 0;}
    item *atual = d->inicio;
    int i;
    for(i = d->nivel; i >= 0; i--){
        while((atual->proximo[i] != NULL) && (strcmp(atual->proximo[i]->verbete, verbete) < 0)){
            atual = atual->proximo[i];
        }
    }

    atual = atual->proximo[0];

    if((atual != NULL) && (strcmp(atual->verbete, verbete) == 0)) {
        printf("%s %s\n", atual->verbete, atual->definicao);
        return 1;
    }
    else{
        printf("OPERACAO INVALIDA\n");
    }

    return 0;
}

/////////////////////////////// Função Imprimir Skiplist
// Finalidade: tomando como referencia o trecho informado pelo usuário,
// realiza uma busca no caminho completo (caminho 0). Conforme encontra,
// imprime o verbete e sua definicao.
// Retorno: não há.
void imprimirSkiplist(skiplist *d, char trecho[], int tamanho){
    if (d == NULL) {return;}
    item *atual = NULL;
    int impressao = 0;

    atual = d->inicio->proximo[0];

    while (atual != NULL) {
        if (strncmp(atual->verbete, trecho, tamanho) == 0){
            printf("%s %s\n", atual->verbete, atual->definicao);
            impressao += 1;
        }
        atual = atual->proximo[0];
    }
    
    if (impressao == 0){printf("NAO HA PALAVRAS INICIADAS POR %s\n", trecho);}
    
    return;
}