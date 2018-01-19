//Prakah editrw vgh
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define IN ({int n; scanf("%d", &n);	n;})
#define CN ({char _char; scanf(" %c",&_char); _char;})
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
// #define FR freopen("input.txt","r",stdin)
// #define FW freopen("output.txt","w",stdout)
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
typedef map<int, int> msi;
#define SIZE 100001;
#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define NIL -1
#define Set(a, s) memset(a, s, sizeof (a))
//global arrays 
int  capacity[1000+3][1000+3];
int residualcapacity[1000+3][1000+3];

void reset(int V)
{
	REP(i,0,V)
		REP(j,0,V)
		{
			capacity[i][j]=0;
			residualcapacity[i][j]=0;
		}
}
//Normal Bfs to check path from s to d graph
bool BFS(int V,int parent[],int s,int d)
{
	bool visited[V];
	Set(visited,false);
	visited[s]=true;

	queue <int>q;
	q.push(s);
	parent[s]=-1;
	
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		REP(i,0,V)
		{
			if(residualcapacity[x][i]>0&&visited[i]==false)
			{
				parent[i]=x;
				q.push(i);
				visited[i]=true;
			}
		}
	}
	if(visited[d]==true)
		return true;
	else 
		return false;
}

int findmin(int V,int parent[],int s,int d)
{
	int minvalue=INF;
	int v,u;
	v=d;
	while(v!=s)
	{
		u=parent[v];
		minvalue=min(minvalue,residualcapacity[u][v]);
		v=parent[v];
	}
	return minvalue;
}

int  Max_flow(int E,int V,int s,int d)
{
	//residual capacity first initilize to real capacity
	REP(i,0,V)
	{
		REP(j,0,V)
		{
			residualcapacity[i][j]=capacity[i][j];
		}
	}
	// printf("\n");
	// REP(i,0,V)
	// 	{
	// 		REP(j,0,V)
	// 			printf("%d ",residualcapacity[i][j] );
	// 			printf("\n");
	// 	}
	//array to store parent of path
	int parent[V];
	Set(parent,0);
	int flowvalue=0;
	// printf("*\n");
	//Check path possible or not from s to d in garph
	while(BFS(V,parent,s,d))
	{
		// printf("*\n");
		int min_value_of_flow=findmin(V,parent,s,d);
		// printf("m-%d ",min_value_of_flow );
			//reset residual capacity of graph in graph path of s to d
		int v, u;
		v=d;
		while(v!=s)
		{
			u=parent[v];
			residualcapacity[u][v]=residualcapacity[u][v]-min_value_of_flow;
			residualcapacity[v][u]=residualcapacity[v][u]+min_value_of_flow;
			v=parent[v];
		}
		flowvalue+=min_value_of_flow;
	}
	return flowvalue;
}

int main(int argc, char const *argv[])
{
	// FR;
	// FW;
	int temp=1;
	while(1)
	{
	int V;
	V=IN;//number of vertex
	if(V==0)
		break;
	reset(V);
	int E,s,d;
	s=IN; d=IN;
	E=IN;//edges
	// printf("%d %d %d \n",E,s,d );
	REP(i,0,E)
		{
		int x,y,w;
		cin>>x>>y>>w;//input u and v edge and weight of it
				capacity[x-1][y-1]+=w;

				capacity[y-1][x-1]+=w;
		}
	printf("Network %d\nThe bandwidth is %d.\n",temp,Max_flow(E,V,s-1,d-1));
	printf("\n");
	temp++;
	}
	return 0;
}
