film: film.o 
	g++  film.o -o film

film.o: film.cpp film.h
	g++ -Wall -W -Werror -pedantic -g -std=c++11 -c film.cpp

clean:
	rm -f film  film.exe film.o 
