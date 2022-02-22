objects = lista.c main.c

teste : $(objects)
	gcc $(objects) -o teste -Wall -Werror -g

fila.o : lista.h lista.c

main.o : lista.h

clean: 
	rm *.o teste