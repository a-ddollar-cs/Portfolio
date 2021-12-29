//compile with makefile included in the Q4 folder

//includes
#include <iostream>
#include <math.h>
#include <mpi.h>

using namespace std;

//define function for velocity
double fv(double time)
{
	// computation of time scale for 1800 seconds
	static double tscale = 1800.0 / (2.0*M_PI);
	// determined such that velocity will peak to result in translation of 122,000.0 meters
	static double vscale = 0.2365893166123*1800.0 / (2.0*M_PI);

	return ((-cos(time / tscale) + 1)*vscale);

}

//function for acceleration
double fa(double time)
{
	// computation of time scale for 1800 seconds
	static double tscale = 1800.0 / (2.0*M_PI);
	// determined such that acceleration will peak to result in translation of 122,000.0 meters
	static double ascale = 0.2365893166123;

	return (sin(time / tscale)*ascale);
}


//trapezoidal sum for accel func
double trapa(double left, double right, int trap_count, double base_len )
{
	double estimate, x;
	int i;

	estimate = (fa(left) + fa(right)) / 2.0;
	for (i = 1; i <= trap_count - 1; i++)
	{
		x = left + i * base_len;
		estimate += fa(x);
	}

	estimate = estimate * base_len;

	return estimate;

}

//trapezoidal sum for accel func
double trapv(double left, double right, int trap_count, double base_len)
{
	double estimate, x;
	int i;

	estimate = (fv(left) + fv(right)) / 2.0;
	for (i = 1; i <= trap_count - 1; i++)
	{
		x = left + i * base_len;
		estimate += fv(x);
	}

	estimate = estimate * base_len;

	return estimate;

}

int main()
{
	//mpi variables
	int comm_sz;	//Num procs
	int my_rank;	//proc rank


	//1/10 s, acceleration variables
	int n = 18000; //amount of steps, so 1800 * 10 for 1/10 of a second
	int local_n;
	double a = 0, b=1800, h, local_a, local_b;       //make b 3.14 when testing with sin(x)
	double local_int, total_int;
	//----------------------------------------------------------------------------------------------


	//1/100 s, acceleration variables
	int n_1 = 180000; //amount of steps, so 1800 * 10 for 1/10 of a second
	int local_n_1;
	double  h_1, local_a_1, local_b_1;       //make b 3.14 when testing with sin(x)
	double local_int_1, total_int_1;
	//----------------------------------------------------------------------------------------------


	//1/10 s, velocity variables
	int n_2 = 18000; //amount of steps, so 1800 * 10 for 1/10 of a second
	int local_n_2;
	double h_2, local_a_2, local_b_2;       //make b 3.14 when testing with sin(x)
	double local_int_2, total_int_2;
	//----------------------------------------------------------------------------------------------


	//1/100 s, velocity variables
	int n_3 = 180000; //amount of steps, so 1800 * 10 for 1/10 of a second
	int local_n_3;
	double  h_3, local_a_3, local_b_3;       //make b 3.14 when testing with sin(x)
	double local_int_3, total_int_3;
	//----------------------------------------------------------------------------------------------


	//setup MPI Stuff
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);



	//1/10 s, acceleration setup
	h = (b - a) / n;
	local_n = n / comm_sz;

	local_a = a + my_rank * local_n*h;
	local_b = local_a + local_n * h;
	local_int = trapa(local_a, local_b, local_n, h);
	//-----------------------------------------------------------------------------------------------


	//1/100 s, acceleration setup
	h_1 = (b - a) / n_1;
	local_n_1 = n_1 / comm_sz;

	local_a_1 = a + my_rank * local_n_1*h_1;
	local_b_1 = local_a_1 + local_n_1 * h_1;
	local_int_1 = trapa(local_a_1, local_b_1, local_n_1, h_1);
	//-----------------------------------------------------------------------------------------------



	//1/10 s, velocity setup
	h_2 = (b - a) / n_2;
	local_n_2 = n_2 / comm_sz;

	local_a_2 = a + my_rank * local_n_2*h_2;
	local_b_2 = local_a_2 + local_n_2 * h_2;
	local_int_2 = trapv(local_a_2, local_b_2, local_n_2, h_2);
	//-----------------------------------------------------------------------------------------------



	//1/10 s, velocity setup
	h_3 = (b - a) / n_3;
	local_n_3 = n_3 / comm_sz;

	local_a_3 = a + my_rank * local_n_3*h_3;
	local_b_3 = local_a_3 + local_n_3 * h_3;
	local_int_3 = trapv(local_a_3, local_b_3, local_n_3, h_3);
	//-----------------------------------------------------------------------------------------------

	if (my_rank != 0)
	{
		MPI_Send(&local_int, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
		MPI_Send(&local_int_1, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
		MPI_Send(&local_int_2, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
		MPI_Send(&local_int_3, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
	}
	
	
	MPI_Reduce(&local_int, &total_int, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce(&local_int_1, &total_int_1, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce(&local_int_2, &total_int_2, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce(&local_int_3, &total_int_3, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	

	if (my_rank == 0)
	{
		cout.precision(17);
		cout << endl << "Trapezoidal Sum using Doubles:" << endl << endl;
		cout << "Integrate Acceleration to get Final Velocity:" << endl;
		cout << "Step size 1/10 s--------Final Velocity: " << fixed << total_int << endl;
		cout << "Step size 1/100 s-------Final Velocity: " << fixed << total_int_1 << endl << endl;
		cout << "Integrate Velocity to get Final Position:" << endl;
		cout << "Step size 1/10 s--------Final Position: " << fixed << total_int_2 << endl;
		cout << "Step size 1/100 s-------Final Position: " << fixed << total_int_3 << endl;
	}

	MPI_Finalize();
	return 0;

}

