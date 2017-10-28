#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#include <string>
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
vi adj[2505];
#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
int d[2505];
void maxRepeating(int rendcount, int n)
{
	if(rendcount==0)
		printf("0\n");
	else
	{
	int count[2505];

	REP(i,0,2505)
	{
		count[i]=0;
	}
	// printf("!!%d\n",count[0] );
   	REP(i,0,2505)
   	{
   		if(d[i]!=MIN)
   		count[d[i]]++;
   	}
  	int m=MIN,index;
  	REP(j,1,2500)
  	{
  		if(m<count[j])
  		{
  			m=count[j];
  			index=j;
  		}
  		// if(j<10)
  		// 	printf("%d %d\n", count[j],d[j]);
  	}
  	printf("%d %d\n",count[index],index );
    }
}

void BFS(int s,int E)
{
	queue<int>q;
	bool visited[E];
	memset(visited,false,sizeof(visited));
	visited[s]=true;
	q.push(s);
	int rendcount=0;
	d[s]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		TRvi(adj[x],it)
		{
			if(d[*it]==MIN&&visited[*it]==false)
				{	
					q.push(*it);
					visited[*it]=true;
					d[*it]=d[x]+1;
					rendcount++;
				}
		}
	}
			maxRepeating(rendcount,E);

}
int main(int argc, char const *argv[])
{
	// FR;
	// FW;
	int E;
	E=IN;
	REP(i,0,E)
	{
		int N;
		N=IN;
		REP(j,0,N)
			{
				int x;
				x=IN;
				adj[i].pb(x);
			}
	}

	int test;
	test=IN;
	REP(i,0,test)
	{
	REP(k,0,2505)
			d[k]=MIN;

	int s;
	s=IN;
	BFS(s,E);
	}
	return 0;
}
