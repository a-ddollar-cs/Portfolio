/* This assignment originated at UC Riverside.*/
 
#include <string>
#include "hash.h"

using std::string;

//This has function follows the djb2 structure, invented by
//Dan Bernstien. It combines bit manipulation with prime numbers
//to index the hash function and minimize collisions.
//The article I used for reference is provided in the following url:
//https://medium.com/swlh/hash-tables-in-c-with-the-djb2-algorithm-21f14ba7ca88


int Hash::hf ( string ins ) 
{
  
  unsigned long hashing = 5381;
  int x;

  for(int i =0; i< (int)ins.length(); ++i)
  {
          x  = (int) ins[i];
          hashing = ((hashing << 5) + hashing) + x;
  }
  return hashing % HASH_TABLE_SIZE;

}

