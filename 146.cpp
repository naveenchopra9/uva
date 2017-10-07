#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
	while(1)
	{
	string str;
	cin>>str;
	if(str=="#")
		break;
	if(next_permutation(str.begin(),str.end()))
		cout<<str<<endl;
	else
		cout<<"No Successor"<<endl;
    }
}