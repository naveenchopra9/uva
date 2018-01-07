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
    int N;
    string str;
    map<string,int>mymap;
    string s;
    while(cin>>N>>str)
    {
        mymap.clear();
        for (unsigned i = 0; i < str.length()-N+1; i += 1)
    {
        s=str.substr(i, N);
//        cout << str.substr(i, N) << endl;
        mymap[s]++;
    }
    map<string,int> :: iterator it;
    string temp;
    int temp1=-1;
    for(it=mymap.begin(); it!=mymap.end() ; it++)
    {
//        cout<<it->first<<" " <<it->second<<endl;
        if(it->second>temp1)
        {
            temp1=it->second;
            temp=it->first;
        }
    }
    printf("%s\n",temp.c_str());
        str.clear();
      
    }
    //auto maxvalue=min_element(mymap.begin(),mymap.end(),mymap.value_comp());
    
    //cout<<maxvalue->first<<" "<<maxvalue->second<<endl;
}
