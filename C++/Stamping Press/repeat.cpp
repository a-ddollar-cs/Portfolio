//
//
//ostream.cpp
//ostream mutators assignment
//Austin Dollar
//
//

#include <iostream>
#include <ostream>
#include "repeat.h"

using namespace std;

Repeat::Repeat(char toRepeat, int num)
	:repeated(toRepeat), repeater(num)
{
}

ostream& operator<<(ostream& os, const Repeat& rep)
{
	int y = rep.repeater;
	for (int x = 0; x < y; x++)
	{
		os << rep.repeated;
	}
	return os;
}


int main()
{
	int count;
	char toRepeat;

	//read in values
	cout << "Enter a character to repeat: ";
	cin >> toRepeat;

	cout << "Enter how many times to repeat: ";
	cin >> count;
	 
	//display with mutator
	cout << Repeat(toRepeat, count) << endl;

	return 0;
}