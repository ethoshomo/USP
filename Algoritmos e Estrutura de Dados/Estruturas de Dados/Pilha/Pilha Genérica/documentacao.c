/*
    A pilha genérica é utilizada para armazenar qualquer tipo de dados, pois usa um vetor
    de vetores do tipo void*. Assim, esses vetores podem apontar para qualquer tipo de
    dados que esteja alocado dinamicamente, bastando apenas que se faça o casting na alocação.

    É extremamente importante tomar cuidado com ponteiros dentro de structs, pois  é comum 
    na desalocação ser negligenciado o ponteiro interno ao struct. Dai a desalocação somente libera os
    ponteiros que estão alocados em seu vetor e não os ponteiros dentro da struct, causando, dessa forma,
    memory leak.
*/