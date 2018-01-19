<<<<<<< HEAD
//prakash edited
//naveen  ....
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
=======
//prakash reedited this file 
#include <algorithm>
#include <iostream>
#include <iterator>
/*#include <numeric>
#include <sstream>,vngekjvbgbty
rrrtryhythyt
#include <fstream>jlgvngki
>>>>>>> d1d181e149d5b01827212c97130e7e983d54e7f9
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
//#include <string>56546846854
#include <cstdio>
#include <vector>
#include <cmath>
// #include <queue>
// #include <deque>
#include <stack>
#include <list>
<<<<<<< HEAD
// #include <map>
=======
//#include <map>
>>>>>>> d1d181e149d5b01827212c97130e7e983d54e7f9
#include <set>
#include <bits/stdc++.h>
using namespace std;
vector< vector<int> >adj;
void TSuntil(int V,int x,vector<int>& color)
{
	 queue<int>q;
	 color[x]=1;
	 q.push(x);//lkjbfejrkjhgbetgyjj
	while(!q.empty())
	{
		int p=q.front();
			q.pop();
	for (int i = 0; i <adj[p].size(); ++i)
	{
		if(color[adj[p][i]]==-1)
		{
			  color[adj[p][i]]=1-color[p];
			  q.push(adj[p][i]);
			 
		}
	}
	}
}
void TS(int V)
{
	vector<int>color;
	color.clear();
	color.resize(V);
	int temp=1;
	fill(color.begin(), color.end(),-1);
	for (int i = 0; i < V; ++i)
	{
		if(color[i]==-1)
		{
			TSuntil(V,i,color);
			
		}
	}
	vector<int>color1;
	color1.clear();
	color1.resize(V);
	fill(color1.begin(), color1.end(),2);
	queue<int>q1;
	color1[0]=3;
	q1.push(0);
	while(!q1.empty())
	{
		int s=q1.front();
		q1.pop();
		for (int i = 0; i <adj[s].size(); ++i)
			{
				if(s==adj[s][i])
					{
						temp=2;
						break;
					}
				if(color[s]==color[adj[s][i]])
					{
						temp=2;
						break;
					}
					if(color1[adj[s][i]]!=3)
					{
						q1.push(adj[s][i]);
						color1[adj[s][i]]=3;
					}
			}
	}


	// for (int i = 0; i < V; ++i)
	// {
	// 	cout<<color[i];
	// }
	if(temp==2)
		cout<<"NOT BICOLORABLE.";
		else 
			cout<<"BICOLORABLE.";
}
// int main()
// {
// 	int V,E,x,y;
// 	while(1)
// 	{
// 	cin>>V>>E;
// 	if(V==0)
// 		break;
// 	adj.clear();
// 	adj.resize(V);

// 	for (int i = 0; i < E; ++i)
// 	{
// 		cin>>x>>y;
// 		adj[x].push_back(y);
// 		adj[y].push_back(x);
// 	}

// 	TS(V);

// 	cout<<endl;
// 	}
// 	return 0;
// }
