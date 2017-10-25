	#include <iostream>
	#include <bits/stdc++.h>
	#include <vector>
	#include <utility>
	#include <queue>
	#include <functional>
	#include <algorithm>

using namespace std;
struct car
{
	 string str;
	int lower;
	 int higher;
	 car(string s,int l,int h)
	 {
	 	str=s;
	 	higher=h;
	 	lower=l;
	 }
};

int main()
{
		// freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	int q=t-1;
	for(int k =0 ; k < t ; k++)
	{
	vector< car* >vec;
	int n;
	cin>>n;
	string s;
	int x,y;
	for (int i = 0; i < n; ++i)
	{
		cin>>s>>x>>y;
		car* p=new car(s,x,y);
		vec.push_back(p);
	}
	int qur=0;
	cin>>qur;
	for (int i = 0; i < qur; ++i)
	{
		int searchnumber=0;
		cin>>searchnumber;
		int index=0;
		int count=0;
		for (int i = 0; i < vec.size(); ++i)
		{
			// printf("%d %d %d \n",searchnumber,vec[i]->lower,vec[i]->higher );
			if(vec[i]->lower<=searchnumber&&vec[i]->higher>=searchnumber)
			{
				count++;
				index=i;
			}
		}
		if(count==1)
			cout<<vec[index]->str<<endl;
		else
		cout<<"UNDETERMINED"<<endl;
	}
	if(q!=k)
	printf("\n");
	vec.clear();
	}

}
