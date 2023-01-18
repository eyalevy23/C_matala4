
CC=gcc
AR = ar
FLAGS= -Wall -g

all: mains

dijkstrasAlgorithm.o: dijkstrasAlgorithm.c
	$(CC) $(Flags) -fPIC -c dijkstrasAlgorithm.c 

edges.o : edges.c
	$(CC) $(Flags) -fPIC -c edges.c 

graph.o: graph.c
	$(CC) $(Flags) -fPIC -c graph.c 

nodes.o: nodes.c
	$(CC) $(Flags) -fPIC -c nodes.c 

main.o: main.c
	$(CC) $(Flags) -fPIC -c main.c 

mains : dijkstrasAlgorithm.o edges.o graph.o nodes.o main.o
	$(CC) $(FLAGS) -o mains main.o edges.o nodes.o dijkstrasAlgorithm.o graph.o

clean: 
	rm -f  *.o  *.a *.so mains

run : 
	./mains < input1.txt
	