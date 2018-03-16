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
int  prime[50000+1];
void factorize(int N)
{
    
    Set(prime, 0);
    for(int i =2 ; i*i<=N; i++)
    {
        if(prime[i]==0)
        {
            for(int j =i*i ; j<=N ; j+=i)
            {
                if(prime[j]==0)
                    prime[j]=i;
            }
        }
    }
    int j=0;
    for(int i =2 ; i<=N ; i++)
    {
        if(prime[i]==0)
        {
            prime[j]=i;
            j++;
        }
    }
}
vector<pair<int ,long long> > vec;
void fact(long long n)
{
    // vector<long long> res;
    //int temp1=0;
    int ind=0;
    long long temp=prime[0];
    vec.clear();
    while(temp*temp<=n)
    {
//        cout<<temp<<endl;
        int temp2=0;
        while (n%temp==0)
        {
            temp2++;
            n /= temp;
//            if(n==1)
//            {
//                temp1=1;
//                break;
//            }
//            if(temp1==1)
//                break;
        }
        if(temp2!=0)
        vec.push_back(make_pair(temp2, temp));
        temp=prime[++ind];
    }
    int  i=0;
    if(n>1)
        vec.push_back(make_pair(1, n));
    for( i =vec.size()-1 ; i>=0 ; i--)
    {
        if(i==vec.size()-1)
        cout<<vec[i].s<<" "<<vec[i].f;
        else
        cout<<" "<<vec[i].s<<" "<<vec[i].f;
    }
    
}

int main()
{
//            FW;
//            FR;
    factorize(50000);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long x,y,result=1;
    string str;
    while(1)
    {
        getline(cin,str);
        if(str=="0")
            break;
        stringstream s(str);
        string word;
        while (s >> word)
        {
            stringstream ss(word);
            ss>>x;
            s >> word;
            stringstream pp(word);
            pp>>y;
            result*=pow(x,y);
        }
        result=result-1;
        fact(result);
        cout<<endl;
        result=1;
        str.clear();
    }
    return 0;
}
