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

int main()
{
    FR;FW;
    int n;
    cin>>n;
    string s,r;
    cin.ignore();
    REP(j, 0, n)
    {
        getline(cin,s);
        REP(i, 0, sz(s))
        {
            string rend=s.substr(i,1);
            int temp=i;
            
            while(check(s[i+1]))
            {
                i++;
            }
            
            string sp=s.substr(temp+1,i-temp);
            
            int num;
            
            //cout<<sp<<endl;
            
            stringstream ss;
            ss<<sp;
            ss>>num;
            
            for(int i =0 ; i<num ; i++)
            {
                //cout<<rend;
                r+=rend;
                
            }
            //cout<<endl;
           // cout<<a<<i<<endl;
        }
        printf("Case %d: ",j+1);
        cout<<r<<endl;
        r.clear();
    }
	    return 0;
}
















