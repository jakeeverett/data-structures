GPP=g++
CFLAGS=-Wall -std=c++14 -g -O0 -pedantic-errors

all: main

PriorityQueue.o: PriorityQueue.cpp
	$(GPP) $(CFLAGS) -c PriorityQueue.cpp

PriorityQueueDr.o: PriorityQueueDr.cpp
	$(GPP) $(CFLAGS) -c PriorityQueueDr.cpp

main: PriorityQueue.o PriorityQueueDr.o
	$(GPP) -o main PriorityQueue.o PriorityQueueDr.o

clean:
	rm -rf *.o

run:
	./main
