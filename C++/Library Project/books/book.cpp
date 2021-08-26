//
//book.cpp
//reads in and displays data from book.txt
//Austin Dollar
//


#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include <vector>
#include<iomanip>
#include "book.h"
using namespace std;


//ctor
Book::Book(string cn, string ti, string sub, string no, string desc, string pub, string ci, string yr, string ss, string  auth)
	: Media(cn, ti, sub, no), description(desc), publisher(pub), city(ci), year(yr), series(ss), author(auth)
{
}

//book's virtual funcs

bool Book::comp_other(string other)
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

void Book::display()
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



































































int main()
{
	ifstream bookfile("book.txt");
	string line;
	vector<Book> books;
	
	if (bookfile.is_open())
	{
		//find the substring representing each field, after saved into class, delete substring and search again
		while (getline(bookfile, line))
		{
			//create instance of book to store in vector
			Book* curBook = new Book;

			//find call number
			curBook ->call_num = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find title
			curBook->title = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find subjects
			curBook->subject = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find author
			curBook->author = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find description
			curBook->description = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find publisher
			curBook->publisher = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find city
			curBook ->city = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find year
			curBook->year = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find series
			curBook->series = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find notes
			curBook->notes = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);


			books.push_back(*curBook);

			
			
		}

	}
	//print label, then data for one instance of book
	cout << "call  number: " << endl;
	cout<< books[0].call_num << endl;

	cout << "title: " << endl;
	cout << books[0].title << endl;

	cout << "subject: " << endl;
	cout << books[0].subject << endl;

	cout << "author: " << endl;
	cout << books[0].author << endl;

	cout << "description: " << endl;
	cout << books[0].description << endl;

	cout << "publisher: " << endl;
	cout << books[0].publisher << endl;

	cout << "city: " << endl;
	cout << books[0].city << endl;

	cout << "year: " << endl;
	cout << books[0].year << endl;

	cout << "series: " << endl;
	cout << books[0].series << endl;

	cout << "notes: " << endl;
	cout << books[0].notes << endl;

	//free memory of all books


	return 0;

}
