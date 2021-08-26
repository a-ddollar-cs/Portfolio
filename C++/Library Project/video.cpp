//
//video.cpp
//creates definitions for video object
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
Video::Video(const string& cn, const string& ti, const string& sub, const string& no, const string& desc, const string& dist, const string& ss, const string& lb)
	: Media(cn, ti, sub, no), description(desc), distributor(dist), series(ss), label(lb)
{
}


//Video's virtual funcs

bool Video::comp_other(const string& other)const
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

void Video::display()const
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

