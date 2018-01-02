#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
int main()
{
    string str;
    //cout << "Enter a string: ";
    while(1){
        getline(cin, str);
        if(str.empty())
            break;
        //cout<<str<<endl;
        //    cout<<str[0]<<endl;
        size_t len=str.length();
        int cout1=0,cout2=0;
        for(int i=0 ; i<len ; i++)
        {
            if(tolower(str[i])>=97&&tolower(str[i])<=122)
            {
                cout1++;
                //        cout<<str[i]<<cout1;
            }
            if((cout1>0&&(tolower(str[i])<97||tolower(str[i])>122))||(cout1>0&&i==len-1))
            {
                cout2++;
                //            cout<<cout1<<cout2<<endl;
                cout1=0;
            }
        }
        cout<<cout2<<endl;
    }
    //    cout<<endl;
    return 0;
}

