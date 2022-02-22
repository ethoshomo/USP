void maxHeapify(int *v, int p, int N){

        //comecando em um nó "p"
        // 1 - verificar os filhos e, caso quebrem a condição
        //     de heap, trocar o maior filho com o pai.
        // 2 - Chamar recursivamente se houver troca.

        //filho da esquerda (2.p)
        int f = p*2;

        // Garantir que o nó não é folha
        // Se o filho calculado excede o tamanho do vetor
        // então
        if (f > N) {return 0;}

        // verificar a condição de heap com relação aos filhos
        // f = p*2 -> esquerda
        // f+1 = p*2 + 1 -> direita
        // se qualquer dos filhos for maior, troca e chama recursivamente
        if ((v[f] > v[p]) || (((f+1) <= N) && (v[f+1] > v[p]))){

            //se entrou no if, sabemos que ao menos um dos filhos é maior.
            // verifica-se qual filho é maior: direita ou esquerda.
            if (((f+1) <= N) && (v[f+1] > v[f]))
                f = f+1; //se for o da direita, atualiza f.

            //troca
            int tmp = v[p];
            v[p] = v[f];
            v[f] = tmp;

            // chamada recursiva (potencialmente até uma folha)
            maxHeapify(v, f, N);

        }
}

/* Monta um maxheap a partir de um vetor arbitrário
 *
 * Parâmetro:
 *      - int* v: árvore cofificada em vetor
 *      - int N: número de elementos 
*/
void buildMaxHeap(int *v, int N){
    int m = (int)N/2.0; // Último nó pai
    for(int p = m; p >= 1; p--){
        maxHeapify(v, p, N);
    }
}

/* Monta o mecanismo de ordenação
 *
 * Parâmetro:
 *      - int* v: árvore cofificada em vetor
 *      - int N: número de elementos 
*/
void heapsort(int* v, int N){
    buildMaxHeap(v, N);
    while (N>=2){
        // seleciona maior: raiz (lembrar que a posição 0 é descartada)
        int maior = v[1];
        //troca com a posição do último
        v[1] = v[N];
        v[N] = maior;
        N--;
        // remontar o maxheap (sempre a raiz):
        maxHeapify(v, 1, N)
    }
}