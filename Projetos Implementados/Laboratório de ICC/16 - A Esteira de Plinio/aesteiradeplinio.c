#include <stdio.h>


int main(){

    //Vari�veis de posicionamento na matriz e de controle de loop.
    int posicaoLinha=0, posicaoColuna=0, fim;
    char caracterLoopanterior, fabrica[32][65];



    //Faz a leitura da matriz
    for (int i=0; i<32; i++)
    {
        for (int j=0; j<65; j++)
        {
            scanf("%c", &fabrica[i][j]);
            
        }
    }


    //Procura a posi��o inicial ("[") da esteira.
    for (int i=0; i<32; i++)
    {
        for (int j=0; j<65; j++)
        {
            if (fabrica[i][j] == '[')
            {
                posicaoLinha = i;
                posicaoColuna = j+2;
            }
        }
    }



    //Inicia um la�o de repeti��o para percorrer a Matriz nas posi��es de linha e coluna indicadas pelas vari�veis.
    fim = 0;

    do
    {
        
        switch(fabrica[posicaoLinha][posicaoColuna])
        {
        //Verifica se o while deve ser finalizado em alguma situa��o limite.
        case ']': 
            printf("Ok.\n");
            fim = 1;
            break;


        case '.':
            printf("Loop infinito.\n");
            fim = 1;
            break;


        case ' ':     
            printf("Falha na esteira.\n");
            fim = 1;
            break;



        //"Ajusta vari�veis" e "indica o pr�ximo passo".
        case '>':
            fabrica[posicaoLinha][posicaoColuna] = '.';
            caracterLoopanterior = '>';
            posicaoColuna = posicaoColuna + 2;
            break;
        

        case '<':     
            fabrica[posicaoLinha][posicaoColuna] = '.';
            caracterLoopanterior = '<';
            posicaoColuna = posicaoColuna - 2;
            break;


        case '^':     
            fabrica[posicaoLinha][posicaoColuna] = '.';
            caracterLoopanterior = '^';
            posicaoLinha = posicaoLinha - 1;
            break;

        
        case 'v':     
            fabrica[posicaoLinha][posicaoColuna] = '.';
            caracterLoopanterior = 'v';
            posicaoLinha = posicaoLinha + 1; 
            break;
        

        case '#':     
            if (caracterLoopanterior == '>')
            {
                posicaoColuna = posicaoColuna + 2;
            }
        
            if (caracterLoopanterior == '<')
            {
                posicaoColuna = posicaoColuna - 2;
            }

            if (caracterLoopanterior == '^')
            {
                posicaoLinha = posicaoLinha - 1;
            }

            if (caracterLoopanterior == 'v')
            {
                posicaoLinha = posicaoLinha + 1;
            }

            break;


        default:
            fim=1;
            break;

        
        }//Fim do switch
    
    } while (fim == 0); //Fim do Do

    //Imprime a matriz
    for (int i=0; i<32; i++)
    {
         for (int j=0; j<65; j++)
         {
             printf("%c", fabrica[i][j]);
         }
    }

    return 0;
}
