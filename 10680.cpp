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
int   prime[1000000+1];
vector<pair <int,int> >vec;
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
}
void factorize(int N)
{
    vec.clear();
    for(int i =2 ; i<=N ; i++)
    {
        if(prime[i]==0)
        {
            int res = log(N)/log(i);
             vec.push_back(make_pair(i,res));
        }
    }
    int arr[10][4];
    arr[1][0]=2;arr[1][1]=4;arr[1][2]=8;arr[1][3]=6;
    arr[2][0]=3;arr[2][1]=9;arr[2][2]=7;arr[2][3]=1;
    arr[3][0]=7;arr[3][1]=9;arr[3][2]=3;arr[3][3]=1;
    arr[4][0]=9;arr[4][1]=1;
    int result=1;
    for(int i =1 ; i<vec.size() ; i++)
    {
        if(vec[i].f!=5)
        {
        int temp=vec[i].f%10;
        if(temp==1)
        {
            result=result*1;
        }
        else if(temp==3)
        {
            int ren=(vec[i].s-1)%4;
            result=result*arr[2][ren];
        }
        else if(temp==7)
        {
            int ren=(vec[i].s-1)%4;
            result=result*arr[3][ren];
        }
        else if(temp==9)
        {
            int ren=(vec[i].s-1)%2;
            result=result*arr[4][ren];
        }
        result=result%10;
        }
    }
    //for two and five for reminder
    int twofive=abs(vec[0].s-vec[2].s);
    if(vec[0].s>vec[2].s)
    {
        int ren=(twofive-1)%4;
        result=result*arr[1][ren];
    }
    else
    {
        result=result*5;
    }
    result=result%10;
    if(N==1)
        cout<<"1"<<endl;
    else
        cout<<result<<endl;
}

int main()
{
//    FR;
//    FW;
    initialize(1000000);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    while(cin>>N)
    {
        if(N==0)
            break;
    factorize(N);
    }
}
