objects = fila.c main.c

teste : $(objects)
	gcc $(objects) -o teste -Wall -Werror -g

fila.o : fila.h fila.c

main.o : fila.h

clean: 
	rm *.o teste