#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


bool checkifprime(int x)
{
  if (x==1 || x==2) return true;
  for (int i=2;i<x;i++)
  {
    if (x%i==0) return false;
  }
  return true;
}

int main()
{
	int n;
	cin >> n;
  if (n==0)
  {
    cout << "there are no prime numbers before 0";
    return 0;
  }
  cout << "the first " << n << " prime nubers are : ";
  int  i=1,j=1;
  while(i <= n)
  {
    if (checkifprime(j))
    {
      cout << " " << j;
      i++;
    }
    j++;
  }



     return 0;
}
