/////////////////////// DEFINIÇÕES
#define tamanhoPilha 100

typedef int tipoDado;
typedef struct pilha_t pilha;

/////////////////////// DECLARAÇÃO DE FUNÇÕES
pilha* criarPilha();
void destruirPilha(pilha *p);
int pilhaCheia(pilha *p);
int pilhaVazia(pilha *p);
int push(pilha *p, tipoDado x);
int pop(pilha *p, tipoDado *x);
int top(pilha *p, tipoDado *x);
