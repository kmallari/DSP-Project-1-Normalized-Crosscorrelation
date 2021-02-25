#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isDouble(string s, double &value)
{
  double tempValue;
  if ((istringstream(s) >> tempValue).eof())
  {
    value = tempValue;
    cout << "Your string \"" << value << "\" is a valid double.";
    return true;
  }
  else
  {
    cout << "Your string \"" << s << "\" is NOT a valid double.";
    return false;
  }
}

int main()
{
  double value;

  isDouble("501", value);

  return 0;
}
