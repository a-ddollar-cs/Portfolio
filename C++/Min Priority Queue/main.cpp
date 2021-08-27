/**
 *
 * @file main.cpp main test driver for min Priority queue
 *
 * @brief drives the minPriority Queue with test commands in order
 * to test functionality
 *
 * @author Austin Dollar
 *
 * @date March 9, 2020
 *
 */


#include "minpriority.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>


using std::string;

/**
 *
 * @brief the main test driver for the min Priority Queue
 *
 * @return bool  the return status if there is more input
 *
 */

bool processing(MinPriorityQueue myQ)
{
        string command;
        string* info;
        int key;

        std::cin >> command;

        if(command == "q")
        {
                return false;
        }

        else if(command == "a")
        {
                info = new string;
                std::cin>> *info;
                std::cin>>key;
                myQ.insert(*info, key);
        }

        else if(command == "d")
        {
                info = new string;
                std::cin>> *info;
                std::cin>>key;
                myQ.decreaseKey(*info, key);
        }

        else if(command == "x")
        {
                std::cout<< myQ.extractMin() << std::endl;
        }

        return true;



}


/**
 *
 * @brief main loop implements everything
 *
 * @return int the return status of the program
 *
 */

int main()
{
        MinPriorityQueue myQ;
        while(processing(myQ));
        return 0;
}
