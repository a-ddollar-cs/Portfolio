video: video.o 
	g++  video.o -o video

video.o: video.cpp video.h
	g++ -Wall -W -Werror -pedantic -g -std=c++11 -c video.cpp

clean:
	rm -f video  video.exe video.o 
