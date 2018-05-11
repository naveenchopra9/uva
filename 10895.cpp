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
#define pb push_back
//#define p push
#define SIZE 1000005
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
int a[10000+2][10000+2];
void initialize()
{
    REP(i, 0, 10002)
    {
        REP(j, 0, 10002)
        {
            a[i][j]=0;
        }
    }
}
int main()
{
//        FR;
//        FW;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>vec,rend1,rend2;
    int n,m,numr,x;
    while(cin>>n&&cin>>m)
    {
        REP(i, 0, n)
        {
            REP(j, 0, m)
            {
                a[i][j]=0;
            }
        }
        REP(k, 0, n)
        {
            cin>>numr;
            REP(j, 0, numr)
            {
                cin>>x;
                vec.push_back(x);
            }
            REP(j, 0, numr)
            {
                cin>>x;
                a[k][vec[j]-1]=x;
            }
            vec.clear();
        }
        cout<<m<<" "<<n<<endl;
        REP(i, 0, m)
        {
            REP(j, 0, n)
            {
                if(a[j][i]!=0)
                {
                    rend1.pb(j+1);
                    rend2.push_back(a[j][i]);
                }
            }
            cout<<rend1.size();

            REP(k, 0, sz(rend1))
                cout<<" "<<rend1[k];
            cout<<endl;
            REP(k, 0, sz(rend2))
            {
                if(k==0)
                cout<<rend2[k];
                else
                cout<<" "<<rend2[k];
            }
            cout<<endl;
            
            rend1.clear();
            rend2.clear();
        }
        
    }
}


