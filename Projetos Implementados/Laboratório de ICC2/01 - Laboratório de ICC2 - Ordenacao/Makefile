objects = ordenacao.c main.c

all : $(objects)
	gcc $(objects) -o all -Wall -Werror -g

fila.o : ordenacao.h ordenacao.c

main.o : ordenacao.h

run : all
	./all

clean: 
	rm *.o teste