#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX=25010;
pair <long long, pair<int, int> > p[MAX];
int vertices,edges;
int id[MAX];
int findset(int x)
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		  x=id[x];
	}
	return x;
}

void union1(int x,int y)
{
	int firstid=findset(x);
	int secondid=findset(y);
	id[firstid]=id[secondid];
}

long long kMST(pair <long long , pair<int,int> > p[])
{
	int x,y;
	long long mcost=0,c;
	int temp=0;
	for (int i = 0; i < edges; ++i)
	{
		//edges selecting one by one in increasing order of weight
		x=p[i].second.first;
		y=p[i].second.second;
		c=p[i].first;
		//check selected edges are in same group /they are creating cycle or not

		if(findset(x)!=findset(y))
		{
			mcost+=c;
			union1(x,y);
		}
		else
		{
			if(temp==0)
				cout<<c;
			else
				cout<<" "<<c;
			temp++;
		}
	}


	return temp;
}
int main()
{

	 // freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(1)
	{
	//intialize all the node 
	for (int i = 0; i < MAX; ++i)
	{
		id[i]=i;
	}
	//input number of edges and number of vertices
	//cout<<"Enter vertices and edges:";
	cin>>vertices>>edges;
	if(vertices==0&&edges==0)
		break;
	int u,v,x,y;
	int count=0;
	long long c,minimumCost,weight;
	//	cout<<"Enter u ,v and weight:"<<endl;
	for (int i = 0; i < edges; ++i)
	{
		cin>>u>>v>>weight;
		p[i]=make_pair(weight,make_pair(u,v));
		count+=weight;
	}
	sort(p,p+edges);

	minimumCost=kMST(p);	
	if(minimumCost==0)
	cout<<"forest"<<endl;
	else
		cout<<endl;
	}
	return 0;
}
