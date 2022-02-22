////////////////////////Bloco de Definições e Declarações
// Definições
typedef int elemento;
typedef struct numero_t numero;
typedef struct no_t no;

// Declaração de structs usadas para montar o
// número grande (lista de algarismos) com seus
// algarismos (nós das listas);
struct no_t{
    elemento numero;
    no *anterior, *proximo;
};

struct numero_t{
    char sinal;
    elemento vaiUm;
    no *inicio, *fim;    
};

////////////////////////Bloco de Declaração de Funções
//Operações de Grandes Números
int big(numero *n1, numero *n2);
int small(numero *n1, numero *n2);
int igual(numero *n1, numero *n2);
void soma(numero *n1, numero *n2, numero *r);

//Relativas à entrada
void lerNumero(numero *n1, numero *n2);
void resolveEntrada();
void verificarBarraRN();

//Relativas ao Grande Número
numero *criarNumero();
void liberarNumero(numero *l);
int inserir(numero *n, elemento x);
int remover(numero *n, elemento x);
void removerZeros(numero *n);
void removerZerosInversa(numero *n);
int tamanho(numero *n);
void imprimir(numero *n);
void imprimirInverso(numero *n);
