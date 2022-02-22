objects = main.c dicionario.c

all : $(objects)
	gcc $(objects) -o all

main.o : dicionario.h

dicionario.o : dicionario.h dicionario.c

run :
	./all

clean: 
	rm *.o teste