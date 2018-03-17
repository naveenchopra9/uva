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
int   prime[50000+1];
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

int main()
{
//    FR;
//    FW;
    initialize(50000);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A,C;
    int T;
    cin>>T;
    REP(i,0,T)
    {
        cin>>A>>C;
        int maxv=MINV;
        int maxInt=MINV;
        REP(j, A, C+1)
        {
            int pp=j;
            int res=1;
            for(int k = 0 ; prime[k]*prime[k]<=pp ; k++)
            {
                int count=0;
                while (pp%prime[k]==0)
                {
                    pp/=prime[k];
                    count++;
                }
                res*=(count+1);
            }
            if(pp>1)
                res*=2;
            if(maxv<res)
            {
                maxv=res;
                maxInt=j;
            }
        }
        cout<<"Between "<<A<<" and "<<C<<", "<<maxInt<<" has a maximum of "<<maxv<<" divisors."<<endl;
//         cout<<maxv<<" "<<maxInt<<endl;
    }
}
