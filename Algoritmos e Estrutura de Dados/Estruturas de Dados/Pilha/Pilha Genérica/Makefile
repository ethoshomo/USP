objects = pilha.o main.o 

teste : $(objects)
	gcc $(objects) -o teste -Werror -Wall -g

pilha.o : pilha.h
main.o : pilha.h

clean :
	rm *.o teste