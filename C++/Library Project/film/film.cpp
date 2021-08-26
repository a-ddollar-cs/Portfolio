//
//film.cpp
//reads in and displays data from film.txt
//Austin Dollar
//


#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include <vector>
#include "film.h"
using namespace std;


//ctor
Film::Film(string cn, string ti, string sub, string no, string dir, string yr)
	: Media(cn, ti, sub, no), director(dir), year(yr)
{
}

//film's virtual funcs

bool Film::comp_other(string other)
{
	if (director.find(other) != string::npos)
	{
		return true;
	}
	else if (notes.find(other) != string::npos)
	{
		return true;
	}
	else if (year.find(other) != string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Film::display()
{
	//header of output

	cout << "==========================" << endl;
	cout << "========== FILM ==========" << endl;
	cout << "==========================" << endl;

	//alignment stuff
	cout << std::left;

	//output
	cout << std::setw(22) << "call_number:" << call_num << endl;
	cout << std::setw(22) << "title:" << title << endl;
	cout << std::setw(22) << "subjects:" << subject << endl;
	cout << std::setw(22) << "director:" << director << endl;
	cout << std::setw(22) << "notes:" << notes << endl;
	cout << std::setw(22) << "year:" << year << endl;

}













































int main()
{
	ifstream perfile("film.txt");
	string line;
	vector<Film> films;
	
	if (perfile.is_open())
	{
		//find the substring representing each field, after saved into class, delete substring and search again
		while (getline(perfile, line))
		{
			//create instance of Periodic to store in vector
			Film* cur = new Film;

			//find call number
			cur->call_num = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find title
			cur->title = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find subjects
			cur->subject = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find director
			cur->director = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find notes
			cur->notes = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find year
			cur->year = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);


			films.push_back(*cur);

			
			
		}

	}
	//print label, then data for one instance of book
	cout << "call  number: " << endl;
	cout<< films[0].call_num << endl;

	cout << "title: " << endl;
	cout << films[0].title << endl;

	cout << "subject: " << endl;
	cout << films[0].subject << endl;

	cout << "director: " << endl;
	cout << films[0].director << endl;

	cout << "notes: " << endl;
	cout << films[0].notes << endl;

	cout << "year: " << endl;
	cout << films[0].year << endl;

	return 0;

}
