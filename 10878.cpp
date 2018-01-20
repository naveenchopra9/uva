#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <regex>
using namespace std;
//#define IN ({int n; scanf("%d", &n);    n;})
//#define CN ({char _char; scanf(" %c",&_char); _char;})a
//#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define FR freopen("input.txt","r",stdin)
#define FW freopen("output.txt","w",stdout)

int main()
{
//    FW;
    string str;
    while(getline(cin,str))
    {
        int b=128;
        int sum=0;
        unsigned i=0;
        if(str[i] != '|') continue;
        
        for(; str[i]; ++i)
        {
            //cout<<str[i]<<endl;;
            if(str[i]=='o')
            {
                sum+=b;
                b>>=1;
            }
            else if(str[i]==' ')
            {
                b>>=1;
            }
        }
        printf("%c",sum);
    }
    return 0;
}
