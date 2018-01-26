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
bool isvowel(char c)
{
    switch(c)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            break;
        default:
            return false;
        
    }
    return true;
    
}
bool isvaild(char c)
{
    if((c>=65 &&c<=90)||(c>=97&&c<=122))
         return true ;
    else
       return false;
}
int main()
{
    //FR;
    string str;
    string s,strr="";
    while(getline(cin,str))
    {
        int temp=0;
        
        for(int i =0 ; i< str.length() ; i++)
        {
            if(!isvaild(str[i])|| i == str.length() -1)
            {
                // cout<<str[i]<< " "<<str[temp]<<" "<<i << temp<<endl;
                if((i!=temp||(i==temp && isvaild(str[temp])))&&i!=str.length()-1)
                {
                    string s=str.substr(temp,i-temp);
                    if(isvowel(str[temp]))
                    {
                        strr.append(s,0,s.length());
                    }
                    else
                    {
                        strr.append(s,1,s.length()-1);
                          strr.append(s.substr(0,1),0,1);
                    }
                     strr.append("ay");
                }
                else if((i!=temp||(i==temp && isvaild(str[temp])))&&(i==str.length()-1))
                {
                    if(isvaild(str[i]))
                    {
                    string s=str.substr(temp,i-temp+1);
                    if(isvowel(str[temp]))
                    {
                        strr.append(s,0,s.length());
                    }
                    else
                    {
                        strr.append(s,1,s.length()-1);
                         strr.append(s.substr(0,1),0,1);
                    }
                    strr.append("ay");
                    }
                    else
                    {
                        string s=str.substr(temp,i-temp);
                        if(isvowel(str[temp]))
                        {
                            strr.append(s,0,s.length());
                        }
                        else
                        {
                            strr.append(s,1,s.length()-1);
                            strr.append(s.substr(0,1),0,1);
                        }
                        strr.append("ay");
                    }
                
                }
            if(!isvaild(str[i]))
                    strr+=str[i];
            temp=i+1;
            }
        }
        cout<<strr<<endl;
        str.clear();
        s.clear();
        strr.clear();
    }
    
    return 0;
}

