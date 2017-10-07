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
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	
		int n,b,h,w;
	while(scanf("%d %d %d %d",&n,&b,&h,&w) != EOF)
	{
	int a[h];
	int arr[h][w];
	int sum=500005;
	for (int i = 0; i < h; ++i)
	{
		cin>>a[i];
		for (int j = 0; j < w; ++j)
		{
			cin>>arr[i][j];
			if(n<=arr[i][j])
			{
				int pe=n*a[i];
				if(pe<=b&&pe<sum)
				{
					sum=pe;
				}
			}
		}
	}

	if(sum<=b)
		cout<<sum<<endl;
	else
		cout<<"stay home"<<endl;
    }
	return 0;
}