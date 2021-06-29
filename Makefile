all: domletters

domletters: main.o get_count.o
	g++ -g -o domletters main.o get_count.o

main.o: main.cpp hw1.h
	g++ -c -g main.cpp hw1.h

get_count.o: get_count.cpp hw1.h
	g++ -c -g get_count.cpp hw1.h

clean:
	rm domletters *.o *~
