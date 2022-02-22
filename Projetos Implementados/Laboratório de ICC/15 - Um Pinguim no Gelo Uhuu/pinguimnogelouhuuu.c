#include <stdio.h>


int main()
{
    //Cria variáveis: numero de rodadas (n), numero de jogadores (m) e posição do pingu
    float n, m, p;

    //Cria variáveis de controle
    int contador, contadorSaida, numeroPinguins, saida;

    //Faz a leitura dos valores das variáveis de numero de rodadas, numero de jogadores e posicao do pingu
    scanf("%f %f %f", &n, &m, &p);

    //Define valores padrão para variáveis de controle
    contador = 0;
    contadorSaida = 0;
    numeroPinguins = 1;
    saida = 0;


    //Loop necessário para atingir o número de rodadas, caso não seja suficiente em seu interior
   while (contador<n)
    {

      //Loop para impressão de Numero de Pinguins, de acordo com a quantidade de pinguins
      for (int i=0; i<numeroPinguins; i++)
        {
            contador = contador+1;
            saida = (p+(contadorSaida*(m)));


            if (contador == saida)
                {
                 contadorSaida = contadorSaida+1;

                 if (contador!=1)
                    {
                    printf("%d pinguins\n", numeroPinguins);
                    }
                    else
                    {
                    printf("1 pinguim\n");
                    } // Fim do IF que imprime a quantidade de pinguins

                } //Fim do IF que imprime a fala do pingu

            if (contador == n)
            {
                return 0;
            }
        }

     //Loop para impressão de no gelo, de acordo com a quantidade de pinguins
      for (int j=0; j<numeroPinguins; j++)
        {
            contador = contador+1;
            saida = (p+(contadorSaida)*(m));

            if (contador == saida)
                {
                    contadorSaida = contadorSaida + 1;
                    printf("no gelo\n");
                }

            if (contador == n)
            {
                return 0;
            }

        }

        //Loop para impressão de uhuu!! de acordo com a quantidade de pinguins
      for (int k=0; k<numeroPinguins; k++)
        {
            contador = contador+1;
            saida = (p+(contadorSaida)*(m));

            if (contador == saida)
                {
                    contadorSaida = contadorSaida + 1;
                    printf("uhuu!\n");
                }

            if (contador == n)
            {
                return 0;
            }
        }



            numeroPinguins = numeroPinguins + 1;

    } //Fim do While



    return 0;
}
