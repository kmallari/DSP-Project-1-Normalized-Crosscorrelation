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
  int signalsIndex1 = 0, signalsIndex2 = 0;
  int signal1LastIndex, signal2LastIndex;
  int lastL, firstL, type;
  vector<double> firstSignals, secondSignals, temp, r_xy;

  cout << "First Signals..." <<endl;
  firstSignals = extractSignals(signalsIndex1);
  //cout << "Index 1: " << signalsIndex1 << endl;
  //for (int i = 0; i < firstSignals.size(); i++)
  //{
    //cout << firstSignals.at(i) << endl;
  //}
// uncomment lines when u want to see the signals extracted

  cout << "\nSecond Signals..." <<endl;
  secondSignals = extractSignals(signalsIndex2);
  //cout << "Index 2: " << signalsIndex2 << endl;
  //for (int i = 0; i < secondSignals.size(); i++)
  //{
    //cout << secondSignals.at(i) << endl;
  //}

  signal1LastIndex=signalsIndex1+firstSignals.size()-1;
  signal2LastIndex=signalsIndex2+secondSignals.size()-1;
  lastL=signal1LastIndex-signalsIndex2;
  firstL=signalsIndex1-signal2LastIndex;

  subtractAverage(firstSignals, getMean(firstSignals));
  //PrintData(firstSignals);
  //cout << endl;
  subtractAverage(secondSignals, getMean(secondSignals));
  //PrintData(secondSignals);
  //cout << endl;

  temp = secondSignals;

  Adjust(temp, firstSignals.size());
  getCrossCorrelation(temp, r_xy, firstSignals, firstL, lastL);
  //PrintData(r_xy);
  //cout << endl;
  Normalize(r_xy, NormalCoeff(firstSignals,secondSignals));
  //PrintData(r_xy);
  //cout << endl;
  FileWrite(r_xy, firstL);

  return 0;
}
