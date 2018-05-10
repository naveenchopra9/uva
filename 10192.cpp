//time exceeded
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
//typedef map<int, int> msi;
//#define f first
//#define s second
//#define pb push_back
//#define p push
//#define SIZE 100001
#define sz(a) int((a).size())
//#define all(c) (c).begin(),(c).end()
//#define IN ({int n; scanf("%d", &n);    n;})
//#define CN ({char _char; scanf(" %c",&_char); _char;})
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
//#define MIN(a,b) ((a) < (b) ? (a) : (b))
//#define MAX(a,b) ((a) > (b) ? (a) : (b))
//#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
//#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
//#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define FR freopen("/Users/naveen/Documents/online_code/input.txt","r",stdin)
#define FW freopen("/Users/naveen/Documents/online_code/output.txt","w",stdout)
//#define NIL -1
#define Set(a, s) memset(a, s, sizeof (a))
int dp(string x,string y)
{
    int temp[sz(x)+1][sz(y)+1];
    REP(i, 0, sz(y)+1)
     temp[0][i]=0;
    REP(i, 0, sz(x)+1)
    temp[i][0]=0;
    REP(i, 1, sz(x)+1){
        REP(j, 1, sz(y)+1){
            if(x[i-1]==y[j-1]){
                temp[i][j]=temp[i-1][j-1]+1;
            }
            else
                temp[i][j]=max(temp[i-1][j],temp[i][j-1]);
        }
    }
    return temp[sz(x)][sz(y)];
}
int main()
{
//    FR;
//    FW;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int temp=1;
    string str1,str2;
    while(getline(cin,str1))
    {
        if(str1=="#")
            break;
        
        getline(cin,str2);
        cout<<"Case #"<<temp<<": you can visit at most "<<dp(str1,str2)<<" cities."<<endl;
        temp++;
    }
    return 0;
}
/*acdb
 abadacb
 */


