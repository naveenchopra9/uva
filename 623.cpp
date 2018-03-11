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
#define FR freopen("/Users/naveen/Desktop/uva/uva/input.txt","r",stdin)
#define FW freopen("/Users/naveen/Desktop/uva/uva/output.txt","w",stdout)
#define NIL -1
#define Set(a, s) memset(a, s, sizeof (a))
//int count_len1=0;
//int count_len2=0;
vector<string>str2;
string multiply(string s1,string s2)
{
    int n1=sz(s1);
    
    int n2=sz(s2);
    
    vector<int>ans(n1+n2,0);
    
    if(n1==0||n2==0)
        return 0;
    
    int lcar1=0;
    for(int j =n1-1 ; j>=0 ; j --)
    {
        int firstnum=s1[j]-'0';
        int carry=0;
        int lcar2=0;
        for(int i=n2-1 ; i>=0 ; i--)
        {
            int secondnum=s2[i]-'0';
            int result=firstnum*secondnum+carry+ans[lcar1+lcar2];
            carry=result/10;
            ans[lcar1+lcar2]=result%10;
            lcar2++;
           // count_len1++;
        }
        if(carry>0)
            ans[lcar1+lcar2]+=carry;
        lcar1++;
    }
    int i =sz(ans)-1;
    while(!ans[i])
    {
        ans.erase(ans.begin()+i);
        i--;
        //count_len2++;
    }
    string rstr;
    for(int i = sz(ans)-1 ; i>=0 ; i--)
        rstr.push_back(ans[i]+'0');
//    cout<<rstr<<endl;
    ans.clear();
    return rstr;
}
void result(int N)
{    //long long int count =0;
    string s="1";
    str2.push_back("1");
//    cout<<str2[0]<<endl;
    for(int i =1 ; i<=N ; i++)
    {
        stringstream ss;
        ss << i;
        string str = ss.str();
        
         s=multiply(str, s);
        //cout<<s<<endl;
       str2.push_back(s);
        //str1[i]=s;
//        cout<<str2[i]<<endl<<endl;
      //  count++;
    }
    //cout<<"countfor N"<<count<<" " <<count_len1<<" "<<count_len2<<endl;
    //cout<<N<<"!"<<endl<<s<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    result(1002);
    while(cin>>N)
    {
        //cout<<str2[N]<<endl;
        cout<<N<<"!"<<endl<<str2[N]<<endl;
    }
    return 0;
}
