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
vi adj[200+3];
bool visited[200+3];
int color[200+3];
int NewBFS(int V,int s,bool visited[],int  color[])
{
	queue<int>q;	q.p(s);
	color[s]=0;
	visited[s]=true;
	// int d[203];
	// Set(d,0);
	int cnt[2];
	Set(cnt,0);
	cnt[0]=1;
	// printf("s-	%d %d \n",cnt[0],cnt[1] );
	while(!q.empty())
	{
		int x=q.front(); q.pop();
		// printf("x-%d \n",x );
		TRvi(adj[x],it)
		{
			// if(*it==x)
			// 	return false;
			// printf("#%d %d %d \n", *it,color[*it],color[x]);
				if(color[*it]==-1)
				{
						color[*it]=1-color[x];	
						cnt[color[*it]]++;
						q.p(*it);
						visited[*it]=true;
						// d[*it]=d[x]+1;
				}
				else if(color[*it]==color[x])
						return -1;
		}
	}

	// int m=0;
	// REP(k,0,V)
	// {
	// 	// printf("%d\n",d[k] );
	// 	if(m<d[k]){
	// 		m=d[k];
	// 	}
		// printf("m=%d\n",m );
	// }
	// printf("%d %d \n",cnt[0],cnt[1] );
	return (cnt[0]>cnt[1]?cnt[1]:cnt[0]);
}
void BFS(int V,int E)
{
	Set(visited,false);
	REP(i,0,V)
		color[i]=-1;
		int ma=0;
		int count=0;
	REP(k,0,V)
	{
		if(visited[k]==false)
		{
		 ma=NewBFS(V,k,visited,color);

		 // printf("#\n");
		if(ma!=-1)
		{
			count+=ma;
		}
	 if(ma==0)
			count++;
		if(ma==-1)
			break;
		// printf("%d \n",ma );
		// printf("%d\n",ma );
		}
		
	}
	if(count==0)
		printf("-1\n");
	else
	printf("%d\n",count);
	// REP(l,0,V)
	// 			printf("%d ",color[l] );

}
int main(int argc, char const *argv[])
{
	// FR;
	// FW;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	t=IN;
	REP(i,0,t)
	{
	int V,E;
	V=IN;
	E=IN;
	
	REP(i,0,203)
		adj[i].clear();

	REP(j,0,E)
	{
		int x,y;       		x=IN; y=IN;
		adj[x].pb(y);		adj[y].pb(x);
	}
	BFS(V,E);
	}
	return 0;
}
