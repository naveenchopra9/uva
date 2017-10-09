#include <iostream>
#include <bits/stdc++.h>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
string str;

int maxpalindrome(int len)
{
	int temp[len][len];
	int i,j,k,l;
	for ( i = 0; i < len; ++i)
	{
		temp[i][i]=1;
	}

	//length of string
	for ( l = 2; l <=len; ++l)	
	{
		for ( i =0; i <len-l+1; ++i)
		{
		     j=l+i-1;
		     if(str[i]==str[j] && l==2)
		  			 temp[i][j]=2;
				else if(str[i]==str[j])
					temp[i][j]=temp[i+1][j-1]+2;
				else
				{
					temp[i][j]=max(temp[i+1][j],temp[i][j-1]);
				}
		
		}
	}
	return temp[0][len-1];
}
int main()
{
	int n;
	cin>>n;
	cin.ignore();
for (int i = 0; i < n; ++i)
	{


	  getline(cin,str);
	 int len=str.length();
	//  cout<<len<<endl;
	  if(len==0)
		cout<<"0"<<endl;
	else
	  cout<<maxpalindrome(len)<<endl;
   }
}