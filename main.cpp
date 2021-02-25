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
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  string fileName1 = "signal-1.txt", fileName2 = "signal-2.txt", signalText1, signalText2, tempString;
  stringstream ss, ss2, ss3, ss4;
  int lineNumber = 0, stringNum = 0;
  double signalsIndex1, signalsIndex2, tempDouble;
  vector<double> firstSignals, secondSignals;
  cout << "Enter file name for the first signals: ";
  // cin >> fileName1;
  fstream signalFile1(fileName1);
  if (signalFile1.is_open())
  {
    while (getline (signalFile1, signalText1))
    {
      if (lineNumber == 0)
      {
        ss << signalText1;
        ss >> tempString;
        if (isDouble(tempString, signalsIndex1))
        {
          cout << "SIGNAL INDEX 1 " << signalsIndex1  << endl;
        }
        tempString = "";
        ss >> tempString;
        if (isDouble(tempString, tempDouble))
        {
          firstSignals.push_back(tempDouble);
        }
        tempString = "";
        lineNumber++;
        ss.clear();
      }
      else
      {
        ss2 << signalText1;
        ss2 >> tempString;
        ss2.clear();
      
        if (isDouble(tempString, tempDouble))
        {
          firstSignals.push_back(tempDouble);
        }
        tempString = "";
      }
    }
    signalFile1.close();
  }
  for (int i = 0; i < firstSignals.size(); i++)
  {
    cout << firstSignals.at(i) << endl;
  }

  lineNumber = 0;
  ss2.clear();

  cout << "Enter file name for the second signals: ";
  // cin >> fileName1;

  fstream signalFile2(fileName2);
  if (signalFile2.is_open())
  {
    while (getline (signalFile2, signalText2))
    {
      if (lineNumber == 0)
      {
        ss3 << signalText2;
        ss3 >> tempString;
        if (isDouble(tempString, signalsIndex2))
        {
          cout << "SIGNAL INDEX 2 " << signalsIndex2  << endl;
        }
        tempString = "";
        ss3 >> tempString;
        if (isDouble(tempString, tempDouble))
        {
          secondSignals.push_back(tempDouble);
        }
        tempString = "";
        lineNumber++;
        ss3.clear();
      }
      else
      {
        ss4 << signalText2;
        ss4 >> tempString;
        ss4.clear();
      
        if (isDouble(tempString, tempDouble))
        {
          secondSignals.push_back(tempDouble);
        }
      }
    }
    signalFile1.close();
  }
  for (int i = 0; i < secondSignals.size(); i++)
  {
    cout << secondSignals.at(i) << endl;
  }

  return 0;
}