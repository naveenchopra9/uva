#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

#define FR freopen("input.txt","r",stdin)
#define FW freopen("output.txt","w",stdout)

int main()
{
   // FW;
    int A,F,T;
    cin>>T;
    
while(T--)
{
    cin>>A>>F;
    
while(F--)
{
    for(int i =1 ; i<= A ; i++)
    {
        for(int j = 1 ; j <= i ; j++)
        {
            cout<<i;
        }
        cout<<endl;
    }
    for(int j =A-1 ; j>=1 ; j--)
    {
        for(int i = 1 ; i<=j ; i++)
        {
            cout<<j;
        }
        cout<<endl;
    }
    if(F>0||T>0)
    cout<<endl;
}
   // cout<<endl;
}
}


