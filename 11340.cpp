#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	int i, j ,k,number;
	cin>>number;
	for(i =0 ; i <number ; i++)
	{
      int number1;
      cin>>number1;
      int arrinteger[number1];
      char arrchar[number1];
      for(j =0 ; j < number1 ; j++){
        cin>>arrchar[j];
        cin>>arrinteger[j];
      }
      int number2;
      long sum =0;
      cin>>number2;
      string str;
      getchar();
      for( k =0 ; k <number2; k ++){
      	getline(cin,str);
      	for(j =0 ; j<number1 ; j ++){
         int cou=count(str.begin(),str.end(),arrchar[j]);
         sum+=(cou*arrinteger[j]);
      	}
      }
       printf("%0.2f$\n", sum/100.0);
	}
}