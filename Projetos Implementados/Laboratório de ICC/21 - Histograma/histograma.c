#include <stdio.h>

int main () {

    //Cria variáveis de controle e comparação para as cores 0, 1, 2, 3, 4
    int cor0 = 0, cor1 = 0, cor2 = 0, cor3 = 0, cor4 = 0, comparacao = 0, valorPesquisar = 0;
    int cores[25];

    //Faz a leitura e armazenamento das cores no vetor apropriado e, ao mesmo tempo, contabiliza a frequência de cada cor.
    for (int contagem=0; contagem <25; contagem++)
    {
         scanf(" %d", &cores[contagem]);

         switch (cores[contagem])
         {
            case 0:
                cor0 = cor0 + 1;
                break;
            case 1:
                cor1 = cor1 + 1;
                break;
            case 2:
                cor2 = cor2 + 1;
                break;
            case 3:
                cor3 = cor3 + 1;
                break;
            case 4:
                cor4 = cor4 + 1;
                break;
         }
    }

    //Inicia a primeira parte da impressão, mostrando a frequência de cada uma das cinco cores
    printf("0: |");

    for (int contador=0; contador<cor0; contador++)
    {
        printf("#");
    }

    printf("\n1: |");

    for (int contador=0; contador<cor1; contador++)
    {
        printf("#");
    }

    printf("\n2: |");

    for (int contador=0; contador<cor2; contador++)
    {
        printf("#");
    }

    printf("\n3: |");

    for (int contador=0; contador<cor3; contador++)
    {
        printf("#");
    }

    printf("\n4: |");

    for (int contador=0; contador<cor4; contador++)
    {
        printf("#");
    }

    //Quebra a linha para mostrar as frequências.
    printf("\n");

    //Compara as frequencias e armazena o valor a ser pesquisado no vetor cores
    if (cor0<cor1)
    {
        comparacao = cor1;
        valorPesquisar = 1;
    }
    else
    {
        comparacao = cor0;
        valorPesquisar = 0;
    }

    if (comparacao<cor2)
    {
        comparacao = cor2;
        valorPesquisar = 2;
    }

    if (comparacao<cor3)
    {
        comparacao = cor3;
        valorPesquisar = 3;
    }

    if (comparacao<cor4)
    {
        comparacao = cor4;
        valorPesquisar = 4;
    }

    //Faz uma varredura no vetor cores e identifica os indices mais frequentes, imprimindo-os
    for (int contador = 0; contador < 25; contador++)
    {
        if (cores[contador] == valorPesquisar)
        {
            printf("%d\n", contador);
        }
    }



    return (0);
}
