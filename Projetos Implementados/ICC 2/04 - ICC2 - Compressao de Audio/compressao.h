typedef struct vetor_coeficientes dados;

struct vetor_coeficientes {
    double complex informacao;
    int indiceCoeficiente;
    double magnitude;
};

unsigned char* read_wav_data(char* fname, int *tamanho);
double complex *DFT(unsigned char *audio, int length);
double complex *IDFT(double complex *audio, int length);
void insertionSort(dados *v, int n);
char* preencherStrings();
double magnitude(double complex numero);
void copiaCalcula(dados *d, double complex *vetor, int tamanho);
void zeradora(dados *d, int tamanho, int preservados);
void organizandoVetor(dados *d, double complex *vetor, int tamanho);
void imprimirMagnitude(dados *d, int preservados);
void gravarBinario(double complex *vetor, int tamanho, char *nomeArquivo);
