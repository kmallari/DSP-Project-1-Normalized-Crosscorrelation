#ifndef GETCROSSCORRELATION_H_INCLUDED
#define GETCROSSCORRELATION_H_INCLUDED
#include <vector>
#include <iostream>

using namespace std;

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


#endif //GETCROSSCORRELATION_H_INCLUDED