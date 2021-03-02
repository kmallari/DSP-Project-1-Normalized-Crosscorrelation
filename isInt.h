<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> Felipe
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
<<<<<<< HEAD
=======
=======
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
>>>>>>> 8df1741c5593124fcd7bbf39aad3c638f1f7c4a5
>>>>>>> Felipe
