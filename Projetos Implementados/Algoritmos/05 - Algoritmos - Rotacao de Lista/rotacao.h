typedef struct lista_t lista;
typedef struct no_t no;

struct no_t {
    int numero;
    no *proximoNo;
    no *anteriorNo;
};

struct lista_t {
    struct no_t *inicio, *fim;
    int tamanhoLista;
};

lista* criarLista();
void destruirLista(lista *l);
int inserirLista(lista *l, int x);
void imprimir(lista *l);
void rotacoes(lista *l, int numeroRotacoes);