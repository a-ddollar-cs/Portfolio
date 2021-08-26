//
//video.h
//reads in and holds data from video.txt
//Austin Dollar
//


#ifndef VIDEO_H
#define VIDEO_H

#include <vector>
#include <string>
using namespace std;

class Video : public Media
{
    public:
		Video(string cn, string ti, string sub, string no, string desc, string dist, string ss, string lb);
		bool comp_other(string);
		void display();

		
    private:
		//variable
		string description;
		string distributor;
		string series;
		string label;

};


#endif