Jacob Everett
811660133

Project creates Unsorted lists of different types with accompanying methods to be used by the user

Using the make file to compile:

Compile:
make

Clean:
make clean

Running:
make run

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Without using the Makefile:

Compile:
g++ UnsortedList.cpp -c
g++ Student.cpp -c
g++ UnsortedList.o Student.o UnsortedListDr.cpp -o main

Running:
./main