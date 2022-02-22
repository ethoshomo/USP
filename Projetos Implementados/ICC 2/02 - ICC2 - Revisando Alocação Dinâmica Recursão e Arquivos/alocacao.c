#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


char* preencherString();
char** alocaMatriz(int linhas, int colunas);
void percorrerLabirinto(char** matriz, int x, int y, int linhas, int colunas, int *terminou);


int main()
{
    
    char *nomeArquivo = NULL;
    char **labirinto = NULL;
    FILE *ponteiro = NULL;

    int linhas = 0, colunas = 0, posicaoX = 0, posicaoY = 0;
    int numeroPessoas = 0, caminhos = 0, visitados = 0, terminou = 0;
    double percentualExploracao = 0;

    char caracter = ' ';

    nomeArquivo = preencherString();

    ponteiro = fopen(nomeArquivo, "r");
    
    if (ponteiro != NULL)
    {
        fscanf(ponteiro, "%d %d", &linhas, &colunas);
        fgetc(ponteiro); //Descarta o \n
        labirinto = alocaMatriz(linhas, colunas);

        fscanf(ponteiro, "%d %d", &posicaoX, &posicaoY);
        fgetc(ponteiro); //Descarta o \n

        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                caracter = fgetc(ponteiro);
                labirinto[i][j] = caracter;

                switch(caracter)
                {
                    case '#':
                        numeroPessoas += 1;
                        break;
                    case '.':
                        caminhos += 1;
                        break;
                    default:
                        break;
                }
            }
            
            if (i != linhas) // Última linha não tem \n
                fgetc(ponteiro); //Descarta o \n
        }

        percorrerLabirinto(labirinto, posicaoX, posicaoY, linhas, colunas, &terminou);

        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                printf("%c", labirinto[i][j]);
                if (labirinto[i][j] == '*')
                    visitados += 1;
            }
            printf("\n");
        }
        
        percentualExploracao = floor((((double)visitados / (double)caminhos) * 100));

        printf("\nVoce escapou de todos! Ninguem conseguiu te segurar!\n");
        printf("Veja abaixo os detalhes da sua fuga:\n");
        printf("----Pessoas te procurando: %d\n", numeroPessoas);
        printf("----Numero total de caminhos validos:   %d\n", caminhos);
        printf("----Numero total de caminhos visitados: %d\n", visitados);
        printf("----Exploracao total do labirinto: %.1f%%\n", percentualExploracao);
        
    }
    else
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    
    fclose(ponteiro);   
    
    for (int contador = 0; contador < linhas; contador++)
        free(labirinto[contador]); 

    free(labirinto);

    free(nomeArquivo);


    return 0;
}


char* preencherString()
{
    char *string = NULL;
    int controle = 0, saida = 0;
    char ch = ' ';

    do
    {
        controle += 1;
        string = (char*)realloc(string, controle);
        saida = scanf("%c", &ch);
        string[controle-1] = ch;

    } while (saida != EOF);

    string[controle-1] = '\0';

    return string;
}


char** alocaMatriz(int linhas, int colunas)
{
    char **matriz = NULL;

    matriz = (char**)malloc(linhas*sizeof(char*));
    for (int contador = 0; contador < linhas; contador++)
        matriz[contador] = (char*)malloc(colunas*sizeof(char));
    
    return matriz;
}

void percorrerLabirinto(char** matriz, int x, int y, int linhas, int colunas, int *terminou)
{
    matriz[x][y] = '*';

    if ((y-1 < 0) || (y+1 > colunas-1) || (x+1 > linhas-1) || ( x-1 < 0) ||
        (y < 0) || (y > colunas-1) || (x>linhas-1) || (x<0)){*terminou = 1; return; }
    if ((matriz[x-1][y] == '.') && (!*terminou)) {percorrerLabirinto(matriz, x-1, y, linhas, colunas, terminou);}
    if ((matriz[x][y+1] == '.') && (!*terminou)) {percorrerLabirinto(matriz, x, y+1, linhas, colunas, terminou);}
    if ((matriz[x+1][y] == '.') && (!*terminou)) {percorrerLabirinto(matriz, x+1, y, linhas, colunas, terminou);}
    if ((matriz[x][y-1] == '.') && (!*terminou)) {percorrerLabirinto(matriz, x, y-1, linhas, colunas, terminou);}

    return;
}