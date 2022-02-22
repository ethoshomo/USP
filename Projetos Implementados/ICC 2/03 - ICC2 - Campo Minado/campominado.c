/*               Título: Campo Minado
 *###########################################################
 * Aluno: Carlos Filipe de Castro Lemos
 * nUSP: 12542630
 * Código do Curso: 
 *###########################################################
 */

/////////////////////////////////////////////////// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////////////////////////////////////////////// DEFINIÇÕES E VARIÁVEIS GLOBAIS
#define bomba '*'
#define vazio '.'

/////////////////////////////////////////////////// DECLARAÇÃO DE FUNÇÕES
char* preencherString();
char* leituraTabuleiro(int* linhas, int* colunas);
void processaPosicao(char* matriz, int x, int y, int colunas);
void analisarVizinhanca(char* matriz, int x, int y, int linhas, int colunas);
void revelaDica(char* matriz, int x, int y, int linhas, int colunas);
char* preencherDicas(char* matriz, int linhas, int colunas);
void copiaPreparaMatriz(char* matriz, char* copia, int linhas, int colunas);
void revelaVazio(char* matriz, char*copia, int linhas, int colunas, int x, int y);

/////////////////////////////////////////////////// FUNÇÃO MAIN
int main(){

    int opcao, linhas, colunas, x, y;
    char* matriz = NULL;

    //Leitura da opção de entrada
    scanf("%d", &opcao);
    getchar(); //Dispensa o \n

    //Inicialização das variáveis
    linhas = 1;
    colunas = 0;
    x = 0;
    y = 0;

    // O programa foi compartimentado em 3 módulos (cada um foi alocada em sua respectiva opção)
    switch(opcao){
        
        case 1: // Faz a leitura do arquivo e imprime o Tabuleiro
            matriz = leituraTabuleiro(&linhas, &colunas);
            printf("%s", matriz);
            break;

        case 2: // Faz a leitura do arquivo e imprime o Tabuleiro com dicas (quantidade de bombas vizinhas).
            matriz = leituraTabuleiro(&linhas, &colunas);
            matriz = preencherDicas(matriz, linhas, colunas);
            printf("%s", matriz);
            break;

        case 3: // Além de ler o arquivo e preencher dicas, responde às coordenadas digitadas pelo usuário.
            matriz = leituraTabuleiro(&linhas, &colunas);
            matriz = preencherDicas(matriz, linhas, colunas);
            scanf("%d %d", &x, &y);
            
            //Existem 3 possibilidades de resposta:
            // 1) Uma bomba foi selecionada -> imprime o tabuleiro com dicas.
            if (matriz[x*colunas + y] == bomba){
                printf("%s", matriz);
                break;   
            }
                
            // 2) Uma dica foi selecionada -> revela a dica e imprimir "X" nas demais.
            if ((matriz[x*colunas + y] != bomba) && (matriz[x*colunas + y] != vazio)){
                revelaDica(matriz, x, y, linhas-1, colunas);
                printf("%s", matriz);
                break;
            }
            
            // 3) Espaço vazio foi selecionado -> revela todo o espaçovazio e dicas contíguas.
            if (matriz[x*colunas + y] == vazio){
                char* matrizCopia = (char*)calloc((((linhas)*(colunas+1))+1), sizeof(char));
                copiaPreparaMatriz(matriz, matrizCopia, linhas, colunas);
                revelaVazio(matriz, matrizCopia, linhas, colunas, x, y);
                printf("%s", matrizCopia);
                free(matrizCopia); 
                break;
            }

            break;

        default: 
            printf("Opcao invalida");
            break;
    }

    free(matriz);
    
    return 0;
}

/////////////////////////////////////////////////// FUNÇÃO preencherString()
/* Quando chamada, é responsável por fazer a alocação de um texto que será tratado como string.
 * Retorno: uma string de tamanho variável.
 */
char* preencherString()
{
    char *string = NULL;
    int controle = 0;
    char ch = ' ';

    do
    {
        controle += 1;
        string = (char*)realloc(string, controle);
        ch = getchar();
        string[controle-1] = ch;

    } while (ch != '\n');

    string[controle-1] = '\0';

    return string;
}

/////////////////////////////////////////////////// FUNÇÃO leituraTabuleiro
/* Quando chamada, é responsável por fazer a leitura de um arquivo ".board"
 * e armazenar os dados em uma matriz alocada dinamicamente. 
 * Além disso, contabiliza linhas e colunas da matriz.
 * Retorno: uma matriz de tamanho variável.
 */
char* leituraTabuleiro(int* linhas, int* colunas)
{

    FILE *ponteiro = NULL;
    char *nome = NULL;
    char* matriz = NULL;

    char ch = ' ';
    int controle = 0, tamanhodaMatriz = 1;
    
    matriz = (char*)realloc(matriz, tamanhodaMatriz*sizeof(char));

    nome = preencherString();
    ponteiro = fopen(nome, "r");

    if (ponteiro != NULL){

        do
        {
            ch = fgetc(ponteiro);
            matriz[controle] = ch;
            controle += 1;

            if (*linhas == 1)
                (*colunas)+= 1;
            
            if (ch == '\n')
                (*linhas)++;

            if ((ch != EOF) && (controle == tamanhodaMatriz))
            {
                tamanhodaMatriz += 1;
                matriz = (char*)realloc(matriz, tamanhodaMatriz*sizeof(char));
            }

        } while (ch != EOF);

        matriz[controle-1] = '\0';

        *linhas -= 1;
    }

    else
    {
        printf("Arquivo %s nao existe.\n", nome);
        free(matriz);
        free(nome);
        exit(1);
    }

    free(nome);
    fclose(ponteiro);

    return matriz;
}

