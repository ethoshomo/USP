//////////////////////////////////////////////////// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////// MAIN
int main(){

    char caracter = ' ';
    FILE *cursorArquivo = NULL;
    cursorArquivo = fopen("temporario.c", "w");

    if (cursorArquivo != NULL)
    {

        fprintf(cursorArquivo, "#include <stdio.h>");
        fputc('\n', cursorArquivo);
        fprintf(cursorArquivo, "#include <stdlib.h>");
        fputc('\n', cursorArquivo);
        fputc('\n', cursorArquivo);
        fprintf(cursorArquivo, "int main(){");
        fputc('\n', cursorArquivo);
        fprintf(cursorArquivo, "\tchar memoria[30000];");
        fputc('\n', cursorArquivo);
        fprintf(cursorArquivo, "\tint indice = 0;");
        fputc('\n', cursorArquivo);
        fputc('\n', cursorArquivo);
        fprintf(cursorArquivo, "\tfor (int contador = 0; contador < 30000; contador++)");
        fputc('\n', cursorArquivo);
        fprintf(cursorArquivo, "\t\tmemoria[contador] = 0;");
        fputc('\n', cursorArquivo);
        fputc('\n', cursorArquivo);


        do
        {
            caracter = getchar();

            switch(caracter)
            {
                case '+':
                    fprintf(cursorArquivo, "\tmemoria[indice]++;");
                    fputc('\n', cursorArquivo);
                    break;

                case '-':
                    fprintf(cursorArquivo, "\tmemoria[indice]--;");
                    fputc('\n', cursorArquivo);
                    break;

                case '>':
                    fprintf(cursorArquivo, "\tindice++;");
                    fputc('\n', cursorArquivo);
                    break;

                case '<':
                    fprintf(cursorArquivo, "\tindice--;");
                    fputc('\n', cursorArquivo);
                    break;

                case '.':
                    fprintf(cursorArquivo, "\tputchar(memoria[indice]);");
                    fputc('\n', cursorArquivo);
                    break;

                case '[':
                    fprintf(cursorArquivo, "\twhile(memoria[indice] != 0){");
                    fputc('\n', cursorArquivo);
                    break;

                case ']':
                    fprintf(cursorArquivo, "}");
                    fputc('\n', cursorArquivo);
                    break;

                default: //Despreza quaisquer outras opções
                    break;
            }

        }while(caracter != EOF);

        fprintf(cursorArquivo, "\tprintf(\"\\n\");");
        fputc('\n', cursorArquivo);
        fprintf(cursorArquivo,  "\tfor (int contador = 0; contador < 30000; contador++) {");
        fputc('\n', cursorArquivo);
        fprintf(cursorArquivo, "\t\tif (memoria[contador] != 0) {");
        fputc('\n', cursorArquivo);
        fprintf(cursorArquivo, "\t\t\tprintf(\"%%d \", memoria[contador]);");
        fputc('\n', cursorArquivo);
        fprintf(cursorArquivo, "\t\t}");
        fputc('\n', cursorArquivo);
        fprintf(cursorArquivo, "\t}");
        fputc('\n', cursorArquivo);
        fprintf(cursorArquivo, "\tprintf(\"\\n\");");
        fputc('\n', cursorArquivo);
        fputc('\n', cursorArquivo);
        fprintf(cursorArquivo, "\treturn 0;");
        fputc('\n', cursorArquivo);
        fprintf(cursorArquivo, "}");

    }
    else
    {
        printf("Falha na abertura do Arquivo.\n");
        fclose(cursorArquivo);
        exit(1);
    }

    fclose(cursorArquivo);


    system("gcc temporario.c -o temporario");
    system("./temporario");

    return 0;

}
