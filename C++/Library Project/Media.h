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
		bool comp_call_num(const string& cn);
		bool comp_title(const string& title);
		bool comp_sub(const string& sub);

		//virtual functons
		virtual bool comp_other(const string& other)const = 0;
		virtual void display()const = 0;
		virtual ~Media();

	
	protected:
		//variables
		string call_num;
		string title;
		string subject;
		string notes;
	

};


#endif