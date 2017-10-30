	//Two condition most be hold for articulation point in graph
	//  root vertex with two independent children in graph
	// visited timevalue <=low timevalue of adj vertex	
	#include <bits/stdc++.h>
	#include <iostream>
	#include <cstdio>
	#include <algorithm>
	#include <cstring>
	#include <string>
	#include <cctype>
	#include <stack>
	#include <queue>
	#include <list>
	#include <vector>
	#include <map>
	#include <sstream>
	#include <cmath>
	#include <bitset>
	#include <utility>
	#include <set>
	#include <numeric>
	using namespace std;
	#define IN ({int n; scanf("%d", &n);	n;})
	#define CN ({char _char; scanf(" %c",&_char); _char;})
	#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
	#define FR freopen("input.txt","r",stdin)
	#define FW freopen("output.txt","w",stdout)
	#define f first
	#define s second
	#define pb push_back	
	#define p push
	#define sz size()
	const int INF = 0x3f3f3f3f;
	#define MAX 2147483647
	#define MIN -2147483647	
	typedef long long ll;
	typedef vector<int> vi;
	typedef pair<int, int> ii;
	typedef vector<ii> vii;
	typedef set<int> si;
	typedef map<string, int> msi;
	#define SIZE 100001;
	#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
	#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
	#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
	#define NIL -1
	#define Set(a, s) memset(a, s, sizeof (a))
	vi adj[100+5];
	int temp=0;
	//global arrays 	
	bool visited[100+3];
	int parent[100+3];
	bool AC[100+3];
	int low[100+3];
	int disc[100+3];
	int timevalue=0;

	//To find the articulation point in graph
	 void DFS(int V,int vertex)
	 {
	 	visited[vertex]=true;
	 	disc[vertex]=low[vertex]=timevalue;

	 	timevalue=timevalue+1;

	 	int child=0;

	 	TRvi(adj[vertex],it)
	 	{
	 			if(visited[*it]==false)
	 			{
	 			// printf("%d  ",*it );
	 				// printf("%d \n",i );
	 				child=child+1;
	 				parent[*it]=vertex;
	 				DFS(V,*it);
	 			
	 			low[vertex]=min(low[vertex],low[*it]);

	 			if(parent[vertex]==-1&&	child>1)
	 			{
	 				// printf("hi%d ",child );
	 				AC[vertex]=true;
	 			}

	 			if(parent[vertex]!=-1&&low[*it]>=disc[vertex])
	 			{
	 				AC[vertex]=timevalue;
	 			}

	 			}

	 			else if(parent[vertex]!=(*it))
	 					 low[vertex]=min(low[vertex],disc[*it]);
	 		
	 	}
	 }


	void ACPOINT(int V)
	{
		

		REP(i,1,103)
		{
			parent[i]=-1;
			visited[i]=false;
			low[i]=0;
			disc[i]=0;
			AC[i]=false;
		}
		REP(i,1,V)
		{
			// printf("f-%d \n",i );
		 	if(visited[i]==false)
		 	{
					 DFS(V,i);
					 // printf("a%d\n",i);
			}	
		}
		REP(i,1,V)
		{
			// printf("%d \n",parent[i] );
		if(AC[i]==true)
		{
			temp++;
					// printf("*%d ",i );
		}
		}
			printf("%d\n",temp );
			temp=0;
			timevalue=0;
	}

	int main(int argc, char const *argv[])
	{
		// FR;
		// FW;
	int t,f;
		string str;	

	while(1)
	{
		int V;
		V=IN;
		cin.ignore();
		if(V==0)
			break;
		REP(i,1,105)
		{
			adj[i].clear();
		}

		int u,v;
		// printf("*\n");
			 while(getline(cin,str)&&str!="0")
	        {
	        	// printf("8\n");
	            istringstream ss(str);
	            ss>>f;
	            if(f==0)	
	                break;
	            while(ss>>t)
	            {
	                adj[f].pb(t);
	                adj[t].pb(f);
	            }
	        }

			// REP(i,1,V+1)
			// {
			// 	REP(j,1,adj[i].size())
			// 	{
			// 		printf("%d ",adj[i][j] );
			// 	}
			// 	printf("\n\n");
			// }
			ACPOINT(V+1);
		}
		return 0;
	}
