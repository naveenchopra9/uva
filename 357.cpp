#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 long long int change( int S[], int n, int m )
  {
      long long int table[n+1];
      memset(table, 0, sizeof(table));

      table[0] = 1;
      for(int i=0; i<m; i++)
      {
          for(int j=S[i]; j<=n; j++)
              table[j] += table[j-S[i]];
        }
      return table[n];
  }
int main()
{
  long long int n;
  while(scanf("%lld",&n)==1)
  {
  int arr1[5]={1,5,10,25,50};
  
  long long int way=change(arr1,n,5);
  if(way!=1)
  cout<<"There are "<<way<<" ways to produce "<<n<< " cents change."<<endl;
  else
  cout<<"There is only 1 way to produce "<< n <<" cents change."<<endl;
  }
}
