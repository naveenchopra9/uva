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
#define FR freopen("/Users/naveen/Documents/online_code/input.txt","r",stdin)
#define FW freopen("/Users/naveen/Documents/online_code/output.txt","w",stdout)
#define NIL -1
#define Set(a, s) memset(a, s, sizeof (a))

void intialize(int arr[],int size[],int n)
{
    for (int i = 0; i < n; ++i)
    {
        arr[i]=i;
        size[i]=1;
    }
}

//finding root of an element
int root(int arr[],int x)
{
    while(arr[x]!=x)
    {
        arr[x]=arr[arr[x]];
        x=arr[x];
    }
    return x;
    
}

void weight_union(int arr[],int size[],int n,int x,int y)
{
    int rootx=root(arr,x);
    int rooty=root(arr,y);
    
    if(size[rootx]<size[rooty])
    {
        arr[rootx]=arr[rooty];
        size[rooty]+=size[rootx];
    }
    else
    {
        arr[rooty]=arr[rootx];
        size[rootx]+=size[rooty];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FR;
    FW;
    int arr[26];
    int size[26];
    
    int t;
    string str;
    cin>>t;
    cin.ignore();
    
    REP(pp, 0, t)
    {
        intialize(arr,size,26);
        while(1)
        {
            getline(cin,str);
            if(str[0]=='*')
                break;
            weight_union(arr,size,26,str[1]-'A',str[3]-'A');
        }
        
        string str1;
         getline(cin,str1);
        bool visited[26];
        Set(visited, false);
        int tree=0,acorn=0;
        bool flag=false;
        
        for(int i = 0 ; i< sz(str1); i+=2)
        {
            visited[str1[i]-'A']=true;
            
            flag=false;
            if(str1[i]-'A'>=0&&str1[i]-'A'<26)
            {
                REP(j, 0, 26)
                {
                    if(arr[str1[i]-'A']==arr[j] && visited[j]==false)
                    {
                        flag=true;
                        visited[j]=true;
                    }
                }
                
                if(flag==true)
                    tree++;
            }
        }
        
        flag=false;
        for(int i = 0 ; i< sz(str1); i+=2)
        {
            flag=false;
            if(str1[i]-'A'>=0&&str1[i]-'A'<26)
            {
                REP(j, 0, 26)
                {
                    if(arr[str1[i]-'A']==arr[j] &&str1[i]-'A'!=j )
                    {
                        flag=true;
                    }
                }
                
                if(flag==false)
                    acorn++;
            }
        }
        cout<<"There are "<<tree<<" tree(s) and "<<acorn<<" acorn(s)."<<endl;
    }
    return 0;
}
