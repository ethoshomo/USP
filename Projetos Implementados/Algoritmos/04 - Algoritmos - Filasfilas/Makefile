objects = fila.c main.c

all : $(objects)
	gcc $(objects) -o all -Wall -Werror -g

fila.o : fila.h fila.c

main.o : fila.h

run : all
	./all

clean: 
	rm *.o teste