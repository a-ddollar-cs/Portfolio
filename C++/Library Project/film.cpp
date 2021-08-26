//
//film.cpp
//class definitions for film objects
//Austin Dollar
//


#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include <vector>
#include <iomanip>

#include "film.h"
using namespace std;


//ctor
Film::Film(const string& cn, const string& ti, const string& sub, const string& no, const string& dir, const string& yr)
	: Media(cn, ti, sub, no), director(dir), year(yr)
{
}

//film's virtual funcs

//compare other

bool Film::comp_other(const string& other)const
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

//display
void Film::display()const
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












































