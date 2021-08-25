/**
 * @file playlist.cpp   Implementation of a Playlist for music.
 *
 * @brief
 *    Implementation of a Playlist for music. A doubly linked list is
 *    used to store the song names.
 *
 *    Note: main() is in this file.
 *
 * @author Judy Challinger & Austin Dollar
 * @date  January 27, 2020
 */

#include <iostream>
#include <string>


#include "doublylinkedlist.h"
#include "playlist.h"
#include <sstream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

string command; 

/**
 * Process a playlist command.
 *
 * Gets an entire line from std::cin, extracts the first word as the command,
 * and calls the appropriate processing function. Invalid commands are
 * ignored.
 *
 * @return false if command is "quit", otherwise true
 */
bool Playlist::processCommand() {

        string command;
        string* song;
        cin >> command;

        if(command == "quit")
        {
                return false;
        }
        else if(command == "appendSong")
        {
                song = new string;
                cin.ignore();
                getline(cin, *song);
                dll.append(*song);

        }
        else if(command == "insertBefore")
        {
                song = new string;
                cin.ignore();
                getline(cin, *song);
                dll.insertBefore(*song);
        }
        else if(command == "insertAfter")
        {
                song = new string;
                cin.ignore();
                getline(cin, *song);
                dll.insertAfter(*song);

        }
        else if(command == "gotoFirstSong")
        {
                dll.begin();

        }
        else if(command == "gotoLastSong")
        {
                dll.end();

        }
        else if(command == "playCurrent")
        {
                cout<< endl;
                cout<< "playing current: ";
                if(!dll.empty())
                {
                       
                        cout<<dll.getData()<< endl;
                }

        }
        else if(command == "removeSong")
        {
                song = new string;
                cin.ignore();
                getline(cin,*song);
                dll.remove(*song);
                delete song;

        }
        else if(command == "gotoSong")
        {
                song = new string;
                cin.ignore();
                getline(cin, *song);
                dll.find(*song);
                delete song;
        }
        else if(command == "nextSong")
        {
                dll.next();

        }
        else if(command == "prevSong")
        {
                dll.prev();

        }
        else if(command == "playForward")
        {
                cout<< endl;
                cout<< "playing forward: "<< endl;
                cout<<dll.getData()<<endl;
                while(dll.next())
                {
                        cout<<dll.getData()<<endl;
                }


        }
        else if(command == "playReverse")
        {
                cout<<endl;
                cout<< "playing reverse: "<<endl;
                cout<<dll.getData()<<endl;
                while(dll.prev())
                {
                        cout<<dll.getData()<<endl;
                }


        }
        return true; 

}

/**
 * The Playlist main loop will process command lines until finished.
 */
void Playlist::mainLoop() {
        while (processCommand());         // process all commands
}

/**
 * The main entry point for the program.
 */
int main()
{
        Playlist myPlaylist;
        myPlaylist.mainLoop();
        return 0;
}

