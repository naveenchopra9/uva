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
int   prime[6000+1];
int prime1[1000001];
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
                {
                    prime[j]=i;
                }
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
int numofprimes(int n)
{
    int countfac=0;
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
            countfac++;
        if(temp1>=2)
        {
            return 0;
        }
    }
    if(temp>1)
        countfac++;
    if(countfac%2==0)
        return 1;
    else
        return -1;
}
void result(int n)
{

    cout<<numofprimes(n)<<endl;
}
vector<pair< int,int > >vec;
void initialize1(int N)
{
    Set(prime1, -1);
    prime1[1]=1;
    for(int i =2 ; i*i<=N; i++)
    {
        if(prime1[i]==-1)
        {

            for(int j =i*i ; j<=N ; j+=i)
            {
                if(prime1[j]==-1)
                {
                    prime1[j]=numofprimes(j);
                    
                    
                }
            }
        }
    }
    int temp=0;
    for(int j =1 ; j <=N ; j++)
    {
        temp+=prime1[j];
        vec.push_back(make_pair(prime1[j], temp));
    }
}
string convert(int a)
{
    stringstream ss;
    ss << a;
    string str = ss.str();
    return str;
}
int main()
{
//    FR;
//    FW;
    initialize(6000);
     initialize1(1000000);
//    REP(j, 0, 20)
//        cout<<vec[j].f<<" "<<vec[j].s<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n)
    {
    if(n==0)
        break;
        REP(i, 0, 8-sz(convert(n)))
        cout<<" ";
        cout<<n;
        REP(i, 0, 8-sz(convert(vec[n-1].f)))
        cout<<" ";
        cout<<vec[n-1].f;
        REP(i, 0, 8-sz(convert(vec[n-1].s)))
        cout<<" ";
        cout<<vec[n-1].s;
        cout<<endl;
    }
}
