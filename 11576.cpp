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
////const int INF = 0x3f3f3f3f;
//#define MAXV 2147483647
//#define MINV -2147483647
////typedef long long ll;
//typedef vector<int> vi;
//typedef pair<int, int> ii;
//typedef vector< ii > vii;
////typedef set<int> si;
//typedef map<int, int> msi;
//#define f first
//#define s second
//#define pb push_back
//#define p push
#define SIZE 100001
#define sz(a) int((a).size())
//#define all(c) (c).begin(),(c).end()
//#define IN ({int n; scanf("%d", &n);    n;})
//#define CN ({char _char; scanf(" %c",&_char); _char;})
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
//#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
//#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
//#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
//#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define FR freopen("/Users/naveen/Documents/online_code/input.txt","r",stdin)
#define FW freopen("/Users/naveen/Documents/online_code/output.txt","w",stdout)
//#define NIL -1
#define Set(a, s) memset(a, s, sizeof (a))
//# define str_max 256
//int  find_match(string s1,string s2 , int k)
//{
//    int i =0 , j,count=0 ;
//    for(i =0,j=k-1 ; i< k && j>=0 ; j-- ,i++)
//    {
//        if(s2[i]==s1[j])
//        {
//            count++;
//        }
//        else
//            break;
//    }
//    return count;
//}
void calculate(vector<int> &vec,string str)
{
    int l=0,r=0;
    size_t lenr=str.length();
    REP(i, 1, lenr)
    {
        if(i>r){
            l=r=i;
            while(r<lenr&&str[r]==str[r-l]){
                r++;
            }
            vec[i]=r-l;
            r--;
        }
        else{
            int k=i-l;
            if(vec[k]<r-i+1){
                vec[i]=vec[k];
            }
            else{
                l=i;
                while(r<lenr&&str[r]==str[r-l]){
                    r++;
                }
                vec[i]=r-l;
                r--;
            }
        }
    }
}
int Z_algorithm(string str,string pat)
{
    string result=pat+"$"+str;
//    cout<<result<<endl;
    size_t lenr=result.length();
    vector<int>vec(lenr,0);
    calculate(vec, result);
//    REP(i, 0, lenr)
//    {
//        cout<<vec[i]<<" ";
//    }
    
    int sol=0;
    int i;
    for( i = lenr-1 ; i>=sz(pat)+1  ; i--)
    {
        if(vec[i]+i==lenr)
            sol=MAX(vec[i],sol);
    }
//    cout<<sol<<endl;
return sol;
}
void find_solution(string result[],int w , int k)
{
    int sumval=w*k;
    REP(i, 0, w-1)
    {
        int less=Z_algorithm(result[i], result[i+1]);
//        int less=find_match(result[i],result[i+1],k);
//        cout<<less<<endl;
        sumval=sumval-less;
//        cout<<"HI"<<endl;
    }
    cout<<sumval<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//        FR;
//        FW;
    int t; cin>>t;
    REP(i, 0, t)
    {
        int k,w; cin>>k>>w;
        string result[w];
        REP(i, 0, w)
            cin>>result[i];
        find_solution(result,w,k);
    }
    
    return 0;
}
