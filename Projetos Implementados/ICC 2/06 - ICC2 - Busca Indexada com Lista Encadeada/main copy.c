/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*    Exercício 3 - Busca Indexada com Lista Encadeada         *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////BLOCO DAS DEFINIÇÕES
typedef struct node_lista_index node_i;
typedef struct node_lista_letras node_l;
typedef struct node_lista_palavras node_p;
typedef struct lista_generica lista;

///////////////////////////////BLOCO DAS STRUCTS
// A estrutura de dados foi elaborada da seguinte forma:
//
//    Index: lista horizontal de letras do alfabeto (no_lista_index)
//      A -> B -> C -> D -> (...) -> Z <-> $  
//      |         |                     
//  #<->A   <->   C <-> C <-> T <-> $   Lista de Palavras: lista horizontal formada por letras (no_lista_palavras).
//      |         |                     Inicio da lista: # e fim da lista: $    
//      D         A                         
//      |         |                     
//      I         S                     Palavras: lista vertical formada por letras (no_lista_letras).
//      |         |     (...)           Fim da sequência: NULL    
//      A         A                         
//      |         NULL
//      R
//      NULL
//
// Observação: a estrutura acima foi montada visando economia de memória.
// Por isso, usou-se structs diferentes para nodes. Enfim, custo/benefício.
struct node_lista_index{ // das palavras
    char letra; // Informação do node
    node_i *proximo;
    node_p *primeira;
};

struct node_lista_letras{ // das palavras
    char letra; // Informação do node
    node_l *abaixo;
};

struct node_lista_palavras{
    char letra; // Informação do node
    node_l *abaixo;
    node_p *anterior, *proximo;
};

//Constroi as listas de palavras e do indice alfabetico
struct lista_generica{
    int atualizado; // 1: Atualizado; 0: Desatualizado
    node_i *inicio_i, *fim_i;
    node_l *inicio_l, *fim_l;
    node_p *inicio_p, *fim_p;
};


///////////////////////////////DECLARAÇÃO DAS FUNÇÕES

//Funções relativas ao vetor de indices
lista *criar_index();
void atualizar_index(lista *i, lista *p);
int verifica_atualizacao(lista *i);

//Funções relativas à lista de palavras
lista *criar_lista();
int processar_palavra(lista *palavras);
node_p *inserir_palavra(lista *palavras, char letra);
void inserir_letra(node_p *palavra, char letra);
int comparar_palavras(lista *i, lista *b);
int buscar_palavra(lista *index);
node_p *buscar_endereco(lista *palavra, char letra);
void imprimir_tres(lista *palavras);
void imprimir_indice(lista *index);
void imprimir_palavra(lista *palavras);

// Funções acessórias para organizar melhor o código
lista *opcao1(lista *palavras);
lista *opcao2(lista *index, lista *palavras);
void opcao3(lista *index, lista *palavras);
void verificarBarraRN();
void destruirTemporaria(lista *temporaria);
void destruirEstrutura(lista *index, lista* palavras);


///////////////////////////////FUNÇÃO MAIN
int main(){

    int opcao = -1, saida = 0;
    lista *listaPalavras = NULL;
    lista *listaIndex = NULL;

    while(saida != 1){

        scanf("%d", &opcao);
        //printf("OPCAO ESCOLHIDA: %d\n\n", opcao);
        verificarBarraRN();

        switch (opcao){
        // Libera toda estrutura e encerra o programa
        case 0: 
            destruirEstrutura(listaIndex, listaPalavras);
            saida = 1;
            break;
        
        case 1:
            listaPalavras = opcao1(listaPalavras);
            //printf("MAIN: SAIU DA FUNCAO OPCAO 1\n");
            if (listaIndex != NULL) listaIndex->atualizado = 0;
            //printf("MAIN: ANTES DO BREAK\n");
            break;

        case 2:
            listaIndex = opcao2(listaIndex, listaPalavras);
            if (listaIndex != NULL) listaIndex->atualizado = 1;
            break;

        case 3: 
            opcao3(listaIndex, listaPalavras);
            break;

        default:
            printf("Opcao invalida.\n");
            break;
        }

    //printf("MAIN: SAIU DO SWITCH OPCAO 1\n");

    }
    
    
    return 0;
}

