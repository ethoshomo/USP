typedef int elem;
typedef struct no_t no;
typedef struct arvore_t arvore;

struct arvore_t {
    no *raiz;
};

arvore *criarArvore();
int estaVazia(arvore *a);
void podarArvore(no *raiz);
void imprimir(no *raiz);
int alturaArvore(no *raiz);
no *busca(no *raiz, elem procurado);
int inserir(no **raiz, elem x);
int remover(no **raiz, elem x);
void preOrdem(no *raiz);
void emOrdem(no *raiz);
void posOrdem(no *raiz);