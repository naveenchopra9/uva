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
ll gcd(ll a,ll b){
    if(b==0)return a;
    else
        return gcd(b, a%b);
}

int main(int argc, char const *argv[])
{
//    FR;
//    FW;
    SYC
    ll a,b;
    while(cin>>a&&cin>>b)
        cout<<abs(b-a)<<endl;
    return 0;
}
