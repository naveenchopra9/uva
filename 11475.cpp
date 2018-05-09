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
//#define MAX(a,b) ((a) > (b) ? (a) : (b))
//#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
//#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
//#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define FR freopen("/Users/naveen/Documents/online_code/input.txt","r",stdin)
#define FW freopen("/Users/naveen/Documents/online_code/output.txt","w",stdout)
//#define NIL -1
#define Set(a, s) memset(a, s, sizeof (a))
//# define str_max 256
int P[SIZE*2];
void LPS(string s)
{
    string result="@#";
    REP(i, 0, sz(s)){
        result+=s.substr(i,1)+"#";
    }
    result+="$";
    REP(i, 0, sz(result))
            P[i]=0;
    
    //    cout<<result<<endl;
    int curc=0,r=0;
    REP(i, 1, sz(result)-1){
        int iMirror = curc - (i - curc);
        if(r>i){
            P[i]=min(r-i,P[iMirror]);
        }
        // expanding around center i
        while (result[i + 1 + P[i]] == result[i - 1 - P[i]]) {
            P[i]++;
        }
        // Update c,r in case if the palindrome centered at i expands past r,
        if (i + P[i] > r) {
            curc = i;              // next center = i
            r = i + P[i];
        }
    }
//        REP(i, 0, sz(result))
//            cout<<P[i]<<" ";
//        cout<<endl;
//     Find the longest palindrome length in p.
    
    int maxPalindrome = 0;
    int centerIndex = 0;
    
    for (int i = result.length() - 1; i >=1; i--) {
        if (P[i] > maxPalindrome&&(P[i]+i-1)/2==sz(s)) {
//            cout<<result[i]<<" "<<P[i]<<" "<<i<<" "<<(P[i]+i-1)/2<<" "<<sz(result)<<endl;
            maxPalindrome = P[i];
            centerIndex  = i;
        }
    }
//    cout <<maxPalindrome<<" "<<centerIndex <<" "<<(centerIndex+maxPalindrome) / 2<< "\n";
    string right;
    
    for(int i =((centerIndex - 1 - maxPalindrome) / 2)-1 ; i>=0 ; i--)
    {
        right+=s[i];
    }
    string str=s.substr(0, (centerIndex - 1 - maxPalindrome) / 2)+ s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome)+right;
    cout<<str<<endl;
//    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//        FR;
//        FW;
    string result;
    while(cin>>result)
    {
//        t++;
//        cin>>result;
        LPS(result);
        result.clear();
    }
    return 0;
}
