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
#include <sstream>
using namespace std;
#define IN ({int n; scanf("%d", &n);    n;})
#define CN ({char _char; scanf(" %c",&_char); _char;})a
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define FR freopen("/Users/naveen/Desktop/uva/uva/input.txt","r",stdin)
#define FW freopen("/Users/naveen/Desktop/uva/uva/output.txt","w",stdout)
int main()
{
    int a[256]={0};
    string str;
    while(getline(cin,str,'\n'))
    {
        string s=" ";
        int maxv=1;
        for(int i = 0  ; i< str.length() ; i++)
        {
            if((str[i]>=65&&str[i]<=90) || (str[i]>=97 &&str[i]<=122))
                                                a[str[i]]++;
            maxv=MAX(maxv,a[str[i]]);
        }
        for(int j =0  ; j< 256 ; j++)
        {
            if(a[j]==maxv)
                printf("%c" ,j);
        }
        cout<<" "<<maxv<<endl;
        memset(a,0,sizeof(a));
    }
  
    return 0;
}

