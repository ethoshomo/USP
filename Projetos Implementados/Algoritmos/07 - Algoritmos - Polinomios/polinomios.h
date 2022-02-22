typedef struct polinomio_t polinomio;
typedef struct termo_t termo;

polinomio* criarPolinomioResultado();
polinomio* readLine(polinomio *pol);
void destruirPolinomioResultado(polinomio *l);
void imprimir(polinomio *l);
int inserirSomarTermo(polinomio *pol, int coeficiente, int grau);
int verificarGrauSomar(polinomio *pol, int coeficiente, int grau);

