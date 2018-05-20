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
typedef map<lli, lli> msi;
#define el endl
#define p push
#define SIZE 100001;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define IN ({lli n; scanf("%lld", &n);    n;})
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

using namespace std;
map<string,lli> mp;
string vec[137466+10];
int main()
{
//    FR;
//    FW;
    lli temp=1;
    for(lli i =0 ; i< 26 ; i++)
    {
        char c=i+'a';
        string s;
        s+=c;
        mp[s]=temp;
        vec[temp++]=s;
        
    }
     lli rend1=temp;
    for(lli i =0 ; i<rend1 ;  i++)
    {
        for (lli j=i+1; j< 26; j++)
        {
            char ci=i+'a';
            string si;
            si+=ci;
            char cj=j+'a';
            string sj;
            sj+=cj;
            mp[si+sj]=temp;
            vec[temp++]=si+sj;
        }
    }
     lli rend2=temp;
    for(lli i =rend1 ; i< rend2 ; i++)
    {
        for (lli j=(vec[i][sz(vec[i])-1]-'a')+1; j< 26&& (vec[i][sz(vec[i])-1]-'a')<j; j++)
        {
            char cj=j+'a';
            string sj;
            sj+=cj;
            mp[vec[i]+sj]=temp;
            vec[temp++]=vec[i]+sj;
        }
    }
    rend1=rend2;
    rend2=temp;
    for(lli i =rend1 ; i< rend2 ; i++)
    {
        for (lli j=(vec[i][sz(vec[i])-1]-'a')+1; j< 26&& (vec[i][sz(vec[i])-1]-'a')<j; j++)
        {
            char cj=j+'a';
            string sj;
            sj+=cj;
            mp[vec[i]+sj]=temp;
            vec[temp++]=vec[i]+sj;
        }
    }
    
    rend1=rend2;
    rend2=temp;
    for(lli i =rend1 ; i< rend2 ; i++)
    {
        for (lli j=(vec[i][sz(vec[i])-1]-'a')+1; j< 26&& (vec[i][sz(vec[i])-1]-'a')<j; j++)
        {
            char cj=j+'a';
            string sj;
            sj+=cj;
             mp[vec[i]+sj]=temp;
            vec[temp++]=vec[i]+sj;
        }
    }
    string str;
    while(cin>>str)
    {
        cout<<mp[str]<<endl;
    }
    return 0;
}

