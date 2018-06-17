#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <set>
#include <list>
#include <unordered_set>
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
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
#define MAXV 2147483647
#define MINV -2147483647
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define error 1e-9
#define sz(a) ll((a).size())
#define all(c) (c).begin(),(c).end()
#define IN ({ll n; scanf("%lld", &n);    n;})
#define REP(i, a, b) for (ll i = ll(a); i < ll(b); i++)
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define TR(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define SYC ios_base::sync_with_stdio(0); cin.tie(0);
#define FR freopen("/Users/naveen/Documents/input.txt","r",stdin)
#define FW freopen("/Users/naveen/Documents/output.txt","w",stdout)
#define Set(a, s) memset(a, s, sizeof (a))
bool ismatch(string s1,string s2){
    if(s1[0]==s2[0]||s1[1]==s2[1])
        return true;
    return false;
}
void findnum(string str){
    vector<vector<string> >stack;
    stringstream s(str);
    string token;
    while (s>>token) {
        stack.PB(vector<string>(1,token));
    }
    bool check=false;
    while(1){
        check=false;
        REP(i, 0, sz(stack)){
            if(i>=3&&ismatch(stack[i-3].back(),stack[i].back())){
                stack[i-3].PB(stack[i].back());
            }
            else if(i>=1&&ismatch(stack[i-1].back(),stack[i].back())){
                stack[i-1].PB(stack[i].back());
            }
            else
                continue;
            
            stack[i].pop_back();
            if(sz(stack[i])==0){
                stack.erase(stack.begin()+i);
            }
            check=true;
            break;
        }
        if(check==false)
            break;
    }
    if(sz(stack)==1){
        cout<<"1 pile remaining: 52"<<endl;
        return;
    }
    cout<<sz(stack)<<" piles remaining:";
    REP(i, 0, sz(stack)){
        cout<<" "<<sz(stack[i]);
    }
    cout<<endl;
}
int main(int argc, char const *argv[])
{
//    FR;
//    FW;
    SYC
    string str,resultstr="";
    int temp=1;
    while(getline(cin,str)){
        if(str=="#")break;
        if(temp<=2){
            if(temp==1)
                resultstr+=str;
            else
                resultstr+=" "+str;
            temp++;
        }
        if(temp>2){
            temp=1;
            findnum(resultstr);
            resultstr="";
        }
        
    }
//    cout<<resultstr<<endl;
    return 0;
}
