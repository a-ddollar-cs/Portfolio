/**
 * @file CensusData.h   Declaration of the CensusData class.
 *
 * @author Judy Challinger and Austin Dollar
 * @date 2/20/20
 */

#ifndef CSCI_311_CENSUSDATA_H
#define CSCI_311_CENSUSDATA_H

#include <vector>
using std::ifstream;
using std::string;
using std::vector;

class CensusData {
public:
   static const int POPULATION = 0;       // type of sort
   static const int NAME = 1;
   ~CensusData();
   void initialize(ifstream&);            // reads in data
   int getSize(){return data.size();}
   void print();                          // prints out data
   void insertionSort(int type);               // sorts data using insertionSort
   void mergeSort(int type);                   // sorts data using mergeSort
   void quickSort(int type);                  // sorts data using quickSort
 
 private:
   void insertionSortPop();
   void insertionSortName();
 
   void swap(int* a, int* b);

   void quickSortName(int l, int r, unsigned seed);
   int partitionName(int l, int r, unsigned seed);

   void quickSortPop(int l, int r, unsigned seed);
   int partitionPop(int l, int r, unsigned seed);

   void mergeName(int l, int q, int r);
   void mergeSortName(int l, int r);

   void mergePop(int l, int q, int r);
   void mergeSortPop(int l, int r);

   class Record {                         // declaration of a Record
   public:
      string* city;
      string* state;
      int population;
      Record(string&, string&, int);
      ~Record();
   };
   vector<Record*> data;                  // data storage

};

#endif // CSCI_311_CENSUSDATA_H