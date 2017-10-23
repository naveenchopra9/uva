	#include <iostream>
	#include <bits/stdc++.h>
	#include <vector>
	#include <utility>
	#include <queue>
	#include <functional>
	#include <algorithm>
	using namespace std;

	const int MAX=999999;
	typedef pair <long long ,int> P;
	vector <P> adj[MAX];
	int cost[MAX];
	bool marked[MAX];
	int parent[MAX];
	void prim_MST(int s,int d,int edges)
	{

			for (int i = 0; i < edges; ++i)
			{
				marked[i]=false;
				parent[i]=-1;
				cost[i]=-99999;

			}

			priority_queue< P,vector<P>,greater<P> >Q;

			int x;
			P p;

			int z;

			Q.push(make_pair(0,s));
			
			while(!Q.empty())
			{
				//select which have minimum weight 
				p=Q.top();
				Q.pop();
				x=p.second;
				// printf("#%d %lld \n",x,p.first );
				//checkcycle in graph
				if(marked[x]==true)
					continue;

				marked[x]=true;
				cost[x]=p.first;
				for (unsigned i = 0; i < adj[x].size(); ++i)
				{
						z=adj[x][i].second;
						//printf("%lld \n",adj[x][i].first );
						if(marked[z]==false)
						{
								Q.push(adj[x][i]);
								parent[z]=x;
								//cost[z]=adj[x][i].first;
								// printf("%d %d %d \n",z,parent[z],cost[z] );
						}
				}

			}
			// // printf("\n");
			// int temp=0;
			// for (int i = 0; i < edges; ++i)
			// {

			// 		cout<<parent[i]<<" "<<cost[i]<<endl;
			// }
			// 	printf("\n");
			// printf("\n");
				 int max=-1;
			if(marked[d]==false)
				printf("no path\n");
			else
			{
			while(s!=d)
				{
					//printf("%d \n",parent[d] );
					//printf("%d\n",cost[d] );
					if(max<cost[d])
						max=cost[d];
					d=parent[d];
				}
				printf("%d\n",max );
			}
	}

	int main()
	{
		// freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
		int temp=0;
		while(1)
		{
		int vertice,edges,test;

		cin>>vertice>>edges>>test;
		if(vertice==0&&edges==0&&test==0)
			break;
		else if(temp!=0)
			printf("\n");
		int x,y;
		long long weight;
		for (int i = 0; i < vertice; ++i)
		{
			adj[i].clear();
		}
		for(int i = 0; i < edges; ++i)
		{
				cin>>x>>y>>weight;
				adj[y-1].push_back(make_pair(weight,x-1));	
				adj[x-1].push_back(make_pair(weight,y-1));	
		}	
		int s,d;
		printf("Case #%d\n", temp+1);
			while(test--)
		{
			cin>>s>>d;
		prim_MST(s-1,d-1,vertice);	
		}
		temp++;
		}
		return 0;
	}
