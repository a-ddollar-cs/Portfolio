//
// stampbuff.h
// stampbuff class for stamping press project
// Austin Dollar
//


//includes
#include <iostream>
#include <ostream>

using std::ostream;
using namespace std;


//class declaration for stampbuf

class stampbuf : public streambuf
{
	//overrides overflow, sync

	public:
		stampbuf(int noCols, int noRows);
		~stampbuf();
		virtual int sync();
		virtual int overflow(int ch);
		void setC(int);
		void setR(int);
		void add_one_to_row();

	private:
		int tot_cols;
		int tot_rows;
		int cur_col;
		int cur_row;
};