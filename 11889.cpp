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
int   prime[10000000+2];
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
int power(int B,int n)
{
    int res=1;
    for(int i=0 ; i< n ; i++)
        res*=B;
    return res;
}
void LCM(int A,int C)
{
    int temp=C;
    vector< pair<int ,int> >result;
    for(int i=0 ; prime[i]*prime[i]<=C ; i++ )
    {
        int count=0;
        while(C%prime[i]==0)
        {
            C/=prime[i];
            count++;
        }
        if(count!=0)
            result.push_back(make_pair(prime[i],count));
    }
    if(C>1)
        result.push_back(make_pair(C,1));
//    REP(i, 0, sz(result))
//       cout<<result[i].f<<" "<<result[i].s<<endl;
    REP(i, 0, sz(result))
   {
       if(A%power(result[i].f,result[i].s)==0)
       {
           temp=temp/power(result[i].f,result[i].s);
       }
   }
    cout<<temp<<endl;
}
int main()
{
//    FR;
//    FW;
    initialize(10000000);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A,C;
    int T;
    cin>>T;
    REP(i,0,T)
    {
        cin>>A>>C;
        if(C%A==0)
            LCM(A,C);
        else
            cout<<"NO SOLUTION"<<endl;
    }
}
