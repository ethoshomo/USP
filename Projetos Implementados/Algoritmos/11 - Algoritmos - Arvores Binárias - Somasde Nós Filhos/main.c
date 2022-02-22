/**************************************************************
*              UNIVERSIDADE DE SÃO PAULO - USP                *
*          INSTITUTO DE MATEMÁTICA E COMPUTAÇÃO - ICMC        *
*               Carlos Filipe de Castro Lemos                 *
*            Árvores Binárias - Soma de Nós Filhos            *
*                      nUSP 12542630                          *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "somas.h"

int main(){

    int quantidadeNodes = 0;
    int id = 0, id_e = 0, id_d = 0, informacao = 0;
    dados *listaDados = criar_lista_dados();
    arvore *arvoreDados = NULL;

    scanf("%d", &quantidadeNodes);

    for(int contador = 0; contador < quantidadeNodes; contador++){
        scanf("%d %d %d %d", &id, &informacao, &id_e, &id_d);
        inserir_lista_dados(listaDados, id, informacao, id_e, id_d);      
    }

    arvoreDados = montar_arvore(listaDados, 0);
    verifica_vf_somas(listaDados->erro);
    destruir_lista_dados(listaDados, arvoreDados);

    return 0;
}