#include <stdio.h>
#include <stdlib.h>


/////////////////////////////////////////////////VARIAVEIS GLOBAIS////////////////////////////
char** tabuleiro = NULL;
char** copia = NULL;
int m = 0, n = 0;


/////////////////////////////////////////////////FUNCOES//////////////////////////////////////
/* Abaixo temos as seguintes funções:

- int contabilizaCelula(): analisa celula.
- void copiaTabuleiro(): faz uma copia da matriz tabuleiro para fazer calculos de quantidade de vizinhos.
- char analiseVizinhos(): analisa a quantidade de vizinhos. Retorno vai para vizinhanca Moore ou Neumann.
- char vizinhancaMoore(): calcula a quantidade de vizinhos tipo Moore. Retorno vai para geraçoes.
- char vizinhancaNeumann(): calcula a quantidade de vizinhos tipo Neumann. Retorno vai para gerações.
- void geracoes(): atualiza as posições da matriz tabuleiro (de acordo com a vizinhanca).
- void imprimir(): imprime a matriz dinâmica tabuleiro.

*/

int contabilizaCelula(int linha, int coluna)
{
    int quantidadeVivos = 0;

    if (copia[linha][coluna] == 'x')
        quantidadeVivos += 1;

    return quantidadeVivos;
}


void copiaTabuleiro()
{
    for (int linhas = 0; linhas < m; linhas++)
       for (int colunas = 0; colunas < n+1; colunas++)
          copia[linhas][colunas] = tabuleiro[linhas][colunas];
}



char analiseVizinhos (char tipo, int quantidadeVizinhos)
{
    char morre = '.';
    char vive = 'x';
    char nasce = 'x';

    switch(tipo)
    {
        case 'x':

            if (quantidadeVizinhos < 2)
            {
                return morre;
            }
            else if ((quantidadeVizinhos == 2) || (quantidadeVizinhos == 3))
            {
                return vive;
            }
            else
            {
                return morre;
            }
            break;


        case '.':

            if (quantidadeVizinhos == 3)
            {
                return nasce;
            }
            else
            {
                return morre;
            }


        default:
            printf("Opcao invalida.");
            break;
    }

    return morre;
}



char vizinhancaMoore(char celula, int linha, int coluna)
{
    /*A vizinhanca de Moore analisa celulas adjacentes. Por isso, é mais complexa porque
      a analise de vizinhança acontece de modo "esférico" (tipo mapa de Karnaugh).

      Observação: os índices abaixo foram ajustados para se ajustar à tabela.
    */

    int quantidadeVivos = 0;


    if (linha==0 && coluna==0)
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-1);
    }

    else if ((linha==0) && (coluna==(n-1)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-1);
    }

    else if ((linha==(m-1)) && coluna==0)
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-1);
    }

    else if ((linha==(m-1)) && (coluna==(n-1)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-2);
    }

    else if ((linha==0) && ((coluna>0) && (coluna<(n-1))))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, coluna-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, coluna+1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, coluna-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, coluna+1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, coluna-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, coluna+1);
    }

    else if ((linha==(m-1)) && ((coluna>0) && (coluna<(n-1))))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, coluna-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, coluna+1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, coluna-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, coluna+1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, coluna-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, coluna+1);
    }

    else if (((linha<(m-1)) && (linha>0)) && (coluna==0))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-1, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+1, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-1, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+1, n-1);
    }

    else if (((linha<(m-1)) && (linha>0)) && (coluna==(n-1)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-1, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+1, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-1, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+1, n-1);
    }

    else
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-1, coluna-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-1, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-1, coluna+1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, coluna-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, coluna+1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+1, coluna-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+1, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+1, coluna+1);
    }

    return analiseVizinhos(celula, quantidadeVivos);

}

