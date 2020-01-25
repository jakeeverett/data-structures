GPP=g++
CFLAGS=-Wall -std=c++14 -g -O0 -pedantic-errors

all: main

SortedList.o: SortedList.cpp
	$(GPP) $(CFLAGS) -c SortedList.cpp

Student.o: Student.cpp
	$(GPP) $(CFLAGS) -c Student.cpp

sortedListDr.o: sortedListDr.cpp
	$(GPP) $(CFLAGS) -c sortedListDr.cpp

main: SortedList.o Student.o sortedListDr.o
	$(GPP) -o main SortedList.o Student.o sortedListDr.o

clean:
	rm -rf *.o

run:
	./main
