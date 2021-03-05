#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <cmath>

using namespace std;

void FileWrite(vector<double> x, int index) //file write function
{
  string FN ="", test, extension = ".txt";

  cout << "File Name of Output:";
  getline(cin, FN);
  test = FN.substr(FN.size()-4, 4);
  if(test != ".txt")
  {
      FN = FN + extension;
  }
  ofstream fileWrite(FN.c_str(), ios::out);

  fileWrite << index << " ";
  for(int i=0; i<x.size(); i++)
    {
        fileWrite << x[i] << endl;
    }
  fileWrite.close();
}

void getCrossCorrelation(vector<double> &temp, vector<double> &r_xy, vector<double> x, int firstL, int lastL)
{
  for(int n = lastL; n >= firstL; n--)
  {
    double sum = 0;
    for(int z = 0; z < x.size(); z++)
    {
      if(temp.size()<z+1)
      {
        break;
      }
      sum+=x[z]*temp[z];
    }
    r_xy.insert(r_xy.begin(),sum);
    temp.erase(temp.begin());
  }
}

double getMean(vector<double> x)
{
  double mean, sum=0;

  for(int i=0; i<x.size(); i++)
  {
    sum = x[i] + sum;
  }
  mean = sum/x.size();
  return mean;
}

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

double NormalCoeff(vector<double> x, vector<double> y)
{
  double sum1=0, sum2=0;
  for(int n=0; n<x.size(); n++)
  {
    sum1+= x[n]*x[n];
  }
  for(int n=0; n<y.size(); n++)
  {
    sum2+= y[n]*y[n];
  }
  return sqrt(sum1*sum2);
}

void Normalize(vector<double> &x, double NormalFactor)
{
  vector<double> temp;
  for(int n = 0; n < x.size(); n++)
  {
    temp.push_back(x[n] / NormalFactor);
  }
  x.swap(temp);
  temp.clear();
}

void PrintData(vector<double> x)
{
  for (int i = 0; i < x.size(); i++)
  {
    cout << x[i] << endl;
  }
}

void subtractAverage(vector<double> &x, double mean)
{
  vector<double> temp;
  for(int n = 0; n < x.size(); n++)
  {
    temp.push_back(x[n] - mean);
  }
  x.swap(temp);
  temp.clear();
}

vector<double> extractSignals(int &signalsIndex)
{
  string signalText, tempString, fileName;
  stringstream ss, ss2;
  int lineNumber = 0;
  double tempDouble;
  vector<double> signals;

  cout << "Enter file name for the signals: ";
  getline(cin, fileName);

  fstream signalFile(fileName);

  if (!signalFile.is_open())
  {
      cout << "Invalid File Name, Please try again..." <<endl;
      signalFile.close();
      signals = extractSignals(signalsIndex);
  }
  else if (signalFile.is_open())
  {
    while (getline(signalFile, signalText))
    {
      if (lineNumber == 0)
      {
        ss << signalText;
        ss >> tempString;
        if (!isInt(tempString, signalsIndex))
        {
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

void Adjust(vector<double> &x, int adjustMax)
{
  for(int n = 1; n < adjustMax; n++) //inserting 0 for begin lag
  {
    x.insert(x.begin(), 0);
  }
}
