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
bool check(char c)
{
    if(c>=48&&c<=57)
        return true;
    
        return false;
}
bool check_num(int t)
{
    if(t==32||t==33 || t==44 || t ==58 ||t ==59 || t ==63 ||t>=58)
        return true;
    return false;
}
int main()
{
   // FR;
   // FW;
    string s,r;
    while(getline(cin,s))
    {
        int temp=0;
            if(!check(s[0]))
                temp++;
        if(temp>0)
        {
            REP(i, 0, sz(s))
            {
                int x=s[i];
                string p=to_string(x);
                r+=p;
            }
             reverse(all(r));
        }
        else
        {
            reverse(all(s));
            int t1=0;
            REP(i, 0, sz(s))
            {
                int len=2;
                if(s[i]=='1')
                {
                    len++;
                }
                
                string rend=s.substr(i,len);
                t1=stoi(rend.c_str());
                //cout<<rend<<endl;
                if(t1==32)
                    r+=" ";
                char c=(char)t1;
                stringstream ss;
                string sp;
                ss << c;
                ss >> sp;
                r+=sp;
                i+=(len-1);
            }
        }
         cout<<r<<endl;
        
        r.clear();
    }
	    return 0;
}



