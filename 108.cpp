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
int a[101][101];
int LIS(int b[],int size)
{

   int max = -999999, maxending = 0;
   for (int  i = 0; i < size; i++)
   {
       maxending = maxending+ b[i];
       if (max < maxending)
           max = maxending;
          if (maxending < 0)
           maxending = 0;
   }
   return max;

}

int main()
{
    int N;
while(scanf("%d",&N)==1)
  {
    int a[N][N];
    for (int i = 0; i < N; ++i)
    {
    	for(int  j =0 ; j< N ; j++)
    	{
    		scanf("%d",&a[i][j]);
    	}
    }

    int L=0,R=0;
    int totalsum=-9999999;
    int b[N];
    for (int i = 0; i < N; ++i)
    {
    	b[i]=0;
    }
     int currentsum=0;

    while(1)
    {
      for (int i = 0; i < N; ++i)
      {
      	   b[i]=b[i]+a[i][R];
      	
      }

        currentsum=LIS(b,N);
      	if(currentsum>totalsum)
      		totalsum=currentsum;
    	if(L==N-1&&R==N-1)
    	{

    		break;
    	}
    	if(R==N-1)
    	{
    		L=L+1;
    		R=L;
    		for(int j=0 ; j< N ; j++)
    		{
    			b[j]=0;
    		}
    	
    	}
    	else
    	{
    	R++;
        }
    }

    cout<<totalsum<<endl;
}

    return 0;
}
