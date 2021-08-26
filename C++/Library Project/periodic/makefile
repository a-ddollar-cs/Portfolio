periodic: periodic.o 
	g++  periodic.o -o periodic

periodic.o: periodic.cpp periodic.h
	g++ -Wall -W -Werror -pedantic -g -std=c++11 -c periodic.cpp

clean:
	rm -f periodic  periodic.exe periodic.o 
