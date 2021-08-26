//
//Media.h
//base class declaration for all media types
//Austin Dollar
//


#ifndef MEDIA_H
#define MEDIA_H

#include <vector>
#include <string>
using namespace std;

class Media
{
	public:
		//Media functions
		Media(string cn, string ti, string sub, string no);  //ctor
		bool comp_call_num(string);
		bool comp_title(string);
		bool comp_sub(string);

		//virtual functons
		virtual bool comp_other(string) = 0;
		virtual void display() = 0;

	
	private:
		//variables
		string call_num;
		string title;
		string subject;
		string notes;
	

};


#endif