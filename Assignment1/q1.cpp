#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


double mean(int* a,int n)
{
    double ans =0;
    for (int i=0;i<n;i++)
    {
    	ans += a[i];
    }
    return (ans/(n*(1.0)));
}

int max_value(int* a,int n)
{
	int ans = a[0];
	for (int i=0;i<n;i++)
	{
		ans = (ans > a[i]) ? ans : a[i];
	}
	return ans;
}

int min_value(int* a,int n)
{
	int ans = a[0];
	for (int i=0;i<n;i++)
	{
		ans = (ans < a[i]) ? ans : a[i];
	}
	return ans;
}


int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	if (n>0)
	{
	cout << "The mean of the above numbers is " << mean(a,n) << endl;

	cout << "The max value of the above numbers is " << max_value(a,n) << endl;

	cout << "The min value of the above numbers is " << min_value(a,n) << endl;
    }
    return 0;
}
