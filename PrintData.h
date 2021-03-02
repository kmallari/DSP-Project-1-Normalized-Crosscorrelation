#ifndef PRINTDATA_H_INCLUDED
#define PRINTDATA_H_INCLUDED
#include <iostream>
#include <vector>

using namespace std;

void PrintData(vector<double> x)
{
  for (int i = 0; i < x.size(); i++)
  {
    cout << x[i] << endl;
  }
}


#endif // PRINTDATA_H_INCLUDED