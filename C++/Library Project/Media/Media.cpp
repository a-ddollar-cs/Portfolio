//
//Media.cpp
//base class for all Media types, provides structure, most comp funcs
//Austin Dollar
//


#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include <vector>
#include "book.h"
using namespace std;


//ctor
Media::Media(string cn, string ti, string sub, string no)
	: call_num(cn), title(ti), subject(sub), notes(no)
{
}
	
//base functions
bool Media::comp_call_num(string c_cn)
{
	if (call_num.find(c_cn) != string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Media::comp_title(string c_title)
{
	if (title.find(c_title) != string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Media::comp_sub(string c_sub)
{
	if (subject.find(c_sub) != string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}