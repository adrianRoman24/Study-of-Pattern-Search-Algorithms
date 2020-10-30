CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

all: build1 build2

build1: algo_test1.o

algo1.o: algo1.cpp
	g++ algo1.cpp -c $(CFLAGS)

algo_test1.o: algo_test1.cpp algo1.o
	g++ algo_test1.cpp algo1.cpp -o test1 $(CFLAGS)
PHONY: clean1
clean1:
	rm -rf *.o test1

build2: algo_test2.o

algo2.o: algo2.cpp
	g++ algo2.cpp -c $(CFLAGS)

algo_test2.o: algo_test2.cpp algo2.o
	g++ algo_test2.cpp algo2.cpp -o test2 $(CFLAGS)
PHONY: clean2
clean2:
	rm -rf *.o test2


