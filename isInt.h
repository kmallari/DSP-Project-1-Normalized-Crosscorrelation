#ifndef ISINT_H_INCLUDED
#define ISINT_H_INCLUDED
#include <string>

using namespace std;


bool isInt(string s, int &value)
{
  int tempValue;
  if ((istringstream(s) >> tempValue).eof())
  {
    value = tempValue;
    return true;
  }
  else
  {
    return false;
  }
}

#endif // ISINT_H_INCLUDED
