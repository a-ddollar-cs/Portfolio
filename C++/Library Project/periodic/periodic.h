//
//periodic.h
//reads in and holds data from periodic.txt
//Austin Dollar
//


#ifndef PERIODIC_H
#define PERIODIC_H

#include <vector>
#include <string>
using namespace std;

class Periodic : public Media
{
    public:
		Periodic(string cn, string ti, string sub, string no, string auth, string desc, string pub, string hist, string ss, string rt, string of, string dn);
		bool comp_other(string);
		void display();


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