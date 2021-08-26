//
//video.cpp
//reads in and displays data from video.txt
//Austin Dollar
//


#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include <vector>
#include <iomanip>

#include "video.h"
using namespace std;


//ctor
Video::Video(string cn, string ti, string sub, string no, string desc, string dist, string ss, string lb)
	: Media(cn, ti, sub, no), description(desc), distributor(dist), series(ss), label(lb)
{
}


//Video's virtual funcs

bool Video::comp_other(string other)
{
	if (description.find(other) != string::npos)
	{
		return true;
	}
	else if (notes.find(other) != string::npos)
	{
		return true;
	}
	else if (distributor.find(other) != string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Video::display()
{
	//header of output

	cout << "==========================" << endl;
	cout << "========== VIDEO =========" << endl;
	cout << "==========================" << endl;

	//alignment stuff
	cout << std::left;

	//output
	cout << std::setw(22) << "call_number:" << call_num << endl;
	cout << std::setw(22) << "title:" << title << endl;
	cout << std::setw(22) << "subjects:" << subject << endl;
	cout << std::setw(22) << "description:" << description << endl;
	cout << std::setw(22) << "distributor:" << distributor << endl;
	cout << std::setw(22) << "notes:" << notes << endl;
	cout << std::setw(22) << "series:" << series << endl;
	cout << std::setw(22) << "label:" << label << endl;

}





































int main()
{
	ifstream perfile("video.txt");
	string line;
	vector<Video> vids;
	
	if (perfile.is_open())
	{
		//find the substring representing each field, after saved into class, delete substring and search again
		while (getline(perfile, line))
		{
			//create instance of Periodic to store in vector
			Video* cur = new Video;

			//find call number
			cur->call_num = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find title
			cur->title = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find subjects
			cur->subject = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find description
			cur->description = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find distributor
			cur->distributor = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find notes
			cur->notes = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find series
			cur->series = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find labels
			cur->label = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);


			vids.push_back(*cur);

			
			
		}

	}
	//print label, then data for one instance of book
	cout << "call  number: " << endl;
	cout<< vids[0].call_num << endl;

	cout << "title: " << endl;
	cout << vids[0].title << endl;

	cout << "subject: " << endl;
	cout << vids[0].subject << endl;

	cout << "description: " << endl;
	cout << vids[0].description << endl;

	cout << "distributor: " << endl;
	cout << vids[0].distributor << endl;

	cout << "notes: " << endl;
	cout << vids[0].notes << endl;

	cout << "series: " << endl;
	cout << vids[0].series << endl;

	cout << "label: " << endl;
	cout << vids[0].label << endl;



	return 0;

}
