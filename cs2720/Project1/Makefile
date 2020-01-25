GPP=g++
CFLAGS=-Wall -std=c++14 -g -O0 -pedantic-errors

all: main

UnsortedList.o: UnsortedList.cpp
	$(GPP) $(CFLAGS) -c UnsortedList.cpp

Student.o: Student.cpp
	$(GPP) $(CFLAGS) -c Student.cpp

UnsortedListDr.o: UnsortedListDr.cpp
	$(GPP) $(CFLAGS) -c UnsortedListDr.cpp

main: UnsortedList.o Student.o UnsortedListDr.o
	$(GPP) -o main UnsortedList.o Student.o UnsortedListDr.o

clean:
	rm -rf *.o

run:
	./main
