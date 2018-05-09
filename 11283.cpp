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
//const int INF = 0x3f3f3f3f;
#define MAXV 2147483647
#define MINV -2147483647
//typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;
//typedef set<int> si;
//typedef map<int, int> msi;
//#define f first
//#define s second
//#define pb push_back
//#define p push
//#define SIZE 100001
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
const int arr1[] = {-1,-1, -1, 0, 1, 1,  1,  0};
const int arr2[] = {-1,0,  1, 1, 1, 0, -1, -1};
bool flag;
bool mat[4][4];
void DFS(string result[],string word ,int row ,int col,int prevrow , int prevcol , int start ,int n)
{
    if(result[row][col]!=word[start]|| start>n){
        return ;
    }
    if(start==n)
    {
        flag=true;
        return ;
    }
    mat[row][col]=true;
    for(int i = 0 ; i< 8 ; i++){
        if((row+arr1[i]>=0) && (row+arr1[i]) <4 &&
           (col+arr2[i])>=0&& (col+arr2[i]) < 4 &&
           !((row+arr1[i])==prevrow && (col+arr2[i])==prevcol)){
            if(mat[row+arr1[i]][col+arr2[i]]==false)
            DFS(result,word,row+arr1[i],col+arr2[i],row,col,start+1,n);
        }
    }
     mat[row][col]=false;
}
bool find_string(string result[],string s)
{
     flag=false;
    REP(i, 0, 4){
        REP(j, 0, 4){
            REP(k, 0, 4)
              Set(mat[k], false);
            DFS(result,s,i,j,-1,-1,0 ,sz(s)-1);
            if(flag==true)
            {
                return true;
            }
            
        }
    }
    return false;
}

int main()
{
//    FR;
//    FW;
    map< int , int >mp;
    static_cast<void>(mp[3]=1);
    static_cast<void>(mp[4]=1);
    static_cast<void>(mp[5]=2);
    mp[6]=3;
    mp[7]=5;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    cin.ignore();
    REP(j, 0, t){
        int q;
        string result[4],s;
        REP(i, 0, 4){
            cin>>result[i];
        }
        cin>>q;
        int count=0;
       REP(i, 0, q){
            cin>>s;
            if(find_string(result,s))
            {
//                cout<<s<<endl;
                if(sz(s)<8)
                    count+=mp[sz(s)];
                else
                    count+=11;
            }
        }
        cout<<"Score for Boggle game #"<<j+1<<": "<<count<<endl;
    }
    return 0;
}



