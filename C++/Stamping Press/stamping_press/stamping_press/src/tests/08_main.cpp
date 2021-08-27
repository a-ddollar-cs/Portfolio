#include "stamp.h"
#include "stampbuff.h"
#include "stampstream.h"
#include <iostream>
#include <string>

using namespace std;



int main()
{
  stampstream s(30,10);

  s << "!@#$%^&*()_+{}[]\\|"
    << ";':\",./<>?";
  return 0;
}
