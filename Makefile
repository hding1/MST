PROG=prog2
CC=g++
CPPFLAGS=-g -Wall -std=c++11

.PHONY: all

all:
	$(CC) $(CPPFLAGS) main.cpp forest.cpp UnionFind.cpp -o $(PROG)

clean:
	rm -f *.o $(PROG) core
