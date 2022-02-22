#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grandesNumeros.h"

//////////////////////// Função Retorna Número
// Finalidade: converter um char em número.
// Observação: na impossibilidade de usar bibliotecas,
// foi necessário criar essa função para a finalidade
// acima mencionada.
// Retorno: recebe o char e retorna o inteiro.
int retornaNumero(char caracter){
    switch(caracter){
        case 48: return 0;
        case 49: return 1;
        case 50: return 2;
        case 51: return 3;
        case 52: return 4;
        case 53: return 5;
        case 54: return 6;
        case 55: return 7;
        case 56: return 8;
        case 57: return 9;
        default: break;
    }
    return -1;
}


//////////////////////// Função Ler Número
// Finalidade: ler dois números grandes da entrada. Como os 
// números são grandes (além do que a linguagem computacional 
// suporta), foi necessário criar uma lista duplamente ligada. 
// Assim, para facilitar sua manipulação, foi necessário ler 
// algarismo por algarismo do numero de entrada, sendo certo 
// que, de qualquer forma, precisou ler números na forma de char.
// Vale acrescentar que também cuida do sinal dos números,
// bem como modela o numero final retirando os zeros à esquerda.
//
// Observação: Essa função ainda trata de \r e \n.
//
// Retorno: não há. Os números são transportados por referência.
void lerNumero(numero *n1, numero *n2){
    char ch;
    ch = getchar();
    
    //Verifica Sinal do Numero 1
    ch = getchar();
    if (ch == '-'){n1->sinal = 'n';}
    else if (ch == ' '){}
    else {ungetc(ch, stdin);}
    
    //Coleta os algarismos do Numero 1
    while (ch != EOF){
        ch = getchar();
        if ((ch == ' ') || (ch == '\r')){break;}
        inserir(n1, retornaNumero(ch));
    } 
    
    // Verifica Sinal do Numero 2
    ch = getchar();
    if (ch == '-'){n2->sinal = 'n';}
    else if (ch == ' '){}
    else {ungetc(ch, stdin);}

    //Coleta os algarismos do Numero 2
    while (ch != EOF){
        ch = getchar();
        if ((ch == ' ') || (ch == '\r')){break;}
        inserir(n2, retornaNumero(ch));
    } 
    verificarBarraRN();

    // Caso tenha zero a esquerda, elimina-os.
    removerZeros(n1);
    removerZeros(n2);
}


//////////////////////// Função Barra R e Barra N
// Finalidade: eliminar os caracteres \r e \n da leitura
// da entrada de dados.
// Retorno: não há.
void verificarBarraRN(){
    char ch = ' ';
    ch = getchar();
    if (ch != '\r'){ungetc(ch, stdin);}
    ch = getchar();
    if (ch != '\n'){ungetc(ch, stdin);}
}

//////////////////////// Função Resolve Entrada
// Finalidade: resolve a entrada do programa por meio da coleta
// do comando (soma ou comparação de igualdade, de maioridade 
// ou de menoridade) e de dois números grandes.
// Ao mesmo tempo, faz a conexão com demais funções do programa.
// Retorno: Não há.
void resolveEntrada(){
    int saida = 0;
    char comando[5];
    numero *numero1 = criarNumero();
    numero *numero2 = criarNumero();
    numero *resultado = criarNumero();

    saida = scanf("%5[^,' ']s", comando);
    
    if (saida == EOF){
        liberarNumero(numero1);
        liberarNumero(numero2);
        liberarNumero(resultado);
        return;
    }
    else if(strcmp(comando, "SUM") == 0) {
        lerNumero(numero1, numero2);
        soma(numero1, numero2, resultado);
    }
    else if(strcmp(comando, "BIG") == 0) {
        lerNumero(numero1, numero2);
        printf("%d\n", big(numero1, numero2));
    }
    else if(strcmp(comando, "SML") == 0) {
        lerNumero(numero1, numero2);
        printf("%d\n", small(numero1, numero2));   
    }
    else if(strcmp(comando, "EQL") == 0) {
        lerNumero(numero1, numero2);
        printf("%d\n", igual(numero1, numero2));
    }

    liberarNumero(numero1);
    liberarNumero(numero2);
    liberarNumero(resultado);

    return;
}