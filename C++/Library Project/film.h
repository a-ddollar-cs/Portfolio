//
//film.h
//class definitions for film object
//Austin Dollar
//


#ifndef FILM_H
#define FILM_H

#include <vector>
#include <string>
#include "Media.h"
using namespace std;


class Film : public Media
{
	//class declarations
    public:
		Film(const string& cn, const string& ti, const string& sub, const string& no, const string& dir, const string& yr);
		bool comp_other(const string& other)const;
		void display()const;
		


    private:
		//variables
		string director;
		string year;
};


#endif