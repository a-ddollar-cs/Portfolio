/**
 * @file CensusDataSorts.cpp   Sort functions for census population data.
 * 
 * @brief
 *    Implements several different types of sorts. Data can be sorted
 * by population or by name of town. This file contains all of the sorting
 * functions and their helpers.
 *
 * @author Judy Challinger and Austin Dollar
 * @date 2/17/20
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include "CensusData.h"

/**
 * @brief implementation of insertion sort
 *
 * @summary detirmines which type of sorting and 
 * calls corresponding insertion sort.
 *
 * @param int type holds the type of sorting method,
 * either 0 for population, or 1 for name.
 *
 */
void CensusData::insertionSort(int type) 
{

        if(type == 0)
        {
                insertionSortPop();
        }
        else if (type == 1)
        {
                insertionSortName();
        }
}

/**
 * @brief implementation of insertion sort by population
 *
 * @summary sorts by population using insertion sort
 *
 */
void CensusData::insertionSortPop()
{
        int n = data.size();
        int i, j; 
        Record* tmp;
        for(i=1; i<n; i++)
        {
                j =i -1;
                tmp=data[i];
                while(j>=0 && tmp-> population <data[j]-> population)
                {
                        data[j+1] = data[j];
                        j--;
                }
                data[j+1]=tmp;
        }


}

/**
 * @brief implementation of insertion sort by name
 *
 * @summary sorts by name using insertion sort
 *
 */
void CensusData::insertionSortName()
{
        int n = data.size();
        int i, j;
        Record* tmp;
        for(i=1; i<n; i++)
        {
                j=i-1;
                tmp=data[i];
                while(j>=0 && *(tmp-> city)<*(data[j]-> city))
                {
                        data[j+1]=data[j];
                        j--;
                }
                data[j+1]=tmp;
        }


}



/**
 * @brief Implementation of merge sort,
 * detirmines type of sorting, implements
 * the corresponding merge sort. 
 *
 * @param int type holds the type of sorting method,
 * either 0 for population, or 1 for name
 *
 */
void CensusData::mergeSort(int type) 
{
        if(type == 0)
        {
                mergeSortPop(0, data.size()-1);
        }
        else if(type == 1)
        {
                mergeSortName(0, data.size()-1);
        }
}


/**
 * @brief implementation of merge sort by population
 *
 * @summary sorts by population using merge sort
 *
 * @param int l, r holds the left and right bound of the vector
 */
void CensusData::mergeSortPop(int l, int r )
{
        if(l<r)
        {
                int q = (l+r)/2;
                mergeSortPop(l,q);
                mergeSortPop(q+1, r);
                mergePop(l,q,r);
        }


}


/**
 * @brief implementation of merge to supplement merge sort
 *
 * @summary helps sort by population using merge sort
 *
 * @param int l, q, r holds left, right, and middle of vector
 */
void CensusData::mergePop(int l, int q, int r)
{
        int i, j, k;
        int n1 = q-l+1;
        int n2 = r-q;
        vector <Record*> L;
        vector <Record*> R;

        for(i= 0; i<n1; i++)
        {
                L.push_back(data[l+i]);
        }
        for(j=0; j<n2; j++)
        {
                R.push_back(data[q+1+j]);
        }

        i=0;
        j=0;
        k=l;

        while(i<n1 && j<n2)
        {
                if(L[i]->population <= R[j]->population)
                {
                        data[k] = L[i];
                        i++;
                }
                else
                {
                        data[k] = R[j];
                        j++;
                }
                k++;
        }

        while(i<n1)
        {
                data[k] = L[i];
                i++;
                k++;
        }

        while(j<n2)
        {
                data[k] = R[j];
                j++;
                k++;
        }



}
/**
 * @brief implementation of merge sort by name
 *
 * @summary sorts by name using merge sort
 *
 * @param int l, r holds left, and right of vector
 *
 */
