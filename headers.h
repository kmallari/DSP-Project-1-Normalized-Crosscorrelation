#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

using namespace std;

void FileWrite(vector<double> x, int index);

void getCrossCorrelation(vector<double> &temp, vector<double> &r_xy, vector<double> x, int firstL, int lastL, int type);

double getMean(vector<double> x);

bool isDouble(string s, double &value);

bool isInt(string s, int &value);

double NormalCoeff(vector<double> x, vector<double> y);

void Normalize(vector<double> &x, double NormalFactor);

void PrintData(vector<double> x);

void subtractAverage(vector<double> &x, double mean);

vector<double> extractSignals(string fileName, int &signalsIndex);

void Adjust(vector<double> &x, int adjustMax);

#endif