//
//periodic.cpp
//reads in and displays data from periodic.txt
//Austin Dollar
//


#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include <vector>
#include "periodic.h"
using namespace std;

//ctor
Periodic::Periodic(string cn, string ti, string sub, string no, string auth, string desc, string pub, string hist, string ss, string rt, string of, string dn)
	: Media(cn, ti, sub, no), author(auth), description(desc), publisher(pub), pub_hist(hist), series(ss), rel_titles(rt), other_forms(of), doc_num(dn)
{
}


//periodic's virtual funcs

bool Periodic::comp_other(string other)
{
	if (description.find(other) != string::npos)
	{
		return true;
	}
	else if (notes.find(other) != string::npos)
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

void Periodic::display()
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












































int main()
{
	ifstream perfile("periodic.txt");
	string line;
	vector<Periodic> pers;
	
	if (perfile.is_open())
	{
		//find the substring representing each field, after saved into class, delete substring and search again
		while (getline(perfile, line))
		{
			//create instance of Periodic to store in vector
			Periodic* cur = new Periodic;

			//find call number
			cur->call_num = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find title
			cur->title = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find subjects
			cur->subject = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find author
			cur->author = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find description
			cur->description = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find publisher
			cur->publisher = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find publishing history
			cur->pub_hist = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find series
			cur->series = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find notes
			cur->notes = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find related titles
			cur->rel_titles = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find other forms of title
			cur->other_forms = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);

			//find gov doc number
			cur->doc_num = line.substr(0, line.find('|'));
			line.erase(0, line.find('|') + 1);


			pers.push_back(*cur);

			
			
		}

	}
	//print label, then data for one instance of book
	cout << "call  number: " << endl;
	cout<< pers[0].call_num << endl;

	cout << "title: " << endl;
	cout << pers[0].title << endl;

	cout << "subject: " << endl;
	cout << pers[0].subject << endl;

	cout << "author: " << endl;
	cout << pers[0].author << endl;

	cout << "description: " << endl;
	cout << pers[0].description << endl;

	cout << "publisher: " << endl;
	cout << pers[0].publisher << endl;

	cout << "publishing history: " << endl;
	cout << pers[0].pub_hist << endl;

	cout << "series: " << endl;
	cout << pers[0].series << endl;

	cout << "notes: " << endl;
	cout << pers[0].notes << endl;

	cout << "related titles: " << endl;
	cout << pers[0].rel_titles << endl;

	cout << "other forms of title: " << endl;
	cout << pers[0].other_forms << endl;

	cout << "govt doc number: " << endl;
	cout << pers[0].doc_num << endl;




	return 0;

}
