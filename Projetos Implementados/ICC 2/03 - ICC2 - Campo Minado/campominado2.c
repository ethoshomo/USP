/*
 ########################################
 #          Título: Campo Minado        #
 ########################################
 # Aluno: Carlos Filipe de Castro Lemos #
 # nUSP: 12542630                       #
 # Código do Curso: SCC201              #
 # Data: 12/09/2021                     #
 ########################################
 */

/////////////////////////////////////////////////// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////////////////////////////////////////////// DEFINIÇÕES E VARIÁVEIS GLOBAIS
#define bomba '*'
#define vazio '.'

/////////////////////////////////////////////////// DECLARAÇÃO DE FUNÇÕES
void imprimirMatriz(char** matriz, int linhas, int colunas);
char* preencherString();
char** leituraTabuleiro(int* linhas, int* colunas);
char** preencherDicas(char** matriz, int linhas, int colunas);
void analisarVizinhanca(char** matriz, int x, int y, int linhas, int colunas);
void processaPosicao(char** matriz, int x, int y, int colunas);
void revelaDica(char** matriz, int x, int y, int linhas, int colunas);

/////////////////////////////////////////////////// FUNÇÃO MAIN
int main(){

    int opcao, linhas, colunas, x, y;
    char** matriz = NULL;

    //Inicialização das variáveis
    opcao = 0;
    linhas = 0;
    colunas = 0;
    x = 0;
    y = 0;

    //Leitura da opção de entrada
    scanf("%d", &opcao);
    getchar(); //Dispensa o \n

    // O programa foi compartimentado em 3 módulos (cada um foi alocada em sua respectiva opção)
    switch(opcao){
        
        case 1: // Faz a leitura do arquivo e imprime o Tabuleiro
            matriz = leituraTabuleiro(&linhas, &colunas);
            imprimirMatriz(matriz, linhas, colunas);
            break;

        case 2:
            matriz = leituraTabuleiro(&linhas, &colunas);
            matriz = preencherDicas(matriz, linhas, colunas);
            imprimirMatriz(matriz, linhas, colunas);
            break;
        
        case 3:
            matriz = leituraTabuleiro(&linhas, &colunas);
            matriz = preencherDicas(matriz, linhas, colunas);
            imprimirMatriz(matriz, linhas, colunas);
            scanf("%d %d", &x, &y);
            printf("\nLeitura do SCANF: %d %d\n\n", x, y);

            //Existem 3 possibilidades de resposta:
            // 1) Uma bomba foi selecionada -> imprime o tabuleiro com dicas.
            if (matriz[x][y] == bomba){
                imprimirMatriz(matriz, linhas, colunas);
                break;   
            }
            printf("\nCaracter selecionado: %c\n\n", matriz[x][y]);
            // 2) Uma dica foi selecionada -> revela a dica e imprimir "X" nas demais.
            if ((matriz[x][y] > 48) && (matriz[x][y] < 58)){
                //revelaDica(matriz, x, y, linhas, colunas);
                imprimirMatriz(matriz, linhas, colunas);
                break;
            }
            /*
            // 3) Espaço vazio foi selecionado -> revela todo o espaçovazio e dicas contíguas.
            if (matriz[x*colunas + y] == vazio){
                char* matrizCopia = (char*)calloc((((linhas)*(colunas+1))+1), sizeof(char));
                copiaPreparaMatriz(matriz, matrizCopia, linhas, colunas);
                printf("Matriz original:\n%s\n", matriz);
                printf("Primeira Copia:\n%s\n", matrizCopia);
                revelaVazio(matriz, matrizCopia, linhas, colunas, x, y);
                printf("%s\n", matrizCopia);
                free(matrizCopia); 
                break;
                
            }
*/
            break;

        default: 
            printf("Opcao invalida");
            break;
    }

    for (int i = 0; i < linhas; i++)
        free(matriz[i]);

    free(matriz);
    
    return 0;
}


void imprimirMatriz (char** matriz, int linhas, int colunas){ 
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%c", matriz[i][j]);
        }
    }
}

char* preencherString() {
    char *string = NULL;
    int controle = 0;
    char ch;

    do {
        controle += 1;
        string = (char*)realloc(string, controle);
        ch = getchar();
        string[controle-1] = ch;
    } while (ch != '\n' && ch != '\r');

    string[controle-1] = '\0';

    return string;
}

char** leituraTabuleiro(int* linhas, int* colunas) {
    FILE *ponteiro = NULL;
    char *nome = NULL;
    char** matriz = NULL;
    char ch = ' ';
    int controleColunas = 0;
    
    nome = preencherString();
    ponteiro = fopen(nome, "r");

    if (ponteiro != NULL){
        
        do {
            matriz = (char**)realloc(matriz, (*linhas + 1)*sizeof(char*));
            matriz[*linhas] = NULL;     

            do{
                matriz[*linhas] = realloc(matriz[*linhas], (*colunas+1)*sizeof(char));
                ch = fgetc(ponteiro);
                matriz[*linhas][*colunas] = ch;
                if (*linhas== 0) {controleColunas += 1;}
                *colunas += 1;

            } while (ch != '\n');
            *colunas = 0;
            *linhas += 1;
            if ((ch = fgetc(ponteiro)) == EOF) {break;}
            else {ungetc(ch, ponteiro);}

        } while (ch != EOF);

        *colunas = controleColunas;
    }
    else
    {
        printf("Arquivo %s nao existe.\n", nome);
        
        for (int i = 0; i < *linhas; i++)
                free(matriz[i]);

        free(matriz);
        free(nome);
        exit(1);
    }

    free(nome);
    fclose(ponteiro);
    return matriz;
}

