//
// stampstream.h
// stampstream implementation for stamping press project
// Austin Dollar
//


#include <iostream>

using namespace std;

class row
{
	public:
		row(int roww);
		int thisRow;
};

class stampstream : public ostream
{
	public:
		stampstream(int column, int row);
		~stampstream();

	private:
		int tot_row;
		int tot_col;

};

ostream& operator<<(ostream& os, const row& row);
ostream& endrow(ostream& os);

