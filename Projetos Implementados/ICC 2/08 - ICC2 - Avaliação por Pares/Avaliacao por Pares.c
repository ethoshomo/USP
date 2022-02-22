/*
 *	A orientação do trabalho foi para analisar o código e contabilizar as operações nele
 *  descritas (com variáveis "a" e "b"), considerando a função final em função do 
 *  tamanho do vetor. As variáveis "a" e "b" deveriam seguir o seguinte critério: 
 *		- "a": operações aritméticas e as atribuições.
 *		- "b": comparações e operações lógicas.
 *	Quaisquer outras operações foram desconsideradas.
 */

void algoritmo1(int *values, int N) { 
            // Função que recebe um ponteiro e seu tamanho. 
				    // Temos, portanto, "N" como variável da função.
				    // Abaixo, adotaremos: N = n.

      int i, j = 0; 	
                    // Temos uma atribuição (j=0) - Logo: a
      int tmp; 		
                    // Nada.

      for (i = 0; i < N; i++) { 
    				// Trata-se de um laço de repetição, que irá iterar "n" vezes. De forma didática,
            // podemos decompor suas operações em:
            // a) operações de cabeçalho
            // b) operações de conteúdo.
            //
            //                  ---------Operações de Cabeçalho---------------
            // Primeira iteração: ao entrar em um laço, temos as seguintes operações
            //                    sendo realizadas e que não serão todas repetidas:
            //      atribuição (i=0) - Logo: a
    				// 			comparação (i<n) - Logo: b
    				// 			Total: (a + b)
    				//
            // Demais iterações: repetições do laço:
            //      comparação (i<n) - Logo: b
    				//			operação e atribuição (i++: i = i+1) - Logo: 2a
    				// 			Observação: essas iterações se repetem (n-1) vezes.
    				//			Total: (2a + b)(n-1)
            //
            // Iteração de saída: a iteração de saída deve acontecer uma única vez
            //                    e não vai repetir o conteúdo dentro do laço.
            //          operação e atribuição (i++: i = i+1) - Logo: 2a
            //          comparação (i<n) - Logo: b
            //
    				// Portanto: (2a + b) + (a + b) + (2a + b)(n - 1)
            // 
            //                  ---------Operações de Conteúdo---------------
         
            for (j = 0; j < N; j++) { 
                  // Trata-se de um laço de repetição aninhado dentro do laço de repetição 
                  // anterior. Por isso, ele será repetido "n" vezes. Seguirá a mesma lógica
                  // do laço acima.
                  //
                  //                  ---------Operações de Cabeçalho---------------
                  // Primeira iteração: ao entrar em um laço, temos as seguintes operações
                  //                    sendo realizadas e que não serão todas repetidas:
                  //      atribuição (j=0) - Logo: a
                  // 			comparação (j<n) - Logo: b
                  // 			Total: (a + b)
                  //
                  // Demais iterações: repetições do laço:
                  //      comparação (j<n) - Logo: b
                  //			operação e atribuição (j++: j = j+1) - Logo: 2a
                  // 			Observação: essas iterações se repetem (n-1) vezes.
                  //			Total: (2a + b)(n-1)
                  //
                  // Iteração de saída: a iteração de saída deve acontecer uma única vez
                  //                    e não vai repetir o conteúdo dentro do laço.
                  //          operação e atribuição (j++: j = j+1) - Logo: 2a
                  //          comparação (j<n) - Logo: b
                  //  
                  // Portanto: (2a + b) + (a + b) + (2a + b)(n - 1)
                  //
                  //                  ---------Operações de Conteúdo--------------
                  // O conteúdo abaixo será repetido "n" vezes pelo laço de repetição interno.

                	if (values[j] > values[j+1]) { 
                          // comparação (values[j] > values [j+1]) - Logo: b
                          // operação (j+1) - Logo: a
                          // Total: (a + b)
                      
                          tmp = values[j+1]; 	 
                                // operacao e atribuição (j+1 e tmp=values[j+1]) - Logo: 2a
                      
                          values[j+1] = values[j]; 
                                // operacao e atribuição (j+1 e values[j+1] = values[j]) - Logo: 2a
                      
                          values[j] = tmp; 	 
                                // atribuição (values[j] = tmp) - Logo: a
                  //
                  // Total de operações: (a+b)+(2a)+(2a)+(a)
          	}
      	}
  }         
}


/* 
* -----------------------------------------------------------------------------------------
* Organizando:
*   a
*     -> referente a atribuição antes do for
*  
*   (2a + b) + (a + b) + (2a + b)(n - 1) = a + b n(2a + b)
*        -> referente ao cabeçalho do primeiro laço.
*
*   n (multiplica tudo abaixo)           
*        -> referente ao conteúdo do primeiro laço
*
*   (2a + b) + (a + b) + (2a + b)(n - 1) = a + b n(2a + b)
*        -> referente ao cabeçalho do segundo laço.
*
*   n((a+b)+(2a)+(2a)+(a))
*        -> referente ao conteúdo do segundo laço e seu conteúdo.
*
* Simplificando:
* f(n) = a + a + b + n(2a + b) + n{a + b + n(2a + b) + n[(a+b)+(2a)+(2a)+(a)]}
* f(n) = 2a + b + 2an + bn + n{a + b + 8an + 2bn}
* f(n) = 2a + b + 3an + 2bn + 8an² + 2bn²
* f(n) = n²(8a + 2b) + n(3a + 2b) + 2a + b
*
* Resultado Final: 
* f(n) = n²(8a + 2b) + n(3a + 2b) + 2a + b
*
* -----------------------------------------------------------------------------------------
*/