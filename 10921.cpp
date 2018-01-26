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
    map <char,char >mp;
    mp['A']='2';mp['B']='2';mp['C']='2';
    mp['D']='3';mp['E']='3';mp['F']='3';
    mp['G']='4';mp['H']='4';mp['I']='4';
    mp['J']='5';mp['K']='5';mp['L']='5';
    mp['M']='6';mp['N']='6';mp['O']='6';
    mp['P']='7';mp['Q']='7';mp['S']='7';mp['R']='7';
    mp['T']='8';mp['U']='8';mp['V']='8';
    mp['W']='9';mp['X']='9';mp['Y']='9';mp['Z']='9';
    string str;
    while(getline(cin,str,'\n'))
    {
        for(int i =0 ; i< str.length() ; i++)
        {
            
            if(str[i]>=65 && str[i]<=91)
                        cout<<mp[str[i]];
            else
                    cout<<str[i];
        }
        cout<<endl;
    }
  
    return 0;
}

