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
const int arr1[] = {-1, -1, 0, 1, 1,  1,  0};
const int arr2[] = {-1,  1, 1, 1, 0, -1, -1};
int endr=0,endc=0;
bool search(string result[],string s, int x , int y ,int n)
{
    if(result[x][y]!=s[0])
        return false;
    int cr,col,j;
    
    REP(i, 0, 7)
    {
        cr=x+arr1[i];
        col=y+arr2[i];
        for( j =1 ; j< sz(s) ; j++)
        {
            if(cr<n && col<n && cr>=0 && col>=0 && result[cr][col]==s[j])
            {
                cr=cr+arr1[i]; col=col+arr2[i];
            }
            else
                break;
        }
        if(j==sz(s))
        {
            endr=cr-arr1[i]+1;
            endc=col-arr2[i]+1;
            
            cout<<x+1<<","<<y+1<<" "<<endr<<","<<endc;
//            cout<<j<<" NAAhi"<<sz(s)<<" "<<endl;
            return true;
        }
    }
    return false;
}
void find_string(string result[],string s,int n)
{
    bool flag=false;
    REP(i, 0, n)
    {
        REP(j, 0, n)
        {
            if(search(result,s,i,j,n))
            {
                flag =true;
                return;
            }
        }
    }
    if(flag==false)
        cout<<"Not found";
}

int main()
{
//    FR;
//    FW;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string result[n],s;
    cin.ignore();
    REP(i, 0, n)
        cin>>result[i];
//    cout<<"hI";
    while(cin>>s)
    {
        if(s=="0")
            break;
        find_string(result,s,n);
         cout<<endl;
    }
    return 0;
}