/////////////////////////////// OPÇÃO 1
// Recebe o nome de um arquivo.txt e faz a leitura
// linha por linha de cada palavra que será adicionada
// na lista de palavras. Ao final, imprime os três
// primeiros nós da lista de palavras.
// Observações: não há.
lista *opcao1(lista *palavras){
    
    int saida = 0;

    if (palavras == NULL){
        palavras = criar_lista();
        do{
            saida = processar_palavra(palavras);
            //printf("SAIDA: %d", saida);
        } while(saida != EOF);
        //printf("SAIU DO DO/WHILE OPCAO 1!!\n");
    }
    else{
        do{
            saida = processar_palavra(palavras);
        } while(saida != EOF);
    }

    imprimir_tres(palavras);
    //printf("ANTES DO RETURN OPCAO 1!!\n");
    return palavras;
}

/////////////////////////////// OPÇÃO 2
// Cria ou atualizacao do vetor de indices e, ao
// final, imprime a quantidade de indices indexados.
lista *opcao2(lista *index, lista *palavras){
    
    if (index == NULL){
        index = criar_index(palavras);
        index->atualizado = 1;
    }
    else{
        atualizar_index(index, palavras);
        index->atualizado = 1;
    }
    //printf("IMPRIMIR LISTA INDEX!\n");
    imprimir_indice(index);
    return index;
}

/////////////////////////////// OPÇÃO 3
// Faz a busca no indice e depois na lista
// 
// Observações: não há.
void opcao3(lista *index, lista *palavras){
    char descarta[30];      
    int busca = -10;

    if (index == NULL){
        printf("Vetor de indices nao atualizado.\n");
        scanf("%30[^,\r]s", descarta);
        //printf("Descaratado: %s\n", descarta);
        void verificarBarraRN();
        return;
    }
    //printf("ENTRE IFS.\n");
    if (verifica_atualizacao(index) == 1){
        //printf("DENTRO DO IF VERIFICA.\n");
        busca = buscar_palavra(index);
        if (busca != -1) printf("%d\n", busca);  
    }
    else{
        printf("Vetor de indices nao atualizado.\n");
        scanf("%30[^,\r]s", descarta);
        //printf("Descaratado: %s\n", descarta);
        void verificarBarraRN();
    }
    //printf("DEPOIS DOS IFS.\n");
}

/////////////////////////////// Função Verificar Barra RN
// Finalidade: fazer o tratamento do \r \n depois da leitura
// de uma linha pela função Resolve Linha.
// Retorno: Não há.
void verificarBarraRN(){
    char ch = ' ';
    ch = getchar();
    //printf("BARRA RN: %d\n", ch);
    if (ch != '\r'){ungetc(ch, stdin);}
    ch = getchar();
    //printf("BARRA RN: %d\n", ch);
    if (ch != '\n'){ungetc(ch, stdin);}
}

lista *criar_index(lista *palavras){
    char letra = 122;
    node_i *auxiliar = NULL;

    lista *index = (lista*)malloc(sizeof(lista));

    node_i *l = (node_i*)malloc(sizeof(node_i));
    l->letra = '$';
    l->primeira = NULL;
    l->proximo = NULL;
    auxiliar = l;
    index->fim_i = l;

    do{
        node_i *l = (node_i*)malloc(sizeof(node_i));
        l->letra = letra;
        l->primeira = NULL;
        l->proximo = auxiliar;
        auxiliar = l;
        letra -= 1;

    }while(letra != 96);

    index->inicio_i = auxiliar;

    atualizar_index(index, palavras);

    return index;
}


