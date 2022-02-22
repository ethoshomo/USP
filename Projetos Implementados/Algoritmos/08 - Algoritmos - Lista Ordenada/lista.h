typedef struct cadastro_t cadastro;
typedef struct lista_t listaCadastro;


listaCadastro *criarLista();
void liberarLista(listaCadastro *l);
int verificarCadastro(listaCadastro *l, int codigo);
int inserir(listaCadastro *l, int codigo, char nome[]);
int remover(listaCadastro *l, int codigo);
void imprimir(listaCadastro *l);
int resolveLinha(listaCadastro *l);
