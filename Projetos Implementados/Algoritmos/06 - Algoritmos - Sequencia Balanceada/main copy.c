
#include <stdio.h>
#include <stdlib.h>

char *push(char *pilha, int *tamanho, char caracter){
    pilha = (char*)realloc(pilha, (*tamanho+1)*sizeof(char));
    pilha[*tamanho] = caracter;
    printf("PUSH! Caracter: %c", caracter);
    *tamanho += 1;
    return pilha;
}

char *pop (char *pilha, int *tamanho){
    printf("POP! Caracter: %c", pilha[*tamanho-1]);
    *tamanho -= 1;
    pilha = (char*)realloc(pilha, (*tamanho)*sizeof(char));
    return pilha;
}

int leituraVetor(){
    char *topoPilha = NULL;
    char *pilha = NULL;
    int tamanho = 0, saida = 0;
    char caracter = ' ';

    pilha = (char*)realloc(pilha, (tamanho+1)*sizeof(char));
    printf("\n---------------------------------------------------------------\n");
    printf("INICIO DE UMA NOVA PILHA\n");
    do{
        saida = scanf(" %c", &caracter);
        printf("Caracter: %c \n", caracter);
        if (topoPilha != NULL){printf("*topoPilha: %c\n", *topoPilha);}
        if ((saida == EOF) && (tamanho == 0)) {
            getchar();
             printf("\n---------------------------------------------------------------\n");
            printf("(EOF) BALANCEADO");
             printf("\n---------------------------------------------------------------\n");
            free(pilha);
            return 1;
        }
        else if (saida == EOF){
            getchar();
            printf("\n---------------------------------------------------------------\n");
            printf("(EOF) NÃO BALANCEADO");
            printf("\n---------------------------------------------------------------\n");
            free(pilha);
            return 1;
        }
        /*else if ((tamanho == 0) && ((caracter == '\r') || (caracter == '\n'))) {
            printf("BALANCEADO");
            free(pilha);
            return 0;
        }*/
            
        if (caracter == '"'){

            pilha = push(pilha, &tamanho, caracter);
            topoPilha = &pilha[tamanho-1];

            if ((*topoPilha == *(topoPilha-1)) && (*topoPilha == '"')){  
                pilha = pop(pilha, &tamanho);
                if (tamanho > 0) {topoPilha = &pilha[tamanho-1];}
                pilha = pop(pilha, &tamanho);
                if (tamanho > 0) {topoPilha = &pilha[tamanho-1];}
            }
        }
        else if ((caracter == '}' && *topoPilha == '{') ||
            (caracter == ']' && *topoPilha == '[') ||
            (caracter == ')' && *topoPilha == '(')){
            pilha = pop(pilha, &tamanho);
            if (tamanho > 0) {topoPilha = &pilha[tamanho-1];}

            //printf("*topoPilha (POP): %c Indice(POP): %d", *topoPilha, tamanho);
        }            
        else if ((caracter == '}' && *topoPilha != '{') ||
            (caracter == ']' && *topoPilha != '[') ||
            (caracter == ')' && *topoPilha != '(')){
            printf("Caracter: %c *topoPilha: %c\n", caracter, *topoPilha);
            printf("NÃO BALANCEADO");
            printf("\n---------------------------------------------------------------\n");
            while (caracter != '\n'){
                caracter = getchar(); 
                printf("Eliminando: %d\n", caracter);
            }
            printf("\n---------------------------------------------------------------\n");
            free(pilha);
            return 0;
        } 
        else{
            pilha = push(pilha, &tamanho, caracter);
            topoPilha = &pilha[tamanho-1];
            //printf("\n*topoPilha (PUSH): %c", *topoPilha);
        }
        printf("\ntamanho da pilha: %d", tamanho);
        //printf("\nPilha: \n");
        //for (int contador = 0; contador < tamanho; contador++)
        //    printf("pilha[%d]= %c\n", contador, pilha[contador]);
        
        printf("\n\n");
    }while (caracter);// || (caracter != '\r') || (caracter != '\n'));

    return 0;
}

int main(){
    int retorno = 0;
    int contador = 0;
    
    do{ 
        if (contador != 0){printf("\n");}
        retorno = leituraVetor();
        contador += 1;
    }while (retorno != 1);

    return 0;
}