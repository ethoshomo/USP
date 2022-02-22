    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>


    int main(){

    //Bloco de variáveis
    int largura, altura, borda;
    int* matriz;

    //Leitura das variáveis e criação de matriz correspondente
    scanf("%d", &largura);
    scanf("%d", &altura);


    //Bloco de alocação de tamanho suficiente para receber a matriz
    matriz = (int*)malloc(largura*altura*sizeof(int));



    //Preenchimento da matriz com dados fornecidos
    for (int linha = 0; linha < altura; linha++)
    {
        for (int coluna = 0; coluna < largura; coluna++)
        {
            scanf(" %d", &matriz[(linha*largura)+coluna]);
        }
    }

    //Leitura do tamanho da borda
    scanf("%d", &borda);


    //Bloco de saída de dados dividido em três partes (borda superior, intermediária e borda inferior).

    //Porção superior com zero.
    for (int zeroLinha = 0; zeroLinha < borda; zeroLinha++)
    {
        for (int zeroColuna = 0; zeroColuna < (largura+2*borda); zeroColuna++)
        {
            printf("0 ");
        }
        printf("\n");
    }

    //Porção intermediária
    for (int linha = 0; linha < altura; linha++)
    {

        //Impressão dos zeros
        for (int zero = 0; zero< borda; zero++)
        {
            printf("0 ");
        }

        //Impressão da linha
        for (int coluna = 0; coluna < largura; coluna++)
        {
            printf("%d ", matriz[(linha*largura)+coluna]);
        }

        //Impressão dos zeros
        for (int zero = 0; zero < borda; zero++)
        {
            printf("0 ");
        }
        printf("\n");
    }

    //Borda inferior
    for (int zeroLinha = 0; zeroLinha < borda; zeroLinha++)
    {
        for (int zeroColuna = 0; zeroColuna < (largura+2*borda); zeroColuna++)
        {
            printf("0 ");
        }
        printf("\n");
    }

    //Espaço exigido pelo programa
    printf("\n");


    //Impressão da matriz original
    for (int linha = 0; linha < altura; linha++)
    {
        for (int coluna = 0; coluna < largura; coluna++)
        {
            printf("%d ", matriz[(linha*largura)+coluna]);
        }
        printf("\n");
    }

    //Desdobra linhas em vetor de colunas
    free(matriz);

    return 0;

}
