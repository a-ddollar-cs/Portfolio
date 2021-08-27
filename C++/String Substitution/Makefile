Sub:  BufferedFile.o  streamSource.o main.o
	g++ -Wall -pedantic -g -o Sub BufferedFile.o  streamSource.o main.o

BufferedFile.o: BufferedFile.cpp 
	g++ -Wall -pedantic -g -std=c++11 -c BufferedFile.cpp

proj5.o: proj5.cpp 
	g++ -Wall -pedantic -g -std=c++11 -c streamSource.cpp

main.o: main.cpp 
	g++ -Wall -pedantic -g -std=c++11 -c main.cpp


clean:
	rm -rf BufferedFile.o  streamSource.o main.o Sub
