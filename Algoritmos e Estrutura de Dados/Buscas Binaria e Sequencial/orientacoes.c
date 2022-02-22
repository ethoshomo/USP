/*
                        Mecanismos de Buscas
    
    Existem várias formas de se realizar a busca de elementos, sendo
    o mais comum a busca em um vetor ordenado de elementos.
    Exemplo: encontrar "m" ou "x" tal que V(m) == x.

    OBSERVAÇÃO: os métodos abaixo somente funcionam com VETORES ORDENADOS.

    Existem dois mecanismos de buscas mais conhecidos: a) Busca Sequencial; 
    b) Busca Binária.

        a) BUSCA SEQUENCIAL: a busca sequencial é realizada por meio
        de comparações. É dado um valor X para que seja procurado em
        um vetor (v[]) de N posições. Dessa forma, a implentação
        ficaria da seguinte forma: 
            int buscaSequencial (int x, int n, int v[]) {
                int j = 0;
                while (j < n && v[j] < x) 
                ++j;
                return j;
            }

        Obviamente não é a única forma de resolver o problema, pois
        poderíamos usar um laço repetitivo para percorrer célula por 
        célula e ir fazendo a comparação, retornando o valor da posição
        quando encontrado o valor.

        Por outro lado, apesar de ser uma forma óbvia de implementar 
        a busca, não é a forma mais eficiente de se executar a tarefa. 
        Afinal, teremos que comparar o valor X com todas as N posições 
        do vetor, razão pela qual o desempenho pode ser prejudicado com
        vetores muito grandes.

        b) BUSCA BINÁRIA: por outro lado, a busca binária é muito mais
        eficiente que a sequencial. Isso porque ela divide o vetor
        ordenado em duas porções, sendo certo que, utilizando o valor
        que ocupa a posição central, verifica de qual lado se encontra o
        valor buscado, e, portanto, qual lado deve dividir novamente o 
        vetor. Desse modo, vai-se subdividindo sucessivamente até chegar no
        valor no valor buscado). Esse método é muito mais rápido que a 
        busca sequencial, uma vez que abrevia consideravelmente a quantidade 
        de operações realizadas.

*/