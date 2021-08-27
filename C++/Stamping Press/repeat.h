//repeat.h
//header for repeat class
//Austin Dollar



#ifndef REPEAT_H
#define REPEAT_H

#include <iostream>
#include <ostream>
#include "repeat.h"

using namespace std;


class Repeat
{
	public:
		Repeat(char toRepeat, int num);

		friend ostream& operator<<(ostream& os, const Repeat& repeater);

	private:
		char repeated;
		int repeater;
};

#endif
