#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include <vector>
#include <cstring>
#include <map>
#include <utility>
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
typedef pair<string,int>psi;
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
msi map_list;

void topological(int v,int indegree[],vi &res,bool visit[])
{
	REP(i,0,v)
	{
		if(indegree[i]==0 && !visit[i])
		{
			res.pb(i);
			// printf("%d ",i );
			visit[i]=true;
			vi :: iterator it;
			for(it=adj[i].begin() ; it!=adj[i].end() ; it++)
			{
				indegree[*it]--;
			}

			topological(v,indegree,res,visit);
		}
	}
}
int main(int argc, char const *argv[])
{
	// FR;
	// FW;
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int V;
	int temp=1;
	while(cin>>V)
	{
	string str[V];
	string s;
	REP(i,0,105)
		adj[i].clear();
	REP(i,0,V)
		{
			cin>>s;
			str[i]=s;
			map_list.insert(psi(s,i));
		}
	string BB;
	int E;
	E=IN;
	int indegree[V];
	bool visit[V];
	Set(visit,false);
	Set(indegree,0);
	getchar();	
	REP(j,0,E)
	{
	getline(cin,BB);
	int  pos = BB.find(" ");
	string str1 = BB.substr(0,pos);   
	string str2	= BB.substr(pos+1,BB.length()); 
	adj[map_list[str1]].pb(map_list[str2]);
	indegree[map_list[str2]]++;
	}

	vi res;
	topological(V,indegree,res,visit);
	cout<<"Case #"<<temp<<": Dilbert should drink beverages in this order:";
	REP(i,0,res.size())
		 cout<<" "<<str[res[i]];
		 cout<<"."<<endl<<endl;
		string rend1,rend2;
		getline(cin,rend1);
		// getline(cin,rend2);
		// if(rend1==""&&rend2=="")
		// 	break;
		temp++;
		map_list.clear();
	}
 	return 0;
}
