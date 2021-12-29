//https://www.codewithc.com/c-program-for-regula-falsi-method/
//
#include<stdio.h>
#include<math.h>
#include <time.h>

double f(double x)
{
    
    return (-(x*x*x) + 9.7*(x*x) -1.3*x -105.7);
}

void regula (double *x, double x0, double x1, double fx0, double fx1, int *itr)
{
    *x = x0 - ((x1 - x0) / (fx1 - fx0))*fx0;
    ++(*itr);
    printf("Iteration no. %3d X = %7.5f \n", *itr, *x);
}

int main(void)
{
    //add gettime
    struct timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &begin);

    int itr = 0, maxmitr;
    double x0,x1,x2,x3,allerr;
    printf("\nEnter the values of x0, x1, allowed error and maximum iterations:\n");
    scanf("%lf %lf %lf %d", &x0, &x1, &allerr, &maxmitr);
    regula (&x2, x0, x1, f(x0), f(x1), &itr);
    do
    {
        if (f(x0)*f(x2) < 0)
            x1=x2;
        else
            x0=x2;
        regula (&x3, x0, x1, f(x0), f(x1), &itr);
        if (fabs(x3-x2) < allerr)
        {
            printf("After %d iterations, root = %6.4f\n", itr, x3);
clock_gettime(CLOCK_MONOTONIC_RAW, &end);
printf ("Total time = %f seconds\n", (end.tv_nsec - begin.tv_nsec) / 1000000000.0 + (end.tv_sec  - begin.tv_sec));

            return 0;
        }
        x2=x3;
    }
    while (itr<maxmitr);
clock_gettime(CLOCK_MONOTONIC_RAW, &end);
printf ("Total time = %f seconds\n", (end.tv_nsec - begin.tv_nsec) / 1000000000.0 + (end.tv_sec  - begin.tv_sec));

    printf("Solution does not converge or iterations not sufficient:\n");

;

	

	

    return 1;
}
