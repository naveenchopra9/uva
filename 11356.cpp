#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int left1[100005];
int right1[100005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	while(1)
	{
	int S,B;
	scanf("%d %d",&S,&B);
		for (int i = 1; i <=S; ++i)
	  {
	  	left1[i]= i-1;
	  	right1[i]= i+1;
	  }
	if(S==0&&B==0)
		break;
	int L,R;
	for (int i = 0; i < B; ++i)
	{
		scanf("%d %d",&L,&R);
		if(left1[L]<=0)
		{
			printf("* ");
		}
		else
			printf("%d ",left1[L] );
		if(right1[R]>S)
			printf("*\n");
		else
			printf("%d\n",right1[R] );
		left1[right1[R]]=left1[L];
		right1[left1[L]]=right1[R];

	}
	printf("-\n");
	}
	return 0;
}
