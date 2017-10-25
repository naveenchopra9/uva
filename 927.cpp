#include <iostream>
#include <bits/stdc++.h>
#include<cmath>
#include<cstdio>

using namespace std;
int cofficient[30];
int seq[1000000];
int n;
unsigned long long int ans(int p,int i)
{
	if(i==n)
		return 0;
	return  cofficient[i]*pow(p,i)+ans(p,i+1);
}

int main()
{
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
// 	freopen("input.txt","r",stdin);
// 		freopen("output.txt","w",stdout);
	{
	int sum = 0;
    for(int i = 0;; i++)
     {
        sum = sum + i;
        if(sum >= 1000000) break;
        seq[sum] = i + 1;
    }
	}

	int test;
	cin>>test;
	while(test--)
	{

	cin>>n;	
	for (int i = 0; i <= n; ++i)
	{
		cin>>cofficient[i];
	}
	n++;
	int d,k;
	scanf("%d\n%d", &d, &k);
	int index=(k-1)/d;
	//printf("%d %d \n",seq[index],index );
		while(index>0 && seq[index]==0)
				 index--;
				//index--;
		///	printf("%d %d \n",seq[index],index );
		 printf("%llu\n",ans(seq[index],0) );
	}
}
