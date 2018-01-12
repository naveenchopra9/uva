#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
//#define IN ({int n; scanf("%d", &n);    n;})
//#define CN ({char _char; scanf(" %c",&_char); _char;})
//#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define FR freopen("input.txt","r",stdin)
#define FW freopen("output.txt","w",stdout)

int main()
{
    //FW;
    int t;
    cin>>t;
    string str;
    int before=0,mid=0,end=0;
    bool f1=false,f2=false,f3=false;
    int arr[256];
    int temp=1;
    while(t--)
    {
        f1=false; f2=false; f3=false;
        before=0; end=0 ; mid=0;
    cin>>str;
    memset(arr, 0, sizeof(arr));
    for (int i=0; i<str.length(); i++){
        arr[str[i]]++;
    }
    for(int i=0; i<str.length(); i++){
        if(str[i]!='M'&&str[i]!='E'&&str[i]!='?')
        {
            f3=true;
            break;
        }
        if(arr[69]!=1||arr[77]!=1)
        {
            f3=true;
            break;
        }
        if(str[i]=='M')
            f1=true;
        if(str[i]=='E')
            f2=true;
        
        if(f1==false&&str[i]=='?'){
            before++;
        }
        else if(f2==false&&str[i]=='?'){
            mid++;
        }
        else if(str[i]=='?'){
            end++;
        }
            
    }
    //printf("%d %d %d \n",before,mid,end);
    if(f3==true)
        printf("no-theorem\n");
    else if(mid==0 || before==0 || end==0 )
        printf("no-theorem\n");
    else if(before+mid!=end)
        printf("no-theorem\n");
    else
        printf("theorem\n"); 
        //printf("\n%d %d %d\n",temp,arr[77],arr[69]);
        // cout<<str<<endl;
        // temp++;
        // str.clear();
    }
    
    return 0;
}
