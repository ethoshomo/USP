#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <string.h>
#include "compressao.h"

///////////////////////////////////// FUNÇÃO READ WAV DATA
// Finalidade: foi fornecida pelo exercício. Faz a leitura do arquivo WAV,
// de acordo com o nome fornecido pelo usuário na main. Além disso, foi
// inserido o parâmtro tamanho para retornar por referência o tamanho da
// alocação dinâmica.
// Retorno: retorna um vetor de samples (unsigned char).
unsigned char* read_wav_data(char* fname, int *tamanho){
    FILE* fp = fopen(fname, "rb");
    unsigned char buf4[4];

    fseek(fp, 40, SEEK_SET);
    fread(buf4, sizeof(buf4), 1, fp);
    int dataSize = buf4[0] | buf4[1]<<8 | buf4[2]<<16 | buf4[3]<<24;

    unsigned char* data = malloc(sizeof(*data) * (dataSize));
    
    int i = 0;
    while (i < dataSize) {
        fread(&data[i++], sizeof(unsigned char), 1, fp);
        *tamanho += 1;
    }
    fclose(fp);
    return data;
}

///////////////////////////////////// FUNÇÃO DFT
// Finalidade: foi fornecida pelo exercício. Trata-se da Transformada 
// Discreta de Fourier que converte os dados obtidos pela leitura do
// arquivo WAV em valores complexos (refletindo a onda do audio no sistema
// gaussiano).
// Retorno: retorna um número complexo.
double complex *DFT(unsigned char *audio, int length) {
    double complex *coef = (double complex *) calloc(length, sizeof(double complex));
    
    for (int k = 0; k < length; k++) {
        for (int n = 0; n < length; n++) {
            coef[k] += audio[n] * cexp((-2.0 * M_PI * (((k+1) * n * 1.0) / (length * 1.0))) * _Complex_I);
        }
    }
    return coef;
}

///////////////////////////////////// FUNÇÃO IDFT
// Finalidade: trata-se de uma equação adaptada da Transformada Discreta de
// Fourier, que tem como finalidade desfazê-la (função inversa).
// Retorno: era de se esperar retornasse um unsigned char, porém retorna um
// número complexo (somente a parte real será aproveitada posteriormente).
double complex *IDFT(double complex *audio, int length) {
    double complex *coef = (double complex *) calloc(length, sizeof(double complex));

    for (int k = 0; k < length; k++) {
        for (int n = 0; n < length; n++) {
            coef[k] += (1/(length*1.0)) * audio[n] * cexp((2.0 * M_PI * (((k+1) * (n+1) * 1.0) / (length * 1.0))) * _Complex_I);
        }
    }

    free(audio);
    return coef;
}

