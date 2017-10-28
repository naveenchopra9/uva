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
#define SIZE 10002
#define IN ({int n; scanf("%d", &n);	n;})
#define CN ({char _char; scanf(" %c",&_char); _char;})
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define FR freopen("input.txt","r",stdin)
#define FW freopen("output.txt","w",stdout)
#define f first
#define s second
#define pb push_back	
const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
int graph[1005][1005];
bool visited[1005][1005];
int result[1005][1005];
int arr1[4]={-1,0,0,1};
int arr2[4]={0,-1,1,0};

int BFS(int x1,int y1,int x2,int y2,int R,int C)
{
	REP(k,0,R)
		{
			REP(d,0,C)
			{
				visited[k][d]=false;
				result[k][d]=-1;
			}
		}
	queue<ii>q;
	q.push(make_pair(x1,y1));
	result[x1][y1]=0;

	while(!q.empty())
	{
		ii red=q.front();
		q.pop();
		int x,y;
		x=red.f;
		y=red.s;
		if(visited[x][y]==true)
				continue;

		visited[x][y]=true;
		REP(i,0,4)
		{
			int newr=x+arr1[i];
			int newc=y+arr2[i];
			if(visited[newr][newc]==false&&newr<R && newr>=0 && newc>=0 &&newc<C)
			{
			if(graph[newr][newc]==0)
			{
				q.push(make_pair(newr,newc));
						result[newr][newc]=result[x][y]+1;
			}
			}	
		}
	}
	return result[x2][y2];
}
int main(int argc, char const *argv[])
{
	// FR;
	// FW;
	while(1)
	{
	int R,C;
	R=IN;
	C=IN;
	if(R==0&&C==0)
			break;
	int RC;
	RC=IN;
	REP(i,0,R)
		REP(k,0,C)
			graph[i][k]=0;

	// printf("%d\n",RC );
	REP(i,0,RC)
	{
		int RV,T,CV;
		RV=IN;
		T=IN;
		REP(k,0,T)
		{
			CV=IN;
			graph[RV][CV] = 1;
		}	
	}
	int x1,y1,x2,y2;
	x1=IN;
	 y1=IN;
	x2=IN; 
	y2=IN;
	// REP(i,0,R)
	// 	{
	// 		REP(j,0,C)
	// 		{
	// 			printf("%d ",graph[i][j] );
	// 		}
	// 		printf("\n");
	// 	}
		printf("%d\n",BFS(x1,y1,x2,y2,R,C));
	}
	return 0;
}

