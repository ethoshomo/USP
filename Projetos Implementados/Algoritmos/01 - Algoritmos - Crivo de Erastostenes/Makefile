objects = crivo.c main.c

all : $(objects)
	gcc $(objects) -o all -Wall -Werror -g

crivo.o : crivo.h crivo.c

main.o : crivo.h

run : all
	./all