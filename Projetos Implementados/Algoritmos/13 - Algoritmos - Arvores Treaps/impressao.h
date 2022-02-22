typedef struct node_arvore arvore;

void inicializa_vetor(char vetor[], int tamanho);
void verificarBarraRN();
void menu_impressao(arvore *a);
arvore *menu_insercao(arvore *a);

arvore *criar_arvore(int elemento);
void inserir_arvore(arvore *a, int elemento);
void impressao_preordem(arvore *a);
void impressao_emordem(arvore *a);
void impressao_posordem(arvore *a);
void destruirArvore(arvore *a);