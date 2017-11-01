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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
//global arrays 
typedef vector<ii> vii;
typedef set<int> si;
#define NIL -1
typedef map<string, int> msi;
#define SIZE 100001;
#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int main(int argc, char const *argv[])
{
	FR;FW;
	int t;
	//map define
	msi countmap;
	cin>>t;
	int x=1;
	cin.ignore();
	string str,temp;
	getline(cin,temp);
	REP(i,0,t)
	{
		countmap.clear();
		int count_pop=0;
	while(getline(cin,str)&&str!="")
	{

		// cout<<str<<endl;
		countmap[str]++;
		count_pop++;
	}
	TRmsi(countmap,it)
	{
		cout<<it->first<<" "<<fixed<<setprecision(4)<<((it->second)*100.00)/count_pop<<endl;
	}
		if(t!=x)
		{
		printf("\n");
		}	
		x++;
	}
	return 0;
}
