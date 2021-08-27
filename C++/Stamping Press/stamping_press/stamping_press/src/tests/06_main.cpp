#include "stamp.h"
#include "stampbuff.h"
#include "stampstream.h"
#include <iostream>
#include <string>

using namespace std;



int main()
{
  stampstream s(30,10);

  for(int i=0; i<10; ++i)
  {
    for(int j=0; j<30; ++j)
      s << j%10;
    s << endrow;
  }
  return 0;
}
