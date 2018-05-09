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
#include <set>
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
typedef map<int, int> msi;
#define f first
#define s second
#define pb push_back
#define lli long long int
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
#define opt ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FR freopen("/Users/naveen/Documents/online_code/input.txt","r",stdin)
#define FW freopen("/Users/naveen/Documents/online_code/output.txt","w",stdout)
#define NIL -1
#define Set(a, s) memset(a, s, sizeof (a))
# define str_max 256
struct suffix
{
    int index;
    int id;
    string suff_str;
};

bool cmp(struct suffix a,struct suffix b)
{
    if(a.suff_str<b.suff_str)
        return true;
    return 0;
}
struct suffix suffixs[1000];

int *Naive_Suffix_Array(string txt)
{
    
    int temp=0;
    REP(i, 0, sz(txt))
    {
        if(txt[i]=='#')
             temp=1;
        suffixs[i].suff_str=txt.substr(i,sz(txt));
        suffixs[i].index=i;
        suffixs[i].id=temp;
    }
    sort(suffixs,suffixs+sz(txt),cmp);
    int *suffex_array=new int[sz(txt)];
    REP(i, 0, sz(txt))
    {
        suffex_array[i]=suffixs[i].index;
//        cout<<suffixs[i].suff_str<<endl;
    }
    return suffex_array;
}

vector<int> kasai(string s, int sa[])
{
    size_t n=s.length();
    int k=0;
    vector<int> lcp(n,0);
    vector<int> rank(n,0);
    
    for(int i=0; i<n; i++) rank[sa[i]]=i;
    
    for(int i=0; i<n; i++, k?k--:0)
    {
        if(rank[i]==n-1) {k=0; continue;}
        int j=sa[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[rank[i]]=k;
    }
    return lcp;
}

int main()
{
//    FR;
//    FW;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string txt,str1,str2;
    bool temp=false;
    while(cin>>str1&&cin>>str2)
    {
        if(temp==true)
             cout<<endl;
        temp=true;
        txt=str1+'#'+str2+'$';
        int *suffix_array=Naive_Suffix_Array(txt);
        vector<int>vec = kasai(txt, suffix_array);
        int maxv=0;
        REP(i, 0, sz(txt)-1)
        {
            if((suffixs[i].id==0&&suffixs[i+1].id==1)||(suffixs[i].id==1&&suffixs[i+1].id==0))
            {
                maxv=MAX(maxv, vec[i]);
            }
        }
        if(maxv==0)
            cout<<"No common sequence."<<endl;
        else
        {
        set<string>strset;
        REP(i, 0, sz(txt)-1)
        {
            if(maxv==vec[i]&&((suffixs[i].id==0&&suffixs[i+1].id==1)||(suffixs[i+1].id==0&&suffixs[i].id==1)))
            {
               strset.insert(suffixs[i].suff_str.substr(0,maxv));
            }
        }
        set<string>::iterator it;
        for(it=strset.begin() ; it!=strset.end() ; it++)
                cout<<*it<<endl;
        }
    }

    return 0;
}

