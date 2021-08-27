minq: main.o minpriority.o
	g++  main.o minpriority.o -o minq

main.o: main.cpp minpriority.h
	g++ -Wall -W -Werror -pedantic -g -std=c++11 -c main.cpp

minpriority.o: minpriority.cpp minpriority.h
	g++ -Wall -W -Werror -pedantic -g -std=c++11 -c minpriority.cpp

clean:
	rm -f minq  minq.exe main.o minpriority.o

