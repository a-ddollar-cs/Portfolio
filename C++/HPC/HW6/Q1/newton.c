// https://www.codewithc.com/c-program-for-newton-raphson-method/
//
#include<stdio.h>
#include<math.h>
#include <time.h>

double f(double x)
{
    
    return (-(x*x*x) + 9.7*(x*x) -1.3*x -105.7);
}

double df (double x)
{
    
    return (-3*(x*x)+19.4*x-1.3);
}

int main(void)
{
 //add gettime
    struct timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &begin);

    int itr, maxmitr;
    double h, x0, x1, allerr;
    printf("\nEnter x0 guess to find first root, allowed error and maximum iterations\n");
    scanf("%lf %lf %d", &x0, &allerr, &maxmitr);

    for (itr=1; itr<=maxmitr; itr++)
    {
        h=f(x0)/df(x0);
        x1=x0-h;
        printf("Iteration: %3d, x = %9.6f\n", itr, x1);
        if (fabs(h) < allerr)
        {
            printf("After %3d iterations, root = %8.6f\n", itr, x1);
		clock_gettime(CLOCK_MONOTONIC_RAW, &end);
		printf ("Total time = %f seconds\n", (end.tv_nsec - begin.tv_nsec) / 1000000000.0 + (end.tv_sec  - begin.tv_sec));

            return 0;
        }
        x0=x1;
    }
    printf(" The required solution does not converge or iterations are insufficient\n");
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	printf ("Total time = %f seconds\n", (end.tv_nsec - begin.tv_nsec) / 1000000000.0 + (end.tv_sec  - begin.tv_sec));

    return 1;
}
