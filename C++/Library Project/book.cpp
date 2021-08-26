//
//book.cpp
//class definitions for book object
//Austin Dollar
//


#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include "book.h"
using namespace std;


//ctor
Book::Book(const string& cn, const string& ti, const string& sub, const string& no, const string& desc, const string& pub, const string& ci, const string& yr, const string& ss, const string& auth)
	: Media(cn, ti, sub, no), description(desc), publisher(pub), city(ci), year(yr), series(ss), author(auth)
{
}

//book's virtual funcs

//compare other function

bool Book::comp_other(const string& other)const
{
	if (description.find(other) != string::npos)
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

//display function
void Book::display()const
{
	//header of output

	cout << "==========================" << endl;
	cout << "========== BOOK ==========" << endl;
	cout << "==========================" << endl;

	//alignment stuff
	cout << std::left;

	//output
	cout << std::setw(22) << "call_number:" << call_num << endl;
	cout << std::setw(22) << "title:" << title << endl;
	cout << std::setw(22) << "subjects:" << subject << endl;
	cout << std::setw(22) << "author:" << author << endl;
	cout << std::setw(22) << "description:" << description << endl;
	cout << std::setw(22) << "publisher:" << publisher << endl;
	cout << std::setw(22) << "city:" << city<< endl;
	cout << std::setw(22) << "year:" << year << endl;
	cout << std::setw(22) << "series:" << series << endl;
	cout << std::setw(22) << "notes:" << notes << endl;

}





























































