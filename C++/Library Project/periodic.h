//
//periodic.h
//creates definitionss for periodic object
//Austin Dollar
//


#ifndef PERIODIC_H
#define PERIODIC_H

#include <vector>
#include <string>
#include "Media.h"
using namespace std;


class Periodic : public Media
{
	//class definitions
    public:
		Periodic(const string& cn, const string& ti, const string& sub, const string& no, const string& auth, const string& desc, const string& pub, const string& hist, const string& ss, const string& rt, const string& of, const string& dn);
		bool comp_other(const string& other)const;
		void display()const;


    private:
		//variables
		string author;
		string description;
		string publisher;
		string pub_hist;
		string series;
		string rel_titles;
		string other_forms;
		string doc_num;
};


#endif