void CensusData::mergeSortName(int l, int r)
{
        if(l<r)
        {
                int q = (l+r)/2;
                mergeSortName(l,q);
                mergeSortName(q+1, r);
                mergeName(l,q,r);
        }

}


/**
 * @brief implementation of merge to supplement merge sort
 *
 * @summary helps sort by name using merge sort
 *
 * @param int l, q, r holds left, right, and middle of vector
 */
void CensusData::mergeName(int l, int q, int r)
{
        int i, j, k;
        int n1 = q-l+1;
        int n2 = r-q;
        vector <Record*> L;
        vector <Record*> R;

        for(i= 0; i<n1; i++)
        {
                L.push_back(data[l+i]);
        }
        for(j=0; j<n2; j++)
        {
                R.push_back(data[q+1+j]);
        }

        i=0;
        j=0;
        k=l;

        while(i<n1 && j<n2)
        {
                if(*(L[i]->city) <= *(R[j]->city))
                {
                        data[k] = L[i];
                        i++;
                }
                else
                {
                        data[k] = R[j];
                        j++;
                }
                k++;
        }

        while(i<n1)
        {
                data[k] = L[i];
                i++;
                k++;
        }

        while(j<n2)
        {
                data[k] = R[j];
                j++;
                k++;
        }


}



/**
 * @brief implementation of a randomized quick sort
 *
 * @summary detirmines the type of sorting, implements the 
 * corresponding quick sort
 *
 * @param int type holds the type of sorting method,
 * either 0 for population, or 1 for name.
 *
 */
void CensusData::quickSort(int type) 
{
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();


        if(type == 0)
        {
                quickSortPop(0,data.size()-1, seed);
        }
        else if(type == 1)
        {
                quickSortName(0, data.size()-1, seed);
        }
}

/**
 * @brief implementation of quick  sort by population
 *
 * @summary sorts by population  using quick sort
 *
 * @param int l, r holds bounds for the vector, unsigned seed holds pivot
 */
void CensusData::quickSortPop(int l, int r, unsigned seed)
{


        if(l<r)
        {
                int q = partitionPop(l, r, seed);
                quickSortPop(l, q -1, seed);
                quickSortPop(q+1, r, seed);

        }
}



/**
 * @brief helper function for implementation of quick  sort by population
 *
 * @summary sorts by population  using quick sort
 *
 * @param int l, r holds bounds for the vector, unsigned seed holds pivot
 */

int CensusData::partitionPop(int l, int r, unsigned seed )
{
        std::default_random_engine generator (seed);
        std::uniform_int_distribution<int> distribution(l,r);

        std::swap(data[distribution(generator)], data[r]);

        int pivot = r;
        int i = (l -1);
        for(int j = l; j <= r-1; j++)
        {
                if(data[j]->population < data[pivot]->population)
                {
                        i++;
                        std::swap(data[i], data[j]);
                }
        }
        std::swap(data[i+1], data[r]);
        return (i+1);


}
/**
 * @brief implementation of quick sort by name
 *
 * @summary sorts by name using quick sort
 *
 */
void CensusData::quickSortName( int l, int r, unsigned seed)
{
        if(l<r)
        {
                int q = partitionName(l, r, seed);
                quickSortName(l, q -1, seed);
                quickSortName(q+1, r, seed);

        }


}



/**
 * @brief helper function for implementation of quick  sort by name
 *
 * @summary sorts by name  using quick sort
 *
 * @param int l, r holds bounds for the vector, unsigned seed holds pivot
 */
int CensusData::partitionName(int l, int r, unsigned seed)
{
         std::default_random_engine generator (seed);
        std::uniform_int_distribution<int> distribution(l,r);

        std::swap(data[distribution(generator)], data[r]);

        int pivot = r;
        int i = (l -1);
        for(int j = l; j <= r-1; j++)
        {
                if(*(data[j]->city) < *(data[pivot]->city))
                {
                        i++;
                        std::swap(data[i], data[j]);
                }
        }
        std::swap(data[i+1], data[r]);
        return (i+1);


}
