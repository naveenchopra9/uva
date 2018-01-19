#include<bits/stdc++.h>
using namespace std;
int p[100];
float d[100];
float c[100];
int main()
{
	int t,n,i;
	cin>>t;
	cout<<endl;
	while(t>0)
	{
		cin>>n;
		for(i=0;i<n;i++)
		   cin>>p[i];
		for(i=0;i<n;i++)
		   cin>>d[i];
		cout<<endl;
		for(i=0;i<n;i++)
           c[p[i]-1]=d[i];
       for(i=0;i<n;i++)
       	  cout<<c[i]<<endl;
       	cout<<endl;
       	t--;
    }
}



