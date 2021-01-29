#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

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
  int  i=1,j=2;
  vector<int> prime;
  while(i <= n)
  {
    {
      bool flag = true;
      for (int z : prime)
      {
        if (j%z==0 && z!=1)
        {
           flag = false;
           break;
        }
      }
      if (flag)
      {
        i++;
        prime.push_back(j);
        cout <<" " << j;
      }
      j++;
    }
  }
  cout << endl;
     return 0;
}
