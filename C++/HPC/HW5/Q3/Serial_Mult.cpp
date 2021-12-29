//serial_mult

#include <stdio.h>
#include <stdlib.h>

#include<iostream>
using namespace std;
int main() {
	int product[10000][10000], rx, cx, ry, cy, i, j, k;

	//matrix A
	cout << "Enter rows for matrix A:" << endl;
	cin >> rx;

	cout << "Enter cols for matrix A:" << endl;
	cin >> ry;


	//matrix A
	cout << "Enter rows for matrix B:" << endl;
	cin >> cx;

	cout << "Enter cols for matrix B:" << endl;
	cin >> cy;
	
	int a[rx][ry];
	int b[cx][cy];

	cout << "Enter Values for Marix A:" << endl;
	for (int q = 0; q < rx; q++)
		for (int p = 0; p < ry; p++)
		{
			cin >> a[q][p];
		}

	cout << "Enter Values for Marix B:" << endl;
		for (int q = 0; q < cx; q++)
			for (int p = 0; p < cy; p++)
			{
				cin >> b[q][p];
			}

	if (cx != ry) {
		cout << "Column of first matrix should be equal to row of second matrix";
	}
	else {
		cout << "The first matrix is:" << endl;
		for (i = 0; i < rx; ++i) {
			for (j = 0; j < cx; ++j)
				cout << a[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		cout << "The second matrix is:" << endl;
		for (i = 0; i < ry; ++i) {
			for (j = 0; j < cy; ++j)
				cout << b[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		for (i = 0; i < rx; ++i)
			for (j = 0; j < cy; ++j) {
				product[i][j] = 0;
			}
		for (i = 0; i < rx; ++i)
			for (j = 0; j < cy; ++j)
				for (k = 0; k < cx; ++k) {
					product[i][j] += a[i][k] * b[k][j];
				}
		cout << "Product of the two matrices is:" << endl;
		for (i = 0; i < rx; ++i) {
			for (j = 0; j < cy; ++j)
				cout << product[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}