void atualizar_index(lista *i, lista *p){
    node_i *auxiliar_i = i->inicio_i;
    node_p *auxiliar_p = NULL;

    while(auxiliar_i != NULL){
        auxiliar_p = buscar_endereco(p, auxiliar_i->letra);
        if (auxiliar_p != NULL){
            auxiliar_i->primeira = auxiliar_p;
        }
        auxiliar_i = auxiliar_i->proximo;
    }
}

int verifica_atualizacao(lista *i){
    if (i == NULL){return 0;}
    if (i->atualizado == 1){return 1;}
    return 0;
}

lista *criar_lista(){
    lista *palavras = (lista*)malloc(sizeof(lista));
    node_p *inicial = (node_p*)malloc(sizeof(node_p));
    node_p *final = (node_p*)malloc(sizeof(node_p));

    inicial->letra = '#';
    inicial->abaixo = NULL;
    inicial->anterior = NULL;
    inicial->proximo = final;

    final->letra = '$';
    final->abaixo = NULL;
    final->anterior = inicial;
    final->proximo = NULL;

    palavras->inicio_p = inicial;
    palavras->fim_p = final;

    return palavras;
}



int processar_palavra(lista *palavras){
    node_p *auxiliar = NULL;
    char nomeArquivo[30];
    char ch = ' ';
    int saida = 0;

    for(int contador = 0; contador < 15; contador++)
        nomeArquivo[contador] = ' ';
    
    scanf("%30[^,\r]s", nomeArquivo);
    void verificarBarraRN();
    //printf("nomeArquivo: %s\n", nomeArquivo);
    
    FILE *cursor = fopen(nomeArquivo, "r");
    if (cursor == NULL){
        printf("Erro na abertura de arquivo.\n");
        return 0;
    }

    int contador = 0;
    while(saida != EOF){
        if (fscanf(cursor, "%c", &ch)==EOF){break;}
        //printf("\n\n%d Loop\n", contador);
        auxiliar = inserir_palavra(palavras, ch);
        //printf("Letra inserida em lista: %c %p %c\n", ch, auxiliar, auxiliar->letra);
        contador += 1;
        while(ch != '\n'){
            saida = fscanf(cursor, "%c", &ch);
            if (saida == EOF){break;}
            //printf("\n%d Loop. Letra a ser inserida em palavra: %c\n", contador, ch);
            if (ch!= '\n') inserir_letra(auxiliar, ch);
            //printf("%c %p %c\n", ch, auxiliar, auxiliar->letra);
            contador += 1;
        }
/*        
        printf("Palavra completa: %c", auxiliar->letra);
        node_l *auxiliarT = auxiliar->abaixo;
        while(auxiliarT != NULL){
            printf("%c", auxiliarT->letra);
            auxiliarT = auxiliarT->abaixo;
        }
        printf("\n");
*/
    //printf("LISTA COMPLETA DE PALAVRAS:");
    //imprimir_palavra(palavras);
    }
    
    fclose(cursor);
    //printf("ANTES DO RETURN DA FUNCAO DE LER!\n");
    return EOF;
}

