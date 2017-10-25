#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	
	int n;
	while(cin>>n)
	{
	int x,y;
	int arr[10001][2];
	int temp=0;
		for(int k =n+1 ; k<=2*n; k++)
		{
			 int x=(k*n)/(k-n);
				if((k*n)%(k-n)==0)
				{
					arr[temp][0]=k;
					arr[temp][1]=x;
					temp++;
				}
		}	
		printf("%d\n",temp );
		for (int i = 0; i < temp; ++i)
		{
			printf("1/%d = 1/%d + 1/%d\n",n,arr[i][1],arr[i][0]);
		}
	}
	return 0;
}
