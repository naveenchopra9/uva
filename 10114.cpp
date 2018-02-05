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
//        FR;
//        FW;
    int mt,dep,gmt;
    double dp,loan,prec;
    while(1)
    {
            int tempmt=0;
            vector<pair<int ,double> >vec;
            cin>>mt>>dp>>loan>>dep;
//    cout<<"fdg"<<endl;
        double borowes=loan,worth=loan+dp;
    if(mt<0)
        break;
      REP(i, 0, dep)
        {
            cin>>gmt>>prec;
            vec.pb(make_pair(gmt,prec));
        }
    bool flag=false;
    REP(i, 0, dep-1)
    {
        
        for(int j=vec[i].f; j<vec[i+1].f ;j++)
        {
                worth=(worth-vec[i].s*worth);
            if(!(i==0&&j==0))
                borowes=borowes-(loan/mt);
//            cout<<"i ="<<i<<"gmt = "<<vec[i].s<<"pre "<<worth<<" "<<tempmt<<" "<<borowes<<" "<<endl;
            if(borowes<worth)
            {
                flag=true;
                break;
            }
            tempmt++;
        }
        if(flag==true)
                break;
    }
    
    while(1&&!flag)
    {
        worth=(worth-vec[dep-1].s*worth);
        borowes=borowes-(loan/mt);
        if(worth>borowes)
        {
            break;
        }
        tempmt++;
//        cout<<"gmt = "<<vec[dep-1].s<<"pre "<<worth<<" "<<tempmt<<" "<<borowes<<" "<<endl;
    }
//    cout<<"gmt = "<<vec[dep-1].s<<"pre "<<worth<<" "<<tempmt<<" "<<borowes<<" "<<endl;
    if(tempmt==1)
        cout<<tempmt<<" month"<<endl;
    else
         cout<<tempmt<<" months"<<endl;
    }
    return 0;
}
