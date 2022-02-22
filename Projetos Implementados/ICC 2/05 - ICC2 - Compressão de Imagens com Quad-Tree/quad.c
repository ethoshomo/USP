#include <stdio.h>
#include <stdlib.h>
#include "quad.h"
//////////////////////////////////Função Ler Matriz
// Finalidade: lê a matriz de numeros disponibilizada na entrada
// Retorno: retorna o endereço de memória da matriz alocada.
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

//////////////////////////////////Função Dividir Quadrantes
// Finalidade: se a matriz inteira ou o quadrante não forem compostos
// pelo mesmo representante, esta função irá dividir a matriz ou o 
// quadrante em linhas ou colunas pela metade (divindo em forma de mais "+").
// Observação: considera-se que a matriz seja quadrada e com numeros 
// de linhas e colunas multiplos de 2).
// Retorno: não há.
void dividirQuadrantes(int **m, int linhas, int colunas, int x, int y, int referencia){
    verificarQuadrante(m, linhas-referencia, colunas - referencia, x, y, referencia);
    verificarQuadrante(m, linhas-referencia, colunas, x, y + referencia, referencia);
    verificarQuadrante(m, linhas, colunas-referencia, x + referencia, y, referencia);
    verificarQuadrante(m, linhas, colunas, x + referencia, y + referencia, referencia);
}

//////////////////////////////////Função Verificar Quadrantes
// Finalidade: verifica se a matriz ou o quadrante são compostos 
// pelos mesmos representantes. Caso tenha representantes diferentes, 
// ou a função irá verificar se ocorreu o caso base (quadrante de 
// quatro elementos não-iguais) ou irá novamente chamar a função 
// para dividir em quadrantes. Caso tenha mesmos representantes, 
// imprime o representante.
// Retorno: não há.
void verificarQuadrante(int **m, int linhas, int colunas, int x, int y, int referencia){
    int representante = m[x][y];
    int diferentes = 0;

    for(int i = x; i < linhas; i++){
        for(int j = y; j < colunas; j++){
            if (m[i][j] != representante){
                diferentes += 1;
            }
        }
    }

    if (diferentes == 0){
        printf("%d ", representante);
        return;
    }
    else if ((diferentes != 0) && (referencia/2 == 1)){
            printf("-1 %d %d %d %d ", m[x][y], m[x][y+1], m[x+1][y], m[x+1][y+1]);
            return;
    }
    else if (diferentes != 0){
        printf("%d ", no);
        dividirQuadrantes(m, linhas, colunas, x, y, referencia/2); 
        return;
    }
    return;
}

//////////////////////////////////Função Dividir Quadrantes
// Finalidade: libera as alocações dinâmicas dinâmicas do programa.
// Retorno: não há.
void liberarAlocacoes(int **m, int linhas){
    for(int i = 0; i < linhas; i++){
        free(m[i]);
        m[i] = NULL;
    }

    free(m);
    m = NULL;
}