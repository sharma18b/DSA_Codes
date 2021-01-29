#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

double monte_carlo()
{
  int n = 10000;
  double pi;
  cout <<" testing for 100" << endl;
  int inside = 0,outside =0,tpoints=0;
  for (int i=0;i<n*n;i++)
  {
    double randomx = double(rand()%(n+1))/n;
    double randomy = double(rand()%(n+1))/n;
    if (randomx*randomx + randomy*randomy <= 1) inside++;
    else outside++;
    tpoints++;
    pi = double(4 * inside)/tpoints;
    //cout << "current value of pi = " << double(4 * inside)/tpoints << endl;
  }
  cout << "final value of pi " << pi << endl;
  return pi;
}



int main()
{
  cout << monte_carlo() << "hell yeah" <<  endl;

  return 0;
}
