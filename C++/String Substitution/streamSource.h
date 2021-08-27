//
//streamSource.h
//OO redesign assignment
//Austin Dollar
//

#include "BufferedFile.h"
#include <unistd.h>
#include <cstring>

class StreamSource
{
	public:
		//ctor initializes search word, replacement word, bf(gets the filename)
		bool eof();
		StreamSource(const char* search, const char* replace, const char* fname);
		~StreamSource();
		StreamSource& get(char& ch);
		bool currently_replacing();
		void match_search_string();
		void found_partial_match(int match_count, char mismatched_char);
		StreamSource& put(char ch);


	private:
		enum { BufFile, SearchString, ReplacementString } getting_from;

		int replace_count;
		int search_count;
		int search_len;
		int  replace_len;
		const char* search_word;
		const char* replacement_word;
		const char* filename;
		int location_to_search;
		BufferedFile bf;
};
