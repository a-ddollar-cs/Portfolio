//
//trackingdq.h
//deque wrapper assignment
//Austin Dollar

#include <iostream>
#include <deque>

using std::deque;
using std::cout;
using std::endl;

template<typename THISTYPE>
class TrackingDeque : public deque<THISTYPE>
{
	public:
		TrackingDeque();
		~TrackingDeque();
		void push_front(const THISTYPE& value);
		void push_back(const THISTYPE& value);

	private:
		int maxSize;
};


template<typename THISTYPE>
TrackingDeque<THISTYPE>::TrackingDeque()
{
	maxSize = 0;
}


template<typename THISTYPE>
TrackingDeque<THISTYPE>::~TrackingDeque()
{
	cout << "---> " << maxSize << " <---" << endl;
}


template<typename THISTYPE>
void TrackingDeque<THISTYPE>::push_front(const THISTYPE& value)
{
	deque<THISTYPE>::push_front(value);
	maxSize++;
}


template<typename THISTYPE>
void TrackingDeque<THISTYPE>::push_back(const THISTYPE& value)
{
	deque<THISTYPE>::push_back(value);
	maxSize++;
}