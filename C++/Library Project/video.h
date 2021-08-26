//
//video.h
//creates definitions for video object
//Austin Dollar
//


#ifndef VIDEO_H
#define VIDEO_H

#include <vector>
#include <string>
#include "Media.h"
using namespace std;


class Video : public Media
{
	//class definitions
    public:
		Video(const string& cn, const string& ti, const string& sub, const string& no, const string& desc, const string& dist, const string& ss, const string& lb);
		bool comp_other(const string& other)const;
		void display()const;

		
    private:
		//variable
		string description;
		string distributor;
		string series;
		string label;

};


#endif