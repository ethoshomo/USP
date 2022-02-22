objects = quad.c main.c

all : $(objects)
	gcc $(objects) -o all

quad.o : quad.h quad.c

main.o : quad.h

run : all
	./all

clean: 
	rm *.o