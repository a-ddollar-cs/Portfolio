//Austin Dollar
//Parallel version of prime counting
//Adapted from the following tutorial Code:
//https://www.tutorialspoint.com/count-primes-in-ranges-in-cplusplus

//Compiled with:
//mpicc -o primecounter Par.cpp -lm 


//Ran with:
//mpirun -n 32 -ppn 4 -f c2_hosts ./primecounter  *upper_bound*


//includes
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>

//isprime remains largely unchanged from sequential version
int isprime(int num)
{
	//only checks positive numbers, if less than or equal to 1, it is not prime 
	//(we will not consider 1 prime)
	if (num <= 1)
	{
		return 0;
	}

	//for loop starts at 2, iterates to the passed number and checks mod to se if prime
	for (int i = 2; i <= num / 2; i++)
	{
		//check modulus, if passes this check, it is not prime
		if ((num % i) == 0)
		{
			return 0;
		}
	}
	return 1; //if it makes it here, then num is prime
}


int main(int argc, char *argv[]) //used command line arguement instead of dealing with inputs with MPI
{
	//setup MPI stuff
	int comm_sz, my_rank;

	//primes inside ranks
	int numprimes;

	//total amount of primes found for the end
	int total;                

	//index for starting point of chec, based upon rank
	int rank_start;  
	
	//step size 
	int skip_evens;          

	//upper bound of calculation
	double  bound;            

	//setup timng
	double start_time, end_time;   

	MPI_Init(&argc, &argv);  //used command line arguement instead of dealing with inputs with MPI

	//MPI setup
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

	//start time
	start_time = MPI_Wtime();		

	//setup starting point based on rank, ensure it is odd
	rank_start = (my_rank * 2) + 1;       

	//set step size
	skip_evens = comm_sz * 2; 

	//initialize counter
	numprimes = 0;                       

	//get bounds from command line arg
	sscanf(argv[1], "%lf", &bound);

	if (my_rank == 0) 
	{
		//print command line, begin loop
		printf("Counting total primes up to %lf\n", bound);
		numprimes = 1;  

		//rank 0 still does work
		for (double n = rank_start; n <= bound; n = n + skip_evens) 
		{
			if (isprime(n))
			{
				numprimes++;
				
			}
		}

		//reduce and populate total primes value
		MPI_Reduce(&numprimes, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

		//end time
		end_time=MPI_Wtime();

		//print results, time
		printf("Total primes is: %d\n", total);
		printf("Total time = %lf seconds\n",end_time-start_time);
	}


	if (my_rank > 0) 
	{
		//work to be done by non 0 ranks (essentially same, just no printing)
		for (double n = rank_start; n <= bound; n = n + skip_evens) 
		{
			if (isprime(n)) 
			{
				numprimes++;
			}
		}

		//reduce and populate total primes value
		MPI_Reduce(&numprimes, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
		
	}

	MPI_Finalize();
}