char** preencherDicas(char** matriz, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if (matriz[i][j] == bomba)
            {
                analisarVizinhanca(matriz, i, j, linhas, colunas);
            }
        }
    }
    return matriz;
}

/////////////////////////////////////////////////// FUNÇÃO processaPosicao()
/* Quando chamada, é responsável por contabilizar as bombas ao redor da posição (x,y).
 * Se o espaço é vazio, atribui valor 1. Caso seja maior que um, acrescenta uma unidade.
 * Retorno: não há retorno.
 */
void processaPosicao(char** matriz, int x, int y, int colunas){
    
    if ((matriz[x][y] == bomba) || (matriz[x][y] == '\n')) {}
    else if (matriz[x][y] == vazio) {matriz[x][y] = '1';}
    else {matriz[x][y] = matriz[x][y] + 1;}
}

/////////////////////////////////////////////////// FUNÇÃO analisaVizinhanca()
/* Quando chamada, é responsável por fazer uma varredura na vizinhança da bomba, de acordo com a posição ocupada
 * no tabuleiro. Analisa os quatro cantos e interregnos entre eles, destacando possíveis células de incremetno. 
 * Em seguida, varre a região central. Assim sendo, chama a função de processamento para incrementar valores.
 * Retorno: Não há.
 */
void analisarVizinhanca(char** matriz, int x, int y, int linhas, int colunas){

    if ((x==0) && y==0) { // Canto superior esquerdo
        processaPosicao(matriz, x, y+1, colunas);
        processaPosicao(matriz, x+1, y, colunas);
        processaPosicao(matriz, x+1, y+1, colunas);
    } 

    else if ((x==0) && y==colunas-2) { //Canto superior direito
        processaPosicao(matriz, x, y-1, colunas);
        processaPosicao(matriz, x+1, y, colunas);
        processaPosicao(matriz, x+1, y-1, colunas);
    }

    else if ((x==linhas-1) && y==0) { //Canto inferior esquerdo
        processaPosicao(matriz, x-1, y, colunas);
        processaPosicao(matriz, x-1, y+1, colunas);
        processaPosicao(matriz, x, y+1, colunas);
    }

    else if ((x==(linhas-1)) && (y==(colunas-1))) { //Canto inferior direito
        processaPosicao(matriz, x-1, y, colunas);
        processaPosicao(matriz, x-1, y-1, colunas);
        processaPosicao(matriz, x, y-1, colunas);
    }

    else if ((x==0) && ((y>0)&&(y<colunas-1))) { // Superior Central
        processaPosicao(matriz, x, y+1, colunas);
        processaPosicao(matriz, x, y-1, colunas);
        processaPosicao(matriz, x+1, y-1, colunas);
        processaPosicao(matriz, x+1, y, colunas);
        processaPosicao(matriz, x+1, y+1, colunas);
    }

    else if ((y==0) && ((x>0)&&(x<linhas-1))) { // Esquerda Central
        processaPosicao(matriz, x-1, y, colunas);
        processaPosicao(matriz, x+1, y, colunas);
        processaPosicao(matriz, x-1, y+1, colunas);
        processaPosicao(matriz, x, y+1, colunas);
        processaPosicao(matriz, x+1, y+1, colunas);
    }

    else if ((y==colunas-1) && ((x>0)&&(x<linhas-1))) { // Direita Central
        processaPosicao(matriz, x-1, y, colunas);
        processaPosicao(matriz, x+1, y, colunas);
        processaPosicao(matriz, x-1, y-1, colunas);
        processaPosicao(matriz, x, y-1, colunas);
        processaPosicao(matriz, x+1, y-1, colunas);
    }
    
    else if ((x==(linhas-1)) && ((y>0)&&(y<colunas-1))) { // Inferior Central
        processaPosicao(matriz, x, y+1, colunas);
        processaPosicao(matriz, x, y-1, colunas);
        processaPosicao(matriz, x-1, y-1, colunas);
        processaPosicao(matriz, x-1, y, colunas);
        processaPosicao(matriz, x-1, y+1, colunas);
    }

    else{ // Posições Centrais (fora da borda)
        processaPosicao(matriz, x-1, y-1, colunas);
        processaPosicao(matriz, x-1, y, colunas);
        processaPosicao(matriz, x-1, y+1, colunas);
        processaPosicao(matriz, x, y+1, colunas);
        processaPosicao(matriz, x, y-1, colunas);
        processaPosicao(matriz, x+1, y-1, colunas);
        processaPosicao(matriz, x+1, y, colunas);
        processaPosicao(matriz, x+1, y+1, colunas);
    }

}

/////////////////////////////////////////////////// FUNÇÃO revelaDica()
/* Quando chamada, é responsável por preparar a matriz para que revele apenas a dica selecionada.
 * Retorno: não há.
 */
void revelaDica(char** matriz, int x, int y, int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if ((i == x) && (j == y)) {}
            else if (matriz[i][j] == '\n') {}
            else {matriz[i][j] = 'X';}
       }
    }
}