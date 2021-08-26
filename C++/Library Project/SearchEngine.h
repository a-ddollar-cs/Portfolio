//
//SearchEngine.cpp
//creates definitions for search engine object
//Austin Dollar
//



#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H
#include <string>
#include <list>
#include <vector>
#include "Media.h"
using namespace std;

class Search
{
	//class definition
	public:
		Search();
		~Search();
		void readBook();
		void readFilm();
		void readPeriod();
		void readVideo();

		vector<Media*> Call(const string& Call_num)const;
		vector<Media*> Title(const string& title)const;
		vector<Media*> Subject(const string& subject)const;
		vector<Media*> Other(const string& other)const;

	private:
		vector<Media*> catalog;
};





#endif