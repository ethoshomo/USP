#include <stdio.h>
#include <time.h>

/* msleep(): Sleep for the requested number of milliseconds. */
void msleep(long msec){
    struct timespec ts;

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    nanosleep(&ts, &ts);
}

int main(){
    // Exemplo de execução da função msleep:
    // A cada iteração do loop, o programa dorme por uma duração cada vez maior
    for (int i = 0; i <= 10; i++){
        int qte_milissegundos = i * 100;
        printf("Dormindo por %d milissegundos\n", qte_milissegundos);
        
        // Basta chamar a função passando como argumento a quantidade de milissegundos que seu programa deve "dormir"
        msleep(qte_milissegundos); 
    }

    return 0;
}

