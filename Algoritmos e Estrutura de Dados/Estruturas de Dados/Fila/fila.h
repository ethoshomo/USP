
/////////////////////////// DEFINIÇÕES E VARIAVEIS
#define tamanhoFila 100
typedef int tipoDado;
typedef struct fila_t fila;

/////////////////////////// FUNÇÕES
fila* criarFila();
void destruirFila(fila *f);
int filaVazia(fila *f);
int filaCheia(fila *f);
int filaInserir(fila *f, tipoDado x);
int filaRemover(fila *f, tipoDado *x);