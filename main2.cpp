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
  string FN ="", SN="";
  double num = 0.0, nextnum = 0.0;

  cout << "File Name of Output:";
  getline(cin, FN);
  ofstream fileWrite(FN.c_str(), ios::out);

  fileWrite << index << " ";
  for(int i=0; i<x.size(); i++)
    {
        fileWrite << x[i] << endl;
    }
  fileWrite.close();
}

void getCrossCorrelation(vector<double> &temp, vector<double> &r_xy, vector<double> x, int firstL, int lastL, int type)
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
    if (type == 1)
    {
      r_xy.insert(r_xy.begin(),sum);
    }
    else if (type == 2)
    {
      r_xy.push_back(sum);
    }
    else
    {
      cout << "What the hell happened?";
    }
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

void Adjust(vector<double> &x, int adjustMax)
{
  for(int n = 1; n < adjustMax; n++) //inserting 0 for begin lag
  {
    x.insert(x.begin(), 0);
  }
}

int main()
{
  string fileName1, fileName2;
  int signalsIndex1, signalsIndex2, signal1LastIndex, signal2LastIndex;
  int lastL, firstL, type;
  vector<double> firstSignals, secondSignals, temp, r_xy;

  cout << "Enter file name for the first signals: ";
  getline(cin, fileName1);
  
  firstSignals = extractSignals(fileName1.c_str(), signalsIndex1);
  cout << "Index 1: " << signalsIndex1 << endl;
  for (int i = 0; i < firstSignals.size(); i++)
  {
    cout << firstSignals.at(i) << endl;
  }

  cout << "Enter file name for the second signals: ";
  getline(cin, fileName2);

  secondSignals = extractSignals(fileName2.c_str(), signalsIndex2);
  cout << "Index 2: " << signalsIndex2 << endl;
  for (int i = 0; i < secondSignals.size(); i++)
  {
    cout << secondSignals.at(i) << endl;
  }
  
  signal1LastIndex=signalsIndex1+firstSignals.size()-1;
  signal2LastIndex=signalsIndex2+secondSignals.size()-1; //is this needed?
  lastL=signal1LastIndex-signalsIndex2;
  firstL=signalsIndex1-signal2LastIndex;

  if(signalsIndex1<signalsIndex2)
  {
    type = 1; //inserts element to start of array via insert begin
  }
  else if(signalsIndex1>signalsIndex2)
  {
    type = 2; //inserts element to end of array via pushback
  }

  subtractAverage(firstSignals, getMean(firstSignals));
  subtractAverage(secondSignals, getMean(secondSignals));

  temp = secondSignals;

  Adjust(temp, firstSignals.size());
  getCrossCorrelation(temp, r_xy, firstSignals, firstL, lastL, type);
  Normalize(r_xy, NormalCoeff(firstSignals,secondSignals));
  PrintData(r_xy);
  FileWrite(r_xy, firstL);

  return 0;
}