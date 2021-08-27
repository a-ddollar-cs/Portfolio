/**
 * @file hash.cpp Implements a hash table, utilizing the hash function
 * given in hash_function.cpp
 *
 * @brief implements a hash table used to store strings of up to 5
 * letter words.
 *
 * @author Austin Dollar
 * @date March 1, 2020
 *
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include "hash.h"

using std::string;


/**
 * @brief The Hash constructor, initializes the hash 
 *
 */

Hash::Hash()
{
        collisions = 0;
        longestList = 0;
        runningAvgListLength = 0;
        numElements = 0;
}




/**
 * @brief Print the hash table to standard output, with
 * each array location on its own line
 */

void Hash::print()
{
        for(int i=0; i<HASH_TABLE_SIZE; i++)
        {
                std::cout << i << ":\t";

                for(auto x: hashTable[i] )
                {
                        std:: cout << x << ", ";
                }
                std::cout << std::endl;
        }

}




/**
 * @brief remove the word from the hashtable
 *
 *
 * @param string word, the word to remove
 *
 */

void Hash::remove(string word)
{
        int key_r = hf(word);

        list <string> :: iterator i;
        for (i = hashTable[key_r].begin(); i != hashTable[key_r].end(); i++) 
        {
                if (*i == word) 
                {
                        break;
                }
        }
        if(i != hashTable[key_r].end())
        {
                hashTable[key_r].erase(i);
        }
        runningAvgListLength = (hashTable[key_r].size() +
                                runningAvgListLength) / 2.0;
        



}



/**
 * @brief Add all words from file "filename" to the table
 *
 *
 * @param The file name to take in and add to table
 *
 */

void Hash::processFile(string filename)
{
        string word;
        int key;
        std::ifstream inFile;
        inFile.open(filename);

        while (inFile >> word)
        {
                key = hf(word);

                if(!hashTable[key].empty())
                {
                        collisions++;
                }

                hashTable[key].push_back(word);
                ++numElements;
                if(hashTable[key].size() > longestList)
                {
                        longestList = hashTable[key].size(); 
                }

                runningAvgListLength = (hashTable[key].size() + 
                                runningAvgListLength) / 2.0;
        }
        inFile.close();
}



/**
 * @brief Search for the given word to see if it is in table
 *
 * @param string word, the word to look for
 *
 * @return bool, true if word is found
 *
 */

bool Hash::search(string word)
{
        int key_f = hf(word);

        list <string> :: iterator i;
        for (i = hashTable[key_f].begin(); i != hashTable[key_f].end(); i++) 
        {
                if (*i == word) 
                {
                        return true;
                        break;
                }
        }
        return false;
}



/**
 * @brief Output the table to specified filename
 *
 *
 * @param string filename the file to output to
 *
 */

void Hash::output(string filename)
{
        std::ofstream outFile;
        outFile.open(filename);

        for(int i=0; i<HASH_TABLE_SIZE; i++)
        {
                outFile << i << ":\t";

                for(auto x: hashTable[i] )
                {
                        outFile << x << ", ";
                }
                outFile<< std::endl;
        }

        outFile.close();

}



/**
 * @brief Print the hash table statistics
 *
 */

void Hash::printStats()
{
        std::cout << "Total Collisions = " << collisions << std::endl;
        std::cout << "Longest List Ever = " << longestList << std::endl;
        std::cout << "Average List Length Over Time = "
                << runningAvgListLength << std::endl;
        
        double loadFactor = numElements/HASH_TABLE_SIZE;
       
        std::cout << "Load Factor = " << loadFactor << std::endl;

}



