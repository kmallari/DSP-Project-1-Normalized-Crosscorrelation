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

  cout << "\nSecond Signals..." <<endl;
  secondSignals = extractSignals(signalsIndex2);

  signal1LastIndex=signalsIndex1+firstSignals.size()-1;
  signal2LastIndex=signalsIndex2+secondSignals.size()-1;
  lastL=signal1LastIndex-signalsIndex2;
  firstL=signalsIndex1-signal2LastIndex;

  subtractAverage(firstSignals, getMean(firstSignals));
  subtractAverage(secondSignals, getMean(secondSignals));

  temp = secondSignals;

  Adjust(temp, firstSignals.size());
  getCrossCorrelation(temp, r_xy, firstSignals, firstL, lastL);
  Normalize(r_xy, NormalCoeff(firstSignals,secondSignals));
  FileWrite(r_xy, firstL);

  return 0;
}
