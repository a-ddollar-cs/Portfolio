//
// stampstream.cpp
// stampstream implementation for stamping press project
// Austin Dollar
//


//includes
#include "stampstream.h"
#include "stampbuff.h"
#include "stamp.h"
#include <fstream>
#include <ostream>
#include <iostream>

using namespace stamping_press;

//row implementation
row::row(int roww)
	:thisRow(roww)
{
}


stampstream::stampstream(int column, int row)
	:ostream(new stampbuf(column, row)), tot_row(row), tot_col(column)
{
}


stampstream::~stampstream()
{
	delete rdbuf();
}

ostream& operator<<(ostream& os, const row& row)
{
	stampbuf* buf = static_cast<stampbuf*>(os.rdbuf());
	os.flush();
	(*buf).setC(0);
	(*buf).setR(row.thisRow);
	return os;

}

ostream& endrow(ostream& os)
{
	stampbuf* sbp = (stampbuf*)os.rdbuf();
	sbp->pubsync();
	sbp->add_one_to_row();
	return os;
} 

