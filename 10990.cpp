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
int prime[6000+1];
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

vector<pair< int,int > >vec;

void numofprimes(int n)
{
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
            vec.push_back(make_pair(prime[i], temp1));
        
    }
    if(temp>1)
        vec.push_back(make_pair(temp, 1));
}

int power(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2==0)
        return power(x*x,n/2);
    else
        return x*power(x*x, (n-1)/2);
}
int phi[2000000+1][2];
//vector <pair < int,int > >phi;
void initeuler(int n)
{
    phi[1][0]=1;
    phi[1][1]=0;
    phi[2][0]=1;
    phi[2][1]=1;
    REP(j, 3, n+1)
    {
        vec.clear();
        numofprimes(j);
        int res=1;
        REP(i, 0, sz(vec))
        {
            res*=power(vec[i].f,vec[i].s-1)*(vec[i].f-1);
        }
        phi[j][0]=res;
        phi[j][1]=phi[res][1]+1;
//        cout<<j<<" "<<res<<endl;
//        phi.push_back(res);
    }
//    cout<<endl;
//    REP(i, 0, 11)
//    {
//        cout<<phi[i][0]<<" "<<phi[i][1]<<endl;
//    }
}

int main()
{
//        FR;
//        FW;
    initialize(6000);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    initeuler(2000000);
    int n,m;
    int T;
    cin>>T;
    REP(ss, 0, T)
    {
        cin>>n>>m;
    
        long long res=0;
        REP(i,n,m+1)
        {
//            cout<<n<<" "<<m<<endl;

                    res+=phi[i][1];
//            cout<<"re :"<<i<<" "<<res<<endl;
        }
        cout<<res<<endl;
    }
}
