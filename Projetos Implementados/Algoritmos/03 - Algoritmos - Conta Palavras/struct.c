#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista_impressao lista;

struct lista_impressao {
    char *palavra;
    int quantidade;
};

void imprimirLista(lista *l, int tamanho){
    printf("Imprimir Lista de Palavras e suas Quantidades:\n");
    for(int i = 0; i < tamanho; i++){
        printf("Posicao %d:\n", i);
        printf("\tPalavras: %s\n", l[i].palavra);
        printf("\tQuantidade: %d\n", l[i].quantidade);        
    }

}

void ordenaLista(lista *l, int *tamanho){
    char temporario[50];
    int temporarioq = 0;
    
    for(int i = 0; i < *tamanho; i++){
        for(int j = i + 1; j < *tamanho; j++){
            if (l[i].quantidade < l[j].quantidade){        
                strncpy(temporario, l[i].palavra, strlen(l[i].palavra)+1);
                temporarioq = l[i].quantidade;

                if ((strlen(l[j].palavra))>strlen(l[i].palavra)){
                    l[i].palavra = (char*)realloc(l[i].palavra, (strlen(l[j].palavra)+1)*sizeof(char));
                    strcpy(l[i].palavra, l[j].palavra);
                }
                else{strcpy(l[i].palavra, l[j].palavra);}
                l[i].quantidade = l[j].quantidade;

                if ((strlen(temporario))>strlen(l[j].palavra)){
                    l[j].palavra = (char*)realloc(l[j].palavra, (strlen(temporario)+1)*sizeof(char));
                    strcpy(l[j].palavra, temporario);
                }
                else{strcpy(l[j].palavra, temporario);}
                l[j].quantidade = temporarioq;            
            }
        }
    } 
}

char* preencherPalavra(){
    char *string = NULL;
    char caracter;
    int tamanhoString = 0;

    do{
        string = (char*)realloc(string, (tamanhoString+1)*sizeof(char));
        caracter = getchar();
        string[tamanhoString] = caracter;
        tamanhoString += 1; 
    }while (caracter != '\n');
    string[tamanhoString-1] = '\0';
    return string;
}

lista* adicionarLista(lista *l, int *quantidade){
    char *temporario = NULL;
    int retorno = -1, encontrou = 0;
    temporario = preencherPalavra();
    printf("%s\n", temporario);
    for(int i = 0; i < *quantidade; i++){
        retorno = strcmp(temporario, l[i].palavra);   
        if (retorno == 0){
            l[i].quantidade += 10;
            encontrou +=1;
        }
    }

    if (encontrou == 0){
        l = (lista*)realloc(l, (*quantidade+1)*sizeof(lista));
        l[*quantidade].palavra = (char*)malloc((strlen(temporario)+1)*sizeof(char));
        strcpy(l[*quantidade].palavra, temporario);
        scanf("%d", &l[*quantidade].quantidade);
        getchar();    
        *quantidade += 1;
    }
    
    free(temporario);
    return l;
}


int main(){
    lista *l = NULL;
    int quantidadeLista = 0;

    l = adicionarLista(l, &quantidadeLista);
    l = adicionarLista(l, &quantidadeLista);
    l = adicionarLista(l, &quantidadeLista);
    l = adicionarLista(l, &quantidadeLista);
    l = adicionarLista(l, &quantidadeLista);
    l = adicionarLista(l, &quantidadeLista);
    ordenaLista(l, &quantidadeLista);
    imprimirLista(l, quantidadeLista);
/*
    l[0].palavra = (char*)malloc(50*sizeof(char));
    strcpy(l[0].palavra, "testando a primeira palavra");
    l[0].quantidade = 10;
    printf("%s\n", l[0].palavra);
    printf("%d\n", l[0].quantidade);

    l[1].palavra = (char*)malloc(50*sizeof(char));
    strcpy(l[1].palavra, "testando a segunda palavra");
    l[1].quantidade = 20;
    printf("%s\n", l[1].palavra);
    printf("%d\n", l[1].quantidade);
*/
    for (int i = 0; i < quantidadeLista; i++)
        free(l[i].palavra);
    
    free(l);
    
    return 0;
}