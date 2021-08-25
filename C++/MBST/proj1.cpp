//Camerini's Algorithim
//Project 1
//Austin Dollar

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <list>
using namespace std;



struct edge
{


		int w;
		int v;

		int uO;
		int vO;

		edge(int U, int V, int W, int uo, int vo)
		{
			uO = U;
			v = V;
			w = W;
			uO = uo;
			vO = vo;
		};

		edge(int U, int V, int W)
		{
			uO = U;
			v = V;
			vO = V;
			w = W;

		}

		int getVo()
		{
			return vO;
		};

		int getUo()
		{
			return uO;
		};

		int getV()
		{
			return v;
		};

		int getW()
		{
			return w;
		};

		void setV(int s)
		{
			v = s;
		};

};


int select(vector<int> &v, int start, int fin, int k);
void MBST(vector<list<edge> > &adjA);
void collect_weights(vector<list<edge>> &adjA, vector<int> &weights);
void select_smallest(vector<list<edge>> &adjA, vector<list<edge>> &adjB, int median);
int connected(vector<list<edge>> &adjA, vector<short int> cc, vector<int> &index);
void dfsVisit(vector<list<edge>> &adjA, int i, vector<bool> &visited, int id, vector<int> &index);








//This function is called inside "mbst" function
//vector v contains all weights of edges in the graph
//start and fin are the starting and ending indices in v (inclusive: 0, and (v.size()-1))
//int k is the index of the median (calculated in mbst)
int select(vector<int> &v, int start, int fin, int k) 
{

	int vsize = fin - start + 1;

	if (start == fin)
		return v[start];
	else if (start > fin)
		return -1;

	if (vsize <= 5) 
	{
		sort(v.begin() + start, v.begin() + fin + 1);

		return v[k];
	}

	int msize = ceil((double)vsize / 5);

	vector<int> medians(msize, 0);

	int med_ind = 0;

	for (int i = start; i <= fin; i = i + 5) 
	{
		vector<int> temp(5, 0);
		int j = 0;
		for (; j < 5 && (i + j) <= fin; j++) 
		{
			temp[j] = v[i + j];
		}//for j
		if (j < 5)
			temp.resize(j);
		sort(temp.begin(), temp.end());
		if (j == 5)
			medians[med_ind++] = temp[2];
		else 
		{
			int jmid = j >> 1;//divide by 2
			if (j % 2 == 0)
				jmid--;
			medians[med_ind++] = temp[jmid];

		}
	}//for i
	//so far we selected medians of n/5 groups of 5 elem
	int mid = msize >> 1; //divide by 2
	if ((msize % 2) == 0)
		mid--;

	int x = select(medians, 0, msize - 1, mid);
	//partition v's elements around x
	//find x
	int indx = -1;
	for (int i = start; i <= fin; i++) 
	{
		if (v[i] == x) 
		{
			indx = i;
			break;
		}
	}//for i
	if (indx == -1)
		return -2;

	int t = v[start];
	v[start] = x;
	v[indx] = t;
	int i = start + 1, j = fin;

	while (i < j) 
	{
		if (v[i] > x && v[j] <= x) 
		{
			t = v[j];
			v[j] = v[i];
			v[i] = t;
			i++;
			j--;
		}//if
		else if (v[i] <= x) 
		{
			i++;
			if (i > fin) 
			{
				i--;
				break;
			}
		}
		else
		{
			j--;
			if (j == 0) 
			{
				j++;
				break;
			}
		}
	}//while partition
	
	int last = i;

	if (v[i] > x)
		last--;//last index that has less than or equal elemenents than x

			   //count how many elements are equal to x
	int count_equal = 0;
	for (int u = start; u <= last; u++) 
	{
		if (v[u] == x)
			count_equal++;
	}//for u

	if (k > (last - count_equal) && k <= last)
		return x;
	else if (last < k)
		return select(v, last + 1, fin, k);
	else
		return select(v, start, last, k);
}//select



