objects = main.c lista.c

all : $(objects)
	gcc $(objects) -o all

main.o : lista.h

lista.o : lista.h lista.c

run :
	./all

clean: 
	rm *.o teste