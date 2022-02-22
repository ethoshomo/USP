#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Funcao que serve para contabilizar palavras proibidas presentes no email
//Para cada vez que é chamada, compara palavras e retorna o valor 1 se em caso positivo
int verificarPalavrasProibidas(char *palavraEmail)
{
    const char gratuito[] = "gratuito";
    const char atencao[] = "atencao";
    const char urgente[] = "urgente";
    const char imediato[] = "imediato";
    const char zoombie[] = "zoombies";
    const char oferta[] = "oferta";
    const char dinheiro[] = "dinheiro";
    const char renda[] = "renda";
    const char fundo[] = "fundo";
    const char limitado[] = "limitado";
    const char ajuda[] = "ajuda";
    const char sos[] = "SOS";
    int contador = 0;

    if (strcmp(palavraEmail, gratuito) == 0)
        contador += 1;

    if (strcmp(palavraEmail, atencao) == 0)
        contador += 1;

    if (strcmp(palavraEmail, urgente) == 0)
        contador += 1;

    if (strcmp(palavraEmail, imediato) == 0)
        contador += 1;

    if (strcmp(palavraEmail, zoombie) == 0)
        contador += 1;

    if (strcmp(palavraEmail, oferta) == 0)
        contador += 1;

    if (strcmp(palavraEmail, dinheiro) == 0)
        contador += 1;

    if (strcmp(palavraEmail, renda) == 0)
        contador += 1;

    if (strcmp(palavraEmail, fundo) == 0)
        contador += 1;

    if (strcmp(palavraEmail, limitado) == 0)
        contador += 1;

    if (strcmp(palavraEmail, ajuda) == 0)
        contador += 1;

     if (strcmp(palavraEmail, sos) == 0)
        contador += 1;

    return contador;

}


int main () {

    //Criação das variáveis utilizadas no programa
    char ch = ' ', linha[80], referencia[6] = {' ', '\n', '.', ',', ';'}, *palavra;
    int quantidadeProibidas = 0, controle = 0;

    //Limpa o vetor linha[]
    for (int numero; numero<80; numero++)
    {
        linha[numero] = ' ';
    }

    //Inicia o loop de leitura de caracter por caracter até encontrar o EOF
    while (ch != EOF)
    {

        //Estabelece critério de 76 caracters e um \n para cada linha
        if (controle < 77)
        {

            //Faz a leitura dos caracteres
            ch = getchar();

            //Verifica, antes de entrar no laço, se o caracter é o EOF.
            if(ch == EOF)
            {
                break;
            }

            //Atualiza o vetor de acordo com a variável controle
            linha[controle] = ch;

            //Caso seja encontrado o fim de linha, analisa a mensagem
            if (ch == '\n' || ch == '\r')
            {

                //Uso de ponteiro e função strtok para analisar palavras da string
                palavra = strtok(linha, referencia);

                //Inicia laço de repetição para analisar palavra por palavra do vetor linha
                //Caso sejam encontradas palavras proibidas, faz contagem reiterada.
                while(palavra != NULL)
                {
                    quantidadeProibidas = quantidadeProibidas + verificarPalavrasProibidas(palavra);
                    palavra = strtok(NULL, referencia);
                }

                //Atualiza variável de controle para continuar o laço de repetição até o EOF.
                controle = (-1);

                //Limpa o vetor linha para o próximo ciclo
                for (int numero; numero<80; numero++)
                {
                    linha[numero] = ' ';
                }
            }
        }

        else // Caso o valor do contador passe de 76 caracteres e um \n, imprime SPAM
        {
            printf("Spam");
            exit (0);
        }

        //Variável de controle é acrescida de uma unidade para o próximo laço.
        controle = controle + 1;

    }//Fim do While


    //Depois de lido o EOF, analisa se a quantidade de palavras proibidas é >= 2.
    if (quantidadeProibidas >= 2)
    {
        printf("Spam");
    }
    else
    {
        printf("Inbox");
    }

    return (0);
}
