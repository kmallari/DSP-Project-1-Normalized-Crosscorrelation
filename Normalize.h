#ifndef NORMALIZE_H_INCLUDED
#define NORMALIZE_H_INCLUDED
#include <vector>

using namespace std;

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

#endif //NORMALIZE_H_INCLUDED