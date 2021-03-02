#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
<<<<<<< HEAD
#include "isDouble.h"
#include "isInt.h"
#include "extractSignals.h"
using namespace std;

/* bool isInt(string s, int &value)
=======
#include "isInt.h"
#include "isDouble.h"
#include "extractSignals.h"


using namespace std;

/*bool isInt(string s, int &value)
>>>>>>> Felipe
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
<<<<<<< HEAD
}*/
=======
} */
>>>>>>> Felipe

//will replace isDboule function with sir lui's code
/*bool isDouble(string s, double &value)
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
} */

/*vector<double> extractSignals(string fileName, int &signalsIndex)
{
  string signalText, tempString;
  stringstream ss, ss2;
  int lineNumber = 0;
  double tempDouble;
  vector<double> signals;

  fstream signalFile(fileName);

  if (signalFile.is_open())
  {
    while (getline(signalFile, signalText))
    {
      if (lineNumber == 0)
      {
        ss << signalText;
        ss >> tempString;
        if (!isInt(tempString, signalsIndex))
        {
          cout << "THIS RUNS" << endl;
          if (isDouble(tempString, tempDouble))
          {
            signals.push_back(tempDouble);
          }
          signalsIndex = 0;
        }
<<<<<<< HEAD
        else 
=======
        else
>>>>>>> Felipe
        {
          ss >> tempString;
          if (isDouble(tempString, tempDouble))
          {
            signals.push_back(tempDouble);
          }
          ss.clear();
        }
        lineNumber++;
      }
      else
      {
        ss2 << signalText;
        ss2 >> tempString;
        ss2.clear();

        if (isDouble(tempString, tempDouble))
        {
          signals.push_back(tempDouble);
        }
        tempString = "";
      }
    }
    signalFile.close();
  }
  return signals;
<<<<<<< HEAD
} */
=======
}*/
>>>>>>> Felipe

int main()
{
  string fileName1 = "signal-1.txt", fileName2 = "signal-2.txt";
  int signalsIndex1, signalsIndex2;
  vector<double> firstSignals, secondSignals;

  // cout << "Enter file name for the first signals: ";
  // cin >> fileName1;
<<<<<<< HEAD
  
=======

>>>>>>> Felipe
  firstSignals = extractSignals(fileName1, signalsIndex1);
  cout << "Index 1: " << signalsIndex1 << endl;
  for (int i = 0; i < firstSignals.size(); i++)
  {
    cout << firstSignals.at(i) << endl;
  }

  // cout << "Enter file name for the second signals: ";
  // cin >> fileName1;

  secondSignals = extractSignals(fileName2, signalsIndex2);
<<<<<<< HEAD
  
=======

>>>>>>> Felipe
  cout << "Index 2: " << signalsIndex2 << endl;
  for (int i = 0; i < secondSignals.size(); i++)
  {
    cout << secondSignals.at(i) << endl;
  }

  int x = 4.5;
  cout << "PRINTING INT " << x << endl;

  return 0;
}
