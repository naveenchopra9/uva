#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bits/stdc++.h>
int checkmirror(int s1,char s2)
{
	  if((s1=='E'&&s2=='3')||(s2=='E'&&s1=='3'))
		return 1;
	 if((s1=='J'&&s2=='L')||(s2=='J'&&s1=='L'))
		return 1;
	 if((s1=='S'&&s2=='2')||(s2=='S'&&s1=='2'))
		return 1;
		if((s1=='Z'&&s2=='5')||(s2=='Z'&&s1=='5'))
			return 1;
	else 
		return 0;
}
int check(char c)
{
	switch(c)
	{
		case 'A':
		case 'H':
		case 'I':
		case 'M':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case '1':
		case '8':
		case 'O':
		case 'Y':
		return 1;
		break;
		default:
		return 0;
	}
}
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	char str[1001];
	while(cin>>str)
	{	
	int l=strlen(str);
	//cout<<l<<endl;
	int s=0,r=l-1;
	int temp=0;
	int mp=0;
	int ms=0;
	for(int i =0 ; i< l/2; i++)
	{
		if(str[i]==str[l-i-1])
		{
			++temp;
			int r=check(str[i]);
			if(r==1)
			  ++mp;

		}

		int q=checkmirror(str[i],str[l-i-1]);
			if(q==1)
				++ms;
		
	}
	int temp1=0;
	if(l%2!=0)
	{
	   temp1=check(str[l/2]);
	}
	if(l%2!=0)
	{
	if(mp==l/2&&temp1==1)
	{
	  cout<<str<<" -- is a mirrored palindrome."<<endl;
	}
	  else if(temp==l/2)
	  cout<<str<<" -- is a regular palindrome."<<endl;
	  else if(mp+ms==l/2&&temp1==1)
	  cout<<str<<" -- is a mirrored string."<<endl;
	  else 
	  cout<<str<<" -- is not a palindrome."<<endl;	
	  cout<<endl;		
	 }	
	else
	{
	if(mp==l/2)
	{
	  cout<<str<<" -- is a mirrored palindrome."<<endl;
	}
	  else if(temp==l/2)
	  cout<<str<<" -- is a regular palindrome."<<endl;
	  else if(mp+ms==l/2)
	  cout<<str<<" -- is a mirrored string."<<endl;
	  else 
	  cout<<str<<" -- is not a palindrome."<<endl;	
	  cout<<endl;		
	 }													
	 //cout<<temp<<" "<<mp<<" "<<ms<<endl;
   }
 return 0;
 }	