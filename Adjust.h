#ifndef ADJUST_H_INCLUDED
#define ADJUST_H_INCLUDED
#include <vector>

using namespace std;

void Adjust(vector<double> &x, int adjustMax)
{
  for(int n = 1; n < adjustMax; n++) //inserting 0 for begin lag
  {
    x.insert(x.begin(), 0);
  }
}



#endif //ADJUST_H_INCLUDED