//
//periodic.cpp
//creates class definitions for periodic object
//Austin Dollar
//


#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include <vector>
#include <iomanip>

#include "periodic.h"
using namespace std;

//ctor
Periodic::Periodic(const string& cn, const string& ti, const string& sub, const string& no, const string& auth, const string& desc, const string& pub, const string& hist, const string& ss, const string& rt, const string& of, const string& dn)
	: Media(cn, ti, sub, no), author(auth), description(desc), publisher(pub), pub_hist(hist), series(ss), rel_titles(rt), other_forms(of), doc_num(dn)
{
}


//periodic's virtual funcs


//comp other
bool Periodic::comp_other(const string& other)const
{
	if (description.find(other) != string::npos)
	{
		return true;
	}
	else if (notes == other)
	{
		return true;
	}
	else if (series.find(other) != string::npos)
	{
		return true;
	}
	else if (rel_titles.find(other) != string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//display
void Periodic::display()const
{
	//header of output

	cout << "==========================" << endl;
	cout << "======= PERIODICAL =======" << endl;
	cout << "==========================" << endl;

	//alignment stuff
	cout << std::left;

	//output
	cout << std::setw(22) << "call_number:" << call_num << endl;
	cout << std::setw(22) << "title:" << title << endl;
	cout << std::setw(22) << "subjects:" << subject << endl;
	cout << std::setw(22) << "author:" << author << endl;
	cout << std::setw(22) << "description:" << description << endl;
	cout << std::setw(22) << "publisher:" << publisher << endl;
	cout << std::setw(22) << "publishing_history:" << pub_hist << endl;
	cout << std::setw(22) << "series:" << series << endl;
	cout << std::setw(22) << "notes:" << notes << endl;
	cout << std::setw(22) << "related_titles:" << rel_titles << endl;
	cout << std::setw(22) << "other_forms_of_title:" << other_forms << endl;
	cout << std::setw(22) << "govt_doc_number:" << doc_num << endl;

}












































