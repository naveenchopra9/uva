#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctype.h>
using namespace std;



int main()
{
    string str1,str2;
    while(getline(cin,str1)&&getline(cin,str2))
    {
        size_t l1=str1.length();
        size_t l2=str2.length();
        int arr1[26],arr2[26];
        memset(arr1,0,sizeof(arr1));
        memset(arr2,0,sizeof(arr2));
        
        for(int i =0 ; i< l1 ; i++)
        {
            arr1[str1[i]-'a']++;
        }
        for(int i =0 ; i < l2 ; i++)
        {
            arr2[str2[i]-'a']++;
        }
        for(int i = 0 ; i <26; i++)
        {
            while(arr1[i]!=0&&arr2[i]!=0)
            {
                arr1[i]--;
                arr2[i]--;
                printf("%c",'a'+i);
            }
        }
        
        cout<<endl;
    }
    return 0;
}


