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
typedef map<string,float> msi;
#define el endl
#define p push
#define SIZE 100001;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define IN ({int n; scanf("%d", &n);    n;})
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
float round1(float n)
{
    n*=10.0;
    n+=0.5;
    int x;
    x=(int)floor(n);
    return (float)x/10.0;
}

bool check(float n1,float n2 , string str)
{
    n1=round1(n1);
    n2=round1(n2);
    
    if(str=="<"){if(n2<n1)return true;};
    if(str==">"){if(n2>n1)return true ;};
    if(str=="="){if(n1==n2)return true;};
    if(str==">="){if(n2>=n1)return true ;};
    if(str=="<="){if(n2<=n1)return true;};
    return false;
}

using namespace std;
int main()
{
//    FR;
//    FW;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    
    float pervote;
    string str;
    
    float equalvalue=0.0;
    map<string,float>mp;
    
    while(n--)
    {
        cin>>str>>pervote;
        mp[str]=pervote;
    }
    cin.ignore();
    float result=0;
    REP(i, 1, m+1) {
        result=0.0;
        getline(cin,str);
        stringstream ss(str);
        string token,temp="",equalstr="";
        bool flag=false;
        while(getline(ss, token, ' ')) {
            if(token=="="||token==">"|token=="<"||token==">="|| token=="<="){
                temp=token;
                flag=true;
            }
            else if(flag==true)
            {
                equalstr=token;
            }
            else if(token!="+")
            {
                result+=mp[token];
            }
        }
        
        equalvalue=(float)stoi(equalstr);
        
        if(check(equalvalue,result,temp))
            cout<<"Guess #"<<i<<" was correct."<<endl;
        else
            cout<<"Guess #"<<i<<" was incorrect."<<endl;
    }
    return 0;
}

