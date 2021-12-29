//ommppi.c

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>


//defined count as a global var for command line to modify
long long unsigned int COUNT;
//#define COUNT  1000ULL


//using 2 threads as defined in documentation
#define NUM_THREADS (2)


//parameters for the thread
typedef struct
{
	int threadIdx;
} threadParams_t;


// POSIX thread declarations and scheduling attributes
pthread_t threads[NUM_THREADS];
threadParams_t threadParams[NUM_THREADS];

// Thread specific globals - static initializer must be updated for sub-ranges
double pi_approx;


//main driver function
int main(int argc, char *argv[])
{
	long int i;
	double factor = 1.0;
	double sum = 0.0;

	//error check cmd line
	if (argc != 2)
	{
		printf("must give a value for n\n");
		return 1;
	}
	//modified count to be command line arg
	COUNT = strtol(argv[1], NULL, 10);

#pragma omp parallel num_threads(thread_count) \ reduction(+:sum)
	for (i = 0; i < COUNT; i++)
	{
		sum += factor / (2 * i + 1);
		factor = -factor;
	}

	pi_approx = 4.0*sum;
	


	printf("TEST COMPLETE: pi_approx=%f\n", pi_approx);
}

