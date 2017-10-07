#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bits/stdc++.h>
using namespace std;
	char a[10001][10001];
	char c[10001][10001];

int rotate(int r1,int r2)
{
   
 	char b[r1][r1];
	for (int i = 0; i < r1; ++i)
	{
		for(int j =0 ; j<r1 ; j++)
		{
			b[i][j]=a[r1-j-1][i];
		}
	}

	int p,q,s,t;
	int temp=0;
	int count=0;
	for (int i = 0; i <= r1-r2; ++i)
	{
		for(int j =0 ; j <= r1-r2 ; j++)
		{
			s=i;
			t=j;
			for(p =i ; p<r2+s ; p++)
			{
				for(q=j; q<r2+t; q++)
				{
					if(b[p][q]==c[p-s][q-t])
					{
						++temp;
					}
				}
				// 	cout<<endl;
			}
			if(temp==r2*r2)
			       count++;
			temp=0;
		}
	}
	for (int i = 0; i < r1; ++i)
	{
		for(int j =0 ; j<r1 ; j++)
		{
			a[i][j]=b[i][j];
		}
	}
	return count;
}
int main()
{
	while(1)
	{
	int r1,r2;
	cin>>r1>>r2;
	if(r1==0&&r2==0)
		break;
	for (int i = 0; i < r1; ++i)
	{
		for(int j =0 ; j<r1 ; j++)
		{
			cin>>a[i][j];
		}
	}
	for (int i = 0; i < r2; ++i)
	{
		for(int j =0 ; j<r2 ; j++)
		{
			cin>>c[i][j];
		}
	}

     int  count4=rotate(r1,r2);
     int  count3=rotate(r1,r2);
     int count2=rotate(r1,r2);
     int  count1=rotate(r1,r2);
     cout<<count1<<" "<<count2<<" "<<count3<<" "<<count4<<endl;
	}

	return 0;
}