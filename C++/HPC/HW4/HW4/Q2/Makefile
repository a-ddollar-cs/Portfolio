INCLUDE_DIRS = -I/opt/intel/compilers_and_libraries_2020.0.166/linux/mpi/intel64/include/
LIB_DIRS = -L/opt/intel/compilers_and_libraries_2020.0.166/linux/mpi/intel64/lib/debug -L/opt/intel/compilers_and_libraries_2020.0.166/linux/mpi/intel64/lib
#LIB_DIRS = -L/opt/intel/compilers_and_libraries_2020.0.166/linux/mpi/intel64/lib/release -L/opt/intel/compilers_and_libraries_2020.0.166/linux/mpi/intel64/lib
CC = mpicc
CXX = mpicxx

CDEFS=
CFLAGS= -g -Wall $(INCLUDE_DIRS) $(CDEFS)
LIBS=

PRODUCT= MPILeft

HFILES= 
CFILES= MPILeft.cpp

SRCS= ${HFILES} ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	${PRODUCT}

clean:
	-rm -f *.o *.NEW *~
	-rm -f ${PRODUCT} ${DERIVED} ${GARBAGE}


MPITrap:	MPILeft.cpp
	$(CXX) $(CFLAGS) -o $@ MPILeft.cpp $(LIB_DIRS)

