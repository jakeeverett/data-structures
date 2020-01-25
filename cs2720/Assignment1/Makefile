GPP=g++
CFLAGS=-Wall -std=c++14 -g -O0 -pedantic-errors

all: main

QueType.o: QueType.cpp
	$(GPP) $(CFLAGS) -c QueType.cpp

QueDr.o: QueDr.cpp
	$(GPP) $(CFLAGS) -c QueDr.cpp

main: QueType.o QueDr.o
	$(GPP) -o main QueType.o QueDr.o

clean:
	rm -rf *.o

run:
	./main
