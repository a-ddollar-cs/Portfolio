#include "stamp.h"
#include "stampbuff.h"
#include "stampstream.h"
#include <iostream>
#include <string>

using namespace std;



int main()
{
  stampstream s(30,10);

  s << row(-5);
  s << "DOES NOT COMPUTE!";
  s << row(5);
  s << "-->COMPUTES WITH STYLE!<--";
  return 0;
}
