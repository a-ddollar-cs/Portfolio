/* This assignment originated at UC Riverside */

#include "hash.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setprecision;

int
main ( ) {

  Hash hashTable;
  cout << setprecision ( 10 );
  cout << "Test 1 - print empty table" << endl;
  hashTable.print ( );
  cout << "-------------------------------------------------------------"
       << endl;
  cout << "Test 2 - processing input file" << endl;
  hashTable.processFile ( "sgb-words.txt" );
  hashTable.print ( );
  cout << "-------------------------------------------------------------"
          << endl;
          hashTable.printStats();
  return 1;
}
