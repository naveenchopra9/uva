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
vi adj[300+3];
bool visited[300+3];
int color[300+3];
int NewBFS(int V,int s,bool visited[],int  color[])
{
	queue<int>q;	q.p(s);
	color[s]=0;
	visited[s]=true;
	while(!q.empty())
	{
		int x=q.front(); q.pop();
		TRvi(adj[x],it)
		{
				if(color[*it]==-1)
				{
						color[*it]=1-color[x];	
						q.p(*it);
						visited[*it]=true;
				}
				else if(color[*it]==color[x])
						return -1;
		}
	}
	return 1;
}
void BFS(int V)
{
	Set(visited,false);
	REP(i,0,V)
		color[i]=-1;
		int ma=0;
	REP(k,0,V)
	{
		if(visited[k]==false)
		{
		 ma=NewBFS(V,k,visited,color);
		 // printf("%d\n",ma );
		 if(ma==-1)
		 	break;
		}
		
	}
	if(ma!=-1)
		printf("YES\n");
	else 
	printf("NO\n");
	// REP(i,0,V)
	// {
	// 	printf("%d ", color[i]);
	// 	cout<<adj[i].size()<<endl;
	// }

}
int main(int argc, char const *argv[])
{
	// FR;
	// FW;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(1)
	{
	int V,E;
	V=IN;
	if(V==0)
		break;
	
	REP(i,0,303)
		adj[i].clear();

	while(1)
	{
		int x,y;       		x=IN; y=IN;
		if(x==0&&y==0)
			break;
		adj[x-1].pb(y-1);		adj[y-1].pb(x-1);
	}
	BFS(V);
	}
	return 0;
}
