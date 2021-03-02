#ifndef GETMEAN_H_INCLUDED
#define GETMEAN_H_INCLUDED
#include <cmath>
#include <vector>

using namespace std;

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

#endif // GETMEAN_H_INCLUDED