#include <iostream>
#include <bits/stdc++.h>	
#include <cstdio>
#include <list>
#include <string>
using namespace std;
int main()
{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	string str;
	while(getline(cin,str)&&str!="")
	{
	list<char> slist;
	slist.clear();
	list<char>:: iterator it;
	it=slist.begin();
	// printf("\n");
	for (int i = 0; i < str.size(); ++i)
	{
		if(str[i]=='[')
			it=slist.begin();
		if(str[i]==']')
			it=slist.end();
		if(str[i]!='[' && str[i]!=']')
		{
			// cout<<str[i];
                slist.insert(it,str[i]);
		}
	}
	for(it=slist.begin(); it!=slist.end() ; it++)
		cout<<*it;
		cout<<endl;
	}
	return 0;
}
