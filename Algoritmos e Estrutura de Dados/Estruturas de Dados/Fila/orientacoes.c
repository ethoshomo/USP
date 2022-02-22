/*
   As filas seguem a noção natural do termo (como filas em bancos, aeroportos, cinemas).
   Assim, trata-se de uma sequência de informações que são gravadas em um vetor estático,
   porém nada impede que se use alocação dinâmica.

   Aproxima-se das pilhas, uma vez que basicamente possui as mesmas funções.
   Mas, ao mesmo tempo, distancia-se dela na medida em que verificamos diferenças
   relativas ao incremento (no final do vetor) e ao decremento (inicio do vetor).
   Tanto que as pilhas são do tipo "last in, first out" e as filas "first in, first out".

   A variável "inicio" aponta para o início da fila, enquanto a "fim" aponta para a posição
   que vai receber o próximo elemento (note que não aponta para o último elemento inserido).
   Além disso, temos a variável "total" que será usada para controlar se a fila está vazia
   ou cheia.

   Os problemas das filas residem na utilização do total de células reservadas aos vetores,
   sem, contudo, aumentar a complexidade do programa. Nesse momento, o programador deve ficar 
   atento principalmente à forma de retorno ao inicio do vetor (por meio de um vetor circular), 
   ou utilizar deslocamentos à esquerda (não recomendado), mas também deve cuidar observando a 
   forma de contabilizar se o vetor está cheio ou vazio.

*/