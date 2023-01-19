
CC=gcc
AR = ar
FLAGS= -Wall -g

all: graph

dijkstrasAlgorithm.o: dijkstrasAlgorithm.c
	$(CC) $(Flags) -fPIC -c dijkstrasAlgorithm.c 

edges.o : edges.c
	$(CC) $(Flags) -fPIC -c edges.c 

graph.o: graph.c
	$(CC) $(Flags) -fPIC -c graph.c 

nodes.o: nodes.c
	$(CC) $(Flags) -fPIC -c nodes.c 

tsp.o : tsp.c
	$(CC) $(Flags) -fPIC -c tsp.c 

main.o: main.c
	$(CC) $(Flags) -fPIC -c main.c 

graph : dijkstrasAlgorithm.o edges.o graph.o nodes.o tsp.o main.o
	$(CC) $(FLAGS) -o graph main.o edges.o nodes.o dijkstrasAlgorithm.o graph.o tsp.o

clean: 
	rm -f  *.o  *.a *.so graph

run : clean all
	./graph < input1.txt > out.txt
	