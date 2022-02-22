objects = main.c polinomios.c

all : $(objects)
	gcc $(objects) -o all -g

polinomios.o : polinomios.h polinomios.c

main.o : polinomios.h

run :
	./all

clean: 
	rm *.o teste