/////////////////////////////////////////////////// FUNÇÃO processaPosicao()
/* Quando chamada, é responsável por fazer contabilizar de bombas na posição (x,y) indicada.
 * Se o espaço é vazio, atribui valor 1. Caso seja maior que um, acrescenta uma unidade.
 * Retorno: não há retorno.
 */
void processaPosicao(char* matriz, int x, int y, int colunas){
    
    if ((matriz[x*colunas+y] == bomba) || (matriz[x*colunas+y] == '\n')) {}
    else if (matriz[x*colunas+y] == vazio) {matriz[x*colunas+y] = '1';}
    else {matriz[x*colunas+y] = matriz[x*colunas+y] + 1;}
}

/////////////////////////////////////////////////// FUNÇÃO analisaVizinhanca()
/* Quando chamada, é responsável por fazer uma varredura na vizinhança da bomba, de acordo com a posição ocupada
 * no tabuleiro. Analisa os quatro cantos e interregnos entre eles, destacando possíveis células de incremetno. 
 * Em seguida, varre a região central. Assim sendo, chama a função de processamento para incrementar valores.
 * Retorno: Não há.
 */
void analisarVizinhanca(char* matriz, int x, int y, int linhas, int colunas){

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

    else if ((x==(linhas-1)) && (y==(colunas-2))) { //Canto inferior direito
        processaPosicao(matriz, x-1, y, colunas);
        processaPosicao(matriz, x-1, y-1, colunas);
        processaPosicao(matriz, x, y-1, colunas);
    }

    else if ((x==0) && ((y>0)&&(y<colunas-2))) { // Superior Central
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

    else if ((y==colunas-2) && ((x>0)&&(x<linhas-1))) { // Direita Central
        processaPosicao(matriz, x-1, y, colunas);
        processaPosicao(matriz, x+1, y, colunas);
        processaPosicao(matriz, x-1, y-1, colunas);
        processaPosicao(matriz, x, y-1, colunas);
        processaPosicao(matriz, x+1, y-1, colunas);
    }
    
    else if ((x==(linhas-1)) && ((y>0)&&(y<colunas-2))) { // Inferior Central
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
void revelaDica(char* matriz, int x, int y, int linhas, int colunas){
    for (int i = 0; i< (((linhas+1)*colunas)-1); i++){
        if (matriz[i] == '\n') {}
        else if (i == x*colunas+y) {}
        else {matriz[i] = 'X';}
    }
}

/////////////////////////////////////////////////// FUNÇÃO preencherDicas()
/* Quando chamada, percorre toda a matriz e, assim que encontrada uma bomba, chama a função de analise da vizinhança
 * para identificar sua posição no tabuleiro e, dessa forma, determinar quais células vizinhas precisam receber dicas.
 * Retorno: retorna a matriz com todas as dicas preenchidas.
 */
char* preencherDicas(char* matriz, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if (matriz[i*colunas + j] == bomba)
            {
                analisarVizinhanca(matriz, i, j, linhas, colunas);
            }
        }
    }
    return matriz;
}

/////////////////////////////////////////////////// FUNÇÃO copiaPreparaMatriz()
/* Quando chamada, é responsável por fazer uma copia, em alocação dinâmica, da matriz que abriga o Tabuleiro.
 * Retorno: Não há.
 */
void copiaPreparaMatriz(char* matriz, char* copia, int linhas, int colunas){
    for (int i = 0; i< ((linhas)*(colunas)); i++)
        copia[i] = matriz[i];

    copia[linhas*colunas+1] = '\0';

    for (int i = 0; i < ((linhas)*(colunas)); i++){
        if (copia[i] == '\n') {}
        else {copia[i] = 'X';}
    }
}

/////////////////////////////////////////////////// FUNÇÃO revelaVazio()
/* Quando chamada, é responsável revelar todos os espaços vazios e dicas contíguas ao ponto que foi escolhido.
 * Retorno: Não há.
 */
void revelaVazio(char* matriz, char*copia, int linhas, int colunas, int x, int y)
{

    //Verifica se está fora da borda
    if (x < 0 || y < 0 || x >= linhas || y >= colunas - 1) {return;}

    // Verifica se já foi visitado
    if (copia[(x*(colunas)+(y))] != 'X') {return;}

    copia[(x*(colunas)+(y))] = matriz[(x*(colunas)+(y))];

    // Verifica se é número
    if ((matriz[(x*(colunas)+(y))] > 47) && (matriz[(x*(colunas)+(y))] < 57)) {return;}

    // Caso tudo acima falhar, com certeza vai ser espaço vazio.    
    revelaVazio(matriz, copia, linhas, colunas, (x-1), (y-1)); // esquerda em cima
    revelaVazio(matriz, copia, linhas, colunas, (x-1), (y));   // em cima
    revelaVazio(matriz, copia, linhas, colunas, (x-1), (y+1)); // direita em cima
    revelaVazio(matriz, copia, linhas, colunas, (x), (y-1));   // esquerda 
    revelaVazio(matriz, copia, linhas, colunas, (x), (y+1));   // direita
    revelaVazio(matriz, copia, linhas, colunas, (x+1), (y-1)); // esquerda em baixo
    revelaVazio(matriz, copia, linhas, colunas, (x+1), (y));   // em baixo
    revelaVazio(matriz, copia, linhas, colunas, (x+1), (y+1)); // direita em baixo
}