/*
    Existem vários mecanismos de ordenação que serão estudados abaixo.
    Destaquei os seguintes nos meus estudos:
        a) Bubble Sort
        b) Insertion Sort
        c) Selection Sort
        d) Quick Sort
        e) Shell Sort
        f) Merge Sort

    Todos eles serão implementados em TAD para comparação. Abaixo,
    temos os conceitos e os pontos positivos e negativos de cada um.

    Em tempo de execução, a ordem do mais rápido para o mais lento
    fica da seguinte forma: Quick Sort < Shell Sort < Insertion Sort 
    < Selection Sort < Bubble Sort.

    /////////////// BUBBLE SORT
    - Promove a troca de posições de valores, sendo ordenado
    de forma crescente ou decrescente. Para tanto, precisa de percorrer
    recursivamente o vetor tantas vezes quantas forem necessárias para 
    ordená-lo. Nesse contexto, o algoritmo apresenta complexidade
    de ordem quadrática, por isso não é recomendado para programas que
    trabalhem com grande quantidades de dados ou precisem de performance. 


    /////////////// INSERTION SORT
    - O Insertion Sort, como o próprio nome diz, está relacionado com
    a adição de um valor por vez na estrutura de dados. Isso ocorre
    por meio de uma comparação, a qual vai escolher o local da adição.
    Dentre os algoritmos de ordem quadrática, é o que apresenta melhor
    desempenho, mas, ainda assim, não é recomendado para estruturas que
    estejam muito desorganizadas ou sejam muito grandes.


    /////////////// SELECTION SORT
    - O algoritmo é responsável por trocar o menor valor com a primeira
    posição, depois do segundo menor valor para a segunda posição e,
    dessa forma, sucessivamente. Conforme a estrutura de dados for
    sendo ordenada mais rápido fica o algoritmo (afinal, diminui o tempo
    de percorrer a estrutura restante). É composto de dois laços, sendo que
    o externo controla o indice que vai receber o menor valor, enquanto
    o interno percorre o restante da estrutura buscando o menor valor.
    Em qualquer análise, sua complexidade é de ordem quadrática
    independendo de o vetor estar ordenado ou não; porém, é um algoritmo
    de fácil implementação (vez que pode ser feito com laços de repetição
    e dispensa vetores auxiliares). Em vetores de pequeno porte, é dos 
    métodos mais velozes; mas, em compensação, é dos mais lentos em 
    grandes vetores.


    /////////////// QUICK SORT
    O Quick Sort é o que apresenta o melhor desempenho entre os algoritmos
    de ordenação, pois, apesar de apresentar complexidade quadrática no
    seu pior caso, ele traz um desempenho bastante razoável nos casos de
    menor e média complexidade, sendo o mais indicado de todos os métodos.
    Ele funciona em três partes: a) define um elemento como pivô; b) rearruma
    a lista ordenando os maiores elementos a direita do pivo e os menores 
    a sua esquerda; c) recursivamente ordena as sublistas de cada lado.


    /////////////// SHELL SORT
    O método de ordenação Shell Sort percorre o vetor e o dividide em 
    várias porções menores (até chegar na unitária). Em seguida, agrupa
    dois grupos menores em outros maiores usando o método da Insertion
    Sort, ordenando-o, sendo, em vetores muito grande, melhor que o Merge
    Sort. Por isso, é muito eficiente e rápido.


    /////////////// MERGE SORT
    /////////////// QUICK SORT
    /////////////// HEAP SORT
    
*/