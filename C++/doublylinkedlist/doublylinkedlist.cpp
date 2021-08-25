/**
 * @file doublylinkedlist.cpp   Implementation of a Doubly Linked List to hold music for Playlist.
 *
 * @brief
 *    Implementation of a  doubly linked list
 *    used to store the song names for class Playlist.
 *
 *
 * @author Austin Dollar
 * @date  January 29, 2020
 */

#include <iostream>
#include <string>
#include <sstream>
#include "doublylinkedlist.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;


/**
 *@brief  Doubly Linked List Constructor.
 * Dynamically allocates a Doubly Linked List
 *
 */
DoublyLinkedList::DoublyLinkedList()
{
        head = NULL;
        tail = NULL;
        current = NULL;

}



/**
 * @brief Doubly Linked List Deconstructor.
 * Deallocates the Doubly Linked List
 *
 */
DoublyLinkedList::~DoublyLinkedList()
{

        Node *deleter = head;

        while(deleter)
        {
                Node* dnext = deleter->next;
                delete deleter;
                deleter = dnext;

        }

}


/**
 *@brief  Doubly Linked List Method Append, adds a song to end of list
 * and makes added song current.
 *
 *@param string& s; name of song wanting to be added
 *
 */
void DoublyLinkedList::append(const string& s)
{

        if(current == NULL)
        {
                current = new Node(s);
                current-> next = NULL;
                current -> prev = NULL;
                tail = head = current;
        }
        else
        {
                tail-> next = new Node(s);
                tail->next -> prev = tail;
                tail->next->next = NULL;
                current = tail = tail->next;
        }
}



/**
 *@brief  Doubly Linked List Method insert before, adds a song before 
 * the current song, makes it the current song
 *
 *@param string& s; name of song wanting to be added
 *
 */
void DoublyLinkedList::insertBefore(const string& s)
{
        if(empty())
        {
                append(s);
        }
        else if(current == head)
        {
                head -> prev = new Node(s);
                head -> prev -> next = head;
                head-> prev-> prev = NULL;
                current = head = head->prev;

        }
        else
        {   
                Node *temp  = new Node(s);
                temp-> prev = current->prev;
                temp-> prev-> next = temp;
                temp-> next = current;
                current -> prev = temp;
                current = temp;
        }
}



/**
 *@brief Doubly Linked List Method Insert After, inserts a song
 * after the current song, makes new song the new current.
 *
 *@param string& s, the name of the song to be added.
 *
 */

void DoublyLinkedList::insertAfter(const string& s)
{
        if(empty())
        {
                append(s);
        }
        else if(current == tail)
        {
                tail-> next = new Node(s);
                tail-> next-> prev = tail;
                tail-> next-> next = NULL;
                current = tail = tail-> next;
        }
        else
        {
                Node *temp = new Node(s);
                temp-> next = current-> next;
                temp-> next-> prev = temp;
                temp-> prev = current;
                current-> next = temp;
                current = temp;
        }

}

/**
 *@brief Doubly Linked List Method Remove, removes the
 *first instance of the given song from the playlist
 *and sets current to the next song, if next doesnt exist,
 *current is previous song.
 *
 *@param string& s, the name of the song to be removed.
 *
 */

void DoublyLinkedList::remove( const string& s)
{
        Node* temp = head;
        while(temp)
        {
                if(*(temp->data) == s)
                {
                        if(temp->next)
                        {
                                current = temp->next;

                        }
                        else if(temp->prev)
                        {
                                current = temp->prev;

                        }
                        else
                        {
                                current = NULL;

                        }


                        if(temp == head)
                        {
                                head = temp->next;
                                if(head)
                                {
                                        head->prev = NULL;
                                }
                                delete temp;
                                return;
                        }
                        else if(temp == tail)
                        {
                                tail = tail->prev;
                                tail->next = NULL;
                                delete temp;
                                return;
                        }
                        else
                        {
                                temp->prev->next = temp->next;
                                temp->next->prev = temp->prev;
                                delete temp;
                                return;
                        }

                }
                else
                {
                        temp = temp->next;
                }
        }


}


/**
 *@brief Doubly Linked List Method Empty, returns
 *whether or not the list is empty.
 *
 *@return bool, whether it is empty or not.
 *
 */
bool DoublyLinkedList::empty()
{
        if(current == NULL)
        {
                return true;
        }
        else
        {
                return false;
        }

}




/**
 *@brief Doubly Linked List Method Begin, sets current
 *to the head of the list.
 *
 */
void DoublyLinkedList::begin()
{
        current = head;

}



/**
 *@brief Doubly Linked List Method End, sets current
 *to the tail of the list.
 *
 */
void DoublyLinkedList::end()
{
        current = tail;

}


/**
 *@brief Doubly Linked List Method Next, sets current
 *to the next node in the list.
 *
 * @return returns true if the next node exists
 */
bool DoublyLinkedList::next()
{
        if(current->next)
        {
                current = current->next;
                return true;
        }
        else
        {
                return false;

        }

}




/**
 *@brief Doubly Linked List Method Prev, sets current
 *to the previous node in the list.
 *
 * @return returns true if previous node exists
 */
bool DoublyLinkedList::prev()
{
        if(current->prev)
        {
                current = current->prev;
                return true;
        }
        else
        {
                return false;

        }


}



/**
 *@brief Doubly Linked List Method find, sets current
 *to the node that is being searched for.
 *
 *@param string& s, the node to be searched for and set as current
 *
 * @return returns true if the node searching for exists
 */
bool DoublyLinkedList::find(const string& s)
{
        Node* temp = head;
        while(temp)
        {
                if(*(temp->data) == s)
                {
                        current = temp;
                        return true;

                }
                else
                {
                        if(temp->next)
                        {
                                temp = temp->next;
                        }
                        else
                        {
                                return false;

                        }
                }


        }
        return false;

}


/**
 *@brief Doubly Linked List Method get data, retrieves
 *what is stored in node.
 *
 * @return returns what is inside current
 */
const string& DoublyLinkedList::getData()
{
        return *(current->data);

}
