#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Criação das variáveis utilizadas no programa
    char planeta[10];
    unsigned long long int *tempoSegundos, dias = 0, horas = 0, minutos = 0, segundos = 0, tempo = 0;
    const unsigned long long int diaTerra = 24*3600;
    const unsigned long long int diaVenus = 243*diaTerra;
    const unsigned long long int diaMercurio = 58*diaTerra + 16*3600;
    const unsigned long long int diaJupiter = 9*3600 + 56*60;


//Funcao que serve para contabilizar os dias, horas, minutos e segundos
int contabilizarTempo(unsigned long long int *tempoSegundosFuncao, char *nomePlaneta)
{
    const char terra[] = "Terra";
    const char venus[] = "Venus";
    const char mercurio[] = "Mercurio";
    const char jupiter[] = "Jupiter";


    if (strcmp(nomePlaneta, terra) == 0)
    {
        dias = (*tempoSegundosFuncao)/(diaTerra);
        horas = (*tempoSegundosFuncao%diaTerra)/(3600);
        minutos = ((*tempoSegundosFuncao % diaTerra)%3600)/60;
        segundos = (((*tempoSegundosFuncao % diaTerra)%3600)%60);

    }

    if (strcmp(nomePlaneta, venus) == 0)
    {
         dias = (*tempoSegundosFuncao)/(diaVenus);
        horas = (*tempoSegundosFuncao%diaVenus)/(3600);
        minutos = ((*tempoSegundosFuncao % diaVenus)%3600)/60;
        segundos = (((*tempoSegundosFuncao % diaVenus)%3600)%60);

    }

    if (strcmp(nomePlaneta, mercurio) == 0)
    {
         dias = (*tempoSegundosFuncao)/(diaMercurio);
        horas = (*tempoSegundosFuncao%diaMercurio)/(3600);
        minutos = ((*tempoSegundosFuncao % diaMercurio)%3600)/60;
        segundos = (((*tempoSegundosFuncao % diaMercurio)%3600)%60);
    }

    if (strcmp(nomePlaneta, jupiter) == 0)
    {
         dias = (*tempoSegundosFuncao)/(diaJupiter);
        horas = (*tempoSegundosFuncao%diaJupiter)/(3600);
        minutos = ((*tempoSegundosFuncao % diaJupiter)%3600)/60;
        segundos = (((*tempoSegundosFuncao % diaJupiter)%3600)%60);

    }

    return 0;

}


int main () {

    //Limpa o vetor planeta[]
    for (int numero; numero<10; numero++)
    {
        planeta[numero] = ' ';
    }

    //Faz a leitura da entrada: tempo em segundos e nome do planeta
    scanf("%llu %s", &tempo, planeta);

    //Inicia ponteiro para transferir o valor por referência
    tempoSegundos = &tempo;

    //Inicia a função que vai contabilizar o tempo
    contabilizarTempo(tempoSegundos, planeta);

    //Imprime a saída de acordo com as instruções do exercício
    printf("%llu segundos no planeta %s equivalem a:\n", tempo, planeta);
    printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n", dias, horas, minutos, segundos);

    return (0);
}
