//Austin Dollar
//Sequential version of prime counting
//Adapted from the following tutorial Code:
//https://www.tutorialspoint.com/count-primes-in-ranges-in-cplusplus

//Compile with:
//g++ Seq.cpp


//Includes
#include <math.h>
#include <cmath>
#include <time.h>
#include <iostream>
using namespace std;


//isprime function, returns 0 if not prime, returns 1 if prime
double isprime(double num) 
{
	//only checks positive numbers, if less than or equal to 1, it is not prime 
	//(we will not consider 1 prime)
	if (num <= 1)
	{
		return 0;
	}
	
	//for loop starts at 2, iterates to the passed number and checks mod to se if prime
	for (double i = 2; i <= num / 2; i++) 
	{
		//check modulus, if passes this check, it is not prime
		if (fmod(num,i) == 0)
		{
			return 0;
		}
	}
	return 1; //if it makes it here, then num is prime
}

//function to count primes
double countPrimes(double strt, double end) 
{
	//init count
	double count = 0;

	//loop through passed boundaries, pass to isprime function
	for (double i = strt; i <= end; i++) 
	{
		if (isprime(i) == 1)
		{
			count++;
		}
	}
	//return prime count
	return count;
}


//main just calls countPrimes function
int main() 
{
	//add gettime
	struct timespec begin, ending;

	//add start and endpoints
	double start = 0, end;  

	cout << endl << "Input n, upper bound for finding primes:" << endl;

	cin >> end;

	//start clock after input
	clock_gettime(CLOCK_MONOTONIC_RAW, &begin);

	double total = countPrimes(start, end);

	//stop clock after getting primes
	clock_gettime(CLOCK_MONOTONIC_RAW, &ending);
	
	//output answer and time
	cout << endl << "Primes in Range: " << total << endl;

	printf("Total time = %f seconds\n", (ending.tv_nsec - begin.tv_nsec) / 1000000000.0 + (ending.tv_sec - begin.tv_sec));

	return 0;
}




