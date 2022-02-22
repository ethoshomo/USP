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
no *buscaPai(no *raiz, elem procurado);
int inserirEsquerda(arvore *a, elem elementoInserir, elem pai);
int inserirDireita(arvore *a, elem elementoInserir, elem pai);
int removerElemento(arvore *a, elem elementoRemover);
void preOrdem(no *raiz);
void emOrdem(no *raiz);
void posOrdem(no *raiz);