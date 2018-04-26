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
#define FR freopen("/Users/naveen/Desktop/naveen/uva/uva/input.txt","r",stdin)
#define FW freopen("/Users/naveen/Desktop/naveen/uva/uva/output.txt","w",stdout)
#define NIL -1
#define Set(a, s) memset(a, s, sizeof (a))
int main()
{
//        FR;
//        FW;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag=false;
    bool p=false;
    bool start=false;
    int arr[1000],n=0;
    int integer,i=0;
    
    while(1)
    {
    string str;
    getline(cin,str);
    stringstream ss(str);
    string s;
    i=0;
    p=false;
    while (ss>>integer)
    {
        if(integer==0)
        {
            flag=true;
            break;
            
        }
        else if(p==false)
        {
            n=integer;
            p=true;
        }
        else
        {
            arr[i]=integer;
            i++;
        }
    }
    if(flag==true)
        break;
     if(flag==false&&start==true)
        {
        cout<<endl;
        }
        start=true;
        REP(a, 0, n-5)
        {
            REP(b, a+1, n-4)
            {
                REP(c, b+1, n-3)
                {
                    REP(d, c+1, n-2)
                    {
                        REP(e, d+1, n-1)
                        {
                            REP(f, e+1, n)
                            {
                                cout<<arr[a]<<" "<<arr[b]<<" "<<arr[c]<<" "<<arr[d];
                                cout<<" "<<arr[e]<<" "<<arr[f]<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