/*********************************************
1. Initially, in adjA's vector is indexed by vertices of
original graph, and for each edge (u, v),
adjA[u] has v
adjA[v] has u

2. At each recursive call adjA will be different
(see parameters passed in the recursive calls below)

3. Once you reach the termination condition, print out
the required output and return

4. Do not do anything after recursive call
***********************************************/
void MBST(vector<list<edge> > &adjA) 
{

	//Count the number of edges in adjA
	int m = 0;
	int size = adjA.size();

	for (int i = 0; i < size; i++) 
	{
		m += adjA[i].size();
	}

	m = m >> 1;//divide by 2, each edge occurs twice in Adj

	//termination case, if the number of edges is 1, print out the output and return
	if (m == 1) 
	{
		//print out the output

		    unsigned int i = adjA.size() -1;

		
			
			for (list<edge>::iterator itr = adjA[i].begin(); itr != adjA[i].end(); itr++)
			{
				if (itr->getUo() < itr->getVo())
				{
					int U = itr->getUo();
					int V = itr->getVo();

					cout << U << " " << V << " " << itr->getW() << endl;
				}
				else
				{
					int U = itr->getUo();
					int V = itr->getVo();

					cout << V << " " << U << " " << itr->getW() << endl;
				}
			}
		

		return;
	}

	/***********   Collect weights of edges **********/
	vector<int> weights(m, 0);
	//You need to write this function:
	//We need to add only one weight for each edge (u, v)
	//Since each edge occurs in adjA twice, use this condition to add the weight only once:
	//if u < v, then add weight
	collect_weights(adjA, weights);



	/*******   Find the median of weights *********/
	int k = m >> 1;//divide by 2
	if (m % 2 == 0)
		k--;
	int median_weight = select(weights, 0, m - 1, k);
	//Function "select" is provided above


	/*****  Collect edges with weights <= median_weight
			from adjA into adjB
			Erase an edge from adjA:
			it takes O(1) to erase (use erase) from
			a list
	*************************************************/
	vector< list<edge> > adjB(adjA.size());//smallest edges

	//You need to write this function
	//when adding the smallest half edges to adjB, erase them from adjA:
	select_smallest(adjA, adjB, median_weight);


	/******* Find connected components in adjB
			in linear time
	 ***************************************/
	vector<short int> cc(adjB.size());
	vector<int> index(adjB.size());

	int total_cc = connected(adjB, cc, index);//number of comp is returned



	/**********     If connected (only one component)
			we don't need edges of A anymore
			just call recursively MBST and return
			after the recursive call returns
			i.e. do nothing after recursive call returns
	****************************************/

	if (total_cc == 1) 
	{
		MBST(adjB);
		return;
	}
	else 
	{ //If not connected

	   /******   You need to find a function that
		   constructs adjC (a new graph)
		   with contracted connected components
		   Construct adjC:
		   each vertex of C corresponds to a single connected component of adjB,
		   add each edge from adjA if this edge is between different connected components.

		   Rename edges of adjC according to the names
		   of their new vertices (connected components) as 0, 1,.., total_cc-1.
	   **************************************************/

		vector<list<edge>> adjC;
		adjC.resize(total_cc);

		for (unsigned int i = 0; i < adjA.size(); i++) 
		{
			for (list<edge>::iterator itr = adjA[i].begin(); itr != adjA[i].end(); itr++)
			{

				if (index[i] != index[itr->v])
				{
					edge topush(index[i], index[itr->v], itr->w, itr->uO, itr->vO);
					adjC[index[i]].push_back(topush);
				}
			}
		}



	   //call recursively MBST on adjC: 

		MBST(adjC);

		/*** In original Camerini's algorithm, at this place of the program,
			 we would add edges from adjB (use original names)
			 into the resulting graph MBST, but
			 in this project we don't need to do anything here.
		 *****************************************/

		return;
	}//else not connected
}//MBST recursive



void collect_weights(vector<list<edge>> &adjA, vector<int> &weights)
{
	int index;
	index = 0;

	for (unsigned int i = 0; i < adjA.size(); i++)
	{

		for (list<edge>::iterator itr = adjA[i].begin(); itr != adjA[i].end(); itr++)
		{
			int j = static_cast<int>(i);

			if (j < itr->getV())
			{
				weights[index++] = itr->getW();
			}
		}
	}

}



void select_smallest(vector<list<edge>> &adjA, vector<list<edge>> &adjB, int median)
{
	for (unsigned int i = 0; i < adjA.size(); i++)
	{
		
		for (list<edge>::iterator itr = adjA[i].begin(); itr != adjA[i].end();)
		{
			if (itr->getW() <= median)
			{
				edge toadd(i, itr->getV(), itr->getW(), itr->getUo(), itr->getVo());
				adjB[i].push_back(toadd);
				itr = adjA[i].erase(itr);
			}
			else
			{
				itr++;
			}
			
		}
	}

}



int connected(vector<list<edge>> &adjA, vector<short int> cc, vector<int> &index) {

	int id = 0;

	vector<bool> visit(adjA.size(), false);

	for (unsigned int i = 0; i < adjA.size(); i++) 
	{
		if (!visit[i]) 
		{
			dfsVisit(adjA, i, visit, id, index);
			id++;
		}
	}

	return id;
}



void dfsVisit(vector<list<edge>> &adjA, int i, vector<bool> &visit, int id, vector<int> &index) {

	if (!visit[i])
	{
		visit[i] = true;

		index[i] = id;


		for (list<edge>::iterator itr = adjA[i].begin(); itr != adjA[i].end(); itr++)
		{
			dfsVisit(adjA, itr->getV(), visit, id, index);
		}

	}

}



int main()
{

	vector<list<edge>> AdjA;

	int u;
	int v;
	int w;
	int n;
	int m;

	cin >> n >> m;

	AdjA.resize(n);

	for (int i = 0; i < n; i++)
	{
		list<edge> distance;
		AdjA[i] = distance;
	}

	for (int j = 0; j < m; j++)
	{
		cin >> u >> v >> w;
		edge fromu(u, v, w);
		edge fromv(v, u, w);
		AdjA[u].push_back(fromu);
		AdjA[v].push_back(fromv);
	}

	MBST(AdjA);

	return 0;
}
