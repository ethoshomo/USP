/////////////////////// DEFINIÇÕES
#define tamanhoPilha 100

typedef int tipoDado;
typedef struct pilha_t pilha;

/////////////////////// DECLARAÇÃO DE FUNÇÕES
pilha* criarPilha(int tamanhoElemento);
void destruirPilha(pilha *p);
int pilhaCheia(pilha *p);
int pilhaVazia(pilha *p);
int push(pilha *p, void *x);
int pop(pilha *p, void *x);
int top(pilha *p, void *x);