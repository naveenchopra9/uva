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
    int n,m;
    int t=0;
    while(1)
    {
        t++;
        n=IN; m =IN;
        if(n==0&&m==0)
            break;
        if((n!=0&&m!=0)&&t!=1)
                printf("\n");
    char a[101][101],b[101][101];
    REP(i, 0, n)
    {
        scanf("%s",a[i]);
    }
    
    REP(i,0,n)
    {
        REP(j,0,m)
        {
            int temp=0;
            if(i-1>=0&&j>=0&&a[i-1][j]=='*')
            {
                temp++;
            }
            if(i-1>=0&&j-1>=0&&a[i-1][j-1]=='*')
            {
                temp++;
            }
            if(i-1>=0&&j+1<=m-1&&a[i-1][j+1]=='*')
            {
                temp++;
            }
            if(i>=0&&j+1<=m-1&&a[i][j+1]=='*')
            {
                temp++;
            }
            if(i+1<=n-1&&j+1<=m-1&&a[i+1][j+1]=='*')
            {
                temp++;
            }
            if(i+1<=n-1&&j>=0&&a[i+1][j]=='*')
            {
                temp++;
            }
            if(i+1<=n-1&&j-1>=0&&a[i+1][j-1]=='*')
            {
                temp++;
            }
            if(i>=0&&j-1>=0&&a[i][j-1]=='*')
            {
                temp++;
            }
            if(a[i][j]!='*')
            {
                b[i][j]=temp+'0';
            }
            else
                b[i][j]='*';
            //cout<<temp<<endl;
                
        }
    }
        printf("Field #%d:\n",t);
    REP(i,0,n)
    {
        REP(j,0,m)
        {
            printf("%c",b[i][j]);
            
        }
        printf("\n");
    }
        //printf("\n");
}
	    return 0;
}
