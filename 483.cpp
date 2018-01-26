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
    // FR;
    // FW;
    string str;
    //cin.ignore();
    string str1;
    while(getline(cin,str))
    {
        int temp=0;
        for(int i =0 ; i< str.length() ; i++)
        {
            if(str[i]==' '||i ==str.length()-1)
            {
            	if(i==str.length()-1 &&str[i]==' ')
            		reverse(str.begin()+temp,str.begin()+i);
            	else if(i ==str.length()-1)
            	{
            		reverse(str.begin()+temp,str.begin()+i+1);
            	}
            	else
                reverse(str.begin()+temp,str.begin()+i);
               //cout<<str<<i<<" "<<temp<<endl;
                temp =i+1;
            }
        }
        cout<<str<<endl;
        str.clear();
    }
  
    return 0;
}

