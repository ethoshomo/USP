#include <stdio.h>


int main()
{
    //Cria o vetor que representar� as posi��es do jogo da velha
    char jogo[9];

    //Cria a vari�vel andamento
    int andamento=0;

    //Faz a leitura das tr�s linhas do jogo da velha
    for (int i=0; i<3; i++) //Primeira linha
    {
        scanf(" %c", &jogo[i]);
    }

    for (int i=3; i<6; i++) //Segunda linha
    {
        scanf(" %c", &jogo[i]);
    }

    for (int i=6; i<9; i++) //Terceira linha
    {
        scanf(" %c", &jogo[i]);
    }


    //Verifica se o jogo est� em andamento
    for (int i=0; i<9; i++)
        {

            if (jogo[i]== '-')
            andamento = andamento+1;

        }


    // Condicional que verifica sistemativamente: vitorias em linhas, depois colunas, depois diagonais, descartando caracteres "-"
    // Caso n�o seja constatada a vit�ria, verifica se n�o h� hifen (sinal de que h� jogadas a serem feitas).
    // Caso n�o seja constatada vit�ria, nem fim do jogo, h� empate.

    if ((jogo[0] == jogo[1]) && (jogo[1] == jogo[2]) && (jogo[0] != '-'))       //Primeira linha
    {
            printf("%c ganhou", jogo[0]);
    }

    else if ((jogo[3] == jogo[4]) && (jogo[4] == jogo[5]) && (jogo[3] != '-'))  //Segunda linha
    {
            printf("%c ganhou", jogo[3]);
    }

    else if ((jogo[6] == jogo[7]) && (jogo[7] == jogo[8]) && (jogo[6] != '-'))  //Terceira linha
    {
            printf("%c ganhou", jogo[6]);
    }

    else if ((jogo[0] == jogo[3]) && (jogo[3] == jogo[6]) && (jogo[0] != '-'))  //Primeira coluna
    {
            printf("%c ganhou", jogo[0]);
    }

    else if ((jogo[1] == jogo[4]) && (jogo[4] == jogo[7]) && (jogo[1] != '-'))  //Segunda coluna
    {
            printf("%c ganhou", jogo[1]);
    }

    else if ((jogo[2] == jogo[5]) && (jogo[5] == jogo[8]) && (jogo[2] != '-'))  //Terceira coluna
    {
            printf("%c ganhou", jogo[2]);
    }

    else if ((jogo[0] == jogo[4]) && (jogo[4] == jogo[8]) && (jogo[0] != '-'))  //Primeira diagonal
    {
            printf("%c ganhou", jogo[0]);
    }

    else if ((jogo[2] == jogo[4]) && (jogo[4] == jogo[6]) && (jogo[2] != '-'))  // Segunda diagonal
    {
            printf("%c ganhou", jogo[2]);
    }

    else if (andamento != 0)
    {
        printf("em jogo");
        return 0;
    }

    else
    {
            printf("empate");
            return 0;
    }


    return 0;
}
