CFLAGS=-O2

all:
	gcc $(CFLAGS) -c main.c -o main.o
	gcc main.o -lbz2 -o main
	objdump -d main > main.s
	objdump -d main.o > main.o.s
