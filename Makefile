CC = gcc
CFLAGS = -g -Wall

solve: solve.o subsets.o
	$(CC) $(CFLAGS) -o solve solve.o subsets.o

test_subsets: test_subsets.o subsets.o
	$(CC) $(CFLAGS) -o test_subsets test_subsets.o subsets.o

solve.o subsets.o test_subsets.o: solve.h

clean:
	-rm -f *.o solve test_subsets
