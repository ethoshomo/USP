typedef int elemento;
typedef struct lista_t lista;

lista *criarLista();
void liberarLista(lista *l);
int inserir(lista *l, elemento x);
int remover(lista *l, elemento x);
void imprimir(lista *l);
void imprimirInverso(lista *l);
