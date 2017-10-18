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

typedef pair<int,int> ii;

typedef pair<int,ii> iii;

typedef vector<int> vi;

vector<vector<int > > weight;

int arr1[4]={-1,0,0,1};
int arr2[4]={0,-1,1,0};

int findmin(int n,int m)
{
	priority_queue<iii,vector<iii>,greater<iii> > Q;

	bool visited[n][m];
	memset(visited,false,sizeof(visited));
	
	vector<vector<int > > result;
	result.clear();
	vi row(m,9999999);
	result.assign(n,row);
	//visited[0][0]=true;
	result[0][0]=weight[0][0];

	Q.push(iii(result[0][0],ii(0,0)));
	
	while(!Q.empty())
	{
		iii temp=Q.top();
		Q.pop(); //
	
		int a=temp.first;
		int b=temp.second.first;
		int c=temp.second.second;
		if(visited[b][c]==true)
			continue;

				visited[b][c]=true;
		for (int i = 0; i < 4; ++i)
		{
			int newr=b+arr1[i];
			int newc=c+arr2[i];

			if(newr<n && newr>=0 && newc>=0 &&newc<m)
			{
				if(result[newr][newc]>a+weight[newr][newc])
				{
					result[newr][newc]=result[b][c]+weight[newr][newc];
					Q.push(iii(result[newr][newc],ii(newr,newc)));
				}
			}
		}

	}
	return result[n-1][m-1];

}
int main()
{
	    // freopen("input.txt","r",stdin);
     // 	freopen("output.txt","w",stdout);

	int t;
	cin>>t;
	while(t--)
	{
		 int n ,m ;
	  	 cin>>n>>m;
	  	 	cin.ignore();
		   for (int i = 0; i < n; ++i)
		   {
		   		vi row;
		   		for(int j = 0 ; j < m ; j++)
		   		{
		   			int wv;
		   			cin>>wv;
		   			row.push_back(wv);
		   		}
		   		  weight.push_back(row);
		   		  row.clear();

		   }
	   cout<<findmin(n,m)<<endl;
	   weight.clear();


   }

}
