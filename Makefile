all: sum_nbo

sum_nbo: main.o sum_nbo.o
	g++ -o sum_nbo main.o sum_nbo.o

main.o: sum_nbo.h main.cpp
	g++ -c -o main.o main.cpp

sum_nbo.o: sum_nbo.h sum_nbo.cpp
	g++ -c -o sum_nbo.o sum_nbo.cpp

clean:
	rm -f sum-test
	rm -f *.o
