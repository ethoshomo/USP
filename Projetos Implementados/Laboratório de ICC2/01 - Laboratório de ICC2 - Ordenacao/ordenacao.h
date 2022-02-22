//////////////////////////// DEFINIÇÕES
typedef struct listas_conchas lista;
typedef struct conchas_nt itens;

//////////////////////////// FUNÇÕES DO PROGRAMA
void shellSort(lista *l, int n);
lista *criarLista(lista *l, int quantidadeConchas);
void destruirLista(lista *l);
char* preencherStrings();
lista* readline(lista *l, int indice);
void imprimir(lista *l, int quantidadeLinhas);