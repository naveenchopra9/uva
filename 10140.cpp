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
typedef long long ll;
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
long long  b[2147483];

void  findallprime(long long R,long long L)
{
    long long  pp=R-L+1;
    REP(i, 0, pp)
    {
        b[i]=1;
    }
    long long count=0;
    for(long long i =2 ; i*i<= R ; i++)
    {
        {
            for(long long j =MAX(i*i,(L+(i-1))/i*i) ; j<=R ; j+=i)
            {
                b[j-L]=0;
                //cout<<j<<" ";
            }
            //cout<<endl;
        }
    }
    long long  arr[1000000];
    for(long long i=MAX(2, L); i<=R ; i++ )
    {
        if(b[i-L])
        {
            arr[count]=i;
            count++;
        }
    }
    long long maxx=0,maxy=0,minx=0,miny=0,minv=MAXV,maxv=MINV;
    REP(i, 0,count-1 )
        {
                if(maxv<MAX(maxv,arr[i+1]-arr[i]))
                {
                    maxv=MAX(maxv,arr[i+1]-arr[i]);
                    maxx=arr[i];
                    maxy=arr[i+1];
                }
               if(minv>MIN(minv,arr[i+1]-arr[i]))
                {
                    minv=MIN(maxv,arr[i+1]-arr[i]);
                    minx=arr[i];
                    miny=arr[i+1];
                }
        }
    if(maxx==0|| maxy==0 || minx==0 || miny== 0)
     cout<<"There are no adjacent primes."<<endl;
    else
        cout<<minx<<","<<miny<<" are closest, "<<maxx<<","<<maxy<<" are most distant."<<endl;
}
int main()
{
//        FR;
//        FW;
    long long R,L;
while(cin>>L>>R)
    {
        findallprime(R,L);
    }
    return 0;
}
