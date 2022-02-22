#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    //////////////////////////////////////////////////// CONSTANTES GLOBAIS
    const int tamanho = 50;

    //////////////////////////////////////////////////// FUNCAO DE PREENCHER STRINGS
    char* preencherString(char *string)
    {
        int controle = 0, tamanhoAuxiliar = tamanho, fim = 0;
        char ch;

        while (fim == 0){

            if (tamanhoAuxiliar == controle)
            {
                tamanhoAuxiliar += 2;
                string = (char*)realloc(string, tamanhoAuxiliar * sizeof(char));
            }

            ch = getchar();
            string[controle] = ch;
            controle += 1;

            if (ch == 36)
            {
                fim = 1;
            }
        }

        string[controle-1] = '\0';
        string = realloc(string, controle*sizeof(char));
        return string;
    }


    //////////////////////////////////////////////////// BLOCO DA MAIN
    int main(){


    //////////////// VARIAVEIS
    char espaco[] = {' ', '\0'}, *auxiliar = NULL, *sobrenomes = NULL, *leituraCompleta = NULL, **vetorNomes = NULL;
    int controle, tamanhoVetor;


    //////////////// ATUALIZACAO DE CONSTANTES
    tamanhoVetor=2;
    controle = 0;


    //////////////// ALOCACAO DE MEMORIA DINAMICA
    leituraCompleta = (char*)malloc(tamanho*sizeof(char)); // Leitura completa de todos os nomes
    vetorNomes = (char**)malloc(tamanhoVetor*sizeof(char*)); // Vetor que armazenará cada nome completo

    leituraCompleta = preencherString(leituraCompleta); //Faz a leitura de toda a entrada


    //////////////// BLOCO DE MANIPULAÇÃO DA LEITURA COMPLETA

    ///// Quebra a string leitura completa em strings de nomes completos
    auxiliar = strtok(leituraCompleta, "\n");
    vetorNomes[controle] = (char*)malloc(strlen(auxiliar)*sizeof(char));
    strcpy(vetorNomes[controle], auxiliar);

    while(auxiliar != NULL)
    {
        if (controle == (tamanhoVetor-1))
        {
            tamanhoVetor += 1;
            vetorNomes = (char**)realloc(vetorNomes, tamanhoVetor*sizeof(char*));
        }

        auxiliar = strtok(NULL, "\n");
        controle += 1;

        if (auxiliar==NULL)
        {
            break;
        }

        vetorNomes[controle] = (char*)malloc(strlen(auxiliar)*sizeof(char));
        strcpy(vetorNomes[controle], auxiliar);
    }


    //////////////// BLOCO DE MANIPULAÇÃO DO NOME COMPLETO
    for(int contador = 0; contador < controle; contador++)
    {
        //////////////// Imprime o nome da linha impar e coleta seu sobrenome
        if (contador%2 == 0)
        {
            printf("%s\n", vetorNomes[contador]);
            auxiliar = strtok(vetorNomes[contador], " ");
            sobrenomes = (char*)realloc(sobrenomes, (strlen(auxiliar)*sizeof(char)+1));
            strcpy(sobrenomes, auxiliar);

            while (auxiliar != NULL)
            {
                auxiliar = strtok(NULL, " ");

                if (auxiliar == NULL)
                {
                    break;
                }

                sobrenomes = (char*)realloc(sobrenomes, (strlen(auxiliar)*sizeof(char)+1));
                strcpy(sobrenomes, auxiliar);

            }
        }

        //////////////// Adiciona sobrenome coletado na linha par
        else
        {
            strcat(vetorNomes[contador], espaco);
            strcat(vetorNomes[contador], sobrenomes);
            printf("%s\n", vetorNomes[contador]);
        }

    }

    //////////////// BLOCO DE LIBERAÇÃO DE MEMÓRIA
    for (int contador = 0; contador < controle; contador++)
        free(vetorNomes[contador]);

    free(sobrenomes);
    free(leituraCompleta);

    return 0;

    }