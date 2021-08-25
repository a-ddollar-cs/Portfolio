//proj4 cpp
//project 5
//SAIS part 3/finalization
//Austin Dollar

#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <climits>
#include <iostream>
#include <utility>
#include <queue>
#include <fstream>
#include <sstream>
using namespace std;

bool LMScompare(int prev, int index, vector<int>&T, vector<bool> &t)
{
	int a = -1;
	int b = -1;

	int c = prev;
	int d = index;

	while ((a != 0 || t[c] != true) && (b != 0 || t[d] != true) && c < (int)T.size() && d < (int)T.size())
	{
		if (T[c] != T[d] || t[c] != t[d])
		{
			return false;
		}

		if (t[c] == true)
		{
			a = 1;
		}
		else
		{
			a = 0;
		}
		c = c + 1;
		if (t[d] == true)
		{
			b = 1;
		}
		else
		{
			b = 0;
		}
		d = d + 1;
	}

	if (T[c] != T[d] || t[c] != t[d])
	{
		return false;
	}

	return true;
}

vector<int> SAIS(vector<int> &T, vector<int> &SA, int alphabetSize)
{
	// 0) termination condition here

	if (alphabetSize == (int)T.size())
	{
		for (int i = 0; i < (int)T.size(); i++)
		{
			SA[T[i]] = i;
		}

		return SA;
	}

	//1) Calculate Array A

	vector<int> A(alphabetSize, 0);

	for (int i = 0; i < (int)T.size(); i++)
	{
		int character = T[i];
		A[character]++;
	}

	//1) Calculate Array C

	vector<int> C(alphabetSize, 0);

	C[0] = 0;
	C[1] = 1;
	C[2] = A[0] + A[1];

	for (int i = 3; i < (int)A.size(); i++)
	{
		C[i] = C[i - 1] + A[i - 1];
	}


	//1) Calculate Array B

	vector<int> B(alphabetSize, 0);

	B[alphabetSize - 1] = T.size() - 1;

	for (int i = (int)A.size() - 2; i >= 0; i--)
	{
		B[i] = B[i + 1] - A[i + 1];
	}
	
	//1)calculate Array t (f = L type, t = S type)

	vector<bool> t(T.size(), false);

	t[T.size() - 1] = true;

	for (int i = (int)T.size() - 2; i >= 0; i--)
	{
		if (T[i] > T[i + 1])
		{
			t[i] = false;

			if (t[i + 1] == true)
			{
				int character = T[i + 1];
				SA[B[character]] = i + 1;
				B[character]--;
			}
		}
		else if (T[i] < T[i + 1])
		{
			t[i] = true;
		}
		else
		{
			if (t[i + 1] == true)
			{
				t[i] = true;
			}
			else
			{
				t[i] = false;
			}
		}
	}

	//calculate lms

	vector<int> lms(T.size());

	for (int i = (int)T.size() - 1; i > 0; i--)
	{
		if ((t[i] == true) && (t[i - 1] == false))
		{
			lms[i] = 1;
		}
		else
		{
			lms[i] = 0;
		}
	}

	//1) fix Array B

	for (int i = 0; i < (int)B.size(); i++)
	{
		B[i] = C[i];
	}

	//1) Calculate SA


	for (int i = 0; i < (int)SA.size(); i++)
	{
		int a = SA[i];
		int b = a - 1;

		if (b < 0)
		{
			b = (int)T.size() + b;
		}

		if (a > (-1))
		{
			if (!(t[b]))
			{
				SA[B[T[b]]] = b;
				B[T[b]] = B[T[b]] + 1;
			}
		}
	}

	int num = (int)A.size() - 1;
	B[num] = T.size() - 1;

	for (int i = num - 1; i >= 0; i--)
	{
		B[i] = B[i + 1] - A[i + 1];
	}


	vector<int> L(SA.size());


	for (int i = (int)SA.size() - 1; i >= 0; i--)
	{
		int a = SA[i];
		int b = a - 1;

		if (b < 0)
		{
			b = (int)T.size() + b;
		}

		if (a > (-1))
		{
			if (t[b])
			{
				SA[B[T[b]]] = b;
				B[T[b]] = B[T[b]] - 1;
			}
		}
	}

	//end P3 Work

	int prev = -1;
	int name = -1;
	vector<int>N(T.size(), -1);

	for (int i = 0; i < (int)SA.size(); i++)
	{
		if (lms[SA[i]] == 1)
		{
			if (prev == (-1))
			{
				name = name + 1;
				N[SA[i]] = name;
				prev = SA[i];
			}
			else
			{
				if (LMScompare(prev, SA[i], T, t) == true)
				{
					N[SA[i]] = name;
				}
				else
				{
					name = name + 1; 
					N[SA[i]] = name;
				}

				prev = SA[i];
			}
		}
	}

	//end p4 work


	vector<int> T0;

	for (int i = 0; i <(int)N.size(); i++)
	{
		if (N[i] != -1)
		{
			T0.push_back(N[i]);
		}
	}

	vector<int> SA0(T0.size(), -1);
	int T0Biggest = *max_element(T0.begin(), T0.end());
	SAIS(T0, SA0, T0Biggest + 1);
	int f = 0;

	for (int i = 0; i <(int)lms.size(); i++)
	{
		if (lms[i] == 1)
		{
			T0[f] = i;
			f = f + 1;
		}
	}

	vector<int> A0(alphabetSize, 0);
	vector<int> C0(alphabetSize, 0);

	for (int i = 0; i <(int)T.size(); i++)
	{
		A0[T[i]] = A0[T[i]] + 1;
	}

	for (int i = 1; i <(int)A0.size(); i++)
	{
		C0[i] = C0[i - 1] + A0[i - 1];
	}
	
	vector<int> B0(alphabetSize, 0);
	B0[C.size() - 1] = T.size() - 1;
	
	for (int i =(int)C0.size() - 1; i > 0; --i)
	{
		B0[i - 1] = C0[i] - 1;
	}

	vector<int> B1 = B0;
	vector<int> SA1(T.size(), -1);
	
	for (unsigned i = SA0.size(); i-- > 0;)
	{
		int q = T0[SA0[i]];
		SA1[B0[T[q]]] = q;
		B0[T[q]] = B0[T[q]] - 1;
	}

	for (int i = 0; i <(int)SA1.size(); i++)
	{
		if (SA1[i] == -1)
		{
			continue;
		}
		if (SA1[i] == 0)
		{
			continue;
		}
		else
		{
			int y = SA1[i] - 1;
			
			if (t[y] == 0)
			{
				SA1[C0[T[y]]] = y;
				C0[T[y]] = C0[T[y]] + 1;
			}
		}
	}
	//
	for (unsigned i = SA1.size(); i-- > 0;)
	{
		if (SA1[i] == -1)
		{
			continue;
		}
		if (SA1[i] == 0)
		{
			continue;
		}
		else
		{

			int y = SA1[i] - 1;

			if (t[y] == 1)
			{
				SA1[B1[T[y]]] = y;
				B1[T[y]] = B1[T[y]] - 1;
			}
		}
	}

	SA = SA1;
	return SA;
}




int main()
{
	string S("");
	string aline;

	while (getline(cin, aline))
	{
		S = S + aline;
	}

	vector<int> count(257, 0);

	//mark chars in S

	int size = (int)S.size();

	for (int i = 0; i < size; i++)
	{
		int index = (int)S[i];
		count[index] = 1;    //this char is in S
	}

	//assign chars in S integer names
	//0 is sentinel char
	int name = 1;
	for (int j = 0; j < 257; j++)
	{
		if (count[j] > 0)
		{
			count[j] = name;
			name++;
		}
	}

	//convert input string to vector of ints
	//in P3 description, T -> Tint
	//here S-> T
	vector<int> T;

	for (int i = 0; i < size; i++)
	{
		int index = (int)S[i]; //char to ASCII
		int aname = count[index];
		T.push_back(aname);
	}
	T.push_back(0); //append sentinel char

	vector<int> SA(T.size(), -1);
	int alphabetSize = name;
	
	vector<int> returner = SAIS(T, SA, alphabetSize);

	for (int i = 0; i < (int)returner.size(); i++)
	{
		if (SA[i] == 0)
		{
			continue;
		}
		int p = returner[i];
		int prev = p - 1;
		cout << S[prev];
	}

	cout << endl;

	return 0;
}
