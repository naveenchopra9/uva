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
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;
vector< int >adj,sum;
vector< bool >visted;	
int maxvalue=-1;

int  DFS(int s,int temp)
{
	visted[s]=true;
	int len=0;
	if(!visted[adj[s]]&&adj[s]!=-1)
	{
			len+=1+DFS(adj[s],temp);
			// 	printf("%d \n", len);
	}
			visted[s]=false;
    return sum[s]=len;
}


int main(int argc, char const *argv[])
{
	  
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

		ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
		int t;
		int l=1;
	cin>>t;
	while(t--)
	{
	int ne;
	cin>>ne;
	int u,v;
	adj.assign(ne,-1);
	for (int i = 0; i < ne; ++i)
	{
		cin>>u>>v;
		adj[u-1]=v-1;
	}

	int maxvalue1=maxvalue;
	int temp1=-1;
		visted.assign(ne,false);
		sum.assign(ne,-1);
	for (int i = 0; i <ne; ++i)
	{
		 if(sum[i]==-1)
			  maxvalue=DFS(i,ne);
		if(maxvalue1<maxvalue)
		{
			maxvalue1=maxvalue;
			temp1=i;
		}
	}
	printf("Case %d: %d\n",l,temp1+1 );
	maxvalue=-1;
	l++;
	}
	return 0;
}
