#include <stdio.h>
#include <ctype.h>



int main()
{
    //Cria vetores que irão representar os rotores
    int rotor1[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    int rotor2[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    int rotor3[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

    //Cria variáveis que farão o controle e a decodificação da mensagem caracter a caracter
    int controleRotor1 = 0, controleRotor2 = 0, controleRotor3 = 0, caracterC = 0, indice = 0, auxiliar=0, conversor = 0;
    char caracter = ' ', resultado = ' ';


    // Ignora tudo até o final da linha. Nesse caso, ignora "Rotores:"
    scanf("%*[^\r\n]s");

    //Faz a leitura do primeiro rotor
    for (int contador = 0; contador < 26; contador++)
    {
        scanf(" %d", &rotor1[contador]);
    }

    // Ignora o pula linha.
    scanf("%*[\r\n]s");

    //Faz a leitura do segundo rotor
    for (int contador = 0; contador <26; contador++)
    {
        scanf(" %d", &rotor2[contador]);
    }

    // Ignora o pula linha.
    scanf("%*[\r\n]s");

    //Faz a leitura do terceiro rotor
    for (int contador = 0; contador<26; contador++)
    {
        scanf(" %d", &rotor3[contador]);
    }

    // Ignora o pula linha.
    scanf("%*[\r\n]s");

    // Ignora tudo até o pula linha. Nesse caso, "Mensagem:"
    scanf("%*[^\r\n]s");

    // Ignora o pula linha.
    scanf("%*[\r\n]s");
    
    //Faz a leitura caracter por caracter da mensagem e processa dados
    while (caracter != EOF){

        caracter = getchar();

        if (caracter == EOF)
        {
            return 0;
        }

        caracterC = (int)caracter;

        
        if ((caracterC>=65) && (caracterC<=90))
        {
            indice = caracterC-65;
            conversor = rotor3[rotor2[rotor1[indice]]] + 65; 
            resultado = (char)conversor;
            printf("%c", resultado);
        }
        
        else if ((caracterC>=97) && (caracterC<=122))
        {
            indice = caracterC-97;
            conversor = rotor3[rotor2[rotor1[indice]]] + 97;
            resultado =  (char)conversor;
            printf("%c", resultado);
        }
        
        else
        {
            printf("%c", caracter);
        }
        

        //Coordena as rotações dos rotores
        if (((caracterC>=65) && (caracterC<=90)) || ((caracterC>=97) && (caracterC<=122)))
        {
            //Rotor 1
            controleRotor1 = controleRotor1 + 1;

            for (int contador = 0; contador<26; contador++)
            {
                
                if (contador == 0)
                {
                    auxiliar = rotor1[0];
                    rotor1[0] = rotor1[1];
                }
                else if (contador == 25)
                {
                    rotor1[25] = auxiliar;
                }
                else
                {
                    rotor1[contador] = rotor1[contador+1];
                }

            }

            // Rotor 2
            if (controleRotor1 == 26)
            {
                controleRotor1 = 0;
                controleRotor2 = controleRotor2 + 1;

                for (int contador=0; contador<26; contador++)
                {

                    if (contador == 0)
                    {
                        auxiliar = rotor2[0];
                        rotor2[0] = rotor2[1];
                    }
                    else if (contador == 25)
                    {
                        rotor2[25] = auxiliar;
                    }
                    else
                    {
                        rotor2[contador] = rotor2[contador+1];
                    }
                }
            }

            //Rotor 3
            if (controleRotor2 == 26)
            {

                controleRotor2 = 0;
                controleRotor3 = controleRotor3 + 1;

                for (int contador=0; contador<26; contador++)
                {

                    if (contador == 0)
                    {
                        auxiliar = rotor3[0];
                        rotor3[0] = rotor3[1];
                    }
                    else if (contador == 25)
                    {
                        rotor3[25] = auxiliar;
                    }
                    else
                    {
                        rotor3[contador] = rotor3[contador+1];
                    }

                }

            }
        }

    } 

    return 0;
}
