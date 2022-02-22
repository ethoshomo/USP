objects = string.c main.c

all : $(objects)
	gcc $(objects) -o all -Wall -Werror -g

string.o : string.h string.c

main.o : string.h

run : all
	./all