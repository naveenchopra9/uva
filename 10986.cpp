	#include <iostream>
	#include <bits/stdc++.h>
	#include <vector>
	#include <utility>
	#include <queue>
	#include <functional>
	#include <algorithm>

	using namespace std;

	const int MAX=100001;
	typedef pair <long long ,int> P;
	bool marked[MAX];
	vector <P> adj[MAX];
	const int INF= 0x3f3f3f3f;
	int d[MAX];
	void Diskstra(int s)
	{

			priority_queue< P,vector<P>,greater<P> >Q;
			memset(d,INF,sizeof(d));
			memset(marked,false,sizeof(marked));
			int x;
			P p;
			d[s]=0;
			int y,z;
			Q.push(make_pair(0,s));
			
			while(!Q.empty())
			{
			//select which have minimum weight 
				p=Q.top();
				Q.pop();
				x=p.second;
				//checkcycle in graph
				if(marked[x]==true)
					continue;
				 marked[x]=true;
				for (int i = 0; i < adj[x].size(); ++i)
				{
						z=adj[x][i].second;
						y=adj[x][i].first;
						if(d[z]>d[x]+y)// check if the next vertex distance could be minimized
						{
							d[z]=d[x]+y;
							Q.push(make_pair(d[z],z));
							}

			}
			}
			
	}

	int main()
	{
		int test,n,m,s,t,x,y,cases=0;
		long long weight;
		cin>>test;
		for(int k = 0 ; k  < test ; k++)
		{
			cin>>n>>m>>s>>t;
			for (int i = 0; i <= n; ++i)
			{
				adj[i].clear();
			}
		for(int i = 0; i < m; ++i)
		{
				cin>>x>>y>>weight;
				adj[y].push_back(make_pair(weight,x));	
				adj[x].push_back(make_pair(weight,y));	
		}	
		Diskstra(s);
		if(INF==d[t])
		cout<<"Case "<<"#"<<++cases<<": "<<"unreachable"<<endl;
	    else
	    	cout<<"Case "<<"#"<<++cases<<": "<<d[t]<<endl;
		}
		return 0;
	}
