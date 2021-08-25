/**
 * @file doublylinkedlist.h   Declaration of a Playlist for music.
 *
 * @brief
 *    Implementation of a doubly linked list used to store data for the Playlist class.
 *
 * @author Austin Dollar
 * @date January 27, 2020
 */


#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

using std::string;

class DoublyLinkedList
{
   public:
    DoublyLinkedList();                                 // class constructor for DoublyLinkedList class

    ~DoublyLinkedList();                                // class destructor for DoublyLinkedList class

    void append(const string& s);                       // append <song> to end of playlist, make current song

    void insertBefore(const string& s);                 // insert <song> before current song, make current song

    void insertAfter( const string& s);                 // insert <song> after current song, make current song

    void remove(const string& s);                       // remove <song> from the playlist

    bool empty();                                       // return true if playlist is empty

    void begin();                                       // set current song to first song in playlist

    void end();                                         // set current song to the last song in playlist

    bool next();                                        // set current song to the next song in the playlist
    
    bool prev();                                        // set current song to the previous song in the playlist

    bool find(const string& s);                         // find <song> in playlist, make current song

    const string& getData();                            // return data from current song

   private:
    class Node{                                         // privately nested node class for the skeleton of the linked list
            public:
                    Node(const string& d) {
                          next = NULL; prev = NULL;
                          data = new string(d);}   // Node class constructor

                    ~Node(){delete data;}               // Node class destructor

                    Node* next;                         // Node object to represent the next song in playlist

                    Node* prev;                         // Node object to represent the previous song in playlist

                    string* data;                       // private string variable to keep track of data stored in node

    };

    Node *head;                                         // private node variable to keep track of front of list

    Node *tail;                                         // private node variable to keep track of back of list

    Node *current;                                      // private node variable to keep track of current node

    
};

#endif //CSCI_311_DOUBLYLINKEDLIST_H
