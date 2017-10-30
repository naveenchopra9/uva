//Two condition most be hold for articulation bridge in graph
//  root vertex with two independent children in graph
// visited timevalue <=low timevalue of adj vertex	
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
typedef map<int, int> msi;
#define SIZE 100001;
#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define NIL -1
#define Set(a, s) memset(a, s, sizeof (a))

//global arrays 
vi adj[1000+3];
bool visited[1000+3];
int parent[1000+3];
int low[1000+3];
int disc[1000+3];	
int timevalue;
vector <ii>rend;
//To find the articulation bridge in graph
 void DFS(int V,int vertex)
 {
 	visited[vertex]=true;
 	
 	disc[vertex]=low[vertex]=timevalue;

 	timevalue=timevalue+1;

 	TRvi(adj[vertex],it)
 	{

 			if(visited[*it]==false)
 			{
 				parent[*it]=vertex;
 				DFS(V,*it);

 				 low[vertex]=min(low[vertex],low[*it]);

	 			if(low[*it]>disc[vertex])
	 			{
	 				// printf("*it%d %d \n",vertex,*it );
		 				if(*it>vertex)
		 					rend.pb(make_pair(vertex,*it));
		 				else
		 				rend.pb(make_pair(*it,vertex));
	 			}
 			}
 			else if(parent[vertex]!=*it)
 					 low[vertex]=min(low[vertex],disc[*it]);
 	} 
 		
 }


void ACPOINT(int V)
{
	

	REP(i,0,V)
	{
		parent[i]=-1;
		visited[i]=false;
		low[i]=0;
		disc[i]=0;
	}
	REP(i,0,V)
	 	if(visited[i]==false)
	 	{
				DFS(V,i);
	 	}
}
void reset()
{
	REP(i,0,1003)
		adj[i].clear();
	rend.clear();
	timevalue=0;
}
int main(int argc, char const *argv[])
{
	// FR;
	// FW;
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	//input vertex and edge



	int V;
	while(scanf("%d",&V)==1)
	{ 
	// printf("#%d \n",V);
	cin.ignore();
	string str;
	int f,t,u,v;
	reset();

	REP(i,0,V)
	        {
	        	getline(cin,str);
	            size_t pos3=str.find(" ");
	       
	            string s3=str.substr(0,pos3);
	              istringstream ss3(s3);
	           			 ss3>>u;
	           			 // cout<<"u-"<<u<<endl;
	            int len=str.length();
				size_t pos1=str.find(")");
				size_t pos2=str.find("(");
				string s1,s2;
				s1=str.substr(pos1+1);
				s2=str.substr(pos2+1,pos1-3);
				// printf("%s\n", );("\n");
				istringstream ss(s2);
				ss>>t;
				// cout<<"server"<<t<<endl;
				istringstream ss2(s1);
				while(ss2>>v)
				{
					// cout<<"server"<<v<<" ";
					adj[u].pb(v);
					adj[v].pb(u);
				}
				// printf("\n");

	        }
	        // REP(i,0,V)
	        // 	{
	        // 		REP(j,0,adj[i].size())
	        // 			printf("%d ",adj[i][j] );
	        // 			printf("\n");
	        // 	}

	ACPOINT(V);
	// printf("\n");
	sort(rend.begin(),rend.end());
	cout<<rend.size();
	printf(" critical links\n" );
	REP(i,0,rend.size())
	{
		printf("%d - %d\n",rend[i].first,rend[i].second );
	}
	string temp1,temp2;
	printf("\n");
	getline(cin,temp1);
	}
	return 0;
}
