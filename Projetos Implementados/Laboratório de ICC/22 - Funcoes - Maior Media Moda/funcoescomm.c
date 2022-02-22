#include <stdio.h>


int maior(int vetor[10])
{

    int auxiliar = 0;
    
    if (vetor[0]> vetor[1])
    {
        auxiliar = vetor[0];
    }
    else
    {
        auxiliar = vetor[1];
    }


    for (int contagem = 2; contagem < 10; contagem++)
    {            
        if (vetor[contagem]> auxiliar)
        {
            auxiliar = vetor[contagem];
        }
    }

    return auxiliar;

}


int menor(int vetor[10])
{

    int auxiliar = 0;
    
    if (vetor[0] < vetor[1])
    {
        auxiliar = vetor[0];
    }
    else
    {
        auxiliar = vetor[1];
    }
    
    for (int contagem = 2; contagem < 10; contagem++)
    {            
        if (vetor[contagem] < auxiliar)
        {
            auxiliar = vetor[contagem];
        }
    }

    return auxiliar;


}

double media(int vetor[10])
{ 
    double auxiliar;
    auxiliar = (vetor[0]+vetor[1]+vetor[2]+vetor[3]+vetor[4]+vetor[5]+vetor[6]+vetor[7]+vetor[8]+vetor[9]);
    auxiliar = auxiliar / 10;
    return auxiliar;

}

int moda(int vetor[10])
{
    int numeroFrequente=0, maisFrequente=0, numeroAtual=0, frequenciaAtual=0;

    for (int numero=0; numero<10; numero++)
    {
        numeroAtual = vetor[numero];
        frequenciaAtual = 0;

        for (int contador =0; contador<10; contador++)
        {
            if (numeroAtual == vetor[contador])
            {
                frequenciaAtual = frequenciaAtual + 1;
            }
        }

        if (frequenciaAtual>maisFrequente)
        {
            maisFrequente = frequenciaAtual;
            numeroFrequente = numeroAtual;
        }

    }

    return numeroFrequente;


}

int main(){

    int menorNumero=0, maiorNumero=0, modaNumero=0;
    double mediaNumero=0;
    int valores[10] = {0,1,2,3,4,5,6,7,8,9};

    
    for (int numero = 0; numero < 10; numero++)
    {
        scanf(" %d", &valores[numero]);
    }

    maiorNumero = maior(valores);
    menorNumero = menor(valores);
    mediaNumero = media(valores);
    modaNumero = moda(valores);

    printf("%d %d %.2lf %d", maiorNumero, menorNumero, mediaNumero, modaNumero);


    return 0;
}
