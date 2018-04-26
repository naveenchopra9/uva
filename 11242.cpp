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
int findfour(int a[] ,int n ,int X)
{
    sort(a,a+n);
    REP(i, 0, n-3)
    {
        REP(j, i+1, n-2)
        {
            int l =j+1;
            int r =n-1;
            while(l<r)
            {
            if(a[i]+a[j]+a[l]+a[r]==X)
            {
                return 1;
                
            }
            else if(a[i]+a[j]+a[r]+a[l]<X)
                l++;
            else
                r--;
            }
        }
    }
    return 0;
}
int main()
{
//        FR;
//        FW;
    vector<double>vec;
    double value;
    double f[100],r[100];
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m;
    while(1){
    cin>>m;
    if(m==0)
        break;
    cin>>n;
    REP(i, 0, m)
    cin>>f[i];
    REP(j, 0, n)
    cin>>r[j];
    
    REP(i, 0, n)
    {
        REP(j, 0, m)
        {
            vec.push_back(r[i]/f[j]);
        }
    }
    sort(vec.begin(),vec.end());
     value=-0.01;
    REP(i, 0, sz(vec)-1)
    {
//        cout<<vec[i]<<endl;
//        cout<<vec[i+1]/vec[i]<<endl;
        value=MAX(value, vec[i+1]/vec[i]);
    }
    printf("%.2lf\n",value);
//    cout<<value<<endl;
        vec.clear();
}
//    cout<<endl;
    return 0;
}
