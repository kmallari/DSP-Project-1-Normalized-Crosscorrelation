#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include "headers.h"

using namespace std;

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