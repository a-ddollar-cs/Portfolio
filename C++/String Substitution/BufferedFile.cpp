//
//BufferedFile.cpp
//OO redesign assignment
//Austin Dollar
//

#include "BufferedFile.h"

BufferedFile::BufferedFile(const char* fname)
	:putpos(0), getpos(0), filename(fname), hit_eof(false), hit_empty_buffer(false)
{
	fstream::open(fname, std::ios::in | std::ios::out);
} 

BufferedFile::~BufferedFile()
{
	truncate(filename, putpos);
}

bool BufferedFile::eof() const
{
	return hit_eof && hit_empty_buffer;
}



void BufferedFile::raw_get(char& c)
{
	fstream::seekg(getpos);
	fstream::get(c);
	getpos = fstream::tellg();

	if (fstream::eof())
	{
		fstream::clear();
		hit_eof = true;
	}
}



BufferedFile& BufferedFile::get(char& c)
{
	if (buffer.size() > 0)//our buffer isn't empty
	{
		c = buffer.front();
		buffer.pop_front();
		return *this;
	}

	//If we reach this point, then our buffer *is* empty. Time to get from file

	raw_get(c);

	if (hit_eof)
	{
		hit_empty_buffer = true;
	}
		
	return *this;
}



BufferedFile& BufferedFile::put(char c)
{
	if (getpos == putpos && !hit_eof)
	{
		char ch = '#';
		raw_get(ch);

		if (!hit_eof)
		{
			buffer.push_back(ch);
		}
			
	}

	fstream::seekp(putpos);
	fstream::put(c);
	putpos = fstream::tellp();
	return *this;
}



void BufferedFile::putback(char ch)
{
	buffer.push_front(ch);
	
}