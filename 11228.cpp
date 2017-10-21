#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX=999999;
pair <double, pair<int, int> > p[MAX];

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


void kMST(pair <double , pair<int,int> > p[],int r,int k)
{
	int x,y;
	double roadcost=0,railcost=0,c;
	int count=0;
	for (int i = 0; i < edges; ++i)
	{
		//edges selecting one by one in increasing order of weight
		x=p[i].second.first;
		y=p[i].second.second;
		c=p[i].first;
		//check selected edges are in same group /they are creating cycle or not
		
		if(findset(x)!=findset(y))
		{
			if(c<=r)
			{
			roadcost+=c;
			count++;
			}
			else
			{
				railcost+=c;
			}
			union1(x,y);
		}
	}
		printf("Case #%d: %d %.0f %.0f\n",k,vertices-count,roadcost ,railcost);
}
int main()
{
	// freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
   for(int k =1 ; k<=t ; k++)
   {
	//intialize all the node 
	for (int i = 0; i < MAX; ++i)
	{
		id[i]=i;
	}


	double dis[1005][2];
	//input number of edges and number of vertices

	int r;

	cin>>vertices>>r;

	int u,v,x,y;

	double c,minimumCost,weight;

	for (int i = 0; i < vertices; ++i)
	{
		cin>>dis[i][0]>>dis[i][1];
	}
	int temp=0;
	for (int i = 0; i < vertices; ++i)
	{
		for(int j = i+1 ; j <vertices ; j++)
		{
			weight=sqrt(pow(dis[i][0]-dis[j][0],2)+pow(dis[i][1]-dis[j][1],2));
			p[temp]=make_pair(weight,make_pair(i,j));
			++temp;
		}
	}
	edges=temp;
	sort(p,p+edges);
	// for (int i = 0; i < edges; ++i)
	// {
	// 			printf("%f %d %d \n",p[i].first,p[i].second.first,p[i].second.second );
	// }

	kMST(p,r,k);	
	
	}
}
