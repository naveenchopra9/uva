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
    int count=0;
    while(getline(cin,str))
    {
        size_t pl=0,eq=0;
        if(str=="")
            break;
        for(int i =0 ; i< str.length() ; i++)
        {
            if(str[i]=='+'||str[i]=='-')
            {
                pl=i;
                break;
            }
        }
            
        eq=str.find('=');
        string str1=str.substr(0,pl);
        string str2=str.substr(pl+1,eq-pl-1);
        string str3=str.substr(eq+1,str.length()-1);
        //cout<<str1<<" "<<str2<<" "<<str3<<endl;
        int c,a=stoi(str1);
        int b=stoi(str2);
        if(str[eq+1]=='?')
            c=-1;
        else
            c=stoi(str3);
        //cout<<a<<" "<<b<<" "<<c<<endl;
        if(str[pl]=='+')
        {
            if(a>=0&&b>=0&&c>=0&&a<=100&&b<=100&&c<200&&a+b==c)
            {
                count++;
            }
        }
       else
        {
            if(a>=0&&b>=0&&c>=0&&a<=100&&b<=100&&c<200&&a-b==c)
            {
                count++;
            }
        }
        
    }
    cout<<count<<endl;
    return 0;
}
