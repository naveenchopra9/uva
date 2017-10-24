#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAX=1001;
int mat[101][101];
int l1[101][101];
int l2[101][101];
void extend_path(int maxvalue)
{
for (int i = 0; i < maxvalue; ++i)
 {
 	for (int j = 0; j < maxvalue; ++j)
 	{
 		l2[i][j]=MAX;
 		for (int k = 0; k < maxvalue; ++k)
 		{
 			l2[i][j]=min(l2[i][j],l1[i][k]+l1[k][j]);
 		}	
 	}
 }
 for (int i = 0; i < maxvalue; ++i)
 {
 	for (int j = 0; j < maxvalue; ++j)
 	{
 		l1[i][j]=l2[i][j];
 	}
 }

}
void sortedpath(int maxvalue,int test)
{
	for (int i = 0; i < maxvalue; ++i)
	{
		for(int j =0 ; j<maxvalue ;j++)
		{
			l1[i][j]=mat[i][j];
		}
	}
	int m=1;
	while(m<maxvalue-1)
	{
		extend_path(maxvalue);
		m=2*m;
	}

	double  sum1=0;
	int sum2=0;
	for (int i = 0; i < maxvalue; ++i)
 {
 	for (int j = 0; j < maxvalue; ++j)
 	{
 		if(l2[i][j]!=MAX&&l2[i][j]!=0)
 		{
 			sum2++;
 			sum1+=l2[i][j];
 		}

 	}
 }	
 	printf("Case %d: average length between pages = %.3lf clicks\n",test,sum1/sum2 );
}
int main(int argc, char const *argv[])
{
	// freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	int test=1;
	int t=0;
	int x,y;
	cin>>x>>y;
	while(1)
	{
		for (int i = 0; i < 101; ++i)
		{
			for (int j = 0; j < 101; j++)
			{
				mat[i][j]=MAX;

			}
			mat[i][i]=0;
		}
	int maxvalue=-1;
	while(1)
	{
	if(x==0&&y==0)
		{			
			break;
		}
		else
		{
			mat[x-1][y-1]=1;
		}
		if(maxvalue<x)
				maxvalue=x;
		if(maxvalue<y)
				maxvalue=y;
			cin>>x>>y;
	}
	sortedpath(maxvalue,test);
		cin>>x>>y;
		if(x==0&&y==0)
			break;
		 test++;
	}
	return 0;
}
