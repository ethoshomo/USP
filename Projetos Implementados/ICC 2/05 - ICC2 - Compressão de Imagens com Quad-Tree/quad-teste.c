#include <stdio.h>
#include <stdlib.h>
#define no -1

int dividirQuadrantes(int **m, int linhas, int colunas, int x, int y, int referencia);
int verificarQuadrante(int **m, int linhas, int colunas, int x, int y, int referencia);
int **lerMatriz(int **m, int linhas, int colunas);

int main(){

    int linhas = 0, colunas = 0;
    int **matriz = NULL;

    scanf("%d %d", &linhas, &colunas);
    matriz = lerMatriz(matriz, linhas, colunas);
    verificarQuadrante(matriz, linhas, colunas, 0, 0, linhas);
    printf("\n");
    
    for(int i = 0; i < linhas; i++)
        free(matriz[i]);

    free(matriz);

    return 0;
}


int **lerMatriz(int **m, int linhas, int colunas){

    m = (int**)malloc(linhas*sizeof(int*));      

    for(int i = 0; i < linhas; i++){
        m[i] = (int*)malloc(colunas*sizeof(int));
        for(int j = 0; j < colunas; j++){
            scanf(" %d", &m[i][j]);
        }
    } 
    return m;

}

int dividirQuadrantes(int **m, int linhas, int colunas, int x, int y, int referencia){
    //printf("Verificar Quadrantes: linhas = %d, colunas = %d, x = %d, y= %d, referencia = %d\n", linhas, colunas, x, y, referencia);
    //printf("Entrando no Primeiro Quadrante:\n");
    verificarQuadrante(m, linhas-referencia, colunas - referencia, x, y, referencia);
    //printf("\n\nEntrando no Segundo Quadrante:\n");
    verificarQuadrante(m, linhas-referencia, colunas, x, y + referencia, referencia);
    //printf("\n\nEntrando no Terceiro Quadrante:\n");
    verificarQuadrante(m, linhas, colunas-referencia, x + referencia, y, referencia);
    //printf("\n\nEntrando no Quarto Quadrante:\n");
    verificarQuadrante(m, linhas, colunas, x + referencia, y + referencia, referencia);
    return 0;
}

int verificarQuadrante(int **m, int linhas, int colunas, int x, int y, int referencia){
       
    //printf("Verificar Quadrantes: linhas = %d, colunas = %d, x = %d, y= %d, referencia = %d\n", linhas, colunas, x, y, referencia);
    int representante = m[x][y];
    //printf("Representante: %d\n", representante);
    int diferentes = 0;

    for(int i = x; i < linhas; i++){
        for(int j = y; j < colunas; j++){
            if (m[i][j] != representante){
                //printf("%d", m[i][j]);
                diferentes += 1;
            }
        }
        //printf("\n");
    }

    if (diferentes == 0){
        printf("%d ", representante);
        return 0;
    }
    else if ((diferentes != 0) && (referencia/2 == 1)){
            printf("-1 %d %d %d %d ", m[x][y], m[x][y+1], m[x+1][y], m[x+1][y+1]);
            return 0;
    }
    else if (diferentes != 0){
        printf("%d ", no);
        dividirQuadrantes(m, linhas, colunas, x, y, referencia/2); 
        return 0;
    }
    return 0;
}