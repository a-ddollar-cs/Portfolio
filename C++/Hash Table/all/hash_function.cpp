/**
 * @file hash_function.cpp Implements a hash function, which creates the
 * key to be utilized by the hash table in implementation
 *
 * @brief implements a hash function  used to
 * create a hash table that stores strings of up to 5
 * letter words.
 *
 * @author Austin Dollar
 * @date March 1, 2020
 *
 */

 
#include <string>
#include "hash.h"

using std::string;

//This has function follows the djb2 structure, invented by
//Dan Bernstien. It combines bit manipulation with prime numbers
//to index the hash function and minimize collisions.I made a few
//modifications in order to make it my own and make it unique.
//This function works well because it both minimizes collisions, as well 
//as minimizes the length of the lists it creates. 
//The article I used for reference is provided in the following url:
//https://medium.com/swlh/hash-tables-in-c-with-the-djb2-algorithm-21f14ba7ca88


int Hash::hf ( string ins ) 
{
  
  unsigned long hashing = 5381;
  int x;

  for(int i =0; i< (int)ins.length(); ++i)
  {
          x  = (int) ins[i];
          hashing = (hashing<< 5) + hashing + (hashing *33) + x;
  }
  return hashing % HASH_TABLE_SIZE;

}

