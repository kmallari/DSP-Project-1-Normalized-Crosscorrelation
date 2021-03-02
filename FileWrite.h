#ifndef FILEWRITE_H_INCLUDED
#define FILEWRITE_H_INCLUDED
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void FileWrite(vector<double> x, int index) //file write function
{
  string FN ="", SN="";
  double num = 0.0, nextnum = 0.0;

  cout << "File Name of Output:";
  getline(cin, FN);
  ofstream fileWrite(FN.c_str(), ios::out);

  fileWrite << index << " ";
  for(int i=0; i<x.size(); i++)
    {
        fileWrite << x[i] << endl;
    }
  fileWrite.close();
}



#endif // FILEWRITE_H_INCLUDED
