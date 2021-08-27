#include "stamp.h"
#include "stampbuff.h"
#include "stampstream.h"
#include <iostream>
#include <string>

using namespace std;



int main()
{
  stampstream s(30,10);

  s << "                      abcdefgh" << endrow;
  s << "                     abcdefghi" << endrow;
  s << "                    abcdefghij" << endrow;
  s << "                   abcdefghijk" << endrow;
  s << "                  abcdefghijkl" << endrow;
  s << "                 abcdefghijklm" << endrow;
  s << "                abcdefghijklmn" << endrow;
  s << "               abcdefghijklmno" << endrow;
  s << "              abcdefghijklmnop" << endrow;
  s << "             abcdefghijklmnopq" << endrow;
  return 0;
}
