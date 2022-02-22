
typedef struct lista_dados dados;

struct node_arvore{
    int info;
    int id, id_e, id_d;
    arvore *e, *d;
};

struct lista_dados{
    int erro;
    arvore *inicio;
    arvore *fim;
};

arvore *criar_node(int id, int info, int id_e, int id_d);
dados *criar_lista_dados();
int inserir_lista_dados(dados *lista, int id, int info, int id_e, int id_d);
arvore *buscar_lista_dados(dados *lista, int id);
void destruir_lista_dados(dados *lista, arvore *dados);

arvore *montar_arvore(dados *lista, int id);
int soma_pais_filhos(arvore* node, arvore *esquerda, arvore *direita);
void verifica_vf_somas(int erro);
void destruirArvore(arvore *a);
