CC=gcc
AR=ar
FLAGS= -Wall -g

all: frequency libtrie.so

frequency: main.o libtrie.a
	$(CC) $(FLAGS) -lm -o frequency main.o -L. -ltrie

main.o:	main.c
	$(CC) $(FLAGS) -O -c main.c

trie.o: trie.c trie.h
	$(CC) $(FLAGS) -O -c trie.c

libtrie.a: trie.o
	$(AR) rcs libtrie.a trie.o

libtrie.so: trie.c trie.h
	$(CC) $(FLAGS) trie.c -o libtrie.so -fPIC -shared

libs: libtrie.a libtrie.so

.PHONY: clean all libs

clean:
	rm -f frequency *.o *.a *.so



