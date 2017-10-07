#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 int main()
{
int arr[10001];
int n,i =0;
while(scanf("%d",&n)!=-1)
   {   
   arr[i]=n;
  sort(arr,arr+i+1);
  if(i%2==0)
      cout<<arr[i/2]<<endl;
  else{
    int l=arr[i/2]+arr[i/2+1];
   cout<<l/2<<endl;
}
 i++;   

}
return 0;
}
