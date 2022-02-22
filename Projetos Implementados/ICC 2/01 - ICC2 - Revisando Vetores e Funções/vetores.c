//////////////////////////////////////////////////////////////////////////// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////// VARIÁVEIS GLOBAIS
int inteiroEntrada[100], numerosUtilizados[100], quantidadeNumerosUsados;

//////////////////////////////////////////////////////////////////////////// FUNÇÕES
//Faz a contagem de quantas vezes o número aparece na sequência e imprime a saída

void contador(int controle, int quantidadeNumerosUsados)
{
    int quantidade;

    for (int i = 0; i < quantidadeNumerosUsados; i++)
    {
        quantidade = 0;

        for (int contador = 0; contador < controle ; contador++)
        {
            if (numerosUtilizados[i] == inteiroEntrada[contador]) //Contabiliza a quantidade de repetições
            {
                quantidade += 1;
            }
        }

        printf("%d (%d)\n", numerosUtilizados[i], quantidade);
    }

}

//////////////////////////////////////////////////////////////////////////// MAIN
int main(){

    /////// Bloco de declaração de variáveis e suas inicializações.
    int controle, saida, controleQuantidadeNumerosUsados;

    for (int contador = 0; contador < 100; contador++)
    {
        inteiroEntrada[contador] = 6666;
        numerosUtilizados[contador] = 6666;
    }

    saida = 0;
    controle = 0;
    quantidadeNumerosUsados = 0;

    /////// Bloco de leitura e preparação da entrada
    /*  Além de fazer uma leitura das entradas (de forma completa), o laço de repetição
    faz uma separação da entrada em dois vetores: inteiroEntrada (todos os números,
    mesmo com repetições), numerosUtilizados (todos numeros a serem impressos, ou seja
    não há repetição de números). */

    while (saida != EOF)
    {
        saida = scanf(" %d", &inteiroEntrada[controle]);

        if (saida != EOF)
        {
            if (controle == 0)
            {
                numerosUtilizados[0] = inteiroEntrada[0];
                quantidadeNumerosUsados += 1;
            }
            else
            {
                controleQuantidadeNumerosUsados = 0;

                for(int contador = 0; contador < 100; contador++)
                {
                    if (inteiroEntrada[controle] == numerosUtilizados [contador])
                    {
                        controleQuantidadeNumerosUsados += 1;
                    }
                }

                if (controleQuantidadeNumerosUsados < 1)
                {
                    numerosUtilizados[quantidadeNumerosUsados] = inteiroEntrada[controle];
                    quantidadeNumerosUsados += 1;
                }
            }

            controle += 1;
        }
    }

    /////// Executa a função contador()
    contador(controle, quantidadeNumerosUsados);

    return 0;
}