///////////////////////////////////// FUNÇÃO INSERTION SORT
// Finalidade: faz a ordenação de forma decrescente das informações
// armazenadas na struct.
// Retorno: não há.
void insertionSort(dados *v, int n) {
	int i = 1;

	while (i < n) {
		dados el = v[i];
		int j = i-1;

		while (j >= 0 && el.magnitude > v[j].magnitude) {
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = el;
		i++;
	}
}

///////////////////////////////////// FUNÇÃO PREENCHER STRING
// Finalidade: cria um string alocada dinamicamente para armazenar 
// o nome do arquivo.
// Retorno: a própria string será retornada.
char* preencherStrings(){
      char *string = NULL;
      int tamanho = 0;
      char caracter = '%';

      while(caracter != '\r'){
          string = (char*)realloc(string, (tamanho+1)*sizeof(char));
          caracter = getchar();
          if (caracter == '\r'){getchar();}
          string[tamanho] = caracter;
          tamanho += 1;
      }

      string[tamanho-1] = '\0';
      return string;
}

///////////////////////////////////// FUNÇÃO MAGNITUDE
// Finalidade: resolver o cálculo da magnitude (fórmula fornecida).
// Retorno: resultado no formato double.
double magnitude(double complex numero){
    return sqrt(pow(creal(numero), 2) + pow(cimag(numero), 2));
}

///////////////////////////////////// FUNÇÃO COPIA CALCULA
// Finalidade: copia os dados do vetorCoeficientes para a struct
// e chama a função magnitude para calcular seu valor.
// Retorno: não há.
void copiaCalcula(dados *d, double complex *vetor, int tamanho){
    for(int contador = 0; contador < tamanho; contador++){
        d[contador].indiceCoeficiente = contador;
        d[contador].informacao = vetor[contador];
        d[contador].magnitude = magnitude(vetor[contador]);
    }
}

///////////////////////////////////// FUNÇÃO ZERADORA
// Finalidade: de acordo com o valor recebido na main (preservados),
// preserva os primeiros "n" valores e, logo depois, preenche com 0.
// Além disso, contabiliza os valores complexos que apresentam as partes
// reais e imaginárias negativas.
// Retorno: não há.
void zeradora(dados *d, int tamanho, int preservados){
    int soma = 0;
    for(int contador = 0; contador < tamanho; contador++){
        if ((creal(d[contador].informacao) <= 0) && (cimag(d[contador].informacao) <= 0)){soma++;}
        if (contador >= preservados) {d[contador].informacao = 0;}
    }
    printf("%d\n", soma);
}

///////////////////////////////////// FUNÇÃO ORGANIZANDO VETOR
// Finalidade: depois do processamento das informações de audio (especialmente
// a ordenação dos maiores valores), há necessidade de retornar as informações
// para as posições originais. Essa é a finalidade dessa função.
// Retorno: não há.
void organizandoVetor(dados *d, double complex *vetor, int tamanho){
    for(int contador = 0; contador < tamanho; contador++)
        vetor[d[contador].indiceCoeficiente] = d[contador].informacao;
}

///////////////////////////////////// FUNÇÃO IMPRIMIR MAGNITUDE
// Finalidade: imprime todas as magnitudes dos preservados.
// Retorno: não há.
void imprimirMagnitude(dados *d, int preservados){
    for(int contador = 0; contador < preservados; contador++)
        printf("%d\n", (int)d[contador].magnitude);
}

///////////////////////////////////// FUNÇÃO IMPRIMIR MAGNITUDE
// Finalidade: regravar o arquivo de audio comprimido. A função, primeiro,
// faz uma cópia do cabeçalho do arquivo original e, depois, adiciona as 
// informações que foram processadas.
// Retorno: não há.
void gravarBinario(double complex *vetor, int tamanho, char *nomeArquivo){
    unsigned char *temporario = NULL;
    int *auxiliar = NULL;
    int numeroAuxiliar = 0;
    
    //Leitura do cabeçalho do arquivo original
    FILE *cursorLeitura = fopen(nomeArquivo, "rb");
    if (cursorLeitura != NULL){
        temporario = (unsigned char*)malloc(45*sizeof(unsigned char));
        fread(temporario, sizeof(unsigned char), 44, cursorLeitura);
    }
    else{
        printf("Erro na abertura do arquivo %s.", nomeArquivo);
        exit(1);
    }
    fclose(cursorLeitura);

    //Gravação do arquivo .wav
    FILE *cursorGravacao = fopen("saida.wav", "wb");
    if (cursorGravacao != NULL){

        //Gravação do cabeçalho do arquivo original
        fwrite(temporario, sizeof(unsigned char), 44, cursorGravacao);
        free(temporario);

        //Gravação do audio processado
        for(int contador = 0; contador < tamanho; contador++){
            numeroAuxiliar = (int)vetor[contador];
            auxiliar = &numeroAuxiliar;
            fwrite(auxiliar, sizeof(unsigned char), 1, cursorGravacao);
        }
    }
    else{
        printf("Erro na gravação de arquivos.");
        exit(1);
    }
    fclose(cursorGravacao);
}