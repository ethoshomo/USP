    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>



    float** alocacaoMatriz(int altura, int largura)
    {
        float** matriz;

        matriz = (float**)malloc(altura*sizeof(float*));

        for (int colunas=0; colunas<altura; colunas++)
            matriz[colunas] = (float*)malloc(largura*sizeof(float));

        return matriz;
    }


    int main(){

    //Bloco de variáveis
    int M, controle, *ataques, tipoInimigo, tamanho, fim, maiorIndice;
    float **matriz, forcaTotal, auxiliar;

    //Estruturação e alocação de memória da matriz M
    scanf("%d", &M);
    matriz = alocacaoMatriz(M,M);


    //Preenchimento da matriz com dados fornecidos
    for (int linha = 0; linha < M; linha++)
    {
        for (int coluna = 0; coluna < M; coluna++)
        {
            scanf("%f", &matriz[linha][coluna]);
        }
    }


    //Bloco de atualização das variáveis
    auxiliar = 0;
    maiorIndice = 0;
    forcaTotal = 0;
    controle = 0;
    tamanho = 2;
    fim = 0;


    //Estruturacao da matriz ataques
    ataques = (int*)malloc(tamanho*sizeof(int));

    for(int contador = 0; contador<tamanho; contador++)
        ataques[contador] = 0;


    //Laço de repetição para fazer a leitura dos ataques e alocar na matriz ataques
    while(fim != (-1))
    {

        if (controle != 0)
        {
            tamanho += 2;
            ataques = (int*)realloc(ataques, tamanho*sizeof(int));
        }

        scanf("%d", &ataques[2*controle]); // Le a força do ataque

        if(ataques[2*controle] == (-1))
        {
            fim = -1;
            break;
        }

        scanf("%d", &ataques[2*controle+1]); // Le o indice do ataque

        controle += 1;
    }


    //Faz a leitura do tipo inimigo
    scanf("%d", &tipoInimigo);

    //Compara forças dos três ataques
    for (int contador = 0; contador<controle; contador++)
    {
       auxiliar = (matriz[ataques[2*contador+1]][tipoInimigo])*ataques[2*contador];

       if (auxiliar > forcaTotal)
       {
            maiorIndice = contador;
            forcaTotal = auxiliar;
       }
    }


    printf("O melhor ataque possui indice %d e dano %.2f\n", maiorIndice, forcaTotal);


    //Bloco de desalocação
    for (int colunas=0; colunas<M; colunas++)
        free(matriz[colunas]);

    free(matriz);
    free(ataques);

    return 0;

}
