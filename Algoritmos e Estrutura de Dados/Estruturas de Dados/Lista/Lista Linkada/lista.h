typedef int tipoDado;
typedef struct lista_t lista;
typedef struct no_t no;

lista* criarLista();
void destruirLista(lista *l);
void imprimir(lista *l);
int tamanhoLista(lista *l);
int inserirLista(lista *l, tipoDado x);
void removerLista(lista *l, tipoDado x);
int elementoLista(lista *l, tipoDado x);

