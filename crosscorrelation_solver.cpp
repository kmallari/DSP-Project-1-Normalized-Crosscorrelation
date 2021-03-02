#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include "FileWrite.h"
#include "PrintData.h"
#include "getMean.h"
#include "isDouble.h"
#include "subtractAverage.h"
#include "NormalCoeff.h"
#include "Normalize.h"
#include "Adjust.h"
#include "getCrossCorrelation.h"


using namespace std;

int main()
{
  vector<double> x{2, 4, 1}, y{3,1,3}, temp, r_xy;
  int xstart = -1, xend, ystart = 3, yend, lastL, firstL, type;
  xend=xstart+x.size()-1;
  yend=ystart+y.size()-1; //is this needed?
  lastL=xend-ystart;
  firstL=xstart-yend;

  if(xstart<ystart)
  {
    type = 1; //inserts element to start of array via insert begin
  }
  else if(xstart>ystart)
  {
    type = 2; //inserts element to end of array via pushback
  }

  subtractAverage(x, getMean(x));
  subtractAverage(y, getMean(y));
  cout << "X DATA: \n";
  PrintData(x);
  cout << "Y DATA: \n";
  PrintData(y);
  temp = y;

  Adjust(temp, x.size());
  getCrossCorrelation(temp, r_xy, x, firstL, lastL, type);

  cout << "r_xy pre-normalization" <<endl;
  PrintData(r_xy);
  cout << "\n r_xy normalized" <<endl;
  Normalize(r_xy, NormalCoeff(x,y));
  PrintData(r_xy);

  FileWrite(r_xy, firstL);
}
