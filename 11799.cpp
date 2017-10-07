#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
using namespace std;
int max(int a ,int b)
{
	return (a>b)?a:b;
}
int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
	 int s,mx;
	 mx=0;
	 cin>>s;
	 int a;
	 for(int j =0 ; j < s ; j++)
	 {
	 	cin>>a;
  		mx=max(mx,a);
	 }
	 cout<<"Case "<<i+1<<": "<<mx<<endl;
	}
}