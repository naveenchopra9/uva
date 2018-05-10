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
void dp(string x,string y)
{
    int temp[sz(x)+1][sz(y)+1];
    
    REP(i, 0, sz(x)+1)
    {
        REP(j, 0, sz(y)+1)
        {
            if(i==0)
                temp[i][j]=j;
            
            else if(j==0)
                temp[i][j]=i;
            
           else if(x[i-1]==y[j-1])
               temp[i][j]=temp[i-1][j-1];
            
            else
            {
                temp[i][j]=min(temp[i-1][j],min(temp[i][j-1],temp[i-1][j-1]))+1;
            }
        }
    }
//    REP(i, 0, sz(x)+1){
//        REP(j, 0, sz(y)+1){
//            cout<<temp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<temp[sz(x)][sz(y)]<<endl;
    int i =sz(x),j=sz(y);
    int step=0;
    while(i>0||j>0)
    {
       if(temp[i][j]==temp[i-1][j-1]&&x[i-1]==y[j-1])
       {
           i--;
           j--;
       }
        else if(i>0&& temp[i][j]==temp[i-1][j]+1) // remove
        {
            step++;
            cout<<step<<" ";
            x.erase(i-1,1);
            cout<<"Delete "<<i<<endl;
            i--;
           
        }
        else if(j>0&& temp[i][j]==temp[i][j-1]+1) //insert
        {
            step++;
            cout<<step<<" ";
            x.insert(i,1,y[j-1]);
            
            cout<<"Insert "<<i+1<<","<<y[j-1]<<endl;
            j--;
        }
        else if(i>0 && j>0)//replace
        {
            step++;
            cout<<step<<" ";
            x[i-1]=y[j-1];
            cout<<"Replace "<<i<<","<<y[j-1]<<endl;
            i--;
            j--;
        }
    }
}
int main()
{
//    FR;
//    FW;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str1,str2;
    bool temp=false;
    while(getline(cin,str1)&&getline(cin,str2))
    {
        if(temp)
            cout<<endl;
        temp=true;
        dp(str1,str2);
    }
    return 0;
}


