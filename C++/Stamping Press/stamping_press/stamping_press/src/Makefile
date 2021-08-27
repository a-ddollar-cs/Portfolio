CXX = g++
CXXFLAGS =-c -g -std=c++11

stamp_press: main.o stampbuff.o stampstream.o stamp.o
	$(CXX) -o stamp_press main.o stampbuff.o stampstream.o stamp.o 
	
stampbuff.o:  stampbuff.cpp   stampbuff.h

stampstream.o: stampstream.cpp stampstream.h

stamp.o: stamp.cpp stamp.h

main.o: main.cpp

clean:
	rm -f *.o stamp_press 