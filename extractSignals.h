<<<<<<< HEAD
#ifndef EXTRACTSIGNALS_H_INCLUDED
#define EXTRACTSIGNALS_H_INCLUDED

#include <vector>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "isInt.h"
#include "isDouble.h"

using namespace std;

vector<double> extractSignals(string fileName, int &signalsIndex)
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
        else 
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
}

=======
#ifndef EXTRACTSIGNALS_H_INCLUDED
#define EXTRACTSIGNALS_H_INCLUDED

#include <vector>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "isInt.h"
#include "isDouble.h"

using namespace std;

vector<double> extractSignals(string fileName, int &signalsIndex)
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
        else 
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
}

>>>>>>> 8df1741c5593124fcd7bbf39aad3c638f1f7c4a5
#endif // EXTRACTSIGNALS_H_INCLUDED