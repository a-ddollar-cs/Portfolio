//compile with g++ -o Riemann Riemann.cpp
//creates executable ./Riemann


//includes
#include <iostream>
#include <math.h>


using namespace std;

//function
double f(double x)
{
	return sin(x);
}

//main driver
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

	for (int i = 0; i < segments; i++) 
	{
		ifx += f(lower) * h;
		lower += h;
	}

	cout << "The integral of the equation using Riemann Sum is:  " << ifx << endl;


	return 0;
}

