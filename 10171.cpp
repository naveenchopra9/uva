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
#define FOR(j,limit) for(int j = 0 ; j < limit ; j++)
#define FR freopen("input.txt","r",stdin)
#define FW freopen("output.txt","w",stdout)
#define f first
#define s second
const int INF = 0x3f3f3f3f;
#define SIZE 100001;

vector< pair < char, pair < int , int> > >vec[100001];
int result[2][27];
void BFS1(int temp,int s,char l)
{
	bool arr[27];
	int arr1[27];
	memset(arr1,INF,sizeof(arr1));
	queue<int>q;
	q.push(s);
	memset(arr,false,sizeof(arr));
	arr[s]=true;
	arr1[s]=0;
	// printf("%d \n",s );
	while(!q.empty())
	{
	int p=q.front();
	q.pop();

	// // vector< pair < char, pair < int , int> > > :: iterator it;

	for(int j = 0 ; j<vec[p].size() ; j++)
	{
		
		if(arr[vec[p][j].s.f]==false&&vec[p][j].f==l)
		{
			// printf("%d \n",vec[p][j].s.f );
			arr[vec[p][j].s.f]=true;

			arr1[vec[p][j].s.f] =arr1[p]+vec[p][j].s.s;

			//printf("%d %d %d  \n",arr1[vec[p][j].s.f],p,arr1[p]+1 );

			//printf("%d %d %d %d\n",vec[p][j].s.f,p,vec[p][j].s.s,arr1[vec[p][j].s.f] );
			q.push(vec[p][j].s.f);
		}
		// printf("%d \n",vec[p][j].s.s );


	}
	// printf("#\n");

	}
	FOR(i,26)
	{
	// printf("%d ",arr1[i] );
	result[temp][i]=arr1[i];
	}
}
int main (int argc, char const *argv[])
 {
 	// FR;
 	// FW;
 	while(1)
 	{
  	int V;
 	int w;
 	char type,edgetype,u,v;
 	V=IN;
 	// printf("#\n");
 	cin.ignore();
 	   if(V==0)
 		break;

 	FOR(i,V)
 	{
 		type=CN;
 		edgetype=CN;
 		u=CN;
 		v=CN;
 		w=IN;
 		// printf("\n%c %c %c %c %d \n",type,edgetype,u,v,w);
 		vec[u-'A'].push_back(make_pair(type,make_pair(v-'A',w)));
 		if(edgetype=='B')
 			vec[v-'A'].push_back(make_pair(type,make_pair(u-'A',w)));
 	}
	 	// FOR(i,V)
	 	// {
	 	// 	 FOR(j,vec[i].size())
	 	// 	// if(vec[i].size()!=0)
	 	// 	// printf("%d %c %d %d\n",i,vec[i][j].f,vec[i][j].s.f,vec[i][j].s.s );
	 	// }
 	char s,d;
 	s=CN;
 	d=CN;
	 	 BFS1(0,s-'A','Y');
	 	 BFS1(1,d-'A','M');
	 	 vector<char>vi;
	 	 int minsum=INF;
	 	 FOR(i,26)
	 	 {
	 	 	// printf("%d %d\n",result[0][i],result[1][i] );
	 	 	if(result[0][i]!=INF&&result[1][i]!=INF)
	 	 	{
	 	 		minsum=min(minsum,result[0][i]+result[1][i]);
	 	 	}
	 	 }
	 	 FOR(i,26)
	 	 {
	 	 	if(result[0][i]!=INF&&result[1][i]!=INF&&minsum==result[0][i]+result[1][i])
	 	 	{
	 	 		vi.push_back(i+65);
	  	 	}
	 	 }
	 	 if(minsum==INF)
	 	 	printf("You will never meet.\n");
	 	 else
	 	 {
	 	 	printf("%d",minsum );
	 	 	vector<char> :: iterator it;
	 	 	for(it=vi.begin() ; it!=vi.end(); it++)
	 	 		printf(" %c",*it );
	 	 	printf("\n");
	 	 }
	 	 for (int i = 0; i < 27; ++i)
	 	 {
	 	 	result[0][i]=INF;
	 	 	result[1][i]=INF;
	 	 }
	 	 FOR(i,100001)
 	   		vec[i].clear();

 	}
  	return 0;
 }
