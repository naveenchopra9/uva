	#include <iostream>
	#include <bits/stdc++.h>
	#include <vector>
	#include <utility>
	#include <queue>
	#include <functional>
	#include <algorithm>
	#include <numeric>
using namespace std;
int main()
{

		// freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int k,j,temp;
	int temp1=0;
   for (int i = 1; i < n; i++)
   {
       k = a[i];
       j = i-1;
       temp=0;
       while (j >= 0)
       {
       	  if(a[j]<=k)
           temp++;
           j = j-1;
       }	
       temp1+=temp;
	}
    	printf("%d\n", temp1);
    }
}
