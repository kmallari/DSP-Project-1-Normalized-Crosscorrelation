#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool isDouble(string s, double *value=0)
{
  char* remains = NULL;
  double temporary = strtod(s.c_str(),&remains);

  if(*remains == '\0')
  {
    *value = temporary;
    return 1;
  }
  else
  {
    cout << "Invalid Value or non-float value present\nRemains: " << remains <<endl;
    return 0;
  }
}

void FileEx(vector<double> &x, vector<double> &y, string ch)
{
  string FN ="", SN="";
  double num = 0.0, nextnum = 0.0;

  cout << "X - File Name:";
  getline(cin, FN);
  ifstream fe(FN.c_str(), ios::in);

  if (!fe.is_open())
  {
    cerr << "There was a problem opening the input file!\n";
    FileEx(x,y,ch);
  }
  else
  {
    x.clear();
    while (fe >> num)
    {
      x.push_back(num);
    }
    cout << "Loading of items successful"<<endl;
    cout << "Number of items read: " << x.size() <<endl;
  }
  fe.close();
}

void PrintData(vector<double> x)
{
  for (int i = 0; i < x.size(); i++)
  {
    cout << x[i] << endl;
  }
}

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

double NormalCoeff(vector<double> x, vector<double> y)
{
  double sum1=0, sum2=0;
  for(int n=0; n<x.size(); n++)
  {
    sum1+= x[n]*x[n];
  }
  for(int n=0; n<y.size(); n++)
  {
    sum2+= y[n]*y[n];
  }
  return sqrt(sum1*sum2);
}

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

void Adjust(vector<double> &x, int adjustMax)
{
  for(int n = 1; n < adjustMax; n++) //inserting 0 for begin lag
  {
    x.insert(x.begin(), 0);
  }
}

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
}