INCLUDE_DIRS = -I/opt/intel/compilers_and_libraries_2020.0.166/linux/mpi/intel64/include/
LIB_DIRS = -L/opt/intel/compilers_and_libraries_2020.0.166/linux/mpi/intel64/lib/debug -L/opt/intel/compilers_and_libraries_2020.0.166/linux/mpi/intel64/lib
#LIB_DIRS = -L/opt/intel/compilers_and_libraries_2020.0.166/linux/mpi/intel64/lib/release -L/opt/intel/compilers_and_libraries_2020.0.166/linux/mpi/intel64/lib
CC = mpicc
CXX = mpicxx

CDEFS=
CFLAGS= -g -Wall $(INCLUDE_DIRS) $(CDEFS)
LIBS=

PRODUCT= MPITrap

HFILES= 
CFILES= MPITrap.cpp

SRCS= ${HFILES} ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	${PRODUCT}

clean:
	-rm -f *.o *.NEW *~
	-rm -f ${PRODUCT} ${DERIVED} ${GARBAGE}


MPITrap:	MPITrap.cpp
	$(CXX) $(CFLAGS) -o $@ MPITrap.cpp $(LIB_DIRS)

