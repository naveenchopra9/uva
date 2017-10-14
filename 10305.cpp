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
vector< vector<int> >adj;
void TSuntil(int x,vector<bool>& visit ,vector <int>& list)
{
	for (int i = 0; i <adj[x].size(); ++i)
	{
		if(!visit[adj[x][i]])
			  TSuntil(adj[x][i],visit,list);
	}
	visit[x]=true;
	list.insert(list.begin(),x+1);
}
void TS(int V,vector<bool>& visit ,vector <int>& list)
{
	for (int i = 0; i <V; ++i)
	{
		visit[i]=false;
	}
	for (int i = 0; i < V; ++i)
	{
		if(!visit[i])
		{
			TSuntil(i,visit,list);
		}
	}
}
int main()
{
	int V,E,x,y;
	while(1)
	{
	cin>>V>>E;
	if(V==0&&E==0)
		break;
	adj.clear();
	adj.resize(V);
    vector <int> list;
    vector<bool>visit;
    visit.clear();
    visit.resize(V);
	for (int i = 0; i < E; ++i)
	{
		cin>>x>>y;
		adj[x-1].push_back(y-1);
	}
	TS(V,visit,list);
	cout<<list[0];
	for (int i = 1; i <list.size(); ++i)
	{
		cout<<" "<<list[i];
	}
	cout<<endl;
	}
	return 0;
}
