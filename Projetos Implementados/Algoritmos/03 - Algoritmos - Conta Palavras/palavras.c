#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavras.h"

//////////////////////////////////////////// Função imprimirLista()
// Serve para imprimir as palavras e a quantidade de vezes que aparecem.
// Pode acontecer de o tamanho da lista ser inferior a quantidade de 
// impressões pedidas. Por isso, foi necessário a estrutura condicional.
// Não há retorno.
void imprimirLista(lista *l, int impressoes, int tamanho, int *imprimir){
    if (impressoes>tamanho){
        for(int i = 0; i < tamanho; i++)
            printf("%s %d\n", l[i].palavra, l[i].quantidade);
    }
    else{
        for(int i = 0; i < impressoes; i++){
            printf("%s %d\n", l[i].palavra, l[i].quantidade);
        }
    }
    *imprimir += 1;
}

//////////////////////////////////////////// Função verificaExistencia()
// Na criação da lista, espera-se que os itens não sejam repetidos, mas, sim,
// contabilizados. Desse modo, toda string nova, que foi capturada da string
// texto, precisa ter verificada a sua ocorrência anterior. Se existir, apenas
// incrementa a sua quantidade, dispensando outros procedimentos.
// O retorno 0 (zero) irá condicionar o incremento da lista.
int verificaExistencia(lista* l, char *palavraAcrescentar, int *tamanho){
    int contador = 0;
    for(int i = 0; i < *tamanho; i++){
        if (strcmp(palavraAcrescentar, l[i].palavra) == 0)
        {
            l[i].quantidade += 1;
            contador +=1 ;
            return contador;
        }
    }
    return contador;
}

//////////////////////////////////////////// Função criarLista()
// Serve para criar a lista (alocando memória e preenchendo seus itens). 
// O preenchimento de itens recebe a string texto da main e o seu tamanho.
// Essa string será quebrada pela função strtok, sendo certo que as novas
// strings ou irão ser inseridas ou irão incrementar a quantidade das 
// existentes (por meio da função que verifica a existência).
// Retorna para a main a lista.
lista* criarLista(char texto[], int *tamanho){
    char *auxiliar = NULL;

    auxiliar = strtok(texto, " ");

    lista *l = (lista*)malloc((*tamanho+1)*sizeof(lista));
    l[*tamanho].palavra = (char*)malloc((strlen(auxiliar)+1)*sizeof(char));
    l[*tamanho].quantidade = 1;    
    strcpy(l[*tamanho].palavra, auxiliar);
    *tamanho += 1;

    while(auxiliar != NULL)
    {
        auxiliar = strtok(NULL, " ");
        if (auxiliar == NULL){break;}
        else {
            if (verificaExistencia(l, auxiliar, tamanho) == 0){
                l = (lista*)realloc(l, ((*tamanho)+1)*sizeof(lista));
                l[*tamanho].palavra = (char*)malloc((strlen(auxiliar)+1)*sizeof(char));
                l[*tamanho].quantidade = 1;
                strcpy(l[*tamanho].palavra, auxiliar);
                *tamanho += 1;
            }
        }
    }
    return l;
}

//////////////////////////////////////////// Função ordenaListaNumero()
// Ordena a lista pela quantidade de vezes que a palavra apareceu.
// Retorna a lista ordenada.
void ordenaListaNumero(lista *l, int *tamanho){
    char *temporario;
    int temporarioq = 0;
    
    for(int i = 0; i < *tamanho; i++){
        for(int j = i + 1; j < *tamanho; j++){
            if (l[i].quantidade < l[j].quantidade){        
                temporario = l[i].palavra;
                temporarioq = l[i].quantidade;
                
                l[i].palavra = l[j].palavra;
                l[i].quantidade = l[j].quantidade;

                l[j].palavra = temporario;
                l[j].quantidade = temporarioq;            
            }//Fim do if para ordenar            
        }
    } 
}

//////////////////////////////////////////// Função ordenaListaLetra()
// Se as quantidades de itens são iguais para dois ou mais, ordena a lista
// dessas palavras em ordem alfabetica.
// Retorna a lista ordenada.
void ordenaListaLetra(lista *l, int *tamanho){
    char *auxiliar = NULL;
    int quantidade = 0;

    for(int i = 0; i < *tamanho; i++){
        for(int j = i + 1; j < *tamanho; j++){
            if (l[i].quantidade == l[j].quantidade){ // Se as quantidades são iguais
                if (strcmp(l[i].palavra, l[j].palavra) > 0){ // Usa-se as palavras
                    auxiliar = l[i].palavra;
                    l[i].palavra = l[j].palavra;
                    l[j].palavra = auxiliar;

                    quantidade = l[i].quantidade;
                    l[i].quantidade = l[j].quantidade;;
                    l[j].quantidade = quantidade;
                }
            }
        }
    }
}

//////////////////////////////////////////// Função iniciaVetor()
// Serve para iniciar o vetor com o texto lido. Todas as posições serão
// preenchidas com espaços em branco. Isso ajuda na hora de quebrar a 
// string em palavras e evita erros com lixo de memória indesejado.
void iniciaVetor(char vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++)
        vetor[i] = ' ';
}