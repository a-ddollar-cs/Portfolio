#include "stamp.h"
#include "stampbuff.h"
#include "stampstream.h"
#include <iostream>
#include <string>

using namespace std;



int main()
{
  stampstream s(30,10);
  s << row(4) << 'a' << row(3) << 'e' << 
       row(2) << 'i' << row(1) << 'o' << 
       row(0) << 'u';
  return 0;
}
