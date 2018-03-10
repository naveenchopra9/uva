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
long long GCD(long long  a,long long   b)
{
    if(b==0)
        return a;
    else
        return  GCD(b, a%b);
}
long long arr[10000001];
void cdf(long long N)
{
    long long count=0,countN=0;
    for(long long j=1 ; j<=sqrt(N) ; j++)
    {
        if(N%j==0)
        {
            arr[count]=j;
            long long d=N/j;
            if(d!=j)
            {
                 count++;
                 arr[count]=d;
            }
            count++;
            }
    }
    for(long long i =0 ; i< count ; i++)
    {
        for(long long j =i ; j< count ; j++)
        {
            if(N==(arr[i])/GCD(arr[i], arr[j])*arr[j])
            {
                countN++;
               // cout<<arr[i]<<arr[j]<<endl;
            }
        }
    }
    cout<<N<<" "<<countN<<endl;
}
int main()
{
    long long N;
    while(cin>>N)
    {
        if(N==0)
            break;
        cdf(N);
    }
    return 0;
}

