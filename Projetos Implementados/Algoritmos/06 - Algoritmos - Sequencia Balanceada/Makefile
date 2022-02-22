objects = balanceada.c main.c

all : $(objects)
	gcc $(objects) -o all -Wall -Werror -g

fila.o : balanceada.h balanceada.c

main.o : balanceada.h

run : all
	./all

clean: 
	rm *.o teste