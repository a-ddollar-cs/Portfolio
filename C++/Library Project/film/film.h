//
//film.h
//reads in and holds data from film.txt
//Austin Dollar
//


#ifndef FILM_H
#define FILM_H

#include <vector>
#include <string>
using namespace std;

class Film : public Media
{
    public:
		Film(string cn, string ti, string sub, string no, string dir, string yr);
		bool comp_other(string);
		void display();
		


    private:
		//variables
		string director;
		string year;
};


#endif