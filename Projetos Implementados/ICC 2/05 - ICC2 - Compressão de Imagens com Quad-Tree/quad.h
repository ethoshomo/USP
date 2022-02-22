#define no -1

void dividirQuadrantes(int **m, int linhas, int colunas, int x, int y, int referencia);
void verificarQuadrante(int **m, int linhas, int colunas, int x, int y, int referencia);
int **lerMatriz(int **m, int linhas, int colunas);
void liberarAlocacoes(int **m, int linhas);