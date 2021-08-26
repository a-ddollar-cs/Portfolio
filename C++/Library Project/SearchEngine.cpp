//
//SearchEngine.cpp
//creates search engine class, contains main()
//Austin Dollar
//



#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include <limits>
#include "book.h"
#include "film.h"
#include "Media.h"
#include "periodic.h"
#include "video.h" 
#include "SearchEngine.h"

using namespace std;

//ctor
Search::Search()
{
	readBook();
	readFilm();
	readVideo();
	readPeriod();
}

//dctor
Search::~Search()
{
	for ( unsigned int i = 0; i < catalog.size(); i++)
	{
		delete catalog[i];
	}
}

//functions to call during constructor, reads in all files into media vector *catalog*
void Search::readBook()
{
	string filename = "book.txt";
	string line, cn, ti, sub, notes, desc, pub, ci, yr, ss, auth;

	ifstream filein(filename.c_str());
	if (filein.is_open())
	{
		while(getline(filein, line))
		{
			//read in data
			cn = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			ti = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			sub = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			auth = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			desc = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			pub = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			ci = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			yr = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			ss = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			notes = line;

			//create book
			Book* book = new Book(cn, ti, sub, notes, desc, pub, ci, yr, ss, auth);

			//push Book into catalog
			catalog.push_back(book);


		}

		filein.close();
	}
	
}

void Search::readFilm()
{
	string filename = "film.txt";
	string line, cn, ti, sub, notes, dir, yr;

	ifstream filein(filename.c_str());
	if (filein.is_open())
	{
		while (getline(filein, line))
		{
			//read in data
			cn = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			ti = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			sub = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			dir = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			notes = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			yr = line;

			//create film
			Film* film = new Film(cn, ti, sub, notes, dir, yr);

			//push Book into catalog
			catalog.push_back(film);


		}

		filein.close();
	}
}

void Search::readPeriod()
{
	string filename = "periodic.txt";
	string line, cn, ti, sub, notes,auth, desc, pub, hist, ss, rt, of, dn;

	ifstream filein(filename.c_str());
	if (filein.is_open())
	{
		while (getline(filein, line))
		{
			//read in data
			cn = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			ti = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			sub = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			auth = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			desc = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			pub = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			hist = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			ss = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			notes = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			rt = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			of = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			dn = line;

			//create film
			Periodic* periodic = new Periodic(cn, ti, sub, notes, auth, desc, pub, hist, ss, rt, of, dn);

			//push Book into catalog
			catalog.push_back(periodic);


		}

		filein.close();
	}
}

void Search::readVideo()
{
	string filename = "video.txt";
	string line, cn, ti, sub, notes, desc, dist, ss, lb;

	ifstream filein(filename.c_str());
	if (filein.is_open())
	{
		while (getline(filein, line))
		{
			//read in data
			cn = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			ti = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			sub = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			desc = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			dist = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			notes = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			ss = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			lb = line;

			//create film
			Video* video = new Video(cn, ti, sub, notes, desc, dist, ss, lb);

			//push Book into catalog
			catalog.push_back(video);


		}

		filein.close();
	}
}

vector<Media*> Search::Call(const string& Call_num)const
{
	vector<Media*> results;

	for (unsigned int i = 0; i < catalog.size(); i++)
	{
		bool result=catalog[i]->comp_call_num(Call_num);
		if (result == true)
		{
			results.push_back(catalog[i]);
		}
	}
	return results;
}



vector<Media*> Search::Title(const string& title)const
{
	vector<Media*> results;

	for (unsigned int i = 0; i < catalog.size(); i++)
	{
		bool result = catalog[i]->comp_title(title);
		if (result == true)
		{
			results.push_back(catalog[i]);
		}
	}
	return results;
}


vector<Media*> Search::Subject(const string& subject)const
{
	vector<Media*> results;

	for (unsigned int i = 0; i < catalog.size(); i++)
	{
		bool result = catalog[i]->comp_sub(subject);
		if (result == true)
		{
			results.push_back(catalog[i]);
		}
	}
	return results;
}


vector<Media*> Search::Other(const string& other)const
{
	vector<Media*> results;

	for (unsigned int i = 0; i < catalog.size(); i++)
	{
		bool result = catalog[i]->comp_other(other);
		if (result == true)
		{
			results.push_back(catalog[i]);
		}
	}
	return results;
}

int main()
{
	//main function/loop menu

	Search search;
	string inputter;
	int menu;
	vector<Media*> results;

	while(menu != 5)
	{
		//reset results vector
		while (!results.empty())
		{
			results.pop_back();
		}

		//display menu
		cout << "1) call_number" << endl;
		cout << "2) title" << endl; 
		cout << "3) subject" << endl;
		cout << "4) other" << endl;
		cout << "5) exit" << endl;
		cin >> menu;

		//process menu input
		if (menu == 1)
		{
			cout << "Enter keyphrase: " << endl;
			cin.ignore();
			getline(cin, inputter);
			results = search.Call(inputter);

			if (results.size() > 0)
			{
				for (unsigned int j = 0; j < results.size(); j++)
				{
					results[j]->display();
				}
			}

		}
		else if (menu == 2)
		{
			cout << "Enter keyphrase: " << endl;
			cin.ignore();
			getline(cin, inputter);
			results = search.Title(inputter);

			if (results.size() > 0)
			{
				for (unsigned int j = 0; j < results.size(); j++)
				{
					results[j]->display();
				}
			}
		}
		else if (menu == 3)
		{
			cout << "Enter keyphrase: " << endl;
			cin.ignore();
			getline(cin, inputter);
			results = search.Subject(inputter);

			if (results.size() > 0)
			{
				for (unsigned int j = 0; j < results.size(); j++)
				{
					results[j]->display();
				}
			}
		}
		else if (menu == 4)
		{
			cout << "Enter keyphrase: " << endl;
			cin.ignore();
			getline(cin, inputter);
			results = search.Other(inputter);

			if (results.size() > 0)
			{
				for (unsigned int j = 0; j < results.size(); j++)
				{
					results[j]->display();
				}
			}
		}
		else if (menu == 5)
		{
			break;
		}
		else
		{
			cerr << "Error: Invalid Entry";
		}

	}

	return 0;
}
