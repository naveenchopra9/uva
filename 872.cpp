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
vector < int >adj[27];
int temp=0;
void topological(int v,vi indegree,vi res,bool visit[])
{
	bool f = false;
	REP(i,0,v)
	{
		if(indegree[i]==0 && !visit[i])
		{
			res.pb(i);
			visit[i]=true;
			vi :: iterator it;
			for(it=adj[i].begin() ; it!=adj[i].end() ; it++)
			{
				indegree[*it]--;
			}

			topological(v,indegree,res,visit);

			visit[i]=false;
			res.erase(res.end() - 1);
			for(it=adj[i].begin() ; it!=adj[i].end() ; it++)
			{
				indegree[*it]++;
			}
			f=true;
		}
	}
	if(!f)
	{
		REP(i,0,res.size())
		{
			temp=1;
			if(i==0)
				printf("%c",res[i]+'A');
			else
				printf(" %c",res[i]+'A');
		if(i==res.size()-1)
			 printf("\n");
		}
	}
}	
int main(int argc, char const *argv[])
{
	// FR;
	// FW;
	int t;
	 cin>>t;
	 cin.ignore();
	 REP(k,0,t)
	{
	vi indegree(26,-1);
		bool visit[26];
	memset(visit,false,sizeof(visit));
	REP(l,0,27)
		adj[l].clear();
	string s,p;
	vi vec(26,-1);
	getline(cin,p);
	getline(cin,s);
	// cout<<s<<endl;
	REP(i,0,s.length())
	{
		if(s[i]!='0')
		{
			vec[s[i]-'A']=1;
		}
	}	
	string pop;
	getline(cin,pop);
	REP(i,0,pop.length()-1)
	{
		if(pop[i]=='<')
		{
			adj[pop[i-1]-'A'].pb((pop[i+1]-'A'));
			if(indegree[pop[i+1]-'A']==-1)
				indegree[pop[i+1]-'A']++;
				indegree[pop[i+1]-'A']++;
		}
	}
		REP(i,0,26)
		{
			if(indegree[i]<0&&vec[i]==1)
				indegree[i]=0;
		}	
	vi res;
	// REP(i,0,26)
	// printf("%d ",indegree[i] );
	topological(26,indegree,res,visit);
	if(temp==0)
	{
		if(k==t-1)
			printf("NO\n");
		else
		printf("NO\n\n");
	}
	if(temp!=0&&k!=t-1)
		printf("\n");
	temp=0;
	}
	return 0;
}
