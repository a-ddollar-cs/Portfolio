/**
 * @file minpriority.cpp Implements a min priority queue
 *
 * @brief implements a min priority queue which
 * is a priority queue based on a min heap
 *
 * @author Austin Dollar
 *
 * @date March 9, 2020
 *
 */

#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "minpriority.h"
using std::ios;
using std::istringstream;
using std::vector;
using std::string;


/**
 *
 * @brief Element constructor.
 *
 * @param m_id the word to be added
 * @param m_key the priority holder
 *
 */

MinPriorityQueue::Element::Element(const string& m_id, int m_key)
{
        id = new string(m_id);
        key = m_key;
}


/**
 *
 * @brief Element destructor
 *
 */

MinPriorityQueue::Element::~Element()
{
        delete id;
}


/**
 *
 * @brief the Min Priority Queue constuctor, initializes the Queue
 *
 */

MinPriorityQueue::MinPriorityQueue()
{
}


/**
 *
 * @brief Min Priority Queue destructor, deallocates al the memory
 *
 */

MinPriorityQueue::~MinPriorityQueue()
{
}


/**
 *
 * @brief insert a string into the queue with the given priority 
 *
 * @param const string& id the string to insert
 * @param int key the priority of the added string
 *
 */

void MinPriorityQueue::insert(const string& id, int key)
{
        Element* inserter =  new Element(id, key);
        minHeap.push_back(inserter);
        buildMinHeap();
}


/**
 *
 * @brief decrease the key with a new key on the given string
 *
 * @param string id the string to be changed
 * @param int newKey the new decreased key
 *
 */

void MinPriorityQueue::decreaseKey(string id, int newKey)
{
        for(int i =0; i < (int)minHeap.size()-1; i++)
        {
                if(*minHeap[i]->id == id)
                {
                        minHeap[i]->key = newKey;
                        buildMinHeap();
                }
        }
}


/**
 *
 * @brief extract the string at the min point of the list
 *
 * @return string of the min point
 *
 */

string MinPriorityQueue::extractMin()
{
        if((int)minHeap.size() == 0)
        {
                return "empty";
        }
        else 
        {
                return *minHeap[0] ->id;
        }

        minHeap[0] = minHeap.back();
        minHeap.pop_back();
        buildMinHeap();
}


/**
 *
 * @brief build the minheap with the newly added elements
 *
 */

void MinPriorityQueue::buildMinHeap()
{
        int length = minHeap.size();
        for(int i = length / 2; i>0; i--)
        {
                minHeapify(i);
        }
}


/**
 *
 * @brief re heapify to keep the heap balanced and add the int
 *
 * @param int i the int to compare amd balance the heap
 *
 */

void MinPriorityQueue::minHeapify(int i)
{
        int m_left = left(i);
        int m_right = right(i);
        int size = (int)minHeap.size()-1;
        int smallest = i;

        if(minHeap[m_left]->key < size && minHeap[m_left]->key < minHeap[i]->key)
        {
                smallest = m_left;
        }

        if( minHeap[m_right]->key < size && minHeap[m_right]->key <
                        minHeap[smallest]->key)
        {
                smallest = m_right;
        }

        if(minHeap[smallest]->key != minHeap[i]->key)
        {
                std::swap(minHeap[i], minHeap[smallest]);
                minHeapify(smallest);
        }

        if(minHeap[i]->key&& minHeap[parent(i)]->key > minHeap[i]->key)
        {
                std::swap(minHeap[i], minHeap[parent(i)]);
                minHeapify(parent(i));
        }
}


/**
 *
 * @brief a placeholder for the parent in the heap
 *
 * @param int i the holder of the int
 *
 * @return int, return the parent int
 *
 */

int MinPriorityQueue::parent(int i)
{
        return (i-1)/2;
}


/**
 *
 * @brief a placeholder for the left child in the heap
 *
 * @param int i the holder of the int
 *
 * @return int, return the left child int
 *
 */

int MinPriorityQueue::left(int i)
{
        return (2 * i +1);
}


/**
 *
 * @brief a placeholder for the right child in the heap
 *
 * @param int i the holder of the int
 *
 * @return int, return the right child int
 *
 */

int MinPriorityQueue::right(int i)
{
        return (2 * i +2);
}




