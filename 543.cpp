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
bool b[1000000+1];
int value=78497;
int arr[78500];
void  findallprime()
{
    b[0]=true;
    b[1]=true;
    for(int i =2 ; i*i<= 1000000 ; i++)
    {
        if(b[i]==0)
        {
            for(int j =i*i ; j<=1000000 ; j+=i)
            {
                b[j]=true;
            }
        }
    }
    int count=0;
    REP(i, 0, 1000000)
        if(b[i]==false)
        {
            arr[count]=i;
            count++;
        }
}
int main()
{
     //   FR;
       // FW;
    int n;
    Set(b, false);
     findallprime();
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
    int x=0;
    for(int i =0 ; ; i++)
    {
        x=arr[i];
        if(b[n-x]==false)
        {
           cout<<n<<" = "<<x<<" + "<<n-x<<endl;
            break;
        }
    }
    }
    return 0;
}
