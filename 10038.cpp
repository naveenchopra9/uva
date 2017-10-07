#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>

using namespace std;
int main()
{
int n,i,j;
int array[3001];
while(scanf(" %d", &n) != -1) {
 int arr[n];
 for(i =0 ; i< n ; i++)
   {
    scanf(" %d", &arr[i]);
}
int k=1,count;
for(i =0 ; i<n-1; i++)
 {
  array[k]= arr[i]-arr[i+1];

  if(array[k]<0)
       array[k]=-array[k];
      k++;
}
count=1;
sort(array+1,array+k);
for(i =1 ; i<k; i++ )
	   {
        if(array[i]!=i){
        	count=0;
        	break;
        }
	   }
if(count==0)
cout<<"Not jolly"<<endl;
else
cout<<"Jolly"<<endl;
}
return 0;
}
