//
//main.cpp
//OO redesign assignment
//Austin Dollar
//

#include <iostream>
#include <cstring>
#include "streamSource.h"

using namespace std;


int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		cout << "Not enough args: " << endl;
		return 1;
	}

	StreamSource  ss(argv[1], argv[2], argv[3]);
	int match_count = 0;
	const char* search_word = argv[1];
	char ch;


	while(!ss.get(ch).eof())
	{

		if (!ss.currently_replacing() && ch == search_word[match_count])
		{
			++match_count;
			if (match_count < (int)strlen(search_word))
			{
				continue;
			}
				
		}

		if (match_count == (int)strlen(search_word))//we have a match!
		{
			ss.match_search_string();
		}
		else if (match_count > 0)//we have a failed match!
		{
			ss.found_partial_match(match_count, ch);
		}
		else
		{
			ss.put(ch);
		}

		match_count = 0;

	}

}