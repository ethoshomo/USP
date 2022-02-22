#include <stdio.h>
#include <stdlib.h>
#include "polinomios.h"

////////////////////////////////// Structs
// Cria as estruturas do polinômio e dos termos que o compõe
struct termo_t {
    int coeficiente;
    int grau;
    struct termo_t *proximoTermo;
};

struct polinomio_t {
    struct termo_t *inicio, *fim;
    int maiorGrau;
};

////////////////////////////////// Função Cria Polinômio Resultado
// Finalidade: cria uma lista encadeada para armazenar o polinômio
// bem como inicializa as variáveis.
// Retorno: retorna o endereço de memória do polinômio criado.
polinomio *criarPolinomioResultado(){
    polinomio* pol = (polinomio*)malloc(sizeof(polinomio));
    if (pol == NULL){printf("Erro na alocacao dinamica."); exit(1);}

    pol->inicio = NULL;
    pol->fim = NULL;
    pol->maiorGrau = 0;

    return pol;
}

////////////////////////////////// Função Destruir Polinômio
// Finalidade: deslocar da memória dinâmica todos os termos e 
// o próprio polinômio.
// Retorno: não há.
void destruirPolinomioResultado(polinomio *pol){
    if (pol == NULL){printf("Erro na desalocacao."); exit(1);}
        
    termo *termo = NULL;
    termo = pol->inicio;
        
    while(termo != NULL){
        pol->inicio = termo->proximoTermo;
        free(termo);
        termo = pol->inicio;
    }
    free(pol);
}

////////////////////////////////// Função Read Line
// Finalidade: lê a linha de entrada que possui o polinômio
// que será somado aos outros polinômios.
// Retorno: retorna o próprio polinômio enviado.
polinomio* readLine(polinomio *pol){
    int indice = 0, numero = 0;
    char ch = ' ';

    ch = getchar(); // Dispensa parentese de abertura

    do{ 
        scanf(" %d", &numero);
        inserirSomarTermo(pol, numero, indice);
        ch = getchar(); // Dispensa virgulas e parentese de fechar
        indice += 1;
    } while (ch != ')');

    ch = getchar(); // Dispensa \r
    ch = getchar(); // Dispensa \n

    return pol;
}

////////////////////////////////// Função Inserir Somar Termos
// Finalidade: a função é responsável por verificar se o termo de determinado
// grau existe. Caso exista, soma o coeficiente. Caso não exista, irá 
// criar um termo novo e será incrementado na lista linkada.
// Retorno: retorna um inteiro 1 para sucesso e fecha o programa em erro.
int inserirSomarTermo(polinomio *pol, int coeficiente, int grau){
    if (pol == NULL){printf("Erro na leitura do polinomio."); exit(1);}

    if (verificarGrauSomar(pol, coeficiente, grau) == 1){return 1;}

    termo *termoAux = (termo*)malloc(sizeof(termo));
    termoAux->coeficiente = coeficiente;
    termoAux->grau = grau;
    termoAux->proximoTermo = NULL;

    //Primeiro caso: lista vazia
    if (pol->inicio == NULL){pol->inicio = termoAux;}
    //Segundo caso: lista com mais de um nó
    else{pol->fim->proximoTermo = termoAux;}
    
    pol->fim = termoAux;
    if (termoAux->grau > pol->maiorGrau){pol->maiorGrau = termoAux->grau;}

    return 1;
}

////////////////////////////////// Função Verificar Grau Somar
// Finalidade: percorre o polinômio verificando se existe um termo de igual
// grau ao que se deseja adicionar. Caso exista, soma seus coeficientes.
// Retorno: retorna um inteiro caso a soma tenha sido efetivada e 0 para insucesso.
int verificarGrauSomar(polinomio *pol, int coeficiente, int grau){
    if (pol == NULL){printf("Erro na verificacao de grau do polinomio."); return 0;}

    termo *termoAux = NULL;
    termoAux = pol->inicio;
    while (termoAux != NULL){
        if (termoAux->grau == grau) {
            termoAux->coeficiente = termoAux->coeficiente + coeficiente;
            return 1;
        }
        termoAux = termoAux->proximoTermo;
    }
    return 0;
}

////////////////////////////////// Função Imprimir
// Finalidade: Imprime o polinômio por ordem de expoente.
// Retorno: não há.
void imprimir(polinomio *pol){
    if (pol == NULL){printf("Erro na impressao do polinomio."); exit(1);}

    printf("(");
    for (int i = 0; i <= pol->maiorGrau; i++){
        termo *termoAux = pol->inicio;
        while (termoAux != NULL){
            if (termoAux->grau == i){
                if(i == pol->maiorGrau){
                    printf("%d)", termoAux->coeficiente);
                }
                else{
                    printf("%d,", termoAux->coeficiente);
                }      
            }
            termoAux = termoAux->proximoTermo;
        }   
    }    
    printf("\n");
}