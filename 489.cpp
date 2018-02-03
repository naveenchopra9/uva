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

int main()
{
//    FR;
//    FW;
    int n;
    while(1)
    {
    n=IN;
        
        if(n==-1)break;
    string real;
    cin>>real;
    string gs;
    cin>>gs;
    //cout<<real<<gs;
    int a[256],b[256];
    Set(a, 0);Set(b, 0);
    REP(i,0,sz(real))a[real[i]]++;
    int temp=0,temp1=0,templose=0;
    REP(i, 0, 256)
    {
        if(a[i]>0)
            temp1++;
    }
    REP(i, 0,sz(gs) ){
        if(a[gs[i]]>0)
        {
            temp++;
            a[gs[i]]=0;
            b[gs[i]]=1;
        }
        if(b[gs[i]]==0)
        {
            templose++;
            b[gs[i]]=1;
        }
        if(templose>=7)
            break;
    }
      //  cout<<templose<<" "<<temp<<" "<<temp1<<endl;
    printf("Round %d\n",n );
    if(temp==temp1)
        cout<<"You win."<<endl;
    else if(templose==7)
        cout<<"You lose."<<endl;
    else 
        cout<<"You chickened out."<<endl;
    }
    return 0;
}





