objects = compressao.c main.c

all : $(objects)
	gcc $(objects) -o all -Wall -Werror -g -lm

compressao.o : compressao.h compressao.c

main.o : compressao.h

run : all
	./all

clean: 
	rm *.o teste