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
#include <stack>
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
#define ff first
#define ss second
#define pb push_back
#define lli long long int
typedef map<int,int> msi;
#define el endl
#define p push
#define SIZE 100001;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define IN ({lli n; scanf("%lld", &n);    n;})
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

using namespace std;
int main()
{
//    FR;
//    FW;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        
        int a[n+1];
       REP(i, 1, n+1){
            cin>>a[i];
       }
        
        int start=0,end=0;
        
        map<int ,int >mp;
        int maxv=0;
        REP(i, 1, n+1){
            
            if(mp[a[i]]!=0)
            {
                if(start<mp[a[i]])
                    start=mp[a[i]];
                
            }
            mp[a[i]]=i;
            end=i;
            
            maxv=MAX(maxv, end-start);
        }
        mp.clear();
        cout<<maxv<<endl;
    }
    return 0;
}

