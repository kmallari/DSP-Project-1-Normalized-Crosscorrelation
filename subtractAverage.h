#ifndef SUBTRACTAVERAGE_H_INCLUDED
#define SUBTRACTAVERAGE_H_INCLUDED
#include <vector>

using namespace std;

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



#endif //SUBTRACTAVERAGE_H_INCLUDED