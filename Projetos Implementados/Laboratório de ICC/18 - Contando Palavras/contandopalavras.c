#include <stdio.h>


int main () {

    //Criação das variáveis de leitura e comparação dos caraceteres: o atual (ch) e o anterior (chAnterior).
    char ch = ' ', chAnterior = ' ';

    //Criação das variáveis de contabilização dos caracteres, palavras e linhas.
    int caracter = 0, palavras = 0, linhas = 0;


    //Laço de repetição utilizado para ler caracter por caracter
    do
    {

        //Faz a leitura dos caracteres
        ch = getchar();


        //Contabiliza caracteres
        caracter = caracter + 1;


        //Analisa casos específicos e faz a contabilidade de linhas e palavras
        switch (ch)
        {

            case ' ':

                palavras = palavras + 1;
                
                if ((chAnterior == ' ') || (chAnterior == '\n') || (chAnterior == '\t') || (chAnterior == '\r'))
                {
                    palavras = palavras - 1;
                }

                break;


            case '\t':
                palavras = palavras + 1;

                if ((chAnterior == ' ') || (chAnterior == '\n') || (chAnterior == '\t') || (chAnterior == '\r'))
                {
                    palavras = palavras - 1;
                }

                break;


            case '\r':
                palavras = palavras + 1;
                linhas = linhas + 1;

                if ((chAnterior == ' ') || (chAnterior == '\n') || (chAnterior == '\t') || (chAnterior == '\r'))
                {
                    palavras = palavras - 1;
                }

                break;


            case '\n':
                
                palavras = palavras + 1;
                linhas = linhas + 1;

                if ((chAnterior == ' ') || (chAnterior == '\n') || (chAnterior == '\t'))
                {
                    palavras = palavras - 1;
                }

                if (chAnterior == '\r')
                {
                    linhas = linhas - 1;
                    palavras = palavras - 1;                    
                }
                
                break;


            case EOF: 
                
                // Descarta o EOF como um caracter
                caracter = caracter - 1; 

                //Correção de eventual falha consistente da ausência de contabilização da ultima palavra do texto em razão de falta de caracteres específicos.
                if ((chAnterior == ' ') || (chAnterior == '\n') || (chAnterior == '\t') || (chAnterior == '\r'))
                {

                }
                else
                {
                    palavras = palavras + 1;
                }

                break;

        }

        //Atualiza a variável de caracter anterior
        chAnterior = ch;

    } while (ch != EOF);


    //Imprime e saída esperada
    printf("Linhas\tPalav.\tCarac.\n");
    printf("%d\t%d\t%d", linhas, palavras, caracter);

    return (0);
}
