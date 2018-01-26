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
    char L[100] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 91, 93, 92,
                    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 59, 39,
                    'z', 'x', 'c', 'v', 'b', 'n', 'm', 44, 46, 47,
                    '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 45, 61} ;
    string str;
    while(getline(cin,str,'\n'))
    {
        for(int i =0 ; i< str.length() ; i++)
        {
           if(str[i]==' ' || str[i]=='\n')
           {
               cout<<str[i];
           }
           else{
           	str[i]=tolower(str[i]);
               //cout<<str[i];
               for(int j=1 ; j< 47 ; j++ )
               {
                   if(str[i]==L[j])
                   {
                       cout<<L[j-2];
                       break;
                   }
               }
               
           }
        }
        cout<<endl;
    }
  
    return 0;
}

