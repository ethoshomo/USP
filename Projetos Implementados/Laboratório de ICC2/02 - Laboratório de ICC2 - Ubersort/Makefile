objects = main.c ubersort.c

all : $(objects)
	gcc $(objects) -o all

main.o : ubersort.h

ubersort.o : ubersort.h ubersort.c

run :
	./all

clean: 
	rm *.o teste