node_p *inserir_palavra(lista *palavras, char letra){
    if (palavras == NULL) {
        printf("Impossível acrescentar palavras!");
        return NULL;
    }

    node_p *auxiliar = palavras->inicio_p;

    //printf("Letra para inserir: %c.\nDados auxiliar: %p, %c, %p, %c\n", letra, auxiliar, auxiliar->letra, auxiliar->proximo, auxiliar->proximo->letra);

    node_p *novaPalavra = (node_p*)malloc(sizeof(node_p));
    novaPalavra->letra = letra;
    novaPalavra->abaixo = NULL;

    if (auxiliar->proximo->letra == '$'){
        //printf("Entrou para inserir primeira palavra!!\n");
        novaPalavra->proximo = auxiliar->proximo;
        novaPalavra->anterior = auxiliar;
        auxiliar->proximo->anterior = novaPalavra;
        auxiliar->proximo = novaPalavra;
    }
    else{
        //int contador = 0;
        while((auxiliar->proximo->letra != '$')&&(novaPalavra->letra > auxiliar->proximo->letra)){
            //printf("%d While busca: \n", contador);
            //printf("Antes: %p, %c, %p, %c\n", auxiliar, auxiliar->letra, auxiliar->proximo, auxiliar->proximo->letra);
            auxiliar = auxiliar->proximo;
            //printf("Depois: %p, %c\n", auxiliar, auxiliar->letra);
            //contador+=1;
        }
        //printf("Entrou para inserir outras palavras!!\n");
        //printf("Antes de inserir: %p, %c, %p, %c\n", auxiliar, auxiliar->letra, auxiliar->proximo, auxiliar->proximo->letra);
        novaPalavra->proximo = auxiliar->proximo;
        novaPalavra->anterior = auxiliar;
        auxiliar->proximo->anterior = novaPalavra;
        auxiliar->proximo = novaPalavra;
    }

    return novaPalavra;
}

void inserir_letra(node_p *palavra, char letra){
    if (palavra == NULL){
        printf("Impossivel acrescentar letras.");
        return;
    }
    else{
        
        node_l *auxiliar = palavra->abaixo;
        node_l *anterior = NULL;

        //printf("PALAVRA ABAIXO: %p\n", palavra->abaixo);

        node_l *novaLetra = (node_l*)malloc(sizeof(node_l));
        novaLetra->letra = letra;
        novaLetra->abaixo = NULL;

        //printf("Letra para inserir: %c. Auxiliar: %p\n", novaLetra->letra, auxiliar);
        //if (auxiliar != NULL) printf("Dados do Auxiliar: %p, %c, %p\n", auxiliar, auxiliar->letra, auxiliar->abaixo);

        if (auxiliar == NULL){
            //printf("Entrou para inserir primeira Letra!!\n");
            palavra->abaixo = novaLetra;
        }
        else{

            //int contador = 0;
            while(auxiliar != NULL){
                //printf("%d (BUSCA) Auxiliar->letra: %c\n", contador, auxiliar->letra);
                anterior = auxiliar;
                auxiliar = auxiliar->abaixo;
                //contador += 1;
            }
            anterior->abaixo = novaLetra;
        }
    }
}

void inserir_letra_encadeada(lista *palavra, char letra){
    if (palavra == NULL){
        printf("Impossivel acrescentar letras.");
        return;
    }
    else{
        
        node_p *auxiliar = palavra->inicio_p;
        node_p *anterior = NULL;

        //printf("PALAVRA ABAIXO: %p\n", palavra->abaixo);

        node_p *novaLetra = (node_p*)malloc(sizeof(node_p));
        novaLetra->letra = letra;
        novaLetra->abaixo = NULL;

        //printf("Letra para inserir: %c. Auxiliar: %p\n", novaLetra->letra, auxiliar);
        //if (auxiliar != NULL) printf("Dados do Auxiliar: %p, %c, %p\n", auxiliar, auxiliar->letra, auxiliar->abaixo);

        if (auxiliar->proximo->letra == '$'){
            //printf("Entrou para inserir primeira Letra!!\n");
            auxiliar->proximo->anterior = novaLetra;
            novaLetra->proximo = auxiliar->proximo;
            novaLetra->anterior = auxiliar;
            auxiliar->proximo = novaLetra;
        }
        else{
            //int contador = 0;
            while(auxiliar->proximo != NULL){
                //printf("%d (BUSCA) Auxiliar->letra: %c\n", contador, auxiliar->letra);
                anterior = auxiliar;
                auxiliar = auxiliar->proximo;
                //contador += 1;
            }
            anterior->proximo->anterior = novaLetra;
            anterior->proximo = novaLetra;
            novaLetra->proximo = auxiliar;
            novaLetra->anterior = anterior;
        }
    }
}


