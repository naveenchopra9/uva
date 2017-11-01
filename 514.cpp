#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define IN ({int n; scanf("%d", &n);	n;})
#define CN ({char _char; scanf(" %c",&_char); _char;})
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define FR freopen("input.txt","r",stdin)
#define FW freopen("output.txt","w",stdout)
#define f first
#define s second
#define p push
#define pb push_back	
#define sz size()
const int INF = 0x3f3f3f3f;
#define MAX 2147483647
#define MIN -2147483647	
#define Set(a, s) memset(a, s, sizeof (a))

int main(int argc, char const *argv[])
{
	FR;
	FW;
	int arr[1000+2];
	int n;
	while(cin>>n&&n!=0)
	{

		// printf("%d\n",n );
	while(true)
	{
		arr[0]=IN;
		if(arr[0]==0)
			break;
		for (int i = 1; i < n; ++i)
		{
			arr[i]=IN;
		}

		stack<int> s;

		int curr=1;
		int target_index=0;
		while(curr<=n)
		{
			s.push(curr);
			// printf("%d %d \n",s.top(),arr[target_index] );
			while(!s.empty()&&s.top()==arr[target_index])
			{
				s.pop();
				target_index++;
				if(target_index>=n)
					break;
			}
			curr++;
		}
		if(s.empty())
			printf("Yes\n");
		else
			printf("No\n");
	}
	printf("\n");
	}
	return 0;
}
