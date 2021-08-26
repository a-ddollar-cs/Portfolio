//
//book.h
//reads in and holds data from book.txt
//Austin Dollar
//


#ifndef BOOK_H
#define BOOK_H

#include <vector>
#include <string>
using namespace std;

class Book : public Media
{
    public:
		Book(string cn, string ti, string sub, string no, string desc, string pub, string ci, string yr, string ss, string  auth);
		bool comp_other(string);
		void display();

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