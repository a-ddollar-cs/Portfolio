//
//book.h
//cllass definitions for book object
//Austin Dollar
//


#ifndef BOOK_H
#define BOOK_H

#include <vector>
#include <string>
#include "Media.h"
using namespace std;


class Book : public Media
{
	//class declarations
    public:
		Book(const string& cn, const string& ti, const string& sub, const string& no, const string& desc, const string& pub, const string& ci, const string& yr, const string& ss, const string& auth);
		bool comp_other(const string& other)const;
		void display()const;

	private:
		//variables
		string description;
		string publisher;
		string city;
		string year;
		string series;
		string author;

};


#endif