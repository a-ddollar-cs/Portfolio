//compile with makefile included in the Q3 folder


//includes
#include <iostream>
#include <math.h>
#include <mpi.h>

using namespace std;

//define function
double f(double x)
{
	return sin(x);
}

double trap(double left, double right, int trap_count, double base_len )
{
	double estimate, x;
	int i;

	estimate = (f(left) + f(right)) / 2.0;
	for (i = 1; i <= trap_count - 1; i++)
	{
		x = left + i * base_len;
		estimate += f(x);
	}

	estimate = estimate * base_len;

	return estimate;

}

int main()
{
	//mpi stuff
	int comm_sz;	//Num procs
	int my_rank;	//proc rank
	int n = 1024;
	int local_n;
	double a = 0, b=3.14, h, local_a, local_b;
	double local_int, total_int;
	int source;


	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);


	h = (b - a) / n;
	local_n = n / comm_sz;

	local_a = a + my_rank * local_n*h;
	local_b = local_a + local_n * h;
	local_int = trap(local_a, local_b, local_n, h);

	if (my_rank != 0)
	{
		MPI_Send(&local_int, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
	}
	else
	{
		total_int = local_int;
		for (source = 1; source < comm_sz; source++)
		{
			MPI_Recv(&local_int, 1, MPI_DOUBLE, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			total_int += local_int;
		}
	}

	if (my_rank == 0)
	{
		cout << "Integral is: " << total_int << endl;
	}

	MPI_Finalize();
	return 0;

}

