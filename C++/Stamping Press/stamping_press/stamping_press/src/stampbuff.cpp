//
// stampbuff.cpp
// stampbuff class for stamping press project
// Austin Dollar
//

#include "stampbuff.h"
#include "stamp.h"
#include <streambuf>
#include <stdexcept>

using namespace stamping_press;  //std?

stampbuf::stampbuf(int noCols, int noRows)
	:tot_cols(noCols), tot_rows(noRows), cur_col(0),  cur_row(0)
{
	char* buf = new char[noCols];
	setp(buf, buf + noCols);
	insert_plate(noCols, noRows);

}


stampbuf::~stampbuf()
{
	pubsync();
	delete pbase();
	eject_plate();
} 


int stampbuf::sync()
{
	char* i;

	//for loop to iterate, use exception handling for spaces, invalid stamps

	for (i = pbase(); i < pptr(); ++i)
	{
		if (cur_col < tot_cols)
		{
			try
			{
				set_die(*i);
				try
				{
					stamp(cur_col, cur_row);
				}
				catch (...)
				{
				}
				cur_col++;
			}
			//catch invalid stamp arg, resolve below
			catch (std::invalid_argument)
			{
				
				if (*i == ' ')   //case of space
				{
					cur_col++;
				}
				else if (*i == get_die())   //case of die already set
				{
					stamp(cur_col, cur_row);
					cur_col++;
				}
				else    //case of invalid character/any other invalid arg exception
				{
					cur_col++;
				}
				
			}
		}


	}
	setp(pbase(), epptr());
	return 0;
}


int stampbuf::overflow(int ch)
{
	char* i;

	//for loop to iterate, use exception handling for spaces, invalid stamps

	for (i = pbase(); i < pptr(); ++i)
	{
		if (cur_col < tot_cols)
		{
			try
			{
				set_die(*i);
				try 
				{
					stamp(cur_col, cur_row);
				}
				catch (...)
				{
				}
				cur_col++;
			}
			//catch invalid stamp arg, resolve below
			catch (std::invalid_argument)
			{
				if(*i == ' ')  //case of space
				{
					cur_col++;
				}
				else if (*i == get_die())   //case of die already set
				{
					stamp(cur_col, cur_row);
					cur_col++;
				}
				else  //case of invalid character/any other invalid arg exception
				{
					cur_col++;
				}
				
			}
		}


	}
	setp(pbase(), epptr());

	sputc(ch);
	return ch;
}

//provides access to private column variable
void stampbuf::setC(int col)
{
	cur_col = col;
}

//provides access to private row variable
void stampbuf::setR(int row)
{
	cur_row = row;
}

//helperfunction for endrow
void stampbuf::add_one_to_row()
{
	cur_row++;
	cur_col = 0;
}