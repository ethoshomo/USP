//////////////////////////////////////////////// BIBLIOTECA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////////////////////////////////////////////// DECLARACAO DE FUNÇÕES
char* lerFrase(int tamanhoTabu);

//////////////////////////////////////////////// VARIAVEIS GLOBAIS
char tabu[20];
int quantidadeVezes;

////////////////////////////////////////////////  FUNCAO MAIN
int main()
{

    //////////////////// Variaveis de escopo local
    char *frase = NULL;


    //////////////////// Faz a leitura e impressao da palavra tabu e frase
    scanf("%20s\n", tabu);
    frase = lerFrase(strlen(tabu));
    printf("A palavra tabu foi encontrada %d vezes\n", quantidadeVezes);
    printf("Frase: %s", frase);


    //////////////////// Promove a desalocação da memória HEAP.
    free(frase);
    return 0;

}

/*
    A funcao abaixo faz a leitura da frase e, ao mesmo tempo, contabiliza
    a quantidade de vezes que a palavra tabu foi encontrada. Alem disso,
    retira a palavra deslocando o caracter \0 do fim para o ponto em que
    ela iniciou.

*/
char* lerFrase(int tamanhoTabu)
{
    char *frase = NULL;
    char *apontador = NULL;
    int controle = 0, tamanho = 2, retorno = 0;
    char ch = ' ';

    frase = (char*) malloc(tamanho*sizeof(char));

    do
    {
        if (tamanho == (controle+2))
        {
            tamanho += 2;
            frase = (char*)realloc(frase, tamanho);
            frase[tamanho-1] = '\0';
        }

        if (controle < tamanhoTabu)
        {
            ch = getchar();
            frase[controle] = ch;
            controle += 1;
        }
        else if (controle >= tamanhoTabu)
        {
            apontador = &frase[controle-tamanhoTabu];
            retorno = strncmp (tabu, apontador, tamanhoTabu*sizeof(char));

            if (retorno == 0)
            {
                quantidadeVezes += 1;
                *apontador = '\0';
                controle -= tamanhoTabu;
            }

            ch = getchar();
            frase[controle] = ch;
            controle += 1;
        }

    } while (ch != '$');

    frase[controle-1] = '\0';
    return (frase);

}

