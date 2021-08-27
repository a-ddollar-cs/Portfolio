/**
 * @file minpriority.h header file for minpriority.cpp
 *
 * @brief provides function declarations to be utilized by minpriority.cpp
 *
 * @author Austin Dollar
 *
 * @date March 9, 2020
 *
 */


#ifndef MINPRIORITY_H
#define MINPRIORITY_H

#include <vector>
#include <sstream>
#include <string>

using std::string;
using std::vector;

class MinPriorityQueue
{
        public:
                MinPriorityQueue();
                ~MinPriorityQueue();
                void insert(const string& id, int key);
                void decreaseKey(string id, int newKey);
                string extractMin();



        private:

                void buildMinHeap();
                void minHeapify(int i);
                int parent(int i);
                int left(int i);
                int right(int i);

                class Element
                {
                        public:
                                string* id;
                                int key;

                                Element();
                                Element(const string& m_id, int m_key);
                                ~Element();
                };

                vector<Element*> minHeap;




};

#endif //CSCI311_MINPRIORITY_H
