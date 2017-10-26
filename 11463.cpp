	#include <cstdio>
	#include <cstdlib>
	#include <cctype>
	#include <cmath>
	#include <algorithm>
	#include <queue>
	#include <iostream>
	#include <string>
	#include <cstring>
using namespace std;
#define IN ({int n; scanf("%d", &n);	n;})
// #define IN ({int _T; scanf("%d", &_T); _T;})
#define FOR(j,limit) for(int j = 0 ; j < limit ; j++)
#define FR freopen("input.txt","r",stdin)
#define FW freopen("output.txt","w",stdout)
const int INF = 0x3f3f3f3f;
int L1[1000][1000];
void slow_all_pairs_shortest_path(int p,int W[][101],int N,int S,int D)
{
	int MAX=0;
	FOR(i,N)
	{
		FOR(j,N)
		{
			L1[i][j]=W[i][j];
		}
	}

		FOR(k,N)
		{
			FOR(i,N)
			{
				FOR(j,N)
				{
					L1[i][j]=min(L1[i][j],L1[i][k]+L1[k][j]);
				}
			}
		}

		FOR(k,N)
		{
			if(L1[S][k]!=INF&&L1[k][D]!=INF)
			MAX=max(MAX,L1[S][k]+L1[k][D]);	
		}	
	printf("Case %d: %d\n",p+1,MAX );

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// FR;
	// FW;
	int T;
	T=IN;
	FOR(p,T)
	{
	int N,E;
	N=	IN;
	E=IN;
	int a,b,w;
	int W[101][101];

	FOR(i,N)
	{
		FOR(j,N)
		{
			W[i][j]=INF;
		}
	}

	FOR(i,N+1)
	{
		W[i][i]=0;
	}

	FOR(i,E)
	{
			a=	IN;	
			b=	IN;
			W[a][b]=1;			
			W[b][a]=1;
	}

	int s,d;
	s=IN;
	d=IN;

	slow_all_pairs_shortest_path(p,W,N,s,d);
	}
	return 0;
}
