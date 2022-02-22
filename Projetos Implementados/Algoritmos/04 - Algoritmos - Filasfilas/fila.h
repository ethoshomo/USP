////////////////////////// DEFINIÇÕES E VARIÁVEIS GLOBAIS
#define tamanhoFila 100
typedef struct fila_t fila;
typedef struct pessoa_t pessoa;

////////////////////////// DECLARAÇÃO DE FUNÇÕES
fila* criarFila(fila* f);
void destruirFila(fila *f);
int classificacao(int idade, int saude);
void trocaPosicao (fila* f, int posicaoA, int posicaoB);
void ordenaFila(fila* f);
void resolveLinha(fila *f);