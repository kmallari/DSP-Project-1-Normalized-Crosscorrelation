<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> Felipe
#ifndef ISDOUBLE_H_INCLUDED
#define ISDOUBLE_H_INCLUDED
#include <string>

using namespace std;

bool isDouble(string s, double &value)
{
  double tempValue;
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

#endif // ISDOUBLE_H_INCLUDED
<<<<<<< HEAD
=======
=======
#ifndef ISDOUBLE_H_INCLUDED
#define ISDOUBLE_H_INCLUDED
#include <string>

using namespace std;

bool isDouble(string s, double &value)
{
  double tempValue;
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

#endif // ISDOUBLE_H_INCLUDED
>>>>>>> 8df1741c5593124fcd7bbf39aad3c638f1f7c4a5
>>>>>>> Felipe