char vizinhancaNeumann(char celula, int linha, int coluna)
{
    /* A vizinhança Neumann analisa a linha e a coluna da celula de referência.
       Todas celulas, exceto a de referência, devem ser contabilizadas como vivas.*/


    int quantidadeVivos = 0;

    if (linha==0 && coluna==0)
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(2, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 0);
    }

    else if ((linha==0) && (coluna==1))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 3);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(2, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 1);
    }


    else if ((linha==0) && (coluna==(n-2)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-4);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-3);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(2, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-2);
    }

    else if ((linha==0) && (coluna==(n-1)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-3);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(2, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-1);
    }

    else if (linha==1 && coluna==0)
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(2, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(3, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, 2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, n-1);
    }

    else if ((linha==1) && (coluna==1))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(2, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(3, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(2, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(2, 2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(2, 3);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(2, n-1);
    }

    else if ((linha==1) && (coluna==(n-2)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, n-3);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, n-4);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(2, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(3, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-2);
    }

    else if ((linha==1) && (coluna==(n-1)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, n-3);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(2, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(3, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-1);
    }

    else if ((linha==(m-2)) && (coluna==(0)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-3, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-4, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, 2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, n-2);
    }

    else if ((linha==(m-2)) && (coluna==(1)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-3, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-4, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, 2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, 3);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, n-1);
    }

    else if ((linha==(m-2)) && (coluna==(n-2)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-3, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-4, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, n-3);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, n-4);
    }

    else if ((linha==(m-2)) && (coluna==(n-1)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, n-3);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-4, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-3, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-1);
    }

    else if ((linha==(m-1)) && (coluna==(1)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-3, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 3);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-1);
    }

    else if ((linha==(m-1)) && (coluna==(n-2)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-3, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-3);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-4);
    }

    else if ((linha==(m-1)) && coluna==0)
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-3, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-2);
    }

    else if ((linha==(m-1)) && (coluna==(n-1)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-3, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, n-3);
    }

    else if ((linha==0) && ((coluna>1) && (coluna<(n-2))))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, coluna-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, coluna-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, coluna+1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, coluna+2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(2, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, coluna);
    }


    else if ((linha==1) && ((coluna>1) && (coluna<(n-2))))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, coluna-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, coluna-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, coluna+1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, coluna+2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(2, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(3, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, coluna);
    }

    else if ((linha==(m-2)) && ((coluna>1) && (coluna<(n-2))))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, coluna-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, coluna-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, coluna+1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, coluna+2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-4, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-3, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, coluna);
    }

    else if ((linha==(m-1)) && ((coluna>1) && (coluna<(n-2))))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, coluna-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, coluna-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, coluna+1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-1, coluna+2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(0, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-2, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(m-3, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(1, coluna);
    }

    else if (((linha<(m-2)) && (linha>(1))) && (coluna==(1)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, 2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, 3);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-2, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-1, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+1, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+2, coluna);
    }

    else if (((linha<(m-2)) && (linha>(1))) && (coluna==(0)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, 2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-2, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-1, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+1, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+2, coluna);
    }

    else if (((linha<(m-2)) && (linha>(1))) && (coluna==(n-1)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, 1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, n-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, n-3);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-2, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-1, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+1, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+2, coluna);
    }

    else if (((linha<(m-2)) && (linha>(1))) && (coluna==(n-2)))
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, 0);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, n-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, n-3);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, n-4);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-2, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-1, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+1, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+2, coluna);
    }


    else
    {
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-1, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha-2, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+1, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha+2, coluna);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, coluna-2);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, coluna-1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, coluna+1);
        quantidadeVivos = quantidadeVivos + contabilizaCelula(linha, coluna+2);
    }

    return analiseVizinhos(celula, quantidadeVivos);

}


void geracoes(char tipoGeracao)
{
    switch(tipoGeracao)
    {
        case 'M':
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    tabuleiro[i][j] = vizinhancaMoore(copia[i][j], i, j);
            break;


        case 'N':
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    tabuleiro[i][j] = vizinhancaNeumann(copia[i][j], i, j);
            break;

        default:
            printf("Opcao invalida.");
            break;
    }

}



void imprimir(int linhasF, int colunasF)
{
    for (int linhas = 0; linhas < linhasF; linhas++)
    {
       for (int colunas = 0; colunas < colunasF; colunas++)
       {
          printf("%c", tabuleiro[linhas][colunas]);
       }
       printf("\n");
    }
}


/////////////////////////////////////////////////FUNCAO MAIN//////////////////////////////////
int main()
{
    //////////////////////// Bloco de variáveis de escopo local e seu preenchimento
    int p = 0, contador = 0;
    char v = ' ';

    scanf("%d %d", &m, &n);
    if ((m == 0) || ( v == 0))
    {
        printf("Dados de entrada apresentam erro.\n");
        return 0;
    }


    scanf("%d", &p);
    getchar(); //Despreza o \n
    if (p<=0)
    {
        printf("Dados de entrada apresentam erro.\n");
        return 0;
    }


    scanf("%c", &v);
    getchar(); //Despreza o \n
    if ((v != 'M') && ( v != 'N'))
    {
        printf("Dados de entrada apresentam erro.\n");
        return 0;
    }


    //////////////////////// BLOCO DE CRIAÇÃO E MANIPULAÇÃO DAS MATRIZES DINÂMICAS.

    //MATRIZ TABULEIRO DE GERAÇÕES

    //Aloca quantidade de linhas lidas.
    tabuleiro = (char**)malloc((m)*sizeof(char*));

    //Aloca quantidade de colunas referenciadas pelas linhas
    for (int contador = 0; contador < m; contador++)
       tabuleiro[contador] = (char*)malloc((n+1)*sizeof(char)); // +1 = inclui o \n

    //Preenche matriz
    for (int linhas = 0; linhas < m; linhas++)
       for (int colunas = 0; colunas < n+1; colunas++)
          tabuleiro[linhas][colunas] = getchar();


    //MATRIZ COPIA DA TABULEIRO

    //Aloca quantidade de linhas lidas.
    copia = (char**)malloc((m)*sizeof(char*));

    //Aloca quantidade de colunas referenciadas pelas linhas
    for (int contador = 0; contador < m; contador++)
       copia[contador] = (char*)malloc((n+1)*sizeof(char)); // +1 = inclui o \n

    //////////////////////// Preenchimento da matriz
    copiaTabuleiro();



    //Laço de repetição para atualizar gerações
    contador = 0;
    while (contador < p)
    {
        geracoes(v);
        copiaTabuleiro();
        contador += 1;
    }

    imprimir(m, n);

    //////////////////////// BLOCO DE DESALOCAÇÃO DAS MATRIZES DINÂMICAS.
    for (int contador = 0; contador < m; contador++)
       free (tabuleiro[contador]);

    for (int contador = 0; contador < m; contador++)
       free (copia[contador]);

    free (tabuleiro);
    free (copia);


    return 0;
}
