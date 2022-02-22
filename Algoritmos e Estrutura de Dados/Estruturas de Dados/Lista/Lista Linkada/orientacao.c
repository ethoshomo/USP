/*
    As listas de memória apresentam características próprias que as diferenciam de filas e pilhas. 
    Em primeiro lugar, não há alocação sequencial como acontece nas outras duas técnicas, afinal 
    cada bloco de memória (cada nó da lista) tem pelo menos dois campos:
        a) informação a ser armazenada; 
        b) indicação do próximo elemento da lista.

    Dessa forma, o acesso aos elementos da lista ocorre por meio de um ponteiro que indica o início 
    da lista (primeiro elemento), enquanto o acesso aos demais ocorre por meio da indicação de quem
    é o próximo elemento da lista (por isso, a lista é encadeada). Vale acrescentar que o último
    nó da lista tem um ponteiro que aponta para NULL, quebrando a sequência.

    Uma desvantagem desse tipo de abordagem está relacionada ao fato de que não conseguiremos 
    acessar um elemento que está no meio da lista (como acontece nas filas e pilhas que possuem
    índices que podem ser manipulados). Se quiséssemos encontrar um determinado elemento,
    deveríamos percorrer toda a lista no seu achamento.
    
    Por outro lado, uma vantagem é a versatilidade, pois podemos criar listas
    estáticas ou dinâmicas, bem como sequenciais ou encadeadas. Para tanto, basta combinar as
    possibilidades de implementação. Nesse contexto, é de se observar que o modo mais eficiente 
    de implementar listas é do tipo dinâmica e encadeada - afinal, ela representa os dados de 
    forma clara e flexível, sendo aplicada a diversos problemas.

    Na elaboração do algoritmo, usa-se uma struct e três ponteiros (inicio, fim e p).
    A struct será referente ao bloco de memória, ou ao nó, sendo certo que, dentro dela, devemos 
    usar uma declaração de ponteiro cujo tipo de dado é igual ao da declaração do nó, da 
    seguinte forma:
                        struct no {
                            char info;
                            struct no *next;
                        };

    Isso será necessário porque os ponteiros "inicio" e "p" poderão receber os valores dos próximos nós.
    Por exemplo: o ponteiro "p" pode percorrer a lista encadeada (desde "inicio" até o "fim") para fazer
    a impressão de dados armazenados; ou, então, quando o ponteiro "inicio" é intercalado com o "p" na 
    desalocação de memória que, porventura, tenha sido alocada durante toda a elaboração da lista. 
*/