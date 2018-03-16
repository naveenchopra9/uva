#include <cstdio>
#include <cstdlib>
#include <cmath>
#include<iomanip>
#include<fstream>
#include<cctype>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include <limits.h>
#include <map>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;
//const int INF = 0x3f3f3f3f;
#define MAXV 2147483647
#define MINV -2147483647
//typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;
//typedef set<int> si;
typedef map<int, int> msi;
#define f first
#define s second
#define pb push_back
#define p push
#define SIZE 100001;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define IN ({int n; scanf("%d", &n);    n;})
#define CN ({char _char; scanf(" %c",&_char); _char;})
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define FR freopen("/Users/naveen/Desktop/uva/uva/input.txt","r",stdin)
#define FW freopen("/Users/naveen/Desktop/uva/uva/output.txt","w",stdout)
#define NIL -1
#define Set(a, s) memset(a, s, sizeof (a))
long long int   prime[10000000+1];
void factorize(long long int N)
{
    
    Set(prime, 0);
    for(long long int i =2 ; i*i<=N; i++)
    {
        if(prime[i]==0)
        {
            for(long long int j =i*i ; j<=N ; j+=i)
            {
                if(prime[j]==0)
                    prime[j]=i;
            }
        }
    }
    long long int j=0;
    for(long long int  i =2 ; i<=N ; i++)
    {
        if(prime[i]==0)
        {
            prime[j]=i;
            j++;
        }
    }
}
int main()
{
//            FW;
//             FR;
    factorize(10000001);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int x;
while(1)
    {
    cin>>x;
    if(x==0)
        break;
        x=abs(x);
    long long int temp=0;
    long long  int maxv=MINV;
    for(long long int i=0 ; prime[i]*prime[i]<x ; i++)
    {
        while(x%prime[i]==0)
        {
            temp=1;
            maxv=prime[i];
            x=x/prime[i];
        }
    }
    if(temp==0||MAX(maxv,x)==2)
        cout<<"-1"<<endl;
    else
        cout<<MAX(maxv,x)<<endl;
    }
//
    return 0;
}


