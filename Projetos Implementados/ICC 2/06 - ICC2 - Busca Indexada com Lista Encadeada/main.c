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

// Funções acessórias para organizar melhor o código
lista *opcao1(lista *palavras);
lista *opcao2(lista *index, lista *palavras);
void opcao3(lista *index, lista *palavras);
void verificarBarraRN();

// Funções desconstrutoras
void destruirTemporaria(lista *temporaria);
void destruirEstrutura(lista *index, lista* palavras);

///////////////////////////////FUNÇÃO MAIN
int main(){

    int opcao = -1, saida = 0;
    lista *listaPalavras = NULL;
    lista *listaIndex = NULL;

    while(saida != 1){

        scanf("%d", &opcao);
        verificarBarraRN();

        switch (opcao){
        case 0: // Libera a memória alocada na estrutura
            destruirEstrutura(listaIndex, listaPalavras);
            saida = 1;
            break;
        case 1: // Finalidade: está na descrição da função Opcao1
            listaPalavras = opcao1(listaPalavras);
            if (listaIndex != NULL) listaIndex->atualizado = 0;
            break;
        case 2: // Finalidade: está na descrição da função Opcao2
            listaIndex = opcao2(listaIndex, listaPalavras);
            if (listaIndex != NULL) listaIndex->atualizado = 1;
            break;
        case 3: // Finalidade: está na descrição da função Opcao3
            opcao3(listaIndex, listaPalavras);
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    }

    return 0;
}

/////////////////////////////// OPÇÃO 1
// Recebe o nome de um arquivo.txt e faz a leitura
// linha por linha de cada palavra que será adicionada
// na lista de palavras. Ao final, imprime os três
// primeiros nós da lista de palavras.
// Retorno: retorna lista de palvras preenchida.
lista *opcao1(lista *palavras){
    
    int saida = 0;

    if (palavras == NULL){
        palavras = criar_lista(); // Cria a lista de palavras
        do{
            saida = processar_palavra(palavras); // Cria parte da estrutura
        } while(saida != EOF);
    }
    else{
        do{
            saida = processar_palavra(palavras); // Amplia estrutura
        } while(saida != EOF);
    }

    imprimir_tres(palavras); // Imprime as três primeiras palavras da lista
    
    return palavras;
}

/////////////////////////////// OPÇÃO 2
// Cria ou atualiza o vetor de indices e, ao
// final, imprime a quantidade de indices indexados.
// Retorno: mémoria do vetor de indices.
lista *opcao2(lista *index, lista *palavras){
    
    if (index == NULL){
        index = criar_index(palavras); // Cria e atualiza vetor
        index->atualizado = 1;
    }
    else{
        atualizar_index(index, palavras); // Atualiza indices
        index->atualizado = 1;
    }

    imprimir_indice(index); //Imprime quantidade de indices indexados

    return index;
}

/////////////////////////////// OPÇÃO 3
// Verifica se o indice está atualizado. Caso não esteja,
// descarta palavra a ser procurada. Caso esteja, busca a
// palavra, primeiro no indice, depois na lista de palavras.
// Retorno: não há.
void opcao3(lista *index, lista *palavras){
    char descarta[30];      
    int busca = -10;

    if (index == NULL){ //Se não foi criada, não está atualizada.
        printf("Vetor de indices nao atualizado.\n");
        scanf("%30[^,\r]s", descarta);
        void verificarBarraRN();
        return;
    }
    
    if (verifica_atualizacao(index) == 1){ // Atualizada
        busca = buscar_palavra(index);
        if (busca != -1) printf("%d\n", busca);  
    }
    else{ // Não atualizada. Descarta palavra procurada.
        printf("Vetor de indices nao atualizado.\n");
        scanf("%30[^,\r]s", descarta);
        void verificarBarraRN();
    }
}

/////////////////////////////// Função Verificar Barra RN
// Faz o tratamento do \r \n depois da leitura do scanf em
// uma linha.
// Retorno: Não há.
void verificarBarraRN(){
    char ch = ' ';
    ch = getchar();
    if (ch != '\r'){ungetc(ch, stdin);}
    ch = getchar();
    if (ch != '\n'){ungetc(ch, stdin);}
}

/////////////////////////////// Função Cria Vetor de Indices
// Cria vetor de indices. Foi colocado valore $ no 
// fim do vetor para facilitar a identificação da posição
// e diferenciardo do NULL que existe no fim das palavras.
// Depois de criada, a lista tem seus indices atualizados
// de acordo com a lista de palavras.
// Retorno: retorna endereço de memória da lista criada.
lista *criar_index(lista *palavras){
    char letra = 122;
    node_i *auxiliar = NULL; // Auxilia na adição de novos nodes.

    lista *index = (lista*)malloc(sizeof(lista)); // Cria a lista

    node_i *l = (node_i*)malloc(sizeof(node_i)); // Cria o último node.
    l->letra = '$';
    l->primeira = NULL;
    l->proximo = NULL;
    auxiliar = l;
    index->fim_i = l;

    do{  // Adiciona todo o alfabeto de Z até A.
        node_i *l = (node_i*)malloc(sizeof(node_i));
        l->letra = letra;
        l->primeira = NULL;
        l->proximo = auxiliar;
        auxiliar = l;
        letra -= 1;
    }while(letra != 96);

    index->inicio_i = auxiliar; // Aponta para a letra A.

    atualizar_index(index, palavras); // Atualiza indexação.

    return index;
}

/////////////////////////////// Função Atualiza Index
// Percorre a lista de index atualizando seus indices,
// de acordo com a lista de palavras.
// Retorno: não há.
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

/////////////////////////////// Função Verifica Atualizacao
// Verifica se o vetor de indices está atualizado.
// Retorno: retorna 1 para atualizado e 0 para desatualizado.
int verifica_atualizacao(lista *i){
    if (i == NULL){return 0;}
    if (i->atualizado == 1){return 1;}
    return 0;
}

/////////////////////////////// Função Criar Listas
// Cria listas genéricas para serem usadas como listas ou palavras
// Retorno: retorna o endereço de memória da lista criada.
lista *criar_lista(){
    lista *palavras = (lista*)malloc(sizeof(lista));
    node_p *inicial = (node_p*)malloc(sizeof(node_p));
    node_p *final = (node_p*)malloc(sizeof(node_p));

    inicial->letra = '#'; // Inicializa valores do primeiro node
    inicial->abaixo = NULL;
    inicial->anterior = NULL;
    inicial->proximo = final;
    final->letra = '$'; // Inicializa valores do último node
    final->abaixo = NULL;
    final->anterior = inicial;
    final->proximo = NULL;
    palavras->inicio_p = inicial; //Inicializa ponteiros da lista
    palavras->fim_p = final;

    return palavras;
}

/////////////////////////////// Função Processa Palavra
// Lê o nome do arquivo e adiciona palavras lidas dentro do arquivo.
// Retorno: retorna EOF para encerrar o loop existente na função opcao1.
int processar_palavra(lista *palavras){
    node_p *auxiliar = NULL;
    char nomeArquivo[30];
    char ch = ' ';
    int saida = 0;

    for(int contador = 0; contador < 30; contador++) 
        nomeArquivo[contador] = ' ';// Inicializa o vetor para evitar erros de memória.
    
    scanf("%30[^,\r]s", nomeArquivo); // Lê o nome do arquivo
    void verificarBarraRN();
    
    FILE *cursor = fopen(nomeArquivo, "r"); // Virtualiza o arquivo
    if (cursor == NULL){
        printf("Erro na abertura de arquivo.\n");
        return 0;
    }

    while(saida != EOF){// Acrescenta os nodes na lista de palavras
        if (fscanf(cursor, "%c", &ch)==EOF){break;}
        auxiliar = inserir_palavra(palavras, ch);

        while(ch != '\n'){ // Acrescenta as letras das palavras
            saida = fscanf(cursor, "%c", &ch);
            if (saida == EOF){break;}
            if (ch!= '\n') inserir_letra(auxiliar, ch);
        }
    }
    
    fclose(cursor); // Fecha a virtualização do arquivo.

    return EOF;
}

/////////////////////////////// Função Inserir Palavra
// Adiciona a primeira letra da palavra na lista de palavras em ordem alfabetica.
// Porém, palavras de mesmo indice inicial ficam desordenadas (a primeira a chegar
// será a última do mesmo indice).
// Retorno: retorna o endereço do node para preencher as demais letras.
node_p *inserir_palavra(lista *palavras, char letra){
    if (palavras == NULL) {
        printf("Impossível acrescentar palavras!");
        return NULL;
    }

    node_p *auxiliar = palavras->inicio_p;

    node_p *novaPalavra = (node_p*)malloc(sizeof(node_p));
    novaPalavra->letra = letra;
    novaPalavra->abaixo = NULL;

    if (auxiliar->proximo->letra == '$'){
        novaPalavra->proximo = auxiliar->proximo;
        novaPalavra->anterior = auxiliar;
        auxiliar->proximo->anterior = novaPalavra;
        auxiliar->proximo = novaPalavra;
    }
    else{
        while((auxiliar->proximo->letra != '$')&&(novaPalavra->letra > auxiliar->proximo->letra)){
            auxiliar = auxiliar->proximo;
        }
        novaPalavra->proximo = auxiliar->proximo;
        novaPalavra->anterior = auxiliar;
        auxiliar->proximo->anterior = novaPalavra;
        auxiliar->proximo = novaPalavra;
    }

    return novaPalavra;
}

/////////////////////////////// Função Inserir Letras
// Insere as letras nas sequências de letras das palavras.
// Retorno: não há.
void inserir_letra(node_p *palavra, char letra){
    if (palavra == NULL){
        printf("Impossivel acrescentar letras.");
        return;
    }
    else{        
        node_l *auxiliar = palavra->abaixo;
        node_l *anterior = NULL;

        node_l *novaLetra = (node_l*)malloc(sizeof(node_l)); // Nova letra
        novaLetra->letra = letra;
        novaLetra->abaixo = NULL;

        if (auxiliar == NULL){palavra->abaixo = novaLetra;} // Primeira letra
        else{
            while(auxiliar != NULL){ // Insere ao final da sequencia.
                anterior = auxiliar;
                auxiliar = auxiliar->abaixo;
            }
            anterior->abaixo = novaLetra;
        }
    }
}

/////////////////////////////// Função Inserir Letra Encadeada
// É usada para criar uma palavra que é usadas na opcao3. Ela é necessária
// haja vista que a comparação deve ser feita caracter por caracter.
// Retorno: não há.
void inserir_letra_encadeada(lista *palavra, char letra){
    if (palavra == NULL){
        printf("Impossivel acrescentar letras.");
        return;
    }
    else{
        
        node_p *auxiliar = palavra->inicio_p;
        node_p *anterior = NULL;

        node_p *novaLetra = (node_p*)malloc(sizeof(node_p));
        novaLetra->letra = letra;
        novaLetra->abaixo = NULL;

        if (auxiliar->proximo->letra == '$'){
            auxiliar->proximo->anterior = novaLetra;
            novaLetra->proximo = auxiliar->proximo;
            novaLetra->anterior = auxiliar;
            auxiliar->proximo = novaLetra;
        }
        else{
            while(auxiliar->proximo != NULL){
                anterior = auxiliar;
                auxiliar = auxiliar->proximo;
            }
            anterior->proximo->anterior = novaLetra;
            anterior->proximo = novaLetra;
            novaLetra->proximo = auxiliar;
            novaLetra->anterior = anterior;
        }
    }
}

/////////////////////////////// Função Buscar Palavra
// Cria uma lista encadeada para armazenar a palavra a ser buscada.
// Logo em seguida, compara com as palavras de mesma letra inicial
// que existem na lista de palavras.
// Retorno: está relacionado com a quantidade de nodes necessarios
// encontrar a palavra buscada.
int buscar_palavra(lista *index){
    int saida = 0;
    char ch = ' ';
    lista *buscada = criar_lista(); // Cria lista encadeada

    do{ // Preenche a palavra chave da busca
        ch = getchar();
        if ((ch != '\r')&&(ch != '\n')) inserir_letra_encadeada(buscada, ch);
    }while(ch != '\n');

    saida = comparar_palavras(index, buscada); // Compara a palavra chave

    destruirTemporaria(buscada); // Desaloca memória da palavra temporária.

    return saida;
}

/////////////////////////////// Função Inserir Letra Encadeada
// Busca o primeiro node com a letra informada e retorna seu endereço
// de memória. É usada como função auxiliar na lista de indices (Index).
// Retorno: retorna endereço do node buscado.
node_p *buscar_endereco(lista *palavra, char letra){
    node_p *auxiliar = palavra->inicio_p;

    while (auxiliar != NULL){
        if (auxiliar->letra == letra){return auxiliar;}
        auxiliar = auxiliar->proximo;
    }
    return NULL;
}

/////////////////////////////// Função Comparar Palavras
// Além da finalidade principal de comparar palavras, a função
// percorre vetor de indices e lista de palavras para verificar
// se a palavra existe, comparando letra por letra.
// Retorno: retorna -1 se a palavra não existe ou a quantidade de
// nodes percorridos para ser encontrada.
int comparar_palavras(lista *i, lista *b){
    node_i *auxiliar_i = i->inicio_i;   
    node_p *auxiliar_il = NULL, *auxiliar_bl = NULL, *auxiliar_b = b->inicio_p->proximo;
    node_l *auxiliar_l = NULL;
    char letra = auxiliar_b->letra;
    
    while (auxiliar_i->letra != '$'){//Procurando letra na lista index
        if (auxiliar_i->letra == letra){break;}
        auxiliar_i = auxiliar_i->proximo;
    }
    
    if (auxiliar_i->primeira == NULL){//Verifica existência
        printf("Palavra nao existe na lista.\n");
        return -1;
    }
    
    auxiliar_il = auxiliar_i->primeira; // Guarda seu endereço e desce para lista de palavras

    //A comparação de letras (nodes) seguirá nesses dois ponteiros.
    auxiliar_l = auxiliar_il->abaixo; // Desce para a segunda letra da palavra (estrutura).
    auxiliar_bl = auxiliar_b->proximo; // Anda para o elemento a direita (palavra buscada)
    
    int contador = 0; // Contabiliza nodes percorridos e retorna seu valor.
    while(auxiliar_il->letra == letra){ 
        while(auxiliar_l->letra == auxiliar_bl->letra){ // Testa para ver se a palavra é igual
            if ((auxiliar_l->abaixo == NULL)&&(auxiliar_bl->proximo->letra == '$')){return contador;}
            auxiliar_l = auxiliar_l->abaixo;
            auxiliar_bl = auxiliar_bl->proximo;
        }
        auxiliar_il = auxiliar_il->proximo; // Caso não seja, tenta procurar outra com mesmo inicio
        auxiliar_l = auxiliar_il->abaixo;
        auxiliar_bl = auxiliar_b->proximo;
        contador += 1;
    }

    printf("Palavra nao existe na lista.\n");
    return -1;
}

/////////////////////////////// Função Imprimir Três
// Imprime as três primeiras palavras da lista de palavras
// Retorno: não há.
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

/////////////////////////////// Função Imprimir Indice
// Percorre o vetor de indices e imprime a quantidade indexada.
// Retorno: não há.
void imprimir_indice(lista *index){
    node_i *auxiliar_i = index->inicio_i;
    int contador = 0;

    while(auxiliar_i->letra != '$'){
        if (auxiliar_i->primeira != NULL){contador += 1;}
        auxiliar_i = auxiliar_i->proximo;
    }
    printf("%d\n", contador);
}

/////////////////////////////// Função Destruir Temporária
// Desaloca memória heap alocada para palavra de busca.
// Retorno: não há.
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

/////////////////////////////// Função Destruir Estrutura
// Desaloca memória heap alocada para toda a estrutura e vetores.
// Retorno: não há.
void destruirEstrutura(lista *index, lista* palavras){
    
    if(index != NULL){ //Liberando nodes do vetor index
        node_i *anterior_i = NULL, *auxiliar_i = index->inicio_i;
        if(auxiliar_i != NULL){
            do{
                anterior_i = auxiliar_i;
                auxiliar_i = auxiliar_i->proximo;
                free(anterior_i);
            }while(auxiliar_i != NULL);
        }
    }

    //Libera lista de palavras e as palavras dela derivadas
    node_p *anterior_p = NULL, *auxiliar_p = palavras->inicio_p;
    node_l *anterior_pl = NULL, *auxiliar_pl = NULL;
    do{ // Libera o node da lista de palavras
        anterior_p = auxiliar_p;
        auxiliar_pl = anterior_p->abaixo;
        auxiliar_p = auxiliar_p->proximo;
        
        if (auxiliar_pl != NULL){
            do{//Libera as letras das palavras
                anterior_pl = auxiliar_pl;
                auxiliar_pl = auxiliar_pl->abaixo;
                free(anterior_pl);
            }while(auxiliar_pl != NULL);
        }
        free(anterior_p);

    }while(auxiliar_p != NULL);

    //Liberando as próprias listas
    free(palavras);
    free(index);
}