int buscar_palavra(lista *index){
    char ch = ' ';
    lista *buscada = criar_lista();
    int saida = 0;

    do{
        ch = getchar();
        //printf("%c ", ch);
        if ((ch != '\r')&&(ch != '\n')) inserir_letra_encadeada(buscada, ch);
    }while(ch != '\n');
    saida = comparar_palavras(index, buscada);
    //printf("IMPRIMINDO SAIDA: %d.\nIMPRIMINDO PALAVRA BUSCADA:\n", saida);
    //imprimir_palavra(buscada);
    destruirTemporaria(buscada);
    return saida;
}

node_p *buscar_endereco(lista *palavra, char letra){
    node_p *auxiliar = palavra->inicio_p;

    while (auxiliar != NULL){
        if (auxiliar->letra == letra){return auxiliar;}
        auxiliar = auxiliar->proximo;
    }
    return NULL;
}

int comparar_palavras(lista *i, lista *b){
    //printf("\n\nCOMPARANDO PALAVRAS\n");
    node_i *auxiliar_i = i->inicio_i;   
    node_p *auxiliar_il = NULL, *auxiliar_bl = NULL, *auxiliar_b = b->inicio_p->proximo;
    node_l *auxiliar_l = NULL;
    char letra = auxiliar_b->letra;
    //printf("LETRA BUSCADA: %c.\n", letra);
    //Procurando letra na lista index
    while (auxiliar_i->letra != '$'){
        //printf("BUSCA (INDICE): %c\n\n", auxiliar_i->letra);
        if (auxiliar_i->letra == letra){
           // printf("ENCONTROU: %c. LETRA BUSCADA: %c\n", auxiliar_i->letra, letra);
            break;
        }
        auxiliar_i = auxiliar_i->proximo;
    }
    //printf("SAIU DO WHILE DE BUSCA!\n");
    
    if (auxiliar_i->primeira == NULL){
        printf("Palavra nao existe na lista.\n");
        return -1;
    }
    // Desce para a lista de palavras. É necessário guardar sua posição a parte 
    // para continuar a busca se for necessáio.
    auxiliar_il = auxiliar_i->primeira; 

    //A comparação de letras (nodes) seguirá nesses dois ponteiros.
    auxiliar_l = auxiliar_il->abaixo; // Desce para a segunda letra da palavra
    auxiliar_bl = auxiliar_b->proximo; // Anda para o elemento a direita

    //printf("AUXILIAR_IL->letra: %c\n", auxiliar_il->letra);
    //printf("AUXILIAR_L->letra: %c\n", auxiliar_l->letra);
    //printf("AUXILIAR_BL->letra: %c\n", auxiliar_bl->letra);

    // Testa para ver se a palavra é igual
    // Caso não seja, tenta procurar outra com mesmo inicio
    int contador = 0;
    //printf("\n\nPRINT DE ENTRADA DO WHILE DE COMPARAÇÃO!!\n");
    while(auxiliar_il->letra == letra){
        //printf("%d AUXILIAR_IL->letra: %c\n", contador, auxiliar_il->letra);
        while(auxiliar_l->letra == auxiliar_bl->letra){
            if ((auxiliar_l->abaixo == NULL)&&(auxiliar_bl->proximo->letra == '$')){return contador;}
            //printf("AUXILIAR_L->letra (DENTRO IF): %c, %p\n", auxiliar_l->letra, auxiliar_l->abaixo);
            //printf("AUXILIAR_BL->letra (DENTRO IF): %c, %c\n\n", auxiliar_bl->letra, auxiliar_bl->proximo->letra);
            auxiliar_l = auxiliar_l->abaixo;
            auxiliar_bl = auxiliar_bl->proximo;
        }
        auxiliar_il = auxiliar_il->proximo;
        auxiliar_l = auxiliar_il->abaixo;
        auxiliar_bl = auxiliar_b->proximo;
        contador += 1;
    }

    printf("Palavra nao existe na lista.\n");
    return -1;
}


