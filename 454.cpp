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
#define IN ({int n; scanf("%d", &n);    n;})
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
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
    cin>>n;
    cin.ignore();
    cin.ignore();
    
    while(n--)
    {
    string w;
    vector<string>in;
    vector< pair<string,string > >mp;
    while (getline(cin,w)) {
        if(w=="")
            break;
        in.pb(w);
    }
        sort(all(in));
    REP(i, 0, sz(in))
    {
        REP(p, i+1, sz(in))
        {
            
            int a[256],b[256],temp=0;
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            REP(l, 0, sz(in[i]))
            {
                a[in[i][l]]++;
            }
            REP(l, 0, sz(in[p]))
            {
                b[in[p][l]]++;
            }
            REP(j, 0, 256)
            {
                if(a[j]==b[j]&&j!=32)
                    temp=1;
                else if(a[j]!=b[j]&&j!=32)
                {
                    temp=-1;
                    break;
                }
            }
            if(temp==1&&in[i]<=in[p])
            {
                mp.pb(make_pair(in[i],in[p]));
                //cout<<in[i]<<in[p]<<endl;
                
            }
            else if(in[i]>in[p]&&temp==1)
            {
                mp.pb(make_pair(in[p],in[i]));
            }
        }
    }
     vector< pair<string,string > > :: iterator it;
        for(it=mp.begin() ; it!=mp.end() ;it++)
        {
            cout<<(*it).f<<" = "<<(*it).s<<endl;
        }
        mp.clear();
        in.clear();
        if(n!=0)
        cout<<endl;
    }
	    return 0;
}





