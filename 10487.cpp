#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long int a[1005];
				freopen("input.txt","r",stdin);
				freopen("output.txt","w",stdout);
		int temp=0;
	while(1)
	{
	int n;
	cin>>n;
	if(n==0)
		break;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &a[i]);
	}
	int k,j;
	long long int value;
	int test;
	cin>>test;
	printf("Case %d:\n",temp+1 );
	temp++;
	while(test--)
	{
	scanf("%lld\n",&value );
	long long int sum=99999999;
	long long int ans=a[0]+a[1];
	for( j = 0 ; j < n ; j++)
	{
		for( k =j+1 ; k < n ; k++)
		{
			if(abs(value-(a[j]+a[k]))<sum)
				{
					sum=abs(value-(a[j]+a[k]));
					ans=a[j]+a[k];
				}
		}
	}
	printf("Closest sum to %lld is %lld.\n",value,ans);
	}
	}
	return 0;
}
