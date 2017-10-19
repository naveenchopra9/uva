#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;
vector< int >adj[2002];
int level[2002];
bool visited[2002];

void findedge(int u,int v,char* name1,char* name2,int l1,int l2)
{
	int temp=0;
	if(l1!=l2)
		return;
	else
	{
		for (int i = 0; i < l1; ++i)
		{
			if(name1[i]!=name2[i])
				++temp;
		}
		if(temp==1)
			 {
			 	adj[u].push_back(v);
			 }
	}
}

int BFS(int s,int v,int temp)
{
	queue<int> q;
	memset(level,0,sizeof(level));
	memset(visited,false,sizeof(visited));
	level[s]=0;
	visited[s]=true;
	q.push(s);
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		if(p==v)
			return level[p];
		for (int i = 0; i < adj[p].size(); ++i)
		{
			if(visited[adj[p][i]]==false)
			{
				level[adj[p][i]]=level[p]+1;
				visited[adj[p][i]]=true;
				q.push(adj[p][i]);
			}
		}
	}
}


int main()
{
	int t;
	int count=0;
	cin>>t;
	getchar();
	getchar();
	while(t--)
	{
		  if(count>0)
	      cout<<endl;
	char name[2002][202];
	
	int temp=0;
	for (int  i = 0; ; ++i)
	{
		scanf(" %s",name[i]);
		if(name[i][0]=='*')
			break;
		++temp;
	}
	for (int i = 0; i <temp; ++i)
	{
		adj[i].clear();
		for (int j = 0; j < temp; ++j)
		{
			findedge(i,j,name[i],name[j],strlen(name[i]),strlen(name[j]));
		}
	}
	// for (int i = 0; i < temp; ++i)
	// {
	// 	for(int j =0 ; j < adj[i].size(); j++)
	// 	{
	// 		cout<<adj[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

		char str1[11];
		char str2[11];
		string s1,s2;
        string line;
        getline(cin,line);
        getline(cin,line);
        while(line !="")
        {
            int pos=0;
            pos=line.find(" ");
            s1=line.substr(0,pos);

            int i;
            for ( i = 0; i < pos; ++i)
            {
            	str1[i]=line[i];
            }
            str1[i]=0;
            s2=line.substr(pos+1,line.size());
            int l=line.size();
            // printf("%d %d \n",pos+1,l);
            for ( i =pos+1; i <line.size(); ++i)
            {
            	str2[i-(pos+1)]=line[i];
            }
            str2[i-(pos+1)]=0;
			int input1=0;
			int input2=0;
			for (int i = 0; i <temp; ++i)
			{
				if(strcmp(name[i],str1)==0)
						input1=i;
				if(strcmp(name[i],str2)==0)
						input2=i;
			}
           cout<<s1<<" "<<s2<<" "<<BFS(input1,input2,temp)<<endl;
           //  temp1=9999999;
            if(!getline(cin,line))
            break;
        }
       count++;
	}
	return 0;
}

