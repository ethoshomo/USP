typedef struct lista_impressao lista;

struct lista_impressao {
    char *palavra;
    int quantidade;
};

void imprimirLista(lista *l, int impressoes, int tamanho, int *imprimir);
int verificaExistencia(lista* l, char *palavraAcrescentar, int *tamanho);
lista* criarLista(char texto[], int *tamanho);
void ordenaListaNumero(lista *l, int *tamanho);
void ordenaListaLetra(lista *l, int *tamanho);
void iniciaVetor(char vetor[], int tamanho);