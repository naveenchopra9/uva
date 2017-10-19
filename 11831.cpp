#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <cstdio>
using namespace std;
int N,M,S;
char a[105][105];
char ins[50005];
int SCR(int u,int v,int direction)
{
		int count=0;
	 int temp1,temp2;
	for (int i = 0; i <S; ++i)
	{
		if(ins[i]=='D')
		{
			if(direction==4)
				direction=1;
			else
				direction=(direction+1)%5;
		}
		else if(ins[i]=='E')
		{
			if(direction-1==0)
				direction=4;
			else
				direction=direction-1;
		}
		else
		{
			temp1=u;
			temp2=v;

			if(direction==1)
					--temp1;
			else if(direction==2)
				++temp2;
			else if(direction==3)
				++temp1;
			else
				--temp2;
			//printf("e-%d %d %d %d %d %c \n",u,v,temp1,temp2,direction,a[temp1][temp2] );
			if(temp2<0||temp1<0||temp1>=N||temp2>=M||a[temp1][temp2]=='#')
			{
				continue;
			}
			else
			{
				//printf("#\n");
			if(a[temp1][temp2]=='*')
					     ++count;
				a[u][v]='.';
				u=temp1;
				v=temp2;
			}
		}
	}
	return count;
}
int main()
{
		// freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(false);
cin.tie(NULL);
while(1){
	cin>>N>>M>>S;
	cin.ignore();
	if(N==0&&M==0&&S==0)
		break;
	for (int i = 0; i < N; ++i)
	{
		cin.getline(a[i],M+1);
	}	

	// for (int i = 0; i < N; ++i)
	// {
	//    cout<<a[i]<<endl;	
	// }
	cin.getline(ins,S+1);
	int temp=1,j,i;
	for ( i = 0; i < N; ++i)
	{
		for( j =0 ; j < M ; j++)
		{
			if(a[i][j]=='N'||a[i][j]=='O'||a[i][j]=='S'||a[i][j]=='L')
			{
				temp=0;
				break;
			}
		}
		if(temp==0)
			break;
	}
	//printf("%d %d \n",i,j );
	 int direction;
	if(a[i][j]=='N')
		direction=1;
	else if(a[i][j]=='O')
		direction=4;
	else if(a[i][j]=='S')
		direction=3;
	else
		direction=2;
	// printf("%d\n",direction );
	// printf("%s\n",ins );
	cout<<SCR(i,j,direction)<<endl;
}
	return 0;
}
