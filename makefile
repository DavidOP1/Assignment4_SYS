CC=gcc
OBJECTS_MAIN=main.o
FLAGS= -Wall -g

all: graph algo.o main.o 
graph :algo.o main.o 
	$(CC) $(FLAGS)   -o graph $(OBJECTS_MAIN) algo.o
algo.o: algo.c algo.h 
	$(CC) $(FLAGS) -c algo.c algo.h 
main.o: main.c algo.h 
	$(CC) $(FLAGS) -c main.c 
.PHONY: clean all
clean:
	rm -f *.o *.a *.so *.h.gch graph