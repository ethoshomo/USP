typedef int elem;
typedef struct no_t no;

typedef union {
    elem atomo;
    no *sublista;
} info;

struct no_t {
    int tipo;
    info info;
    no *proximo;
};

void libera(no *p);
no *atomo(elem x);
no *sublista(no *sublista);
no *concat(no *p, no *q);
info cabeca(no *p, int *tipo);
no *cauda(no*p);
void imprime(no *p);
void imprimir(no *p);