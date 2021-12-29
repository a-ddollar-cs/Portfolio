//compile with g++ -o Trapezoid Traprule.cpp
//creates executable ./Trapezoid


//includes
#include <iostream>
#include <math.h>

using namespace std;

//define function
double f(double x)
{
	return sin(x);
}

int main()
{
	//vars to read in (lower, upper, segments
	double lower;
	double upper;
	int segments;

	//get limits of integration
	cout << "Enter the lower limit of the integral : ";
	cin >> lower;

	cout << "Enter the upper limit of the integral : ";
	cin >> upper;

	//number of segments
	cout << "Enter the number of segments you want : ";
	cin >> segments;

	double h = abs((upper - lower)) / segments;
	double ifx = 0;
	ifx = ifx + f(lower) + f(upper);

	for (double i = lower + h; i < upper;) 
	{
		ifx = ifx + (2 * f(i));
		i = i + h;
	}

	ifx = ifx * h / 2;

	cout << "The integral of the equation using Trapezoidal Sum is  " << ifx << endl;
}

