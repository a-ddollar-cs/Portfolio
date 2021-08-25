/*
 * Proj2.cpp 
 * Austin Dollar
 * Min Cut partition of a palindrome 
 */



#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;



/* Backtracking function that recursively calls itself to find and make cuts, then print palindromes */
void backtracking(const char *str, vector<int> B, int idx)
{
	if (idx < 0)     //base case for recursion, if reach end of inputted string
	{
		return;
	}


	backtracking(str, B, B[idx] - 1);  //recursively call backtracking to find all cuts and print out the palindromes created

	for (int i = idx; i >= B[idx]; i--)
	{
		cout << str[i];
	}

	cout << endl;
}



/*  creates and populates the tables P, C, B */
void makeTables(const char *str, int strSize)
{

	// create tables P, C, B
	vector<int> C(strSize);
	vector<int> B(strSize);
	vector<vector<int> > P(strSize);

	//resize P to fit the string
	for (int i = 0; i < strSize; i++)
	{
		P[i].resize(strSize);
	}

    //Fill the P Table following given psuedocode
	for (int i = 0; i < strSize; i++)
	{
		P[i][i] = true;
	}

	for (int subStringSize = 2; subStringSize <= strSize; subStringSize++)  
	{
		int j;
		
		for (int i = 0; i < strSize - subStringSize + 1; i++)
		{
			j = i + subStringSize - 1;

			if (subStringSize == 2)   //base case, if size is 2, compare both ends
			{
				P[i][j] = (str[i] == str[j]);
			}
			else                     //compare and update entire P table 
			{
				P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
			}
		}
	}

	//Fill Table C, and B following given psuedocode
	for (int i = 0; i < strSize; i++)
	{
		if (i == 0)  
		{
			C[i] = 0;
			B[i] = 0;
		}
		else if (P[0][i] == true) 
		{
			C[i] = 0;
			B[i] = 0;
		}
		else
		{
			C[i] = INT_MAX;

			for (int k = 0; k < i; k++)
			{
				if (P[k + 1][i] == true && C[k] + 1 < C[i]) 
				{
					C[i] = 1 + C[k];
					B[i] = k + 1;
				}
			}
		}
	}
	backtracking(str, B, strSize - 1);
}



int main()
{
	//reads cin and turn the string into a character array for indexing, saving size
	string palindrome;
	cin >> palindrome;
	const char *str = palindrome.c_str();
	int size = palindrome.size();

	//run driver function
	makeTables(str, size);
	return 0;
}

