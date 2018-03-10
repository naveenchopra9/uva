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
bool b[18409202+1];
long long value=2000000;
long long arr[2000000][2];
void  findallprime()
{
    b[0]=true;
    b[1]=true;
    for(long long i =2 ; i*i<= 18409202 ; i++)
    {
        if(b[i]==0)
        {
            for(long long j =i*i ; j<=18409202; j+=i)
            {
                b[j]=true;
            }
        }
    }
   long long count=0,pre=3;
    REP(i,0, 18409202)
    if(b[i]==false)
    {
        if(i-pre==2)
        {
        arr[count][0]=pre;
        arr[count][1]=i;
        count++;
        }
        pre=i;
    }
    //cout<<endl<<temp<<" "<<count<<endl;
}
int main()
{
//    FR;
//    FW;
    findallprime();
    long long n;
    while(cin>>n)
    {
            cout<<"("<<arr[n-1][0]<<", "<<arr[n-1][1]<<")"<<endl;
    }
    return 0;
}
