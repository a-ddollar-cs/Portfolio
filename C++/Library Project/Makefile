CXX = g++
CXXFLAGS = -c -g -std=c++11 -Wall -W -Werror -pedantic

PROG = SearchEngine
HDRS = SearchEngine.h Media.h book.h film.h periodic.h video.h
SRCS = SearchEngine.cpp Media.cpp book.cpp film.cpp periodic.cpp video.cpp
OBJS = $(SRCS:.cpp=.o)

$(PROG) : $(OBJS)
	$(CXX)  $(OBJS) -o $(PROG)

engi.o :  SearchEngine.cpp    SearchEngine.h
	$(CXX) $(CXXFLAGS) engine.cpp

medi.o: Media.cpp Media.h
		$(CXX) $(CXXFLAGS) Media.cpp

boo.o: book.cpp book.h
		$(CXX) $(CXXFLAGS) book.cpp

fil.o: film.cpp film.h
		$(CXX) $(CXXFLAGS) film.cpp

perio.o: periodic.cpp periodic.h
				$(CXX) $(CXXFLAGS) periodic.cpp

vid.o: video.cpp video.h
						$(CXX) $(CXXFLAGS) video.cpp

clean :
	rm -f core $(PROG) *.o