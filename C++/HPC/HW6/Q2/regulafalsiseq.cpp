//https://www.codewithc.com/c-program-for-regula-falsi-method/
//
#include<stdio.h>
#include<math.h>
#include <time.h>

double f(double x)
{

	return (cos(x*x));
}

void regula(double *x, double x0, double x1, double fx0, double fx1, int *itr)
{
	*x = x0 - ((x1 - x0) / (fx1 - fx0))*fx0;
	++(*itr);
	//printf("Iteration no. %3d X = %7.5f \n", *itr, *x);
}

//turned old main into a function called in a loop
double calcR(int itr, int maxmitr, double x0, double x1, double x2, double x3, double allerr)
{
	
	regula(&x2, x0, x1, f(x0), f(x1), &itr);
	do
	{
		if (f(x0)*f(x2) < 0)
			x1 = x2;
		else
			x0 = x2;
		regula(&x3, x0, x1, f(x0), f(x1), &itr);
		if (fabs(x3 - x2) < allerr)
		{
			//printf("root = %6.4f\n", x3);
			return x3;
		}
		x2 = x3;
	} while (itr < maxmitr);
	
	printf("Solution does not converge or iterations not sufficient:\n");

	return 10000;
}


int main(void)
{
	//add gettime
	struct timespec begin, end;
	

	int itr = 0, maxmitr;
	double x0, x1, x2, x3, allerr;

	printf("\nEnter the values of lower bound, upper bound, allowed error and maximum iterations:\n");
	scanf("%lf %lf %lf %d", &x0, &x1, &allerr, &maxmitr);

	clock_gettime(CLOCK_MONOTONIC_RAW, &begin);

	for (double i = x0; i < x1; i = i + 0.1)
	{
		double sol = calcR(itr, maxmitr, x0, i, x2, x3, allerr);


		if (sol != 10000 && sol < x1 && sol > x0)
		{
			printf("root = %6.4f\n \n", sol);
		}

		//x0 = sol;
	}

	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	printf("Total time = %f seconds\n", (end.tv_nsec - begin.tv_nsec) / 1000000000.0 + (end.tv_sec - begin.tv_sec));

}
