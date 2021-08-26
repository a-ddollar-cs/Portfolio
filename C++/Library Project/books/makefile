book: book.o 
	g++  book.o -o book

book.o: book.cpp book.h
	g++ -Wall -W -Werror -pedantic -g -std=c++11 -c book.cpp

clean:
	rm -f book  book.exe book.o 
