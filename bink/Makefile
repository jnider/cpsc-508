CC=gcc
CFLAGS=-O2 -g

all: __stack_chk_fail

__stack_chk_fail: __stack_chk_fail.c
	$(CC) $(CFLAGS) -c $@.c -o $@.o
