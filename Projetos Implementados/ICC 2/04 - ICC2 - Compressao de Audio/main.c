/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*       SCC0201 - Introdução a Ciência da Computação II       *
*               Trabalho 2 - Compressão de Audio              *
*               Carlos Filipe de Castro Lemos                 *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <string.h>
#include "compressao.h"

int main(){

    ///////////////////////////////////// BLOCO DE DECLARAÇÃO DE VARIÁVEIS
    int preservados = 0, tamanho = 0;
    unsigned char *vetorWAV = NULL;
    double complex *vetorCoeficientes = NULL;
    char *nomeArquivo = NULL;

    ///////////////////////////////////// BLOCO DE LEITURA DE DADOS DE ENTRADA
    nomeArquivo = preencherStrings(); 
    scanf("%d", &preservados);        

    ///////////////////////////////////// BLOCO DE PROCESSAMENTO DOS DADOS
    
    //Função fornecida que faz a leitura do arquivo binário de audio (WAV).
    vetorWAV = read_wav_data(nomeArquivo, &tamanho);
    printf("%d\n", tamanho);
    
    //Aplica a fórmula da Transformada de Fourier.
    vetorCoeficientes = DFT(vetorWAV, tamanho);
    
    //Cria uma struct para armazenar dados do vetorCoeficiente original.
    dados *dadosVetor = (dados*)malloc(tamanho*sizeof(dados));
    
    // Preenche a struct e usa os dados para calcular a magnitude.
    copiaCalcula(dadosVetor, vetorCoeficientes, tamanho);
    
    //Ordena o vetor de forma decrescente, de acordo com a magnitude.
    insertionSort(dadosVetor, tamanho);
    
    // Zera valores com indices acima dos indices preservados.
    zeradora(dadosVetor, tamanho, preservados);

    //Imprime as magnitudes dos indices preservados
    imprimirMagnitude(dadosVetor, preservados);

    // Restaura as posições originais dos dados do vetor.
    organizandoVetor(dadosVetor, vetorCoeficientes, tamanho); 
    
    // Faz a Inversa da Transformada de Fourier. Saida é complexa. Não volta unsigned.
    vetorCoeficientes = IDFT(vetorCoeficientes, tamanho); 

    ///////////////////////////////////// BLOCO DE GRAVAÇÃO DE DADOS EM ARQUIVO
    gravarBinario(vetorCoeficientes, tamanho, nomeArquivo);

    ///////////////////////////////////// BLOCO DE DESALOCAÇÃO
    free(dadosVetor);
    free(vetorCoeficientes);
    free(vetorWAV);
    free(nomeArquivo);

    return 0;

}