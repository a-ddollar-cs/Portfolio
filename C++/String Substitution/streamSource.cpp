//
//streamSource.cpp
//OO redesign assignment
//Austin Dollar
//

#include "streamSource.h"

StreamSource::StreamSource(const char* Search, const char* Replace, const char* Fname)
	:replace_count(0), search_count(0), search_word(Search), replacement_word(Replace), filename(Fname), search_len(0), replace_len(0), bf(Fname)
{
	
}


StreamSource::~StreamSource()
{
	
}


StreamSource& StreamSource::get(char& ch)
{
	if (replace_count>0)
	{
		ch = replacement_word[strlen(replacement_word) - replace_count--];
		getting_from = ReplacementString;
	}	
	else if (search_count > 1)
	{
		ch = search_word[strlen(search_word) - search_count--];
		getting_from = SearchString;
	}		
	else
	{
		bf.get(ch);
		getting_from = BufFile;
	}

	return *this;
}


bool StreamSource::currently_replacing()
{
	return getting_from == ReplacementString;
}

void StreamSource::match_search_string()
{
	replace_count = strlen(replacement_word);
}


void StreamSource::found_partial_match(int match_count, char mismatched_char)
{
	if (getting_from == SearchString)
	{
		

		++location_to_search;
	}
	else
	{
		location_to_search = 0;
		search_len = match_count;
		bf.putback(mismatched_char);
	}

	bf.put(search_word[location_to_search]);
	search_count = search_len  - location_to_search;
}


StreamSource& StreamSource::put(char ch)
{
	bf.put(ch);
	return *this;
}


bool StreamSource::eof()
{
	return bf.eof();
}

