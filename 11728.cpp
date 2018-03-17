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
int   prime[50+1];
void initialize(int N)
{
    Set(prime, 0);
    for(int i =2 ; i*i<=N; i++)
    {
        if(prime[i]==0)
        {
            
            for(int j =i*i ; j<=N ; j+=i)
            {
                if(prime[j]==0)
                    prime[j]=i;
            }
        }
    }
    int i=0;
    for(int j =2 ; j <=N ; j++)
    {
        if(prime[j]==0)
           {
               prime[i]=j;
               i++;
           }
    }
}
int power(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return power(x*x,n/2);
    else
        return x*power(x*x,(n-1)/2);
}
vector<pair< int,int > >primes;
void numofprimes(int n)
{
    primes.clear();
    int temp=n;
    for(int i =0 ; prime[i]*prime[i]<= temp ;i++)
    {
        int temp1=0;
        while(temp%prime[i]==0)
        {
            temp/=prime[i];
            temp1++;
        }
        if(temp1!=0)
            primes.push_back(make_pair(prime[i], temp1));
    }
    if(temp>1)
        primes.push_back(make_pair(temp,1));
}

void result(int n)
{
    int maxv=MINV,res,factorsum=-1;
    for(int pp= 1 ; pp <= n ; pp++)
    {
//        cout<<pp<<endl;
        numofprimes(pp);
         res=1;
        REP(i, 0, sz(primes))
        {
            res*=(power(primes[i].f, primes[i].s+1)-1)/(primes[i].f-1);
//            cout<<primes[i].f<<" "<<primes[i].s<<" ";
        }
//        cout<<endl<<"res"<<res<<endl;
        if(res==n)
        {
                factorsum=MAX(maxv,pp);
        }
    }
    if(factorsum==-1)
        cout<<factorsum<<endl;
    else
        cout<<factorsum<<endl;
}
int main()
{
//    FR;
//    FW;
    initialize(50);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int temp=1;
    while(cin>>n)
    {
    if(n==0)
        break;
        cout<<"Case "<<temp<<": ";
    result(n);
        temp++;
    }
}
