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
    //FR;FW;
    int n;
    cin>>n;
    string s,r="";
    cin.ignore();
    REP(j, 0, n)
    {
        getline(cin,s);
        int x=sqrt(sz(s));
        bool check=false;
            if(sz(s)==(x*x))
            {
                check=true;
                //cout<<sz(s)<<"hi"<<(sz(s)==(sqrt(sz(s))*sqrt(sz(s))))<<sqrt(sz(s))<<endl;
            }
        
            if(check==false)
            {
                cout<<"INVALID"<<endl;
            }
            else
            {
                REP(i, 0, x)
                {
                    REP(j, 0, x)
                    {
                        string rend=s.substr(i+j*x,1);
                       // cout<<rend<<endl;
                        r+=rend;
                    }
                }
                cout<<r<<endl;
            }
        r.clear();
    }
	    return 0;
}
