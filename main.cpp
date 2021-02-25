#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

//will replace isDboule function with sir lui's code
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
  string fileName1, fileName2, signalText1, signalText2;
  cin >> fileName1;
  fstream signalFile1(fileName1);
  if (signalFile1.is_open())
  {
    while (getline (signalFile1, signalText1))
    {
      cout << signalText1 << endl;
    }
    signalFile1.close();
  }
  return 0;
}