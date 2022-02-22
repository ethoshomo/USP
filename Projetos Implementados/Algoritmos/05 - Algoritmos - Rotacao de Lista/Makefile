objects = rotacao.c main.c

all : $(objects)
	gcc $(objects) -o all -Wall -Werror -g

fila.o : rotacao.h rotacao.c

main.o : rotacao.h

run : all
	./all

clean: 
	rm *.o teste