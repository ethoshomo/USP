/*
    Título: aprendendo a fazer o Makefile.

    - Pré-requisitos: é necessário ter uma ferramenta GNU instalada, que é o make.
    - Modo de usar: deve-se criar um arquivo chamado "Makefile", o qual vai ter as regras
                  de compilação do programa.
    - Regras:
        -> Os comentários devem ser feitos com o "#" na frente.
        -> Pode-se fazer a declaração de variáveis no início do arquivo.
        -> Em seguida, deve-se atribuir "alvos" com a seguinte sintaxe:

            alvo1 : dependencia_1 dependencia_2
            <TAB> comando

            alvo2 : dependencia_1 dependencia_2
            <TAB> comando

    -Observações: 
        -> Caso o alvo1 seja, por exemplo, o arquivo executável, deve-se colocar como dependência os arquivos -o.
        -> Assim, o alvo2 poderia ser o arquivo -o com dependência do arquivo .c.
        -> O arquivo .c poderia, por exemplo, ser o alvo3 com dependencia em um arquivo .h
*/