
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

char *push(char *pilha, int *tamanho, char caracter, char *topo){
    pilha[*tamanho] = caracter;
    topo = &pilha[*tamanho];
    //printf("PUSH: %c. Topo Pilha: %c\n", pilha[*tamanho], *topo);
    *tamanho += 1;        
    pilha = (char*)realloc(pilha, (*tamanho+1)*sizeof(char));
    return pilha;
}

char *pop(char *pilha, int *tamanho, char *topo){
    //printf("Entrou no POP FUNÇÃO!!\n");
    *tamanho -= 1;
    if (*tamanho > 0){
        pilha = (char*)realloc(pilha, (*tamanho)*sizeof(char));
        topo = &pilha[*tamanho];
    }
    //printf("(POP) Tamanho: %d. Pilha[tamanho]: %c. StrlenPilha: %ld. TopoPilha: %c.\n", *tamanho, pilha[*tamanho], strlen(pilha), *topo);
    return pilha;
}


int leituraVetor(){
    
    char *pilha = NULL;
    char *topoPilha = NULL;
    
    int tamanho = 0, saida = 0;
    char caracter = ' ';

    pilha = (char*)malloc((tamanho+1)*sizeof(char));
    pilha[0] = ' ';
    topoPilha = &pilha[0];

    //printf("\n\n\n-----------NOVA LISTA-------------\n");
    while(saida != EOF){

        saida = scanf("%c", &caracter);
        //printf("Caracter: %c. TopoPilha: %c.\n", caracter, *topoPilha);
        
        if (saida == EOF) {break;}
        else if (caracter == '\r') {getchar(); break;}
        
        if (caracter != ' '){     
                           
                if (((caracter == '}') && (topoPilha[0] == '{')) ||
                    ((caracter == ']') && (topoPilha[0] == '[')) ||
                    ((caracter == ')') && (topoPilha[0] == '(')) ||
                    ((caracter == '"') && (topoPilha[0] == '"'))) {
                    //printf("Tamanho (ANTES DA FUNÇÃO): %d\n", tamanho);
                    pilha = pop(pilha, &tamanho, topoPilha);
                    //printf("Tamanho (DEPOIS DA FUNÇÃO): %d\n", tamanho);
                }
                else if ((caracter == '}' && topoPilha[0] != '{') ||
                         (caracter == ']' && topoPilha[0] != '[') ||
                         (caracter == ')' && topoPilha[0] != '(')){
                    printf("NÃO BALANCEADO");
                    //printf("(NÃO BALANCEADO) Caracter: %c. TopoPilha: %c.\n", caracter, *topoPilha);
                    
                    //printf("\n-----------------------------------------------------\n");
                    do{
                        saida = scanf("%c", &caracter);
                        printf("Eliminando: %d\n", caracter);
                        if (saida == EOF){break;}
                        //printf("Saida: %d. Eliminado: %d\n", saida, caracter);
                    }while(caracter != '\n');
                    //printf("\n-----------------------------------------------------\n");

                    free(pilha);
                    if (saida == EOF) {return EOF;}
                    else {return 5;}
                }
                else{
                    //printf("Tamanho (ANTES DA FUNÇÃO): %d\n", tamanho);
                    pilha = push(pilha, &tamanho, caracter, topoPilha);
                    //printf("Tamanho (DEPOIS DA FUNÇÃO): %d\n", tamanho);
                }
                /*
                else if ((caracter == '}' && *topoPilha != '{') ||
                         (caracter == ']' && *topoPilha != '[') ||
                         (caracter == ')' && *topoPilha != '(')){
                    printf("\nNÃO BALANCEADO");
                    while (caracter != '\n'){
                        saida = scanf("%c", &caracter);
                        if (saida == EOF){break;}
                        printf("\nEliminado: %d", caracter);
                    }
                    break;
                }
                else{
                    
                }
                */
        }

        //printf("\ntamanho da pilha: %d", tamanho);
        //printf("\ntamanho da alocacao: %ld", strlen(pilha));
        //printf("\nPilha: \n");
        //for (int contador = 0; contador < tamanho; contador++)
        //    printf("pilha[%d]= %c\n", contador, pilha[contador]);

        //printf("\n\n");
    }

    //printf("\ntamanho da pilha: %d", tamanho);
    //printf("\nPilha: \n");
      //  for (int contador = 0; contador < tamanho; contador++)
       //     printf("pilha[%d]= %c\n", contador, pilha[contador]);

    printf("BALANCEADO");

    free(pilha);
    if (saida == EOF) {return EOF;}
    else {return 0;}
}

int main(){
    int contador = 0;
    int retorno = 0;

    do{ 
        if (contador != 0){printf("\n");}
        retorno = leituraVetor();
        contador += 1;
    }while (retorno != EOF);

    return 0;
}