//
//BufferedFile.h
//OO redesign assignment
//Austin Dollar
//

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstring>
#include "trackingdq.h"

using namespace std;


class BufferedFile : public std::fstream 
{

	public:
		BufferedFile(const char* fname);
		~BufferedFile();
		BufferedFile& get(char& ch);
		BufferedFile& put(char ch);
		bool eof() const;
		void putback(char ch);

		

	private:
		void raw_get(char& ch);

		std::streampos putpos;//be sure to set to zero in initialization list
		std::streampos getpos;//be sure to set to zero in initialization list
		TrackingDeque<char> buffer;
		const char* filename;//used for truncating the file
		bool hit_eof;//be sure to set to false in initialization list
		bool hit_empty_buffer;//be sure to set to false in initialization list

};
