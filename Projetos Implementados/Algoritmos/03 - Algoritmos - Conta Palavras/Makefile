objects = main.c palavras.c

all : $(objects)
	gcc $(objects) -o all -Wall -Werror -g

all.o : palavras.h

palavras.o : palavras.c palavras.h

run : all
	./all