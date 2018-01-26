#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <cstring>

using namespace std;
#define IN ({int n; scanf("%d", &n);    n;})
#define CN ({char _char; scanf(" %c",&_char); _char;})a
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define FR freopen("input.txt","r",stdin)
#define FW freopen("output.txt","w",stdout)
int main()
{
    //FR;
    int n;
    n=IN;
    vector<int>eventranking(n);
    vector<int>studentranking(n);
    
    REP(i,0,n)
    eventranking[i]=IN;
   
    int temp[n] ;
    int temp1=0;
while(scanf("%d",&temp1)==1)
{
    studentranking[temp1-1]=eventranking[0];
    
    temp[0]=1;
    REP(i, 1, n)
    {
    temp[i]=1;
        int x;
        x=IN;
    studentranking[x-1]=eventranking[i];
    }
    
    REP(i, 1, n)
    {
        REP(j, 0 ,i)
        {
           if(studentranking[i]>studentranking[j]&&temp[i]<temp[j]+1)
           {
               temp[i]=temp[j]+1;
           }
        }
    }
    int maxv=1;
    REP(i,0,n)
    maxv=MAX(maxv, temp[i]);
    cout<<maxv<<endl;
}
    return 0;
}

