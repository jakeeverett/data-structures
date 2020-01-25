GPP=g++
CFLAGS=-Wall -std=c++14 -g -O0 -pedantic-errors

all: main

QueType.o: QueType.cpp
	$(GPP) $(CFLAGS) -c QueType.cpp

PriorityQueue.o: PriorityQueue.cpp
	$(GPP) $(CFLAGS) -c PriorityQueue.cpp

Customer.o: Customer.cpp
	$(GPP) $(CFLAGS) -c Customer.cpp
 
BankSimulations.o: BankSimulations.cpp
	$(GPP) $(CFLAGS) -c BankSimulations.cpp

main: QueType.o PriorityQueue.o BankSimulations.o
	$(GPP) -o main QueType.o PriorityQueue.o BankSimulations.o

clean:
	rm -rf *.o

run:
	./main
