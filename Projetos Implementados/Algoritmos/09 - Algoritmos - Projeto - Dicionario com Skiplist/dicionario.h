typedef struct item_t item;
typedef struct slista_t skiplist;

/////////////////////////////////////FUNÇÕES ACESSÓRIAS
int resolverLinha(skiplist *d, char verbete[], char definicao[]);
void inicializaVetor(char vetor[], int tamanho);
int sorteiaNivel(skiplist *d);

//////////////////////////////////// FUNÇÕES PRINCIPAIS
skiplist *criarSkiplist(skiplist *d);
void destruirSkiplist(skiplist *d);
int inserirSkiplist(skiplist *d, char verbete[], char definicao[]);
int alterarSkiplist(skiplist *d, char verbete[], char definicao[]);
int removerSkiplist(skiplist *d, char verbete[]);
int buscarSkiplist(skiplist *d, char verbete[]);
void imprimirSkiplist(skiplist *d, char trecho[], int tamanho);