void imprimir_tres(lista *palavras){
    node_p *auxiliar = palavras->inicio_p->proximo;
    node_l *auxiliarB = NULL;

    int contador = 0;
    while(contador < 3){
        if((auxiliar->letra != '#')||(auxiliar->letra != '$')){
            printf("%c", auxiliar->letra);
            auxiliarB = auxiliar->abaixo;
            while (auxiliarB != NULL){
                printf("%c", auxiliarB->letra);
                auxiliarB = auxiliarB->abaixo;
            }
            printf("\n");
        }
        auxiliar = auxiliar->proximo; 
        contador += 1;
    }

}


void imprimir_indice(lista *index){
    node_i *auxiliar_i = index->inicio_i;
    int contador = 0;

    while(auxiliar_i->letra != '$'){
        //printf("Letra: %c. Ponteiro abaixo: %p.\n", auxiliar_i->letra, auxiliar_i->primeira);
        if (auxiliar_i->primeira != NULL){contador += 1;}
        auxiliar_i = auxiliar_i->proximo;
    }

    printf("%d\n", contador);
}

void imprimir_palavra(lista *palavras){
    node_p *auxiliar = palavras->inicio_p;
    node_l *auxiliarB = NULL;

    while(auxiliar != NULL){
        if((auxiliar->letra != '#')||(auxiliar->letra != '$')){
            printf("%c", auxiliar->letra);
            auxiliarB = auxiliar->abaixo;
            while (auxiliarB != NULL){
                printf("%c", auxiliarB->letra);
                auxiliarB = auxiliarB->abaixo;
            }
            printf("\n");
        }
        auxiliar = auxiliar->proximo; 
    }
}


void destruirTemporaria(lista *temporaria){
    node_p *auxiliar = temporaria->inicio_p;
    node_p *anterior = NULL;

    while (auxiliar != NULL){
        anterior = auxiliar;
        auxiliar = auxiliar->proximo;
        free(anterior);
    }
    free(temporaria);
}


void destruirEstrutura(lista *index, lista* palavras){
    //printf("ENTROU EM DESTRUIR ESTRUTURA!\n");
    if(index != NULL){
        node_i *anterior_i = NULL, *auxiliar_i = index->inicio_i;
        if(auxiliar_i != NULL){
            //Liberando os nodes do index
            do{
                anterior_i = auxiliar_i;
                auxiliar_i = auxiliar_i->proximo;
                free(anterior_i);
            }while(auxiliar_i != NULL);
        }
    }
    node_p *anterior_p = NULL, *auxiliar_p = palavras->inicio_p;
    node_l *anterior_pl = NULL, *auxiliar_pl = NULL;
            
    //printf("TERMINOU INDEX E COMEÇOU LISTA DE PALAVRAS!\n");
    // Libera os nodes da lista e das letras de palavras
    do{
        anterior_p = auxiliar_p;
        auxiliar_pl = anterior_p->abaixo;
        auxiliar_p = auxiliar_p->proximo;
        
        if (auxiliar_pl != NULL){
            //Libera as letras das palavras
            //printf("COMEÇOU SEQUENCIA DE LETRAS DAS PALAVRAS!\n");
            do{
                anterior_pl = auxiliar_pl;
                auxiliar_pl = auxiliar_pl->abaixo;
                //printf("Liberou Anterior_PL (LETRA): %c\n", anterior_pl->letra);
                free(anterior_pl);
            }while(auxiliar_pl != NULL);
        }
        //printf("Liberou Primeira Letra da Palavra (LISTA DE PALAVRAS): %c\n\n", anterior_p->letra);
        free(anterior_p);

    }while(auxiliar_p != NULL);

    //Liberando as próprias listas
    free(palavras);
    free(index);

}